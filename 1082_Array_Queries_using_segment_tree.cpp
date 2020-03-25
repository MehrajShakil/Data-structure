// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

#define MAXN 100001

using ll = long long;

ll tree[4*MAXN]; //Size of tree.
ll mn=100000000;
// build the tree .
void build(ll arr[],ll v,ll tl,ll tr)           //v = index of the current vartex.
{

    if(tl==tr)
    {
        tree[v]=min(arr[tl],mn);
    }
    else
    {
        ll tmid = ((tr+tl)/2);
        build(arr,v*2,tl,tmid);             // 1'based array.
        build(arr,v*2+1,tmid+1,tr);
        tree[v]=min(mn,min(tree[v*2],tree[v*2+1]));
    }

}

//query id here.
long long query(ll arr[],ll v,ll tl,ll tr,ll ql,ll qr)
{

    if(ql>tr or qr<tl)
    {
        return MAXN; // Case 1 : out of the range.
    }
    if(tl>=ql and tr<=qr)
    {
        return tree[v]; // Case 2 :  totally intersect the range.
    }
    // Case 3 : partial intersect.

    ll tmid  = (tr+tl)/2;
    ll suml = query(arr,v*2,tl,tmid,ql,qr);
    ll sumr = query(arr,v*2+1,tmid+1,tr,ql,qr);
    return min(suml,sumr);
}
//update is here.
/*
This problem don't need the update function.
void update(ll arr[],ll v, ll tl, ll tr, ll pos,ll NewValue)
{
    if(pos>tr or pos<tl)
        return;
    if(pos<=tl and pos >=tr)
    {
        tree[v]=NewValue;
        return;
    }
    ll tmid  = (tr+tl)/2;
    update(arr,v*2,tl,tmid,pos,NewValue);
    update(arr,v*2+1,tmid+1,tr,pos,NewValue);
    tree[v]=tree[v*2]+tree[v*2+1];
}
*/
int main()
{
    ll testcase;
    scanf("%lld",&testcase);
    for(ll i=1; i<=testcase; i++)
    {
        ll  n,q;
        scanf("%lld%lld",&n,&q);
        ll arr[n+1];
        for(ll i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        build(arr,1,1,n);
        printf("Case %lld:\n",i);
        while(q--)
        {
            ll l,r;
            scanf("%lld%lld",&l,&r);
            ll ans = query(arr,1,1,n,l,r);
            printf("%lld\n",ans);
        }
    }
}
