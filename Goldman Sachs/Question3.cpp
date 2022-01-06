int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
    int ans = 0;
    long long int product = 1;
    int right = 0;
    int left = 0;

    while (right < n) {
        product *= a[right];

        while (product >= k) {
            product /= a[left];
            left++;
        }
        ans += right - left + 1;
        right++;
    }

    return ans;
}
