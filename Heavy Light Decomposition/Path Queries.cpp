#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+10;

vector<ll> e[N],parent,depth,heavy,head,pos;
ll cur_pos = 1;
ll BIT[N];
ll arr[N];

/// select the specialChild.
int dfs( int node , int par = -1 ){
    int Size = 1;
    int max_c_size = 0;
    parent[node] = par;
    for ( auto child : e[node] ) {
        if(par==child) continue;
        depth[child] = depth[node] + 1;
        int isSpecialChild = dfs(child,node);
        Size+=isSpecialChild;
        if(isSpecialChild>max_c_size){
            max_c_size = isSpecialChild;
            heavy[node] = child; /// This one is a special child. because it's subtree size is greater than others.
        }
     }
     return Size;
}


/// divide into chain.
void decompose(int node, int h){
    head[node] = h;
    pos[node] = cur_pos++;
    if(heavy[node]!=-1) {
        decompose(heavy[node],h);
    }
    for(auto child:e[node]){
        if(child!=parent[node] and child!=heavy[node]){
           decompose(child,child);
        }
    }
}



/// update binary indexed query.
void update ( ll idx , ll val ) {
    while ( idx<N ){
       BIT[idx]+=val;
       idx+=(idx&-idx);
    }
}

/// Binary indexed query.
ll query ( ll idx ){
   ll sum = 0;
   while ( idx > 0 ){
       sum+=BIT[idx];
       idx-=(idx&-idx);
   }
   return sum;
}



/// heavy light query.
ll hldQuery(int u, int v){
   ll res = 0;
   for(; head[u]!=head[v]; v = parent[head[v]]){
       if(depth[head[u]]>depth[head[v]]){
        swap(u,v);
       }
       ll cur_heavy_path_sum = query(pos[v]) - query(pos[head[v]]-1);
       res+=cur_heavy_path_sum;
   }
   if(depth[u]>depth[v]){
    swap(u,v);
   }
   ll last_heavy_path_sum = query(pos[v]) - query(pos[u]-1);
   res+=last_heavy_path_sum;
   return res;
}


/// Initialize all of them.
void init(int node){
  for(int i = 1 ; i<=node; ++i ) {
    e[i].clear();
  }

  parent.resize(node+1);
  depth.resize(node+1);
  heavy.resize(node+1,-1);
  head.resize(node+1);
  pos.resize(node+1);
  cur_pos = 1;
}





int main(){

    int node, m,u,v;
    cin >> node >> m;

    for ( int i = 1 ; i<=node ; ++i ) cin >> arr[i];

    init(node);

    for(int i = 1; i<node; ++i){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1);
    decompose(1,1);

    for ( int i = 1 ; i<=node ; ++i ) {
        update(pos[i],arr[i]); /// position of each node.
    }

    for ( int i = 1 ; i<=m ; ++i ) {
        ll task,u,x;
        cin >> task;
        if(task==1){
            cin >> u >> x;
            update(pos[u],-arr[u]);
            arr[u] = x;
            update(pos[u],arr[u]);
        }
        else{
            cin >> u;
            cout << hldQuery(1,u) << "\n";
        }
    }
}
