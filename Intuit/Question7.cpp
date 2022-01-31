class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxWeight = 0;
        for (auto& w : weights) {
            sum += w;
            maxWeight = max(w, maxWeight);
        }
        int minNeed = maxWeight, maxNeed = sum;
        while (minNeed < maxNeed) {
            int mid = (minNeed + maxNeed) / 2;
            int ship = 0, load = 0;
            for (auto& w : weights) {
                if (mid - load >= w) {
                    load += w;
                } else {
                    ship++;
                    if (ship == days) {
                        break;
                    }
                    load = w;
                }
            }
            if (ship < days) {
                maxNeed = mid;
            } 
            else {
                minNeed = mid + 1;
            }
        }
        return minNeed;
    }
};