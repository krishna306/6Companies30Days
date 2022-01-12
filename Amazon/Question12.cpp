string colName (long long int n){
    string ans ="";
    while(n>0){
        char ch = (n-1)%26+'A';
        ans = ch +ans ;
        n=(n-1)/26;
    }
     return ans ;
}