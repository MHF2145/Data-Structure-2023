#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    map<string, string> peserta;
    map<string, map<string, vector<string>>> chat;

    for (int i = 0; i < N; i++) {
        string id, name;
        cin >> id >> name;
        peserta[id] = name;
    }

    for (int i = 0; i < Q; i++) {
        string idsender, idpenerima, isichat;
        cin >> idsender >> idpenerima;
        getline(cin, isichat);

        if(peserta.find(idsender) == peserta.end() || peserta.find(idpenerima) == peserta.end()){
        	continue;
		}

        chat[idpenerima][idsender].push_back(isichat);
    }

    for (const auto& recipient : peserta) {
        const string& idpenerima = recipient.first;
        const string& namapenerima = recipient.second;
        
        if (chat[idpenerima].empty()) {
            continue;
        }
        
        cout << "===========\n";
        cout << "Mail: " << namapenerima << "\n";
        
        for (const auto& sender : chat[idpenerima]) {
            const string& idsender = sender.first;
            const string& senderName = peserta[idsender];
            
            cout << "From: " << senderName << "\n";
            
            for (const string& message : sender.second) {
                cout << ">> " << message << "\n";
            }
        }
    }


    return 0;
}



/*
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class backend {
public:
    void adress(const string& id, const string& namapeserta) {
        peserta[id] = namapeserta;
    }

    void nerima(const string& idsender, const string& idpenerima, const string& isichat) {
        chat[idpenerima][idsender].push_back(isichat);
    }

    void inbox(const string& idpenerima) {
        cout << "===========\n";
        cout << "Mail: " << peserta[idpenerima] << "\n";

        auto it = chat.find(idpenerima);
        if (it != chat.end()) {
            for (auto i = it->second.begin(); i != it->second.end(); ++i) {
                const auto& idsender = i->first;
                const auto& chats = i->second;
                cout << "From: " << peserta[idsender] << "\n";
                for (auto j = chats.begin(); j != chats.end(); ++j) {
                    const auto& chat = *j;
                    cout << ">> " << chat << "\n";
                }
            }
        }
    }

    const map<string, string>& getpeserta() const {
        return peserta;
    }

private:
    map<string, map<string, vector<string>>> chat;
    map<string, string> peserta;
};

int main() {
    int N, Q;
    cin >> N >> Q;

    backend mesin;

    for (int i = 0; i < N; i++) {
        string id, name;
        cin >> id >> name;
        mesin.adress(id, name);
    }

    for (int i = 0; i < Q; i++) {
        string idsender, idpenerima, chat;
        cin >> idsender >> idpenerima;
        getline(cin >> ws, chat);
        mesin.nerima(idsender, idpenerima, chat);
    }

    const auto& namapeserta = mesin.getpeserta();
    for (auto i = namapeserta.begin(); i != namapeserta.end(); ++i) {
        const string& idpenerima = i->first;
        mesin.inbox(idpenerima);
    }

    return 0;
}
*/
