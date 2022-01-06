vector<vector<string>>Anagrams(vector<string>& string_list) {

	map<string, vector<string>> m;
	map<string, vector<string>> :: iterator it;
	
	for (int i = 0; i < string_list.size(); i++) {
		string str = string_list[i];
		sort(str.begin(), str.end());
		m[str].push_back(string_list[i]);
	}

	int index = 0;
	vector<vector<string>>ans(m.size());

	for (it = m.begin(); it != m.end(); it++) {
		vector<string>s;
		s = it->second;

		for (int i = 0; i < s.size(); i++) {
			ans[index].push_back(s[i]);
		}

		index++;
	}
	
	return ans;
}