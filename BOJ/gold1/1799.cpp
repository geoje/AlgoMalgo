#include <cstdio> // For Test
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, ans = 0;
bool diag[2][199] = {0};

int dfs(vector<pii> &points, int idx)
{
    if (idx >= points.size())
        return 0;

    int result = 0;

    int r = points[idx].first;
    int c = points[idx].second;

    bool &d1 = diag[0][r - c + n - 1];
    bool &d2 = diag[1][r + c];

    // 놓을 수 있는 경우
    if (!d1 && !d2)
    {
        // 대각선 둘을 놓을 수 없다고 변경
        d1 = d2 = true;

        // 다음 포인트 탐색
        result = dfs(points, idx + 1) + 1;

        // 다시 대각선 둘 놓을 수 있다고 변경
        d1 = d2 = false;
    }

    // 다음 포인트 탐색
    return max(result, dfs(points, idx + 1));
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    vector<pii> black, white;
    bool able;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> able;
            if (!able)
                continue;

            if ((i + j) % 2)
                white.push_back({i, j});
            else
                black.push_back({i, j});
        }

    /* Process & Output */
    cout << dfs(black, 0) + dfs(white, 0) << '\n';
    return 0;
}