#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Person {
    int confidence;
    int group;
};

struct Friendship {
    int distance;
    bool valid;
};

class AK47 {
private:
    vector<Person> people;
    vector<Friendship> friendships;
    unordered_map<int, vector<int>> groups;

public:
    AK47(int n, int m) {
        people.resize(n + 1);
        friendships.resize(m);
        for (int i = 1; i <= n; i++) {
            cin >> people[i].confidence;
            people[i].group = i;
            groups[i].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            friendships[i].distance = w;
            friendships[i].valid = true;

            mergeGroups(u, v);
        }
    }

    int findGroup(int x) {
        if (people[x].group != x) {
            people[x].group = findGroup(people[x].group);
        }
        return people[x].group;
    }

    void mergeGroups(int a, int b) {
        int groupA = findGroup(a);
        int groupB = findGroup(b);
        if (groupA == groupB) return;

        if (groups[groupA].size() < groups[groupB].size()) {
            swap(groupA, groupB);
        }

        for (int person : groups[groupB]) {
            people[person].group = groupA;
            groups[groupA].push_back(person);
        }
        groups[groupB].clear();
    }

    int findSmallestDistance(int group) {
        int smallest = -1;
        for (int person : groups[group]) {
            for (int i = 0; i < friendships.size(); i++) {
                if (friendships[i].valid) {
                    int u = i + 1;
                    int v = (u == person) ? i + 2 : i + 1;
                    if (v > friendships.size()) break;

                    if (findGroup(u) == group && findGroup(v) == group) {
                        if (smallest == -1 || friendships[i].distance < smallest) {
                            smallest = friendships[i].distance;
                        }
                    }
                }
            }
        }
        return smallest;
    }

    int calculateConfidence(int a, int b) {
        int groupA = findGroup(a);
        int groupB = findGroup(b);

        if (groupA == groupB) return 0;

        int confidenceA = *max_element(groups[groupA].begin(), groups[groupA].end(), [&](int x, int y) {
            return people[x].confidence < people[y].confidence;
        });

        int confidenceB = *max_element(groups[groupB].begin(), groups[groupB].end(), [&](int x, int y) {
            return people[x].confidence < people[y].confidence;
        });

        return people[confidenceA].confidence + people[confidenceB].confidence;
    }

    void updateConfidence(int person, int newConfidence) {
        people[person].confidence = newConfidence;
    }

    void updateDistance(int a, int b, int newDistance) {
        for (int i = 0; i < friendships.size(); i++) {
            if (friendships[i].valid) {
                int u = i + 1;
                int v = (u == a) ? i + 2 : i + 1;
                if (v > friendships.size()) break;

                if ((u == a && v == b) || (u == b && v == a)) {
                    friendships[i].distance = newDistance;
                    break;
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    AK47 ak47(n, m);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, x;
            cin >> a >> x;
            ak47.updateConfidence(a, x);
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            ak47.updateDistance(a, b, x);
        } else if (type == 3) {
            int a;
            cin >> a;
            int smallestDistance = ak47.findSmallestDistance(ak47.findGroup(a));
            cout << smallestDistance << endl;
        } else if (type == 4) {
            int a, b;
            cin >> a >> b;
            int totalConfidence = ak47.calculateConfidence(a, b);
            cout << totalConfidence << endl;
        }
    }

    return 0;
}
