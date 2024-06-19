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
vector <vector <int>> memo;

bool valid(int row, int col) {
    return row >= 0 and row < rows and col >= 0 and col < cols and grid[row][col] != '#';
}

int Grid1 (int row, int col) {
    if (!valid(row, col))
        return 0;

    if (row == rows - 1 and col == cols - 1)
        return 1;

    int& ret = memo[row][col];
    if (~ret)
        return ret;

    int right = Grid1(row, col + 1);
    int down = Grid1(row + 1, col);

    return ret = (right + down) % mod;
}

int main () {
    MO();

    cin >> rows >> cols;
    grid = vector <string> (rows);
    memo = vector <vector <int>> (rows + 1, vector <int> (cols + 1, -1));

    for (auto & row : grid) 
        cin >> row;


    cout << Grid1(0, 0) << endl;
    cout_2d(memo, rows, cols);
    return 0;
}