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
vector <int> memo;

int frog2 (int indx) {
    if (indx >= numberOfStones) 
        return oo;
    
    if (indx == numberOfStones - 1)
        return 0;

    int& ret = memo[indx];
    if (~ret)
        return ret;

    int op = oo;
    for (int i = 1; i <= jumps; i++) {
        if (indx + i < numberOfStones) 
            op = min(op, abs(stones[indx] - stones[indx + i]) + frog2(indx + i));
    }

    return ret = op;
}

int main () {
    MO();

    cin >> numberOfStones >> jumps;
    stones = memo = vector <int> (numberOfStones, -1);

    for (auto &stone : stones) 
        cin >> stone;

    cout << frog2(0) << endl;

    return 0;
}