// algo to find Kth smallestelement in linear time complexity
#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r)
{
    int x=a[r];
    int i=l;
    for(int j=l;j<r-1;j++)
    {
        if(a[j]<x)
        i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}
int randompartition(int a[],int l,int r)
{
    int n=r-l+1;
    int pivot=rand()%n;
    swap(a[l+pivot],a[r]);
    return partition(a,l,r);
    
     
}

int kminimum(int a[],int l,int r,int k)
{
    if(k>0 and k<r-l+1)
    {
        int pos=randompartition(a,l,r);
        if(pos-l==k-1)
        return a[pos];
        if(pos-l>k-1)
        return kminimum(a,l,pos-1,k);
        
        return kminimum(a,pos+1,r,k-pos+l-1);
        
    }
    return INT_MAX;
}

int main()
{
    int a[]={30,7,2,8,5,9,6,17,12,29};
    int n=10;
    int k;
    cin>>k;

   cout<<k<<"smallest number is==>" <<kminimum(a,0,n-1,k);
    
}