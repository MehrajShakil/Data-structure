// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll     long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses    "\n"
#define all(x) (x).begin(), (x).end()
//#define INF   ((int)2e18)
#define ii pair<ll, ll>

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e7;
const ll MOD = 1e9+7;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // when M is prime;
}

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/// Fast read.
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//***********************************************  The END **********************************************************************************************************************************

/////////////////////////////////////////////////////////////////////////////

vector<ll> arr,node;

void build(ll id, ll l, ll r)
{

    if(r-l<2)
    {
        node[id]=arr[l];
        return;
    }
    ll mid = (l+r)/2;

    build(id*2, l, mid);
    build(id*2+1,mid,r);
    node[id]=__gcd(node[id*2],node[id*2+1]);
}

ll query(ll x, ll y, ll id, ll l, ll r)
{

    if(x>=r or y<=l)
        return 0;
    if(x<=l and r<=y)
        return node[id];
    ll mid=(l+r)/2;

    return __gcd(query(x,y,id*2,l,mid),query(x,y,id*2+1,mid,r));
}



////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    //ios
    ll t;
    read(t);
    while(t--)
    {
        arr.clear();
        node.clear();


        ll n,q;
        cin >> n >> q;
        arr.resize(n);
        node.resize(4*n);
        for( ll i=0 ; i<n; i++)
            cin >> arr[i];
        build(1LL, 0LL, n);
        while(q--)
        {
            ll l,r;
            cin >> l >> r;

            if(l-1==0)
            {
                cout << query(r,n,1LL,0LL,n);
            }
            else if(r==n)
            {
                cout << query(0,l-1,1LL,0LL,n);
            }
            else
                cout << __gcd(query(0,l-1,1LL,0LL,n),query(r,n,1LL,0LL,n));

            cout << '\n';
        }
    }
}




/*



  Alhamdulillah
*/

