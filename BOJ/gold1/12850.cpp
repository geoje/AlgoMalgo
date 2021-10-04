#include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;

const vector<int> roads[8] = {
    {1, 5},       //정보과학관
    {0, 2, 5},    //전산관
    {1, 3, 5, 6}, //신양관
    {2, 4, 6},    //진리관
    {3, 7},       //학생회관
    {0, 1, 2, 6}, //미래관
    {2, 3, 5, 7}, //한경직기념관
    {4, 6}        //형남공학관
};

int d;
long long dp[2][8];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> d;

    /* Process */
    long long *prev = dp[0], *cur = dp[1];
    prev[0] = 1;
    while (d--)
    {
        for (int i = 0; i < 8; i++)
        {
            cur[i] = 0;
            for (int j : roads[i])
                cur[i] += prev[j];
            cur[i] %= MOD;
        }

        swap(cur, prev);
    }

    /* Output */
    cout << prev[0] << '\n';
    return 0;
}