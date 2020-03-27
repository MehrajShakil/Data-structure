
//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll    long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses   "\n"
#define INF   ((int)2e18)
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

typedef tree< ii, null_type, less<ii>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
      ordered_set s;
      int n;
      cin >> n;
      ll a[n],b[n];
      for(ll i=0;i<n;i++)cin>>a[i];
      for(ll i=0;i<n;i++)cin>>b[i];
      for(int i = 0; i < n; i++) {
          s.insert(ii(b[i] - a[i], i));

      }
      ll ans = 0;
      for(int i = 0; i < n; i++) {
          s.erase(ii(b[i] - a[i], i));
          ll g =s.order_of_key(ii(a[i] - b[i], -INF));  // order_of_key which return number of element less than x..o(logn)
          ans += g;
      }
      cout << ans << endl;
}
// using policy based Data structure.



//Alhamdulillah
