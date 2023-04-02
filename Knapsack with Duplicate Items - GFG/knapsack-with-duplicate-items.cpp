//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];

    int recursion(int W,int i,int n,int *wt,int *val)

    {

        if(i==n)    return 0;

        if(dp[i][W]!=-1) return dp[i][W];

        if(wt[i]>W)

            return dp[i][W]=recursion(W,i+1,n,wt,val);

        else

        {

            int ans1=val[i]+recursion(W-wt[i],i+1,n,wt,val);

            int ans2=val[i]+recursion(W-wt[i],i,n,wt,val);

            int ans3=recursion(W,i+1,n,wt,val);

            return dp[i][W]=max(ans2,ans3);

        }

    }

    int knapSack(int N, int W, int val[], int wt[])

    {

        for(int i=0;i<N;i++)

            for(int j=0;j<=W;j++)

                dp[i][j]=-1;

        return recursion(W,0,N,wt,val);

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends