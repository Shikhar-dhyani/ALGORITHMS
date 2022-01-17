// What is the optimal block size to be skipped? 
// In the worst case, we have to do n/m jumps and if the last checked value is greater than the element to be searched for,
// we perform m-1 comparisons more for linear search. Therefore the total number of comparisons in the worst case will be ((n/m) + m-1). 
// The value of the function ((n/m) + m-1) will be minimum when m = √n. Therefore, the best step size is m = √n.



#include <bits/stdc++.h>
using namespace std;
void JUMPSEARCH(int arr[], int x, int n)
{
    int block = sqrt(n);
    int pre = 0;
    while (arr[min(block, n)-1] < x)
    {
        pre = block;
        block += sqrt(n);
        if (pre >= n)
        {
            cout << "Element not found 1" << endl;
            return;
        }
    }
    while (arr[pre] < x)
    {
        pre++;
        if (pre == min(block, n))
        {
            cout << "Element not found 2" << endl;
            return;
        }
    }
    if (arr[pre] == x)
    {
        cout << "ELEMENT IS AT " << pre << " index" << endl;
        return;
    }
    else
    {
        cout << "Element not found 3" << endl;
        return;
    }
}
int main(){
//    int arr[]={1,2,3,5,58,78,98,101};
//    int n=sizeof(arr)/sizeof(arr[0]);
//    int x=58;
   int n,x;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   cin >> arr[i];
   cin>> x;
    JUMPSEARCH(arr,x,n);
}
