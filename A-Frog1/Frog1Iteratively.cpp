#include <bits/stdc++.h>
using namespace std;

void MO() {
    // ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin),freopen("../output.txt","w",stdout);
    #endif
}

const int N = 1e5 + 5;
const int oo = 0x3f3f3f3f;

int numberOfStones;

vector <int> stones;
vector <int> dp;

int frog1 (int n) {
    dp[n - 1] = 0;
    dp[n - 2] = abs(stones[n - 1] - stones[n - 2]);

    for (int indx = n - 3; indx >= 0; indx--) {
        int op1 = abs(stones[indx] - stones[indx + 1]) + dp[indx + 1];
        int op2 = abs(stones[indx] - stones[indx + 2]) + dp[indx + 2];

        dp[indx] = min(op1, op2);
    } 

    return dp[0];
}

int main () {
    MO();

    cin >> numberOfStones;
    stones = dp = vector <int> (numberOfStones, 0);

    for (auto &stone : stones) 
        cin >> stone;

    cout << frog1(numberOfStones) << endl;

    return 0;
}