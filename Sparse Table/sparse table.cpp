#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN=(int)1e5+1;
const int logk=17;

int sparsetable[MAXN][logk];
int arr[MAXN];

void sparse(ll n)
{

    for(int i=0; i<n ; i++)
        sparsetable[i][0]=arr[i];

    for(ll j = 1 ; (1<<j)<=n ; j++)
    {
        for(ll i=0 ; i+(1<<j)-1 < n ; i++)
        {
            sparsetable[i][j]=min(sparsetable[i][j-1],sparsetable[i+(1<<(j-1))][j-1]);
        }
    }
}

ll query(int l, int r)
{

    int len = r-l+1;
    int k = log2(len);

    return min(sparsetable[l][k],sparsetable[l+len-(1<<k)][k]);

}

void init()
{

    for(int i=0; i<MAXN; i++)
    {
        for(int j=0; j<logk; j++)
            arr[i][j]=0;
    }

}

int main()
{

    int t,tc=0;
    cin>>t;
    while(t--)
    {
        init();
        ll n,q;
        cin>>n>>q;
        for(ll i=0; i<n; i++)
            cin>>arr[i];
        sparse(n);
        ll l,r;
        cout<<"Case "<<++tc<<":\n";
        while(q--)
        {
            cin>>l>>r;
            cout<<query(l-1,r-1)<<'\n';
        }
    }


}
