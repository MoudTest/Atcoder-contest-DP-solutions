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

int numberOfStones, jumps;

vector <int> stones;
vector <int> dp;

int frog2 (int n) {
    dp[n - 1] = 0;

    for (int indx = n - 2; indx >= 0; indx--) {
        int op = oo;

        for (int k = 1; k <= jumps; k++) {
            if (indx + k < n)
                op = min(op, abs(stones[indx] - stones[indx + k]) + dp[indx + k]);
        }
        
        dp[indx] = op;
    }

    return dp[0];
}

int main () {
    MO();

    cin >> numberOfStones >> jumps;
    stones = dp = vector <int> (numberOfStones, -1);

    for (auto &stone : stones) 
        cin >> stone;

    cout << frog2(numberOfStones) << endl;

    return 0;
}