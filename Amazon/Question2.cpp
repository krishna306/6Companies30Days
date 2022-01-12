 int longestMountain(vector<int>& arr) {
    int n = arr.size();
    int result =0;
    for(int i=1;i<n;i++){
        int j=i;
        int count =1;
        int flag=0;
        while(j<n && arr[j]>arr[j-1]){
            j++;
            count++;
        }
        while(j<n && i!=j && arr[j]<arr[j-1]){
            j++;
            count++;
            flag=1;
        }
        if(i!=j && flag&&count >2){
            result = max(result,count);
            j--;
        }
        i=j;
    }
    return result;
}