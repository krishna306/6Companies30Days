class Solution{
    public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        set<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int sum;
        
        for(int i=0;i<n-3;++i) {
            if(i>0 and arr[i]==arr[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;++j){
                if(j>i+1 and arr[j]==arr[j-1]){
                    continue; 
                }
                int left=j+1,right=n-1;
                while(left<right){ 
                    sum=arr[i]+arr[j]+arr[left]+arr[right];
                    if(sum>target)
                        right-=1;
                    else if(sum==target) {
                        vector<int> t;
                        t.push_back(arr[i]);
                        t.push_back(arr[j]);
                        t.push_back(arr[left]);
                        t.push_back(arr[right]);
                        ans.insert(t);
                        left+=1;
                    }
                    else{
                        left+=1;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto it: ans)
            res.push_back(it);
        return res;
        
    }
};