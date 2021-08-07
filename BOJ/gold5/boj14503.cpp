#include <iostream>
using namespace std;

// map[i][j] 상태
// 0: 아무것도 안함
// 1: 벽
// 2: 청소함
int map[50][50] = {0};
int n, m, r, c, d;       // 세로, 가로, row, col, 방향
pair<int, int> dir[] = { // 북, 동, 남, 서 // {row, col}
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

void TurnLeft()
{
    if (d == 0)
        d = 3;
    else
        d--;
}
int Process()
{
    int count = 0;

    while (true)
    {
        // 1. 현재 위치 청소 안되어 있으면 청소
        if (map[r][c] == 0)
        {
            map[r][c] = 2;
            count++;
        }

        // 2. 왼쪽으로 돌면서 청소할 방향을 찾음
        bool canClean = false;
        for (int i = 0; i < 4; i++)
        {
            TurnLeft();
            int nr = r + dir[d].first;  // 왼쪽 row
            int nc = c + dir[d].second; // 왼쪽 col

            // 왼쪽이 청소할 수 있으면 위치 이동
            if (map[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                canClean = true;
                break;
            }
        }

        // 2-d. 청소할 곳이 없을 때
        if (!canClean)
        {
            int nd = (d + 2) % 4;
            int nr = r + dir[nd].first;  // 뒤쪽 row
            int nc = c + dir[nd].second; // 뒤쪽 col

            // 뒤가 벽이 아니면 후진
            if (map[nr][nc] != 1)
            {
                r = nr;
                c = nc;
            }
            // 뒤가 벽이거나 맵 끝이면 청소 끝
            else
                break;
        }
    }

    return count;
}

int main()
{
    // Input
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    // Process & Output
    cout << Process();
    return 0;
}