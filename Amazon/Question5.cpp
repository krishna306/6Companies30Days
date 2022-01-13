class Solution {
public:
    vector<vector<string>> displayContacts(int n, string A[], string s) {
        vector<vector<string>>result(s.length());
        vector<string>contact = removeDuplicate(A, n);
        n = contact.size();
        int j = 1,k=0;
        string check = s.substr(0, 1);
        while (check.length() <= s.length()) {
            for (int i = 0; i < n; i++) {
                    if (check == contact[i].substr(0, j)) {
                        result[k].push_back(contact[i]);
                    }
            }
            j++;
            k++;
            if (check.length() == s.length()) {
                break;
            }
            check = s.substr(0, j);
        }
        for (int i = 0; i < s.length(); i++) {
            if (result[i].size() == 0) {
                result[i].push_back("0");
            }
        }
        return result;
    }
    vector<string> removeDuplicate(string contact[], int n) {
        set<string>unqString(contact, contact + n);
        return vector<string>(unqString.begin(), unqString.end());
    }
};