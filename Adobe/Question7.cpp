class Solution {
public:
    int maxCoins(vector<int>&A,int n){
        map<string,int>mp;
	    int result=maxCoin(mp,A,0,n-1);
	    return result;
    }
    int maxCoin(map<string,int>&mp,vector<int>&t,int l,int r){
        string key = to_string(l)+"|"+to_string(r) ;
        if(l>r){
           return 0;
        }
        if(l==r){
           return t[l];
        }
        auto it = mp.find(key);
        if(it != mp.end()){
           return it->second;
        }
        int a = t[l]+min(maxCoin(mp,t,l+2,r),maxCoin(mp,t,l+1,r-1));
        int b = t[r]+min(maxCoin(mp,t,l+1,r-1),maxCoin(mp,t,l,r-2));
        int profit = max(a,b);
        mp.insert(make_pair(key,profit));
        return profit;
    }
};