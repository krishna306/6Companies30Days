class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int left = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
           sum +=arr[i];
           while(sum >= s){
               if(sum == s){
                   return vector<int >{left+1,i+1};
               }
               sum -= arr[left];
               left++;
           }
        }
            return vector<int>{ -1 };
    }
};