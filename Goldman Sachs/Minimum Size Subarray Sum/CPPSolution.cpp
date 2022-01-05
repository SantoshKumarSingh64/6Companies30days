class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sublen = INT_MAX, left = 0, i = 0, sum = nums[0], size = nums.size(), temp;

        //corner case
        if (size == 1)
        {
            if (nums[0] < target)
                return 0;
            else
                return 1;
        }

        while (1)
        {
            if (sum >= target)
            {
                temp = i - left + 1;
                sublen = sublen < temp ? sublen : temp;
                sum = sum - nums[left];
                left++;
            }
            else
            {
                i++;
                if (i < size)
                    sum = sum + nums[i];
                else
                    break;
            }
        }
        if (sublen == INT_MAX)
            return 0;
        else
            return sublen;
    
    }
};
