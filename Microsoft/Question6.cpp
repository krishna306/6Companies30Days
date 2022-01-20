class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void createString(int a[],int n,int i,map<int,string>&mp,string tem,vector<string>&result){
        if(tem.length() ==n) {
            result.push_back(tem);
        }
        string currString = mp[a[i]];
        for(int j=0;j<currString.length();j++){
            tem+=currString.at(j);
            createString(a,n,i+1,mp,tem,result);
            tem = tem.substr(0,tem.length()-1);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>result;
        if(N == 0){
            return result;
        }
        
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string s="";
        createString(a,N,0,mp,s,result);
        return result;
    }
};