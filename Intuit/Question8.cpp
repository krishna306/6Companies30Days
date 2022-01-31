class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(i==j) continue;
                else {
                    int d = pow((points[i][0] - points[j][0]),2)+ pow((points[i][1] - points[j][1]),2);
                    mp[d]++;
                }
            }
            for(auto x: mp){
                ans += (x.second)*(x.second-1);
            }
            mp.clear();
        }
        return ans;
    }
};