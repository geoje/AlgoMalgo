#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 시계 방향 90도 회전
vector<vector<int>> rotate(vector<vector<int>> &key)
{
    int n = key.size();
    vector<vector<int>> nkey(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nkey[i][j] = key[n - j - 1][i];

    return nkey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    vector<vector<int>> layer;
    int kn = key.size(), ln = lock.size();
    for (int r = 0; r < 4; r++)
    {
        // 열쇠가 좌물쇠 왼쪽위 한칸 곂치는 곳부터 오른쪽 아래 한칸 곂치게 까지 반복
        for (int ksi = kn - 1; ksi > -ln; ksi--)
            for (int ksj = kn - 1; ksj > -ln; ksj--)
            {
                bool promising = true;
                for (int i = 0, ki = ksi; promising && i < ln; i++, ki++)
                    for (int j = 0, kj = ksj; j < ln; j++, kj++)
                    {
                        // 키랑 곂치는 부분 일경우
                        if (ki >= 0 && kj >= 0 && ki < kn && kj < kn)
                        {
                            // 좌물쇠와 키가 서로 맞물리는게 아니라면 실패
                            if (key[ki][kj] == lock[i][j])
                            {
                                promising = false;
                                break;
                            }
                        }
                        // 키가 곂치지 않으면
                        else
                        {
                            // 좌물쇠가 빈곳일 경우 실패
                            if (lock[i][j] == 0)
                            {
                                promising = false;
                                break;
                            }
                        }
                    }

                if (promising)
                    return true;
            }

        key = rotate(key);
    }

    return false;
}

int main()
{
    cout << solution({{0, 0, 0},
                      {1, 0, 0},
                      {0, 1, 1}},
                     {{1, 1, 1},
                      {1, 1, 0},
                      {1, 0, 1}})
         << '\n';
    return 0;
}