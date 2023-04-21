class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;

//int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int N = group.size();
    vector<vector<int>> dp(minProfit+1, vector<int>(n+1));
    dp[0][0] = 1;
    for (int k = 0; k < N; ++k) {
        int p = profit[k], g = group[k];
        for (int i = minProfit; i >= 0; --i) {
            for (int j = n - g; j >= 0; --j) {
                dp[min(minProfit, i+p)][j+g] = (dp[min(minProfit, i+p)][j+g] + dp[i][j]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = (ans + dp[minProfit][i]) % MOD;
    }
    return ans;
}

    
};
