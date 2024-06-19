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
const int INF = int(1e9) + 5;
const ll N = 2e5 + 5;
const ll mod = 1e9 + 7;
bool cmp(int a, int b) {
    return a > b;
}

void MO() {
    ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin),freopen("output.txt","w",stdout);
    #endif
}

vector <int> dp(N, -1);

int fib(int n) {
    if (n <= 2) 
        return 1;
    
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

signed main() {
    MO();


    cout << fib(6) << endl;
    
    return 0;
}