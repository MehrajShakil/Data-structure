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
using ll = long long;

const ll N = 1e5;
ll a[N] , n;

pair < ll , ll > tr[4*N];

   /// first for odd and second for even.

void build ( ll node , ll l , ll r ){

    if ( l==r ){
        if ( a[l]&1 ){
            tr[node].first = 1;
            tr[node].second = 0;
            /// tr[node] = { 1 , 0 } ;
        }
        else{
            tr[node].first = 0;
            tr[node].second = 1;
        }
        return;
    }

    ll mid = (l+r) >> 1LL;

    ll lc = node * 2;
    ll rc = node * 2 + 1;

    build ( lc , l , mid );
    build ( rc , mid + 1 , r );

    tr[node].first = tr[lc].first + tr[rc].first;
    tr[node].second = tr[lc].second + tr[rc].second;
}

void update ( ll node , ll l , ll r , ll index , ll Newvalue ){

    if ( l==r ){
        if ( Newvalue&1 ){
            tr[node] = { 1 , 0 };
            a[index] = Newvalue;
        }
        else{
            tr[node] = { 0 ,1 };
            a[index] = Newvalue;
        }
        return;
    }

    ll mid = (l+r) >> 1;

    ll lc = node * 2;
    ll rc = node * 2 + 1;

    if( index<=mid )  update ( lc , l , mid , index , Newvalue );
    else              update ( rc , mid + 1 , r , index , Newvalue );

    tr[node].first = tr[lc].first + tr[rc].first;
    tr[node].second = tr[lc].second + tr[rc].second;
}

ll query ( ll node , ll l , ll r , ll ql , ll qr , ll sign ){

          if ( l > qr or r<ql ) return 0;
          if ( l>=ql and r<=qr and !sign ) return tr[node].second;
          if ( l>=ql and r<=qr and sign ) return tr[node].first;

          ll mid = (l+r)>>1;

          ll lc = node * 2;
          ll rc = node * 2 + 1;

          ll lg = query ( lc , l , mid , ql , qr , sign );
          ll rg = query ( rc , mid + 1, r , ql , qr , sign );
          return lg + rg;
}

int main()
{

  MOHAMMAD

  cin >> n;

  for ( ll i = 1 ; i<=n ; ++i ){
      cin >> a[i];
  }

  build ( 1LL , 1LL , n );

  ll q , option , l , r , index , Newvalue;
  cin >> q;
  while ( q-- ){
        cin >> option >> l >> r;
        if( !option ){
           index = l;
           Newvalue = r;
           if ( Newvalue%2==a[index]%2) continue;
           update ( 1LL , 1LL , n , index , Newvalue );
        }
        else if ( option == 1 ){
                cout << query ( 1LL , 1LL , n , l , r , 0 ) << "\n";
        }
        else{
                cout << query ( 1LL , 1LL , n , l , r , 1 ) << "\n";
        }
  }

}

/*





  Alhamdulillah
*/

