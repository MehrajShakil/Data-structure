
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

// █▀█─█──█──█▀█─█─█
// █▄█─█──█──█▄█─█▄█
// █─█─█▄─█▄─█─█─█─█


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

const int N=1e6+5;
const ll M=1e18;
const ll MOD = 1000000007;

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
    return bigmod(a,M-2,M);   // when M is prime;}
}
typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

struct Edge
{
    int u, vv;
    bool operator<(Edge const& other)
    {
        return vv > other.vv;
    }
}; // eta joss jinis.krsukal er jnno and sort 1 out of 3 or more er jnno better


//***********************************************  The END **********************************************************************************************************************************
/*

*/
/////////////////////////////////////////////////////////////////////////////
vector<ll> s,arr,lazy;
ll n;

void upd(ll id, ll l,ll r, ll x)     /// increase all members in this interval by x.
{

    lazy[id]+=x;
    s[id]+=(r-l)*x;

}

void shift(ll id, ll l, ll r)     ///pass update info to the children
{

    ll mid = (l+r)/2;
    upd(id*2,l,mid,lazy[id]);
    upd(id*2+1,mid,r,lazy[id]);
    lazy[id]=0; /// passing is done.

}

void build(ll id=1LL, ll l=0LL, ll r=n)
{
    if(r-l<2)
    {
        s[id]=arr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid,r);
    s[id]=s[id*2]+s[id*2+1];
}

void increase(ll x, ll y,ll value, ll id=1LL, ll l=0LL, ll r=n)
{

    if(x>=r or y<=l)
        return ;
    if(x<=l and r<=y)
    {
        upd(id,l,r,value);
        return;
    }

    shift(id,l,r);
    ll mid = (l+r)/2;

    increase(x,y,value,id*2,l,mid);
    increase(x,y,value,id*2+1,mid,r);
    s[id]=s[id*2]+s[id*2+1];
}

ll sum(ll x, ll y, ll id=1LL, ll l=0LL, ll r=n)
{

    if(x>=r or y<=l)
        return 0;
    if(x<=l and r<=y)
        return s[id];
    shift(id,l,r);
    ll mid=(l+r)/2;

    return sum(x,y,id*2,l,mid)+sum(x,y,id*2+1,mid,r);

}


////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    //ios
    ll n,x,y;
    cin>>n;
    arr.resize(n+1);
    s.resize(4*n+1);
    lazy.resize(n*4+1);
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    build(1LL,0LL,n);
    ll q,value;
    cin>>q;
    while(q--)
    {
        ll mark, l,r;
        cin>>mark>>l>>r;
        if(mark==1)
        {
            cout<<sum(l-1,r,1LL,0LL,n)<<ses;
        }
        else
        {
            cin>>value;
            increase( l-1, r,value,  1LL,  0LL,  n);
        }
    }
}
/*


     Alhamdulillah
*/

