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

int numberOfDays;

vector <int> sea, mountain, home;
vector <vector <int>> dp;

int Vacation (int n) {
    dp[0][0] = sea[0];
    dp[0][1] = mountain[0];
    dp[0][2] = home[0];

    for (int indx = 1; indx < n; indx++) {
        dp[indx][0] = max(dp[indx - 1][1], dp[indx - 1][2]) + sea[indx];
        dp[indx][1] = max(dp[indx - 1][0], dp[indx - 1][2]) + mountain[indx];
        dp[indx][2] = max(dp[indx - 1][0], dp[indx - 1][1]) + home[indx];
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main () {
    MO();

    cin >> numberOfDays;
    sea = mountain = home = vector <int> (numberOfDays, -1);
    dp = vector <vector <int>> (numberOfDays, vector <int> (3, 0));

    for (int i = 0; i < numberOfDays; i++)
        cin >> sea[i] >> mountain[i] >> home[i];

    cout << Vacation(numberOfDays) << endl;

    // cout_2d(dp, numberOfDays, 3);

    return 0;
}