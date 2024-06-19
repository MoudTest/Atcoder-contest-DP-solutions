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
vector <int> memo;

int frog1 (int indx) {
    if (indx == numberOfStones - 1)
        return 0;
    
    int& ret = memo[indx];
    if (~ret)
        return ret;
    
    int op1 = frog1(indx + 1) + abs(stones[indx] - stones[indx + 1]);

    int op2 = oo;
    if (indx + 2 < numberOfStones) 
        op2 = frog1(indx + 2) + abs(stones[indx] - stones[indx + 2]);

    return ret = min(op1, op2);
}

int main () {
    MO();

    cin >> numberOfStones;
    stones = memo = vector <int> (numberOfStones, -1);

    for (auto &stone : stones) 
        cin >> stone;

    cout << frog1(0) << endl;

    return 0;
}