#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    int r, c, ans;

    for (auto place : places) // 모든 입력
    {
        ans = 1;
        for (int i = 0; i < 5; i++)        // 모든 y 위치
            for (int j = 0; j < 5; j++)    // 모든 x 위치
                if (place[i][j] == 'P')    // x, y 위치에 사람일 경우
                    for (auto dir1 : dirs) // 방향 한 곳을 보고
                    {
                        r = i + dir1.first;
                        c = j + dir1.second;
                        if (r < 0 || c < 0 || r >= 5 || c >= 5 || place[r][c] == 'X') // 맵 밖이거나 벽이면 패스
                            continue;

                        if (place[r][c] == 'P') // 사람일 경우 확진 판정
                        {
                            ans = 0;
                            goto FINISH;
                        }
                        for (auto dir2 : dirs) // 다음 방향 보기
                        {
                            r = i + dir1.first + dir2.first;
                            c = j + dir1.second + dir2.second;
                            if (r == i && c == j) // 뒤로 돌아갈 경우 패스
                                continue;
                            if (r < 0 || c < 0 || r >= 5 || c >= 5 || place[r][c] == 'X') // 맵 밖이거나 벽이면 패스
                                continue;

                            if (place[r][c] == 'P') // 사람일 경우 확진 판정
                            {
                                ans = 0;
                                goto FINISH;
                            }
                        }
                    }
    FINISH:
        answer.push_back(ans);
    }

    return answer;
}

int main()
{
    vector<int> result = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                   {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                   {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                   {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                   {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});

    for (int n : result)
        cout << n << ' ';
    cout << '\n';
}