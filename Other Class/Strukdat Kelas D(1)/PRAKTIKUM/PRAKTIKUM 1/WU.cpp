#include <iostream>
#include <vector>

using namespace std;

struct Node{
    string name;
    vector<Node*> v;
};

struct Node *getNode(string n){
    struct Node *pNode = new Node;
    pNode->name = n;
    return pNode;
};

void ins(struct Node *root, vector<string> k)
{
    struct Node *p = root;
    for(int i = 0; i < k.size(); i++)
    {
        bool check = 0;
        for(int j=0; j < p->v.size(); j++)
        {
            if(p->v[j]->name == k[i])
            {
                p = p->v[j];
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            Node* new_node = getNode(k[i]);
            p->v.push_back(new_node);
            p = new_node;
        }
    }
}

void src(struct Node *root, vector<string> k)
{
    struct Node *p = root;
    for(int i = 0; i < k.size(); i++)
    {
        bool check = 0;
        for(int j = 0; j < p->v.size(); j++)
        {
            if(p->v[j]->name == k[i])
            {
                p = p->v[j];
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            cout << "ls: " << k[i] << ": " << "No such file or directory" << '\n';
            return;
        }
    }
    for(int i = 0; i < p->v.size(); i++)
        cout << p->v[i]->name << " ";
    
    cout << '\n';
}

vector<string> dec(string s)
{
    vector<string> ans;
    string curr = "";
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == '/')
        {
            ans.push_back(curr);
            curr = "";
        }
        else 
            curr += s[i];
    }
    return ans;
}

int main()
{
    struct Node *root = getNode("");
    int n; 
    cin >> n;
    cin.ignore();
    for(int u = 0; u < n; u++)
    {
        string s, res = "";
        getline(cin, s);
        int i = 0;
        for(; i < (int)s.size(); i++)
        {
            if(s[i] == ' ') 
                break;
            else
                res += s[i];
        }
        if(res == "mkdir")
        {
            i++;
            string res2 = "";
            for(; i < (int)s.size(); i++)
            {
                if(s[i] == ' ') 
                    break;
                else
                    res2 += s[i];
            }
            if(res2 == "-p") 
                ins(root, dec(s.substr(i + 1)));
            else 
                cout << "command not found: " << res << " " << res2 << '\n';
        }
        else if(res == "ls") 
            src(root, dec(s.substr(i + 1)));
        else 
            cout << "command not found: " << res << '\n';
    }

    return 0;
}