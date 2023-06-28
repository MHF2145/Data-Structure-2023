//Bismillah Ga salah!!!
#include <bits/stdc++.h>

struct Message
{
    std::string senderIP;
    std::string receiverIP;
    std::string content;
};

struct Participant
{
    std::string IP;
    std::string name;
};

int main()
{
    int N, Q;
    std::cin >> N >> Q;

    std::map<std::string, std::string> participants;
    for (int i = 0; i < N; ++i)
    {
        std::string IP, name;
        std::cin >> IP >> name;
        participants[IP] = name;
    }

    std::vector<Message> messages(Q);
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> messages[i].senderIP >> messages[i].receiverIP;
        std::cin.ignore();
        std::getline(std::cin, messages[i].content);
    }

    std::map<std::string, bool> print;
    std::map<std::string, std::vector<std::vector<std::string>>> arr;

    for (const Message &message : messages)
    {
        auto it_receiver = participants.find(message.receiverIP);
        auto it_sender = participants.find(message.senderIP);
        if (it_receiver != participants.end() && it_sender != participants.end())
        {
            print[message.receiverIP] = true;
            arr[message.receiverIP].push_back({message.senderIP, message.content});
        }
    }

    for (const auto &entry : print)
    {
        std::map<std::string, std::vector<std::string>> temp1;
        std::cout << "===========\n";
        std::cout << "Mail: " << participants[entry.first] << "\n";

        for (const auto &message : arr[entry.first])
        {
            temp1[message[0]].push_back(message[1]);
        }

        for (const auto &entry2 : temp1)
        {
            std::cout << "From: " << participants[entry2.first] << "\n";
            for (const std::string &msg : entry2.second)
            {
                std::cout << ">> " << msg << "\n";
            }
        }
    }

    return 0;
}
