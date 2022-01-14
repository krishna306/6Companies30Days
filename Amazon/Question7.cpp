class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int>charFreq(26);
		    queue<char>q;
		    string result="";
		    for(int i=0;i<A.length();i++){
		       q.push(A[i]);
		       charFreq[A[i]-'a']++;
		       while(!q.empty()){
		           if(charFreq[q.front()-'a'] >1){
		               q.pop();
		           }
		           else {
		               result += q.front();
		               break;
		           }
		       }
		       if(q.empty()){
		           result +='#';
		       }
		    }
		    return result;
		}

};