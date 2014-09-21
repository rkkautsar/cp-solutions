#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;
 
template<class T> void heapify(T& arr,int i,int n){
    int l=2*i+1,r=2*i+2,imax=i;
    if(l<n && arr[l]>arr[i]) imax=l;
    if(r<n && arr[r]>arr[imax]) imax=r;
    if(imax!=i){
        swap(arr[i],arr[imax]);
        heapify(arr,imax,n);
    }
}
 
template<class T> void build_heap(T& arr,int n){
    for(int i=n/2;i>=0;--i) heapify(arr,i,n);
}
 
template<class T> void heapsort(T& arr,int n){
    build_heap(arr,n);
    for(int i=n-1;i>0;--i){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}
 
template<class T>
void merge(T& arr,int l,int m,int r){
    int idx=0,i=l,j=m+1;
    int tmp[r-l+1];
    while(i<=m && j<=r){
        if(arr[i]<arr[j])tmp[idx++]=arr[i++];
        else tmp[idx++]=arr[j++];
    }
    while(i<=m)tmp[idx++]=arr[i++];
    while(j<=r)tmp[idx++]=arr[j++];
    for(int i=l,j=0;i<=r;++i,++j)arr[i]=tmp[j];
 
}
 
template<class T>
void mergesort(T& arr,int l,int r){
    if(r==l)return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
 
template<class T> int partition(T& arr,int l,int r){
    int p=(l+r)/2; //middle pivot
    swap(arr[p],arr[r]);
    int store=l;
    for(int i=l;i<r;++i)
        if(arr[i]<arr[r]){
            swap(arr[i],arr[store]);
            ++store;
        }
    swap(arr[r],arr[store]);
    return store;
}
 
template<class T> void quicksort(T& arr,int l,int r){
    if(l>=r)return;
    int p=partition(arr,l,r);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
}
 
int bucket[MAX+1]; //initially 0
 
template<class T> void countsort(T& arr,int n){
    for(int i=0;i<n;++i)
        ++bucket[arr[i]];
    int idx=0;
    for(int i=0;i<=MAX;++i)
        while(bucket[i]--)arr[idx++]=i;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    //heapsort(v,n);
    //sort(v.begin(),v.end());
    //mergesort(v,0,n-1);
    //quicksort(v,0,n-1);
    //__insertion_sort(v.begin(),v.end());
    //countsort(v,n);
    make_heap(v.begin(),v.end());sort_heap(v.begin(),v.end());
    for(int i=0;i<n;++i)cout<<v[i]<<'\n';
    
    return 0;
}