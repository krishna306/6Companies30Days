
class Solution{
    void fun(string s, string &res,int k,int ind){
        if(k == 0){
             return;
        }
        if(ind == s.length()){
            return;
        }
        int check = s[ind] - '0';
        int j = -1;
        for(int i = ind + 1 ; i < s.length() ; i++){
            if(check < s[i] - '0'){
                check = s[i] - '0';
            }
        }
        if(check != s[ind] - '0'){
            k--;
        }
        for(int i =  s.length()  - 1; i >= ind; i --){
            if(s[i] - '0' == check){
                swap(s[ind],s[i]);
                res = max(res,s);
                fun(s,res,k,ind + 1);
                swap(s[ind],s[i]);
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    
    string findMaximumNum(string s, int k){
       string res = s;
       fun(s,res,k,0);
       return res;
    }
};