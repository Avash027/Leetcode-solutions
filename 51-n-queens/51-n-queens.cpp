class Solution {
private:

    vector<vector<string>> ans;

    void placeQueens(int n, int row, vector<string> cur) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }


        string s = string(n , '.');

        for (int col = 0; col < n ; col++) {
            bool ok = 0;
            cur.push_back(s);


            for (int i = 0; i < cur.size(); i++)
                ok |= (cur[i][col] == 'Q');


            for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
                ok |= (cur[i][j] == 'Q');


            for (int i = row, j = col; i >= 0 and j < n; i--, j++)
                ok |= (cur[i][j] == 'Q');

            if (!ok) {
                cur[row][col] = 'Q';
                placeQueens(n , row + 1 , cur);

            }


            cur.pop_back();
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {

        placeQueens(n, 0, {});
        return ans;
    }
};
