//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
   // vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
//void dfs (vector<int> adj[],unordered_map<int,bool> &visited,vector<int> & ans, int node){
            
           void dfs(int node,int V, vector<int> adj[],vector<int>&ans,vector<bool>&vis){
        vis[node] = true;
        ans.push_back(node);
        for(auto i :adj[node]){
            if(!vis[i]) dfs(i,node,adj,ans,vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V,false);
 
        for(int i = 0; i < V; ++i) if(!vis[i]) dfs(i,V,adj,ans,vis);
            
        
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends