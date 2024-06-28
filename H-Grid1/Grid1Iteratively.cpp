#include <bits/stdc++.h>
using namespace std;
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);

void MO() {
    // ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin),freopen("../output.txt","w",stdout);
    #endif
}

const int N = 1e5 + 5;
const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int rows, cols;

vector <string> grid;
vector <vector <int>> dp;

int Grid1 () {
    dp[rows][cols] = 1;

    for (int row = rows; row >= 1; row--) {
        for (int col = cols; col >= 1; col--) {
            if (row == rows and col == cols) 
                continue;

            dp[row][col] = (dp[row + 1][col] + dp[row][col + 1]) % mod;

            if (grid[row - 1][col - 1] == '#')
                dp[row][col] = 0;
        }
    }

    return dp[1][1];
}

int main () {
    MO();

    cin >> rows >> cols;
    grid = vector <string> (rows);
    dp = vector <vector <int>> (rows + 5, vector <int> (cols + 5, 0));

    for (auto & row : grid) 
        cin >> row;

    cout << Grid1() << endl;
    // cout_2d(dp, rows + 1, cols + 1);
    return 0;
}