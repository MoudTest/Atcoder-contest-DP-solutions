#include <bits/stdc++.h>
#define len(s) int(s.size())
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define fix(n) fixed << setprecision(n)
#define fi first
#define sc second
#define ll long long
#define endl '\n'
#define double long double
#define SUM(v) accumulate(all(v), 0LL)
#define pqueue priority_queue
#define Min(c) vector<c>, greater<c>
#define ON(n, bit) ((n) | (1 << bit))
#define OFF(n, bit) ((n) & ~(1 << bit))
#define isON(n, bit) (((n) >> (bit)) & 1)
#define tog(n, bit) ((n) ^ (1 << (bit - 1)))
#define ull unsigned long long
#define popcount __builtin_popcount
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
const int oo = 0x3f3f3f3f;
// const ll oo = 0x3f3f3f3f3f3f3f3f;
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
using namespace std;
string res[2] = {"NO" , "YES"};
bool cmp(int a, int b) {
    return a > b;
}

void MO() {
    ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin),freopen("output.txt","w",stdout);
    #endif
}

const int N = 1001, W = 1001;
vector <int> we(N), val(N);

int memo[N][W];

int solve(int n, int c) {
    if (n == 0 or c == 0) 
        return 0;

    if (memo[n][c] != -1)
        return memo[n][c];

    int op1 = -oo;
    if (we[n - 1] <= c) 
        op1 = val[n - 1] + solve(n - 1, c - we[n - 1]);
    int op2 = solve(n - 1, c);

    return memo[n][c] = max(op1, op2);
}

int dp[N][W];

int itSolve(int n, int c) {
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 0; i <= c; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= c; k++) {
            int op1 = we[i] <= k ? val[i] + dp[i - 1][k - we[i]] : -oo;
            int op2 = dp[i - 1][k];

            dp[i][k] = max(op1, op2);
        }
    }

    return dp[n][c];
}

signed main() {
    MO();
    
    memset(memo, -1, sizeof memo);
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> we[i] >> val[i];
    }

    cout << solve(n, c) << endl;
    cout << itSolve(n, c) << endl;

    
    return 0;
}