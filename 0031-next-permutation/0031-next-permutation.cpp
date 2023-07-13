class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int size = nums.size();
        int idx = size-1;
        while(idx>0){
            if(nums[idx-1]< nums[idx]){
                int j = idx+1;
                while(j<size && nums[idx-1]<nums[j])
                    j++;
                
            swap(nums[idx-1], nums[j-1]);
                break;
                
            }
            --idx;
            
        }
        reverse(nums.begin()+idx, nums.end());
        return;
        
        
    }
};