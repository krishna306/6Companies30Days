class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int getRegionSize(vector<vector<int>>&grid, int row, int column) {
        if (row < 0 || column < 0 || row >= grid.size() || column >= grid[row].size()) {
            return 0;
        }
        if (grid[row][column] == 0) {
            return 0;
        }
        grid[row][column] = 0;
        int size = 1;
        for (int r = row - 1; r <= row + 1; r++){
            for (int c = column - 1; c <= column + 1; c++) {
                if (r != row || c != column) {
                    size += getRegionSize(grid, r, c);
                }
            }
        }
        return size;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int maxRegion = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int column = 0; column < grid[row].size(); column++) {
                if (grid[row][column] == 1) {
                    int size = getRegionSize(grid, row, column);
                    maxRegion = max(size, maxRegion);
                }
            }
        }
        return maxRegion;
    }
};