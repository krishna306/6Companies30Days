int *findTwoElement(int *arr, int n) {
    int *ans = new int[2];
    int x, y;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]>0){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        else {
            x = abs(arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] >0){
            y = i+1;
        }
    }
    ans[0]=x;
    ans[1]=y;
     return ans;
}