string printMinNumberForPattern(string S){
    stack<int>a;
    int j=1;
    string ans="";
    for(int i=0;i<S.length();i++){
        if(S[i]=='D'){
             a.push(j);
            j++;                
        }
        else{
            a.push(j);
            j++;
            while(!a.empty()){
                ans+=(char)(a.top()+48);
                a.pop();
            }
        }
    }
    a.push(j);
    while(!a.empty()){
        ans+=(char)(a.top()+48);
        a.pop();
    }
    return ans;
}