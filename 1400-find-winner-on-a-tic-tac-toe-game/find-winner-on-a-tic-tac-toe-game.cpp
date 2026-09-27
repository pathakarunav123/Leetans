#include <vector>
#include <cmath>
#include <string>

class Solution {
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves) {
        std::vector<int> rows(3, 0);
        std::vector<int> cols(3, 0);
        int diag = 0;
        int anti_diag = 0;
        
        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0];
            int c = moves[i][1];
            
            int player = (i % 2 == 0) ? 1 : -1;
            
            rows[r] += player;
            cols[c] += player;
            
            if (r == c) {
                diag += player;
            }
            if (r + c == 2) {
                anti_diag += player;
            }
            
            if (std::abs(rows[r]) == 3 || 
                std::abs(cols[c]) == 3 || 
                std::abs(diag) == 3 || 
                std::abs(anti_diag) == 3) {
                return (player == 1) ? "A" : "B";
            }
        }
    
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};
