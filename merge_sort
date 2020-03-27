// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void mergesort(ll arr[],ll l , ll r);
void merge(ll arr[], ll l,ll mid , ll r);



int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(ll i=0;i<n;i++){
                cout<<arr[i]<<" ";
    }

}
void mergesort(ll arr[], ll l , ll r){

    if(l<r){
          ll mid = l+(r-l)/2; // For large.
          mergesort(arr,l,mid);
          mergesort(arr,mid+1,r);
          merge(arr,l,mid,r);
    }

}
void merge(ll arr[], ll l,ll mid , ll r){
      ll i,j,k;
      ll n1 = mid-l+1; //size for left array.
      ll n2 = r-mid;    // size for right array.
      //Create temp array.
      ll L[n1];
      ll R[n2];
      for(ll i=0;i<n1;i++){
                L[i]=arr[l+i];
      }
      for(ll j=0;j<n2;j++){
                R[j]=arr[mid +1+j];
      }
      i=0,j=0,k=l;
      while(i<n1 and j<n2){
                if(L[i]<=R[j]){
                       arr[k]=L[i];
                       i++;
                }
                else {
                       arr[k]=R[j];
                       j++;
                }
                k++;
      }
      while(i<n1){
                arr[k]=L[i];
                i++,k++;
      }
      while(j<n2){
                arr[k]=R[j];
                j++,k++;
      }
}
