#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN=(int)1e5+1;
const ll logk = 15;


ll sparsetable[MAXN][logk];
ll arr[MAXN];

void sparse(ll n)
{

    for(ll i=0; i<n; i++)
    {
        sparsetable[i][0]=arr[i];
    }

    for(ll j=1; (1<<j)<=n ; j++)
    {
        for(ll i=0; i+(1<<j)-1<n; i++)
        {
            sparsetable[i][j]=min(sparsetable[i][j-1],sparsetable[i+(1<<(j-1))][j-1]);
        }
    }
}

ll query(ll l, ll r)
{

    ll len = r-l+1;
    ll k = log2(len);

    return min(sparsetable[l][k],sparsetable[l+len-(1<<k)][k]);

}

int main()
{

    ll n,q,l,r;
    cin>>n;
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    sparse(n);

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
}
