// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+1;

int trie[MAXN][26],nxt=1,ans;
bool isleaf[MAXN];

void insert(string s)
{
    int root=1;
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i]-'a';
        if(!trie[root][c])
        {
            trie[root][c]= ++nxt;
        }
        root = trie[root][c];
    }

    isleaf[root]=true;
}

bool search(string s)
{
    int root=1;
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i]-'a';
        if(!trie[root][c])
        {
            return false;
        }
        root = trie[root][c];
    }
    return isleaf[root];
}

int main()
{

    int t;
    cin >> t;
    while(t--)
    {

        int n ;
        memset(trie,0,sizeof trie);
        memset(isleaf,false,sizeof isleaf);
        nxt=1;
        string s ,txt;
        cin >> s >> txt;
        insert(s);
        if(search(txt))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
