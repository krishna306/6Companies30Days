vector<int> klargest(vector<int>&a,int n,int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]>pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans ;
}