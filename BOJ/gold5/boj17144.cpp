// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int r, c, t, map[2][51][51] = {0};
int cleaner[2] = {0}; // 공기 청정기의 c 값은 1로 고정이니 r 값 2개가 작은 것 부터 들어감;

pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> map[0][i][j];

            // 공기청정기 위치 입력
            if (map[0][i][j] == -1)
            {
                if (cleaner[0])
                    cleaner[1] = i;
                else
                    cleaner[0] = i;
            }
        }

    // Process
    // k: 1초 부터 t초 까지 진행
    int ni, nj;
    for (int k = 1; k <= t; k++)
    {
        // 다음 입력될 곳 초기화
        fill_n(&map[k % 2][0][0], 51 * 51, 0);
        int(*pMap)[51] = map[!(k % 2)];
        int(*cMap)[51] = map[k % 2];

        // 미세먼지 확산
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
            {
                cMap[i][j] += pMap[i][j];
                // 미세먼지가 있을 때
                if (pMap[i][j] > 0)
                {
                    int dustPart = pMap[i][j] / 5;
                    for (auto dir : dirs)
                    {
                        ni = i + dir.first;
                        nj = j + dir.second;

                        // 퍼트릴 곳이 맵 밖이거나 공기청정기가 있을 경우 중지
                        if (ni < 1 || nj < 1 || ni > r || nj > c || pMap[ni][nj] == -1)
                            continue;

                        cMap[ni][nj] += dustPart;
                        cMap[i][j] -= dustPart;
                    }
                }
            }

        // 테스트 코드
        // cout << k << "초 후 미세먼지 확산\n";
        // for (int i = 1; i <= r; i++)
        // {
        //     for (int j = 1; j <= c; j++)
        //     {
        //         cout << cMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 공기청정기 위쪽 작동
        int ci = cleaner[0] - 1;
        int cj = 1;
        pair<int, int> dir = dirs[0];
        while (true)
        {
            // 현재 위치를 보고 미세먼지를 가져올 방향 정함
            if (ci == 1 && cj == 1)
                dir = dirs[1];
            else if (ci == 1 && cj == c)
                dir = dirs[2];
            else if (ci == cleaner[0] && cj == c)
                dir = dirs[3];

            // 다음 위치 정함
            ni = ci + dir.first;
            nj = cj + dir.second;

            // 다음 위치가 공기청정기일 경우 현재 위치 미세먼지 제거 후 확산 끝
            if (cMap[ni][nj] == -1)
            {
                cMap[ci][cj] = 0;
                break;
            }

            // 미세먼지 이동 시킴
            cMap[ci][cj] = cMap[ni][nj];
            ci = ni;
            cj = nj;
        }

        // 테스트 코드
        // cout << k << "초 후 위쪽 공기청정기 작동\n";
        // for (int i = 1; i <= r; i++)
        // {
        //     for (int j = 1; j <= c; j++)
        //     {
        //         cout << cMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 공기청정기 아래쪽 작동
        ci = cleaner[1] + 1;
        cj = 1;
        dir = dirs[2];
        while (true)
        {
            // 현재 위치를 보고 미세먼지를 가져올 방향 정함
            if (ci == r && cj == 1)
                dir = dirs[1];
            else if (ci == r && cj == c)
                dir = dirs[0];
            else if (ci == cleaner[1] && cj == c)
                dir = dirs[3];

            // 다음 위치 정함
            ni = ci + dir.first;
            nj = cj + dir.second;

            // 다음 위치가 공기청정기일 경우 현재 위치 미세먼지 제거 후 확산 끝
            if (cMap[ni][nj] == -1)
            {
                cMap[ci][cj] = 0;
                break;
            }

            // 미세먼지 이동 시킴
            cMap[ci][cj] = cMap[ni][nj];
            ci = ni;
            cj = nj;
        }

        // 테스트 코드
        // cout << k << "초 후 아래쪽 공기청정기 작동\n";
        // for (int i = 1; i <= r; i++)
        // {
        //     for (int j = 1; j <= c; j++)
        //     {
        //         cout << cMap[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    // Output
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (map[t % 2][i][j] > 0)
                ans += map[t % 2][i][j];
    cout << ans << '\n';
    return 0;
}