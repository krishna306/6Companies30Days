string decodedString(string s){

    stack<int>counts;
    stack<string>str;

    int i = 0;
    string res = "";

    while (i < s.length()) {

        if (isdigit(s[i])) {
            int count = 0;
            while (isdigit(s[i])) {
                count = 10 * count + (s[i] - '0');
                i++;
            }
            counts.push(count);
        }

        else if (s[i] == '[') {
            str.push(res);
            res = "";
            i++;
        }

        else if (s[i] == ']') {
            string temp = str.top();
            str.pop();
            int count = counts.top();
            counts.pop();
            while (count--) {
                temp += res;
            }
            res = temp;
            i++;
        }

        else {
            res += s[i];
            i++;
        }
    }
    
    return res;
}