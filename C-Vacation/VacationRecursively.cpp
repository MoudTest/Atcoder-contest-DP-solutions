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

int numberOfDays;

vector <int> sea, mountain, home;
vector <vector <int>> memo;

int Vacation (int indx, int last) {
    if (indx == numberOfDays)
        return 0;

    int& ret = memo[indx][last];
    if (~ret)
        return ret;

    int op1 = -oo, op2 = -oo, op3 = -oo;
    if (last != 1)
        op1 = sea[indx] + Vacation(indx + 1, 1);

    if (last != 2)
        op2 = mountain[indx] + Vacation(indx + 1, 2);

    if (last != 3)
        op3 = home[indx] + Vacation(indx + 1, 3);

    return ret = max({op1, op2, op3});
}

int main () {
    MO();

    cin >> numberOfDays;
    sea = mountain = home = vector <int> (numberOfDays, -1);
    memo = vector <vector <int>> (numberOfDays, vector <int> (4, -1));

    for (int i = 0; i < numberOfDays; i++)
        cin >> sea[i] >> mountain[i] >> home[i];

    cout << Vacation(0, 0) << endl;

    return 0;
}