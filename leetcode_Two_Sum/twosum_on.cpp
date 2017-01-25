class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        map<int, int> m;
        if (nums.size() < 2)
            return result;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) 
        {
            if ((it = m.find(target - nums[i])) != m.end())
            {
                if (i == it->second) continue;
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }
};