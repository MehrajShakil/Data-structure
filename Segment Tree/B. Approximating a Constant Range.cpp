///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.


///   Author : Md Mehraj Hossain
///   Tag : Two pointers , indexing.

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

const ll MAXN=2e5;
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
/// 0 base index  lc = 2*id+1 rc = 2*id+2;

ll T[4*MAXN][2], arr[MAXN] , n;

void build(ll id, ll l, ll r)
{

    if(l==r)
    {
        T[id][0]=T[id][1]=arr[l];
        return;
    }
    ll mid = (l+r)/2;
    ll lc = id*2+1;
    ll rc = lc+1;
    build( lc, l, mid );
    build( rc, mid+1, r );

    T[id][0] = min(T[lc][0],T[rc][0]);
    T[id][1] = max(T[lc][1],T[rc][1]);
}

ll query( ll id, ll ql, ll qr,ll l,ll r, ll sign )
{
    if(ql>r or qr<l)
    {
        if(sign)
            return 0;
        else
            return MAXN;
    }

    if(ql<=l and qr>=r)
    {
        return T[id][sign];
    }

    ll mid = (l+r)/2;
    ll lc = 2*id+1;
    ll rc = lc+1;

    if(!sign)
        return min(query(lc,ql,qr,l,mid,sign),query(rc,ql,qr,mid+1,r,sign));
    else
        return max(query(lc,ql,qr,l,mid,sign),query(rc,ql,qr,mid+1,r,sign));
}


////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    ///MOHAMMAD

    ll  sz = 0;
    cin >> n;
    for(ll i = 0; i<n; i++)
    {
        cin >>arr[i];
    }

    build( 0LL , 0LL , n-1 );

   ll l = 0;
   ll r = 0;
   while(r<n){
        ll mn = query( 0 , l , r , 0 , n-1 , 0 );
        ll mx = query( 0 , l , r , 0 , n-1 , 1 );

        if((mx-mn)>1){
                l++;
        }
        else{
                sz = max( sz , r-l+1 );
                r++;
        }
   }
    cout << sz << '\n';
}

/*

  Alhamdulillah
*/

