string solve(string s1,string s2){
    string s1,s2;
    cin>>s1>>s2;
    vector<int> v1,v2;
    string str="";
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='.'){
            int k=stoi(str);
            v1.pb(k);
            str="";
        }
        else{
            str+=s1[i];
        }
    }
    if(str!=""){
        int k=stoi(str);
        v1.pb(k);
    }
    str="";
    for(int i=0;i<s2.length();i++){
        if(s2[i]=='.'){
            int k=stoi(str);
            v2.pb(k);
            str="";
        }
        else{
            str+=s2[i];
        }
    }
    if(str!=""){
        int k=stoi(str);
        v2.pb(k);
    }
    int flag=0;
    for(int i=0;i<min(v1.size(),v2.size());i++){
        if(v1[i]==v2[i]){
            continue;
        }
        else if(v1[i]<v2[i]){
            flag=1;
            cout<<s1<<nl;
            return;
        }
        else{
            flag=1;
            cout<<s2<<nl;
            return;
        }
    }
    if(flag==0){
        if(v1.size()>v2.size()){
            return s2;
        }
        else{
            return s1;
        }
    }
}