class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        bool check9x9[9] = {false}; // init counters
        bool checkRows[9] = {false};
        bool checkCols[9] = {false};

        for (int y = 0; y < 9; ++y)
        {   
            const int topLeftRow = y/3 * 3; // vars for 9x9 check
            const int topLeftCol = y%3 * 3;

            memset(check9x9, 0, sizeof(bool)*9); // reset counters
            memset(checkRows, 0, sizeof(bool)*9);
            memset(checkCols, 0, sizeof(bool)*9);

            for (int x = 0; x < 9; ++x)
            {
                // check 9x9 box
                char val = board[x/3 + topLeftRow][x%3 + topLeftCol];
                if (val != '.') 
                {
                    if (check9x9[val-'1']) return false; // duplicate found
                    else check9x9[val-'1'] = true;
                }

                // check rows
                val = board[y][x];
                if (val != '.')
                {
                    if (checkRows[val-'1']) return false;
                    else checkRows[val-'1'] = true;
                }

                // check columns
                val = board[x][y];
                if (val != '.')
                {
                    if (checkCols[val-'1']) return false;
                    else checkCols[val-'1'] = true;
                }
            }
        }

        return true;
    }
};