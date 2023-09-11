#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void singmailpros(const map<string, map<string, vector<string>>>& mail, const map<string, string>& pengguna, const string& recipient) 
{
    auto it = mail.find(recipient);
    if (it == mail.end()) 
	{
        return;
    }

    cout << "===========" << endl;
    cout << "Mail: " << pengguna.find(recipient)->second << endl;

    const auto& messages = it->second;

    for (auto msg_it = messages.begin(); msg_it != messages.end(); ++msg_it) 
	{
        const string& sender = msg_it->first;
        cout << "From: " << pengguna.find(sender)->second << endl;

        const auto& messageList = msg_it->second;

        for (auto msg_text_it = messageList.begin(); msg_text_it != messageList.end(); ++msg_text_it) 
		{
            cout << ">> " << *msg_text_it << endl;
        }
    }
}

void allmailpros(const map<string, map<string, vector<string>>>& mail, const map<string, string>& user) 
{
    for (auto mg_it = mail.begin(); mg_it != mail.end(); ++mg_it) 
	{
        const string& recipient = mg_it->first;
        singmailpros(mail, user, recipient);
    }
}

int main() 
{
    map<string, map<string, vector<string>>> PESAN; //Jan ketuker
    map<string, string> user;
    int N, Q;
    string IPpes, nama, IPsend, IPrec, pesan;

    cin >> N >> Q;

    for (int i = 0; i < N; i++) 
	{
        cin >> IPpes >> nama;
        user[IPpes] = nama;
    }

    for (int j = 0; j < Q; j++) 
	{
        cin >> IPsend >> IPrec;
        getline(cin, pesan);

        if (user.find(IPsend) == user.end() || user.find(IPrec) == user.end())
            continue;

        PESAN[IPrec][IPsend].push_back(pesan);
    }

    allmailpros(PESAN, user);

    return 0;
}
