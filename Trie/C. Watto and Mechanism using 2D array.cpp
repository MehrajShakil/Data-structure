// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e5+1;
string s;
int trie[MAXN][3],nxt=1,ans=0;
bool isleaf[MAXN];

void insert()
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

bool dfs(int root, int cnt, int pos)
{

    bool ok =0;
    if(cnt>1)
        return 0;
    if(cnt==1 && isleaf[root] && pos==s.size())
        return 1;
    if(!isleaf[root] && pos==s.size())
        return 0;

    for(int j=0; j<3; j++)
    {
        if(trie[root][j]==0)
            continue;
        if(s[pos]-'a'==j)
        {
            ok = ok | dfs(trie[root][j],cnt,pos+1);
        }
        else
            ok = ok | dfs(trie[root][j],cnt+1,pos+1);
        if(ok)
            return ok;
    }
    return 0;
}


int main()
{
    memset(trie,0,sizeof trie);
    memset(isleaf,false,sizeof isleaf);
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
