#include <iostream>
using namespace std;

int n, answer[2] = {0};
// ...[0]: 색약X
// ...[1]: 색약O
// ...[2]: 입력받은 RGB
char map[100][100][3] = {0};
const pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool bfs(int r, int c, int cb, char color)
{
    // 이미 처리했을 경우 종료
    if (map[r][c][cb])
        return false;

    // 맵 밖일 경우 종료
    if (r < 0 || c < 0 || r >= n || c >= n)
        return false;

    // 내가 전염될 수 있는지 체크 후 처리
    if (cb == 0 ? (color == map[r][c][2]) : ((color == 'B' && map[r][c][2] == 'B') || (color != 'B' && map[r][c][2] != 'B')))
    {
        map[r][c][cb] = 1;
        for (int i = 0; i < 4; i++)
            bfs(r + dirs[i].first, c + dirs[i].second, cb, color);
    }
    return true;
}

int main()
{
    // Input
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j][2];

    // Process
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int cb = 0; cb <= 1; cb++)
                if (bfs(i, j, cb, map[i][j][2]))
                    answer[cb]++;

    // Output
    cout << answer[0] << ' ' << answer[1] << '\n';
    return 0;
}