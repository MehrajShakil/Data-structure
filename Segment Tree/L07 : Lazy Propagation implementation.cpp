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
ll tr[4*N] , Lazy[4*N] , a[N] , n;

void build ( ll node , ll l , ll r ){
    if ( l==r ){
        tr[node] = a[l];
        Lazy[node] = 0;
        return;
    }

    ll mid = (l+r)>>1;

    ll lc = node * 2;
    ll rc = node * 2 + 1;

    build ( lc , l , mid );
    build ( rc , mid + 1 , r );

    tr[node] = tr[lc] + tr[rc];
    Lazy[node] = 0;
}


ll query ( ll node , ll l , ll r , ll ql , ll qr , ll carry ){

        if ( l>qr or r<ql ) return 0;
        if( l>=ql and r<=qr ) return tr[node] + carry*(r-l+1);

        ll mid = (l+r)>>1;
        ll lc = node * 2;
        ll rc = node * 2 + 1;
        ll carryValue = carry + Lazy[node];
        ll lg = query ( lc , l , mid , ql , qr , carryValue );
        ll rg = query ( rc , mid + 1 , r , ql , qr , carryValue );

        return lg + rg;
}

void update ( ll node , ll l , ll r , ll ql , ll qr , ll Newvalue ){

     if ( l>qr or r<ql ) return;
     if ( l>=ql and r<=qr ) {
                tr[node]+= (r-l+1)*Newvalue;
                Lazy[node]+=Newvalue;
                return;
     }

     ll mid = (l+r) >> 1;

     ll lc = node * 2;
     ll rc = node * 2 + 1;

     update ( lc , l , mid , ql , qr , Newvalue );
     update ( rc , mid + 1 , r , ql , qr , Newvalue );

     tr[node] = tr[lc] + tr[rc] + (r-l+1)*Lazy[node];
}




int main()
{

  /// MOHAMMAD
  cin >> n;
  for ( ll i = 1 ; i<=n ; ++i ) cin >> a[i];
  build ( 1LL , 1LL , n );

  ll q , option , l , r , Newvalue;
  cin >> q;
  while ( q-- ){
        cin >> option >> l >> r;
        if(!option){
           cout << query ( 1LL , 1LL , n , l , r , 0) << "\n";
        }
        else{
           cin >> Newvalue;
           update ( 1LL , 1LL , n , l , r , Newvalue );
        }
  }

}

/*





  Alhamdulillah
*/

