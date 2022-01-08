int findPosition(int N , int M , int K) {
    int ans = (M+K-1)%N;
    if(ans ==0){
        return N;
    }
    return ans ;
}