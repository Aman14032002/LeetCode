class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         set<vector<int>> unique_combinations;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, {}, unique_combinations);
        return vector<vector<int>>(unique_combinations.begin(), unique_combinations.end());
    }
    
    void backtrack(vector<int>& candidates, int target, int start, int curr_sum, vector<int> curr_combination, set<vector<int>>& unique_combinations) {
        if (curr_sum == target) {
            unique_combinations.insert(curr_combination);
        }
        else if (curr_sum < target) {
            for (int i = start; i < candidates.size(); i++) {
                if (i != start && candidates[i] == candidates[i-1]) {
                    continue; // skip duplicates
                }
                curr_combination.push_back(candidates[i]);
                backtrack(candidates, target, i+1, curr_sum+candidates[i], curr_combination, unique_combinations);
                curr_combination.pop_back(); // backtrack
            }
        }
    
    }
};