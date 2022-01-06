string encode(string src){

    string ans;
    int count =1;

    for(int i=0;i<src.length()-1;i++){
        if(src[i]!=src[i+1]){
            ans+=src[i];
            ans+=(char)(count+48);
            count =0;
        }
        count++;
    }

    ans+= src[src.length()-1];
    ans+= (char)(count+48);
    
    return ans ;
}     
