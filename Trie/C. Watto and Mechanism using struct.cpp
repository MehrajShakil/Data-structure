// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6e5+2;
int nxt;
string s;
struct Trie
{
    int ch[3];
    bool isleaf;
} trie[MAXN];

void insert()
{
    int root=1;
    for(int i=0; i<s.size(); i++)
    {

        int c = s[i]-'a';
        if(!trie[root].ch[c])
        {
            trie[root].ch[c] = ++nxt;
        }
        root = trie[root].ch[c];
    }
    trie[root].isleaf=true;
}

bool dfs(int root,int cnt, int pos)
{

    bool ok =0;
    if(cnt>1)
        return 0;

    if(s[pos]=='\0')
    {
        return  cnt==1 && trie[root].isleaf ?  1 : 0;
    }

    for(int j=0; j<3; j++)
    {
        if(trie[root].ch[j]==0)
            continue;
        if(s[pos]-'a'==j)
        {
            ok = ok | dfs(trie[root].ch[j],cnt,pos+1);
        }
        else
            ok = ok | dfs(trie[root].ch[j],cnt+1,pos+1);
        if(ok)
            return ok;
    }
    return 0;
}


int main()
{

    int n,m;
    cin >> n >> m;

    while(n--)
    {
        cin >> s;
        insert();
    }
    while(m--)
    {
        cin >> s;

        if(dfs(1,0,0))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

}
