vector<string> generate(int N)
{
	vector<string>result;
	queue<string>q;
	q.push("1");
	int count = 0;
	while (count < N) {
		string curr = q.front();
		result.push_back(curr);
		q.pop();
		q.push(curr+'0');
		q.push(curr+'1');
		count++;
	}
	return result;
}
