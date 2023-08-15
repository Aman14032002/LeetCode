//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    unordered_set<int>numSet;
    for( int i=0; i<size; i++){
         int PN1 = arr[i]-n;
         int PN2 = arr[i]+n;
         
         if(numSet.find(PN1)!= numSet.end()||numSet.find(PN2) != numSet.end()){
             return true;
             
         }
         numSet.insert(arr[i]);
    }
     return false;
}