#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        std::vector<std::string> grid(m, std::string(n, '#'));

        int currR = 0;
        int currC = 0;
        grid[currR][currC] = '.';

        while (currR != m - 1 || currC != n - 1) {
            if (currR == m - 1) {
                currC++;
            } else if (currC == n - 1) {
                currR++;
            } else if (currR == currC) {
                currC++;
            } else { 
                currR++;
            }
            grid[currR][currC] = '.';
        }
        return grid;
    }
};