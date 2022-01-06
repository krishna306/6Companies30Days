static const int mod = 1e9+7;
int CountWays(string str){
	if(str.length() == 0 || str[0] == '0'){
        return 0;
    } 
    if(str.length() == 1) {
        return 1;
    }

    int count1 = 1, count2 = 1;
    for(int i = 1; i < str.length(); ++i){
        int d = str[i] - '0';
        int dd = (str[i-1] - '0')*10 + d;
        int count = 0;
        if(d > 0) {
            count += count2 % (mod);
        }

        if(dd >= 10 && dd <= 26){
            count += count1 % (mod);
        } 

        count1 = count2;  
        count2 = count;  
    }
    return count2 % (mod);
}