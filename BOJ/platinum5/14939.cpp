#include <cstdio> // For Test
#include <cstring>
#include <iostream>
using namespace std;

char map[10][10], temp[10][10];
int ans = 101;

const pair<int, int> dirs[5] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void switching(int i, int j)
{
    for (auto dir : dirs)
    {
        int ni = i + dir.first, nj = j + dir.second;
        if (ni < 0 || nj < 0 || ni >= 10 || nj >= 10)
            continue;

        char &m = map[ni][nj];
        m = m == 'O' ? '#' : 'O';
    }
}
// i, j 위치 c 번 스위칭
void light(int col, int count)
{
    // 첫째줄 일 경우 백트래킹
    if (col < 10)
    {
        // 안누르고 진행
        light(col + 1, count);

        // 누르고 진행
        switching(0, col);
        light(col + 1, count + 1);

        // 원상 복귀
        switching(0, col);
        return;
    }

    // 둘째줄 부터는 끝까지 판별
    memcpy(temp, map, 100);
    for (int i = 1; i < 10; i++)
        for (int j = 0; j < 10; j++)
            // 위 부분이 켜져있을 경우 내 위치 눌러서 끄기
            if (map[i - 1][j] == 'O')
            {
                switching(i, j);
                count++;
            }

    // 마지막줄 체크
    for (int j = 0; j < 10; j++)
        if (map[9][j] == 'O')
        {
            memcpy(map, temp, 100);
            return;
        }

    // 정답 업데이트
    ans = min(ans, count);
    memcpy(map, temp, 100);
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];

    /* Process */
    light(0, 0);

    /* Output */
    cout << (ans == 101 ? -1 : ans) << '\n';
    return 0;
}