#include <bits/stdc++.h>
using namespace std;
vector<set<pair<int, int>, greater<pair<int, int>>>> setNodes(1000006);
vector<set<pair<int, pair<int, int>>>> setEdges(1000006);
vector<pair<int, pair<int, int>>> edge;
map<pair<int, int>, int> cmdlist;
vector<int> conf(1000006, 0);
vector<int> parnt(1000006, 0);
vector<int> kastaHR(1000006, 0);

int find_root(int key){
    if (parnt[key] == key){
        return key;
    }
    return parnt[key] = find_root(parnt[key]);
}

void merge_sets(int node1, int node2){
    int root1 = find_root(node1);
    int root2 = find_root(node2);

    if (root1 != root2) {
        int temp;
        if (kastaHR[root1] < kastaHR[root2]){
            temp=root1;
            root1=root2;
            root2=temp;
        }
        if (kastaHR[root1] == kastaHR[root2]){
            kastaHR[root1]++;
        }
        parnt[root2] = root1;
    }
}

int main(){
    int vert,edg; 
    cin >> vert>>edg;

    for (int i = 1; i <= vert; ++i){
        cin >> conf[i];
        parnt[i] = i;
        kastaHR[i] = 1;
    }
    for (int i = 1; i <= edg; ++i){
        int str, ed, weight; 
        cin >> str>>ed>>weight;
        int temp;
        if (str > ed){
            temp=str;
            str=ed;
            ed=temp;
        }
        merge_sets(str, ed);

        int prntnow = find_root(str);
        setEdges[prntnow].insert({ weight, {str, ed} });
        cmdlist[{str, ed}] = weight;
    }
    
    for (int i = 1; i <= vert; ++i){
        int rootnow = find_root(i);
        setNodes[rootnow].insert({ conf[i], i });
    }

    int tcase; 
    cin >> tcase;
    for (int i = 0; i < tcase; ++i){
        string a1; 
        int a2; 
        cin >> a1>>a2;
        if (a1 == "!"){
            if (a2 == 1){
                int num, confnew; 
                cin >> num>>confnew;
                int rootnow = find_root(num);

                setNodes[rootnow].erase({ conf[num], num });
                setNodes[rootnow].insert({ confnew, num });
                conf[num] = confnew;
            }
            else if (a2 == 2){
                int ank1, ank2, neweight; 
                cin >> ank1>>ank2>>neweight;
                int temp;
                if (ank1 > ank2){
                    temp=ank1;
                    ank1=ank2;
                    ank2=temp;
                }
                int curRoot = find_root(ank1);
                pair<int, int> curCnct = { ank1, ank2 };
                setEdges[curRoot].erase({ cmdlist[curCnct], curCnct });
                setEdges[curRoot].insert({ neweight, curCnct });
                cmdlist[curCnct] = neweight;
            }
        }
        else if (a1 == "?"){
            if (a2 == 1){
                int askNode; 
                cin >> askNode;
                int curRoot = find_root(askNode);
                if (setEdges[curRoot].size() == 0){
                    cout << "0\n";
                }
                else{
                    cout << setEdges[curRoot].begin()->first << "\n";
                }
            }
            else if (a2 == 2){
                int askNode1, askNode2; 
                cin >> askNode1>>askNode2;
                int temp;
                if (askNode1 > askNode2){
                    temp=askNode1;
                    askNode1=askNode2;
                    askNode2=temp;
                }
                int node1Root = find_root(askNode1);
                int node2Root = find_root(askNode2);
                if (node1Root == node2Root){
                    cout << "0\n";
                }
                else{
                    int con = setNodes[node1Root].begin()->first;
                    int con2 = setNodes[node2Root].begin()->first;
                    cout << con + con2 << "\n";
                }
            }
        }
    }
    // while(1){

    // }
    return 0;
}