#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ip, name;
    string send, receive, message;
    string previousreceive = "";
    string previoussender = "";
    map<string, string> mail;
    vector<pair<string, pair<string, pair<int, string>>>> messages;

    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    while(N--)
    {
        cin >> ip >> name;
        mail[ip] = name;
    }

    for (size_t i = 0; i < Q; ++i)
    {
        cin >> send >> receive;
        cin.ignore();
        getline(cin, message);

        if (mail.find(receive) != mail.end() && mail.find(send) != mail.end())
        {
            messages.push_back(make_pair(receive, make_pair(send, make_pair(i, message))));
        }
    }

    sort(messages.begin(), messages.end(), [&](const pair<string, pair<string, pair<int, string>>>& a, const pair<string, pair<string, pair<int, string>>>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else if (a.second.first != b.second.first) {
            return a.second.first < b.second.first;
        } else {
            return a.second.second.first < b.second.second.first;
        }
    });

    for (const auto &message : messages)
    {
        if (message.first != previousreceive)
        {
            previousreceive = message.first;
            cout << "===========\n";
            cout << "Mail: " << mail[previousreceive] << "\n";
            previoussender = "";
        }

        if (message.second.first != previoussender)
        {
            previoussender = message.second.first;
            cout << "From: " << mail[previoussender] << "\n";
        }

        cout << ">> " << message.second.second.second << "\n";
    }

    return 0;
}
