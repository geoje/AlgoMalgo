#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m, b;
int map[500][500];
pair<int, int> ans = {2e9, 0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    /* Process */
    for (int h = 0; h <= 256; h++)
    {
        int sec = 0, blocks = b;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int vh = map[i][j] - h;
                // 블럭을 팠을 경우
                if (vh > 0)
                {
                    // 생긴 블럭 추가 및 시간 증가
                    blocks += vh;
                    sec += 2 * vh;
                }
                // 블럭을 심었을 경우
                else if (vh < 0)
                {
                    // 주머니에서 블럭 심고 시간 증가
                    vh *= -1;
                    blocks -= vh;
                    sec += vh;
                }
            }

        // 이번 높이가 불가능할 경우였으면 중단
        if (blocks < 0)
            break;

        // 시간이 더 짧거나, 시간이 같으면서 높이가 높을 경우 업데이트
        if (sec < ans.first || (sec == ans.first && h > ans.second))
            ans = {sec, h};
    }

    /* Output */
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}