///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.

///   EID MUBARAK

///   Author : Md Mehraj Hossain

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull      unsigned long long
#define ll       long long
#define MOHAMMAD ios::sync_with_stdio(0);cin.tie(0);
#define ses      "\n"
#define all(x)   (x).begin(), (x).end()
#define INF      ((int)2e18)
#define pi       2*acos(0.0)
#define AE       cout << fixed << setprecision(8);

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e7;
const ll MOD = 998244353 ;

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
ll n, l, r, len ,q;

vector<ll> arr(MAXN),block;

void pre_processing()
{
    len = sqrt(n)+1; /// here 1 is for precision part.
    block.resize(len+1 , MAXN); /// every block contain len number of element . then len*len about n.

    for( ll i=0 ; i<n ; ++i )
    {
        block[i/len]=min(arr[i],block[i/len]);
    }
}

int query( ll l, ll r )
{
    ll mn = 1e18;
    ll cl = l/len; /// cl contain the block where is l
    ll cr = r/len; /// cr contain the block where is r

    if( cl==cr ) /// if l and r are in same block then we apply brute force.
    {
        for( ll i = l ; i<=r ; ++i)
        {
            mn = min(mn,arr[i]);
        }
    }
    else
    {
        for( ll i = l ; i<(cl+1)*len ; ++i )  /// here we traverse l to end of the block l
        {
            mn = min(mn,arr[i]);
        }
        for( ll i = cl+1 ; i<cr ; ++i )  /// here we traverse every block from cl < x < cr
        {
            mn = min(mn ,block[i]);
        }
        for( ll i = cr*len ; i<=r ; ++i ) /// here i traverse cr to r.
        {
            mn = min(mn,arr[i]);
        }
    }

    return mn;
}


////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
     MOHAMMAD
    /// 0-based index.
    cin >> n;
    for( ll i=0 ; i<n ; ++i )
        cin >> arr[i];

    pre_processing();

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << query( l, r ) << '\n';
    }
}

/*

  Alhamdulillah
*/

