int minSubArrayLen(int target, vector<int>& nums) {

    int sum =0;
    int ans =INT_MAX;
    int left =0, right=0;

    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        while(sum >= target){
            ans = min(ans ,i+1-left );
            sum -= nums[left];
            left++;
        }
    } 
    
    return ans!=INT_MAX ? ans :0;
}