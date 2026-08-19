#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Map row number to a bitmask representing occupied seats 1-10
        unordered_map<int, int> rowMask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only columns 2 to 9 matter
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << col);
            }
        }

        int totalFamilies = (n - rowMask.size()) * 2;

        // Masks for each 4-seat block
        int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Seats 2, 3, 4, 5
        int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); // Seats 6, 7, 8, 9
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // Seats 4, 5, 6, 7

        for (const auto& [row, mask] : rowMask) {
            bool leftPossible = (mask & leftMask) == 0;
            bool rightPossible = (mask & rightMask) == 0;

            if (leftPossible && rightPossible) {
                totalFamilies += 2;
            } else if (leftPossible || rightPossible || ((mask & middleMask) == 0)) {
                totalFamilies += 1;
            }
        }

        return totalFamilies;
    }
};