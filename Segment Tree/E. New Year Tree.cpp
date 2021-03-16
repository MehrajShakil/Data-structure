///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

///   Every soul shall taste death.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>



///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MUHAMMAD        ios::sync_with_stdio(0);cin.tie(0);
#define all(x)          (x).begin(), (x).end()
#define AE              cout << fixed << setprecision(10);
#define ld              double


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long;
const ll MOD = 1e9 + 7;


typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//***********************************************  The END **********************************************************************************************************************************

const ll N = 4e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const int K = 1e3 + 1;

/// Global...

int dis[N] , en[N] , tim = 0 , color[N] , ct[N];
ll tr[N<<2] , lazy[N<<2];

vector < int > e[N];


/// make the subtree as a segment or range.
void dfs ( int node , int par = 0 ){
    dis[node] = ++tim;
    ct[tim] = node; /// who contain the time.
    for ( auto child : e[node] ){
        if ( child != par ) {
            dfs ( child , node );
        }
    }
    en[node] = tim;
}

/// segment tree with lazy.

ll combine ( ll bame , ll dane ){ /// 1. merge left and right.
   return (bame|dane);
}

void propagate ( int node , int l , int r ){ /// 2. Push lazy down and merge lazy
    if ( !lazy[node] ) return;
    tr[node] = (1LL<<lazy[node]);
    if ( l!=r ){
      lazy[node*2] = lazy[node];
      lazy[node*2+1] = lazy[node];
    }
    lazy[node] = 0;
}

void build ( int node , int l , int r ){
    if ( l == r ){   /// 3. initialize.
        tr[node] = (1LL<<color[ct[l]]);
        lazy[node] = 0;
        return;
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc+1;

    build ( lc , l , mid );
    build ( rc , mid + 1 , r );
    tr[node] = (tr[lc]|tr[rc]);
    lazy[node] = 0;
}

void update ( int node , int l , int r , int ql , int qr , int value ){

    propagate ( node , l , r );
    if ( l > qr or r < ql ) return;
    if ( l>=ql and r<=qr ){
        lazy[node] = value;  /// 4. Merge lazy.
        propagate ( node , l , r );
        return;
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc+1;

    update ( lc , l , mid , ql , qr , value );
    update ( rc , mid + 1 , r , ql , qr , value );

    tr[node] = (tr[lc]|tr[rc]);
}

ll query ( int node , int l , int r , int ql , int qr ){

    propagate ( node , l , r );
    if ( l > qr or r < ql ) return 0; /// 5. Proper null value.
    if ( l>=ql and r<=qr ){
        return tr[node];
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc+1;

    return combine ( query ( lc , l , mid , ql , qr ) , query ( rc , mid + 1 , r , ql , qr ));
}



void solve ( int tc ){

   int node , q;
   cin >> node >> q;

   for ( int i = 1 ; i <= node ; ++i ) cin >> color[i];

   for ( int i = 1 ; i < node ; ++i ){
    int u  , v;
    cin >> u >> v;
    e[u].push_back ( v );
    e[v].push_back ( u );
   }

   dfs ( 1 );
  // dbg ( tim );
   build ( 1 , 1 , tim );

   for ( int i = 1 ; i <= q ; ++i ) {
    int task;
    cin >> task;
    if ( task ^ 1 ){ /// query
        ll u;
        cin >> u;
        ll res = query ( 1 , 1 , tim , dis[u] , en[u] );
        cout << __builtin_popcountll ( res ) << "\n";
    }
    else{ /// update.
       int u , c;
       cin >> u >> c;
       update ( 1 , 1 , tim , dis[u] , en[u] , c );
    }
   }






   return;
}

int main()
{
    MUHAMMAD

   /// AE;
    /*
    #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int t = 1 , tc = 0;

   // cin >> t;

    while ( t-- ){
       solve( ++tc );
    }
}


/*


Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
