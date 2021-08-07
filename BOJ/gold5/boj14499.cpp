#include <iostream>
using namespace std;

// cmds[i]: 1 동쪽, 2 서쪽, 3 북쪽, 4 남쪽
int n, m, x, y, k, map[20][20] = {0}, cmds[1000];
// 주사위 번호 배열 (아래는 처음 시작할 때 기준 위치)
// [0]: 상단
// [1]: 전면
// [2]: 우측
// [3]: 하단
// [4]: 후면
// [5]: 좌측
int dice[6] = {0};

void roll()
{
    for (int i = 0; i < k; i++)
    {
        // 동쪽 굴리기
        bool move = false;
        int cmd = cmds[i];
        if (cmd == 1 && x < m - 1)
        {
            int tmp = dice[0];
            dice[0] = dice[5];
            dice[5] = dice[3];
            dice[3] = dice[2];
            dice[2] = tmp;
            move = true;
            x++;
        }
        // 서쪽 굴리기
        else if (cmd == 2 && x > 0)
        {
            int tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[3];
            dice[3] = dice[5];
            dice[5] = tmp;
            move = true;
            x--;
        }
        // 북쪽 굴리기
        else if (cmd == 3 && y > 0)
        {
            int tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[4];
            dice[4] = tmp;
            move = true;
            y--;
        }
        // 남쪽 굴리기
        else if (cmd == 4 && y < n - 1)
        {
            int tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[3];
            dice[3] = dice[1];
            dice[1] = tmp;
            move = true;
            y++;
        }
        if (!move)
            continue;

        // 맵이 0이 아니면 맵 값을 주사위 하단으로 복사 후 맵은 0으로 변경
        if (map[y][x])
        {
            dice[3] = map[y][x];
            map[y][x] = 0;
        }
        // 맵이 0이면 주사위 하단 값을 맵으로 복사
        else
            map[y][x] = dice[3];

        //// 윗면 숫자 출력
        cout << dice[0] << '\n';
    }
}
int main()
{
    // Input
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    for (int i = 0; i < k; i++)
        cin >> cmds[i];

    // Process
    roll();

    // Output
    return 0;
}