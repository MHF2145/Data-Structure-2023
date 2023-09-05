#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void sendMessage(map<string, multiset<pair<string, string>>>& mailboxes, const string& send, const string& receive, const string& pesan) {
    if (mailboxes.count(receive) == 0 || mailboxes.count(send) == 0) {
        return;
    }

    mailboxes[receive].insert({send, pesan});
}

void printMailbox(const multiset<pair<string, string>>& messages, const map<string, string>& participants, const string& name) {
    cout << "===========\n";
    cout << "Mail: " << name << endl;

    map<string, vector<string>> senderMessages;
    for (const auto& message : messages) {
        senderMessages[message.first].push_back(message.second);
    }

    for (const auto& entry : senderMessages) {
        string send = entry.first;
        if (participants.count(send) == 0) {
            continue;
        }

        cout << "From: " << participants.at(send) << endl;
        for (const string& pesan : entry.second) {
            cout << ">> " << pesan << endl;
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    map<string, string> participants;
    for (int i = 0; i < N; i++) {
        string ip, name;
        cin >> ip >> name;
        participants[ip] = name;
    }

    map<string, multiset<pair<string, string>>> mailboxes;
    for (const auto& entry : participants) {
        mailboxes[entry.first] = {};
    }

    for (int i = 0; i < Q; i++) {
        string send, receive, pesan;
        cin >> send >> receive;
        getline(cin, pesan);
        pesan = pesan.substr(1);

        sendMessage(mailboxes, send, receive, pesan);
    }

    for (const auto& entry : mailboxes) {
        printMailbox(entry.second, participants, participants.at(entry.first));
    }

    return 0;
}
