bool canPair(vector<int> nums, int k) {
  int rem,frq;
  if(nums.size()%2 != 0){
    return false;
  }

  map<int ,int>mp;
  for(int i=0;i<nums.size();i++){
    mp[nums[i]%k]++;
  }

  if(mp[0]%2!=0){
    return false ;
  }

  for(auto x : mp){
    rem = x.first;
    frq = x.second;
    if(rem != 0 && mp[k-rem] != frq){
      return false ;
    }
  }
  
  return true;
}