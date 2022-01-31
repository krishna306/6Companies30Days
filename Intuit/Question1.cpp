class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	   int sum = accumulate(arr,arr+n,0);
        int halfSum = sum/2;
        vector<vector<int>>mat(n,vector<int>(halfSum+1));
        for(int i=0;i<n;i++){
            mat[i][0]=1;
        }
        for(int i =0 ;i <= halfSum;i++ ){
            if(i == arr[0]){
                mat[0][i] =1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=halfSum;j++){
                if(mat[i-1][j]){
                    mat[i][j] =1;
                }
                else {
                    if(j>=arr[i]){
                        mat[i][j] = mat[i-1][j-arr[i]];
                    }
                    
                }
            }
        }
        int last = n-1;
        int firstPartSum = -1;
        for(int j=halfSum ; j>= 0;j--){
            if(mat[last][j]){
                firstPartSum = j;
                break;
            }
        }
        int secondPartSum = sum - firstPartSum;
        return abs(firstPartSum - secondPartSum);
	} 
};