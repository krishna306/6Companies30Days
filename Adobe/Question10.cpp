class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int>mp;
        vector<string>result;
        mp.insert(make_pair(arr[0],1));
        for(int i=1;i<n;i++){
            auto it  = mp.find(arr[i]);
            if(it == mp.end()){
                mp.insert(make_pair(arr[i],1));
            }
            else {
                it->second+=1;
            }
        }
        int Max =0;
        for(auto it = mp.begin();it != mp.end();it++){
            //cout << "it->key "<< it->first<<"  it->value "<< it->second<< endl;
            if(it->second > Max){
                Max = it->second;
            }
        }
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->second == Max){
                result.push_back(it->first);
                result.push_back(to_string(it->second));
                break;
            }
        }
        return result;
    }
};