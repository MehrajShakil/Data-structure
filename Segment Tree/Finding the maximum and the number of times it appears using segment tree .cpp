
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
const ll MAXN = 10000000;
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
3
1 4 1
2
1 1
1 2
*/
/////////////////////////////////////////////////////////////////////////////
ii Tree[4*MAXN];

ii combine(ii a, ii b)
{
    if(a.first>b.first)
        return a;
    else if(a.first<b.first)
        return b;
    return {a.first,a.second+b.second};
}

void build(ll arr[], ll v, ll tl, ll tr)
{

    if(tl==tr)
    {

        Tree[v]= {arr[tl],1LL};
        //cout<<v<<" "<<Tree[v]<<ses;
    }
    else
    {
        ll tmid = (tl+tr)/2;
        build(arr,v*2,tl,tmid);
        build(arr,v*2+1,tmid+1,tr);
        Tree[v]=combine(Tree[v*2],Tree[v*2+1]);
    }
}

ii query(ll arr[], ll v, ll tl, ll tr, ll ql, ll qr)
{
    if(ql>tr or qr<tl)
    {
        return {-M,0};
    }
    else if(tl>=ql and tr<=qr)
    {
        return Tree[v];
    }

    ll tmid=(tl+tr)/2;
    ii mnl = query(arr,v*2,tl,tmid,ql,qr);
    ii mnr = query(arr,v*2+1,tmid+1,tr,ql,qr);
    return combine(mnl,mnr);
}

void update(ll arr[],ll v, ll tl, ll tr, ll pos,ll NewValue)
{
    if(pos>tr or pos<tl)
        return;
    if(pos<=tl and pos >=tr)
    {
        Tree[v]= {NewValue,1};
        return;
    }
    ll tmid  = (tr+tl)/2;
    update(arr,v*2,tl,tmid,pos,NewValue);
    update(arr,v*2+1,tmid+1,tr,pos,NewValue);
    Tree[v]=combine(Tree[v*2],Tree[v*2+1]);
}


////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    //ios
    ll n,q;
    cin >> n;
    ll arr[n+1];
    for(ll i=1; i<=n; i++)
        cin>>arr[i];
    build(arr,1LL,1LL,n);
    cin>>q;
    while(q--)
    {
        ll l,r,mark;
        cin >>mark >> l >> r;
        if(mark==1)
        {
            ii pp = query(arr,1LL,1LL,n,l,r);
            cout<<pp.first<<" "<<pp.second<<ses;
        }
        else
        {
            update(arr,1LL,1LL,n,l,r);
        }
    }
}
/*

     Alhamdulillah
*/

