#include <cstdio> // For Test
#include <iostream>
using namespace std;

// 발 위치
//   1
// 2 0 4
//   3

const int INF = 400000;

// dirs[기존발][이후발]
const int dirs[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1},
};

// dp[번쨰][왼발][오른발]
int dp[2][5][5] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Init
    int n, (*cur)[5] = dp[0], (*prev)[5] = dp[1], (*temp)[5];
    cin >> n;
    fill_n(&prev[0][0], 5 * 5, INF);
    prev[n][0] = prev[0][n] = 2;

    while (true)
    {
        // Input
        cin >> n;
        if (n == 0)
            break;

        // Process
        fill_n(&cur[0][0], 5 * 5, INF);
        for (int i = 0; i < 5; i++)     // 기존 왼발
            for (int j = 0; j < 5; j++) // 기존 오른발
            {
                if (i == j)
                    continue; // 기존 발이 같은 경우 없음

                // 업데이트 할 발이 서로 달라야함
                if (i != n)
                    cur[i][n] = min(cur[i][n], prev[i][j] + dirs[j][n]);
                if (j != n)
                    cur[n][j] = min(cur[n][j], prev[i][j] + dirs[i][n]);
            }

        // Swap
        temp = cur;
        cur = prev;
        prev = temp;
    }

    /* Output */
    int ans = 400000;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (i != j && prev[i][j] < ans)
                ans = prev[i][j];

    cout << ans << '\n';
    return 0;
}