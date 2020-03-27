
//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Allah amader korona virus theke rokkha korun.Amin.

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

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{

    ll n,b;
    cin>>n>>b;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    vector<pair<ll,ll> > v;
    ll prefix[b+1]= {0};
    ordered_multiset st;
    while(b--)
    {
        ll d,g;
        cin>>d>>g;
        v.push_back(make_pair(d,g));
    }
    sort(all(v));
    for(ll i=0; i<v.size(); i++)
    {
        prefix[i+1]=prefix[i]+v[i].second;
        st.insert({v[i].first,i});
    }
    for(ll i=0; i<n; i++)
    {
        ll g = st.order_of_key({arr[i]+1,-1});
        cout<<prefix[g]<<" ";
    }
}





//Alhamdulillah
