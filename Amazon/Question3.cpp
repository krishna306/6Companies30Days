class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
         vector<int>result;
        deque<int>dq(k);
        int i;
        for(i=0;i<k;i++){
            while((!dq.empty()) && arr[i]>= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<n;i++){
            result.push_back(arr[dq.front()]);
            while((!dq.empty()) && dq.front()<=i-k){
                dq.pop_front();
            }
            while((!dq.empty()) && arr[i]>= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(arr[dq.front()]);
        return result;
    }
};