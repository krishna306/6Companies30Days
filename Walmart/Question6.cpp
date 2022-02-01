class Solution{
    public:
    //You need to complete this fucntion
    #define mod 1000000007
    long power(int N,int R){
        //Your code here
        return computePowerRecursive(N,R)%mod;
    }
    long computePowerRecursive(int N, int R){
        if(R == 0){
            return 1;
        }
        long result = power(N,R/2);
        result = (result*result)%mod;
        if(R%2 == 0){
            return result;
        }
        else{
              return result*N;
        }
    }
};