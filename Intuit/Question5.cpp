class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> pref_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            pref_sum[i+1] = nums[i] + pref_sum[i];
        }
        auto bin_search = [&pref_sum](int left, int right, int target) {
            while (left < right) {
                int mid = (left+right)/2;
                if (pref_sum[mid] > target) right = mid;
                else left = mid + 1;
            }
            return left;
        };
        int left_sum = 0;
        int right_sum = pref_sum.back();
        while (left_sum < right_sum) {
            int mid_sum = (left_sum + right_sum) / 2;
            int curr_tot = mid_sum;
            int curr_m = 1;
            int curr_left = 0;
            while (curr_tot < pref_sum.back()) {
                int new_left = bin_search(curr_left, pref_sum.size() - 1, curr_tot);
                if (curr_left == new_left) {
                    curr_m = m + 1;
                    break;
                }
                curr_left = new_left;
                curr_tot = pref_sum[curr_left - 1] + mid_sum;
                ++curr_m;
            }
            if (curr_m > m) left_sum = mid_sum + 1;
            else right_sum = mid_sum;
        }
        return left_sum;
    }
};