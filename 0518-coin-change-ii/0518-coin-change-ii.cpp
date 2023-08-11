class Solution {
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case: 0 rupaye banane ke liye 1 tarike se bana sakte hain (kuch coin na lena)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            // Coins[i-1] ko include karke + Coins[i-1] ko exclude karke
            dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
        }
    }

    return dp[n][amount];

    }
};