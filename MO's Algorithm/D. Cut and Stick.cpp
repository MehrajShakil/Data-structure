///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


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
#define f               first
#define ss              second


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long;
const ll MOD =  1e9+7;


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

const int N = 1e6 + 1;
const ll INF = 1e18;
const ld EPS   = 1e-6;
const ll limit = (1LL<<32) - 1;
const ll K = 1e6 + 1;

/// --------------------------------------------------------------

/// 0-based index.

int k , ans[N] , arr[N] , sum;
int cnt[N] , oc[N];

struct Query{
    int ind , L , R;
    bool operator < ( const Query &other ) const {
       int block_own = L/k;
       int block_other = other.L/k;
       if ( block_own == block_other )
            return R < other.R;
       return block_own < block_other;
    }
}query[N];

void Add ( int index ){
     int &w = cnt[arr[index]]; /// occurrence previous.
     oc[w]--; /// previous would be decreased from main.
     w++;    ///  increase arr[index] occurrence for current.
     oc[w]++; /// increase this occurrence times in main.
     if ( w > sum ) sum++;
}
void Remove ( int index ){
     int &w = cnt[arr[index]];
     oc[w]--;
     w--;
     oc[w]++;
     if ( oc[sum] == 0 ) sum--;
}

void Solution ( int tc ){

  int n , q;
  cin >> n >> q;

  k = sqrt ( n );

  for ( int i = 0 ; i < n ; ++i ) cin >> arr[i];



  for ( int i = 0 ; i < q ; ++i ) {
    int L , R;
    cin >> L >> R;
    query[i] = { i , L - 1 , R - 1 };
  }

  sort ( query , query + q );
  int L = 0 , R = -1;
  for ( int i = 0 ; i < q ; ++i ) {
     while ( R < query[i].R ) Add (++R);
     while ( L < query[i].L ) Remove (L++);
     while ( R > query[i].R ) Remove ( R-- );
     while ( L > query[i].L ) Add ( --L );
     /// dbg ( query[i].L , query[i].R , query[i].ind , sum );
     int res;
     int len = query[i].R - query[i].L + 1;
      
     if ( (len+1)/2 >= sum ) res = 1; /// here sum is the maximum occurrence of the given range.
     else {
        int rem = len - sum;
        rem+=(rem+1);
        res = (len-rem+1);
     }
     ans[query[i].ind] = res;
  }

  for ( int i = 0 ; i < q ; ++i ) cout << ans[i] << "\n";

  return;
}

int main()
{
    /// MUHAMMAD

    /// AE;\

    /*
    #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int testcase = 1 , tc = 0;



    /// cin >> testcase;

    for ( int i = 1 ; i <= testcase ; ++i ){

       Solution( ++tc );
    }


    return 0;
}


/*


Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
