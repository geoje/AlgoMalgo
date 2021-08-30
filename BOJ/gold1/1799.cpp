#include <cstdio> // For Test
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, ans = 0;
vector<pii> points, bishops;
// [0]...: 좌하[0] ~ 우상[198] \
// [1]...: 좌상[0] ~ 우하[198] /
// ...[x]: x번째 대각선
int globalDiag[2][199] = {0}, curDiag[2][199];

bool promising(int (*diag)[199], pii p)
{
    return !(diag[0][p.first - p.second + n - 1] ||
             diag[1][p.first + p.second]);
}
void place(int (*diag)[199], pii p)
{
    diag[0][p.first - p.second + n - 1]++;
    diag[1][p.first + p.second]++;
}
void unplace(int (*diag)[199], pii p)
{
    diag[0][p.first - p.second + n - 1]--;
    diag[1][p.first + p.second]--;
}

void backtrack(int idx)
{
    if (idx >= points.size())
        return;

    // 첫째줄에 대하여 n^2 으로 탐색함
    if (points[idx].first == 0)
    {
        // 비숍을 두고 백트래킹 진행
        place(globalDiag, points[idx]);
        bishops.push_back(points[idx]);
        backtrack(idx + 1);

        // 비숍을 빼고 백트래킹 진행
        unplace(globalDiag, bishops.back());
        bishops.pop_back();
        backtrack(idx + 1);
    }
    // 둘째 줄일 경우 그냥 쭉 탐색하여 정답 갱신
    else
    {
        copy(&globalDiag[0][0], &globalDiag[0][0] + 2 * 199, &curDiag[0][0]);

        int num = bishops.size();
        for (; idx < points.size(); idx++)
            if (promising(curDiag, points[idx]))
            {
                num++;
                place(curDiag, points[idx]);
            }
        if (num > ans)
            ans = num;
    }
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(argv[1], "r", stdin); // For Test

    /* Input */
    bool placeable;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> placeable;
            if (placeable)
                points.push_back({i, j});
        }

    /* Process */
    backtrack(0);
    // 정단 갱신이 둘째줄 부터 이루어 지므로 첫째줄만 둔 경우를 대비해 정답 갱신
    if (!points.empty() && ans == 0)
        ans = points.size();

    /* Output */
    cout << ans << '\n';
    return 0;
}