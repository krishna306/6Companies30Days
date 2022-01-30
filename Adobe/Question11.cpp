class Solution{
    public:
    string amendSentence (string s)
    {
        string result="";
        string temp="";
        if(s.at(0)>='A' && s.at(0)<='Z'){
            result += char(s.at(0)+32);
        }
        else {
            result += s.at(0);
        }
        for(int i=1;i<s.length();i++){
            if(s.at(i)>='A' && s.at(i)<='Z'){
                result += temp;
                result+=" ";
                temp=char(s.at(i)+32);
            }
            else {
                temp+=s.at(i);
            }
        }
        return result+temp;
    }
};