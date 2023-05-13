class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> unique_permutations;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, unique_permutations);
        return vector<vector<int>>(unique_permutations.begin(), unique_permutations.end());
    }
    
    void backtrack(vector<int>& nums, int start, set<vector<int>>& unique_permutations) {
        if (start == nums.size()) {
            unique_permutations.insert(nums);
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) {
                continue; // skip duplicates
            }
            swap(nums[i], nums[start]);
            backtrack(nums, start+1, unique_permutations);
            swap(nums[i], nums[start]);
        }
        
    }
};