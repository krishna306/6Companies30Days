class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<string>fresh;
        set<string>rotten;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    string s = "";
                    s += char(48 + i);
                    s += char(48 + j);
                    fresh.insert(s);

                }
                else if (grid[i][j] == 2) {
                    string s = "";
                    s += char(48 + i);
                    s += char(48 + j);
                    rotten.insert(s);
                }
            }
        }
        int time = 0;
        int directions[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
        while (fresh.size() > 0) {
            set<string>infected;
            for (auto str : rotten) {
                int i = str.at(0) - '0';
                int j = str.at(1) - '0';
                for (int k = 0; k < 4;k++) {
                    int nextI = i + directions[k][0];
                    int nextJ = j + directions[k][1];
                    string s = "";
                    s += char(48 + nextI);
                    s += char(48 + nextJ);

                    if (fresh.find(s) != fresh.end()) {
                        fresh.erase(fresh.find(s));
                        infected.insert(s);
                    }
                }
            }
            if (infected.size() == 0) {
                return -1;
            }
            rotten = infected;
            time += 1;
        }
        return time;
    }
};