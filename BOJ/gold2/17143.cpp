// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

struct shark
{
    // row, col, speed, direction, size
    int r, c, s, d, z;
    bool die = false;
};

const pair<int, int> dirs[5] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int r, c, m, ans = 0;
// [0]: 짝수초, [1]: 홀수초
vector<vector<int>> map[2];
vector<shark> sharks;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int rr, cc, s, d, z;
    cin >> r >> c >> m;
    map[0].assign(r + 1, vector<int>(c + 1, -1));

    for (int i = 0; i < m; i++)
    {
        cin >> rr >> cc >> s >> d >> z;
        // 쓸모없는 왕복을 막기 위해 상어 속도를 줄인다.
        if (d <= 2)
            s %= (r - 1) * 2;
        else
            s %= (c - 1) * 2;
        sharks.push_back({rr, cc, s, d, z});

        map[0][rr][cc] = i;
    }

    /* Process */
    for (cc = 1; cc <= c; cc++)
    {
        // cc는 사람의 열 위치와 지난 시간을 같이 의미함
        auto &curMap = map[cc & 1], &prevMap = map[~cc & 1];

        // Debug Output
        // cout << "[Time " << cc - 1 << "]\n";
        // for (int i = 1; i <= r; i++)
        // {

        //     for (int j = 1; j <= c; j++)
        //         cout << prevMap[i][j] << '\t';
        //     cout << '\n';
        // }
        // cout << '\n';

        // 사람 이동 후 상어 잡기 // prevMap
        for (rr = 0; rr <= r; rr++)
            if (prevMap[rr][cc] != -1)
            {
                shark &sk = sharks[prevMap[rr][cc]];

                // 잡은 크기 정답에 더해주고
                ans += sk.z;
                // 상어는 이동하지 않도록 죽은걸로 표시
                sk.die = true;
                // 상어 잡기는 한번만 수행
                break;
            }

        // 상어들 이동 // curMap
        curMap.assign(r + 1, vector<int>(c + 1, -1));
        for (int i = 0; i < m; i++)
        {
            shark &sk = sharks[i];

            // 죽은 상어일 경우 패스
            if (sk.die)
                continue;

            s = sk.s;
            while (s--)
            {
                // 움직이기 전 벽일 경우 방향 전환
                if (sk.d == 1 && sk.r == 1)
                    sk.d = 2;
                if (sk.d == 2 && sk.r == r)
                    sk.d = 1;
                if (sk.d == 3 && sk.c == c)
                    sk.d = 4;
                if (sk.d == 4 && sk.c == 1)
                    sk.d = 3;

                // 한칸 이동
                sk.r += dirs[sk.d].first;
                sk.c += dirs[sk.d].second;
            }

            // 움직인 후 해당 위치에 상어 없으면 상어 두기
            if (curMap[sk.r][sk.c] == -1)
                curMap[sk.r][sk.c] = i;
            // 움직인 후 해당 위치에 상어가 있을 경우 냠냠
            else
            {
                shark &psk = sharks[curMap[sk.r][sk.c]];
                // 새로 움직인 상어가 더 클 경우
                if (sk.z > psk.z)
                {
                    psk.die = true;
                    curMap[sk.r][sk.c] = i;
                }
                // 기존 상어가 더 클 경우
                else
                    sk.die = true;
            }
        }
    }

    // Debug Output
    // cout << "[Time " << c << "]\n";
    // for (int i = 1; i <= r; i++)
    // {

    //     for (int j = 1; j <= c; j++)
    //         cout << map[c & 1][i][j] << '\t';
    //     cout << '\n';
    // }
    // cout << '\n';

    /* Output */
    cout << ans << '\n';
    return 0;
}