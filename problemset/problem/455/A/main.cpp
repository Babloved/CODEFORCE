#include<iostream>
using namespace std;
long long a[100001],i,n,k;
int main(){
    cin>>n;for(;i<n;i++)cin>>k,a[k]+=k;
    for(i=2;i<=100000;i++)
        a[i]=max(a[i-1],a[i]+a[i-2]);
    cout<<a[100000];
}