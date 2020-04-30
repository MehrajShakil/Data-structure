// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;

int trie[MAXN][10],nxt=1,ans;
bool isleaf[MAXN];

bool insert(string s)
{
    int root=1;
    for(int i=0; i<s.size(); i++)
    {

        int c = s[i]-'0';
        if(trie[root][c]==0)
        {
            trie[root][c]= ++nxt;
        }
        root = trie[root][c];

        if(isleaf[root]==true)ans=0;
    }
    isleaf[root]=true;
    return ans;

}
bool cmp(string s1, string s2){
    return s1.length()<s2.length();
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
        cin >> n;
        string s[n];

        ans=1;
        for(int i=0; i<n; i++)
        {
            cin >> s[i];
        }
        sort(s,s+n,cmp);
        for(int i=0; i<n; i++)
        {
            if(!insert(s[i]))break;
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
