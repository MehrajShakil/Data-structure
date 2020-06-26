///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.



#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

///  order_of_key return number of elements less than x.
///  find_by_order return index.

using namespace std;
using namespace __gnu_pbds;


#define MOHAMMAD  ios::sync_with_stdio(0);cin.tie(0);
#define all(x)    (x).begin(), (x).end()
#define AE        cout << fixed << setprecision(10);

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

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
//***********************************************  The END **********************************************************************************************************************************
const int N = 1e5;
int n , tr[4*N] , a[N];

void build ( int node , int l , int r ){

   if ( l==r ) {
   tr[node] = a[l];
   return;
   }

   int mid = (l+r)>>1;

   int lc = node*2;
   int rc = node*2+1;

   build ( lc , l , mid );
   build ( rc , mid + 1 , r );

   tr[node] = min ( tr[lc] , tr[rc] );
}

void update ( int node , int l , int r , int index , int Newvalue ){
   /// dbg ( l , r );
   if ( l==r ){
       tr[node] = Newvalue;
       a[index] = Newvalue;
       return;
   }

   int mid = (l+r) >> 1;

   int lc = node*2;
   int rc = node*2 + 1;

   if ( index<=mid) update( lc , l , mid , index , Newvalue ); /// if index position less than or equal mid
   else update ( rc , mid + 1 , r , index , Newvalue );

   tr[node] = min ( tr[lc] , tr[rc] );
}

int query ( int node , int l , int r , int ql , int qr ){

   if ( l>qr or r<ql ) return INT_MAX;

   if ( l>=ql and r<=qr ) return tr[node];

   int mid = (l+r) >> 1;
   int lc = node * 2;
   int rc = node * 2 + 1;

   int lg = query ( lc, l , mid , ql , qr );
   int rg = query ( rc , mid + 1 , r , ql , qr );

   return min ( lg , rg );

}



int main()
{

  /// MOHAMMAD

  cin >> n;

  for ( int i = 1 ; i<=n ; ++i ) cin >> a[i];

  build ( 1 , 1 , n );

  int q , mark , l , r;

  cin >> q;
  while ( q-- ){
    cin >> mark >> l >> r;
    if ( mark ) cout << query ( 1 , 1 , n , l , r ) << "\n";
    else update ( 1 , 1 , n , l , r );
  }




}

/*





  Alhamdulillah
*/

