class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int numssize = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)
                continue;
            nums[numssize++] = nums[i];
        }
        return numssize;
    }
};
    