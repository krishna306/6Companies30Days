class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int len = nums.size();
        
        sort(begin(nums), end(nums), [&](string s1, string s2){
            if (s1.length() < s2.length())
                return true;
            if (s2.length() < s1.length())
                return false;
            else
                return (s1 < s2);
        });
        
        return nums[len-k];
    }
};