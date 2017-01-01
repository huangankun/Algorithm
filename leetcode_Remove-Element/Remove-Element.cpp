class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
            int startIndex = 0;
            int n = nums.size();
            for(int i=0;i<n;i++)
                if(val != nums[i])
                    nums[startIndex++]=nums[i];
            return startIndex;
    }
};