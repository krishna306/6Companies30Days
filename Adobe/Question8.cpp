class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        for(int i=0;i<str.length();i++){
            if(!((str.at(i)>='0' && str.at(i)<='9' )|| (str.at(i)=='-'))){
                return -1;
            }
        }
        stringstream stream(str);
        int ans ;
        stream >> ans ;
        return ans ;
    }
};
