class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int>result;
       result.push_back(a[n-1]);
       int Max=a[n-1] ;
        for(int i=n-2;i>=0;i--){
            if(Max <a[i]){
                Max =a[i];
            }
            if(Max == a[i]){
                result.push_back(Max);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};