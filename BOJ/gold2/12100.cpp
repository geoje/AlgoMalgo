// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, answer = 0;

void game(int (*board)[21], int count, int dir)
{
    // 상
    if (dir == 1)
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1, si = 2; si <= n;)
            {
                // 서칭 위치 찾기
                while (i == si || (si <= n && board[si][j] == 0))
                    si++;

                // 서칭 위치가 범위 밖이면 탐색 종료
                if (si > n)
                    break;

                // 내 위치가 0일 경우 그냥 땡겨 오기
                if (board[i][j] == 0)
                {
                    answer = max(answer, board[i][j] = board[si][j]);
                    board[si][j] = 0;
                }
                // 내 위치에 숫자가 있고
                else
                {
                    // 서칭 위치 수랑 같을 경우 합치기
                    if (board[i][j] == board[si][j])
                    {
                        answer = max(answer, board[i][j] *= 2);
                        board[si++][j] = 0;
                    }
                    i++;
                }
            }
        }

    // 하
    else if (dir == 2)
        for (int j = 1; j <= n; j++)
        {
            for (int i = n, si = n - 1; si >= 1;)
            {
                // 서칭 위치 찾기
                while (i == si || (si >= 1 && board[si][j] == 0))
                    si--;

                // 서칭 위치가 범위 밖이면 탐색 종료
                if (si < 1)
                    break;

                // 내 위치가 0일 경우 그냥 땡겨 오기
                if (board[i][j] == 0)
                {
                    answer = max(answer, board[i][j] = board[si][j]);
                    board[si][j] = 0;
                }
                // 내 위치에 숫자가 있고
                else
                {
                    // 서칭 위치 수랑 같을 경우 합치기
                    if (board[i][j] == board[si][j])
                    {
                        answer = max(answer, board[i][j] *= 2);
                        board[si--][j] = 0;
                    }
                    i--;
                }
            }
        }

    // 좌
    if (dir == 3)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1, sj = 2; sj <= n;)
            {
                // 서칭 위치 찾기
                while (j == sj || (sj <= n && board[i][sj] == 0))
                    sj++;

                // 서칭 위치가 범위 밖이면 탐색 종료
                if (sj > n)
                    break;

                // 내 위치가 0일 경우 그냥 땡겨 오기
                if (board[i][j] == 0)
                {
                    answer = max(answer, board[i][j] = board[i][sj]);
                    board[i][sj] = 0;
                }
                // 내 위치에 숫자가 있고
                else
                {
                    // 서칭 위치 수랑 같을 경우 합치기
                    if (board[i][j] == board[i][sj])
                    {
                        answer = max(answer, board[i][j] *= 2);
                        board[i][sj++] = 0;
                    }
                    j++;
                }
            }
        }

    // 우
    else if (dir == 4)
        for (int i = 1; i <= n; i++)
        {
            for (int j = n, sj = n - 1; sj >= 1;)
            {
                // 서칭 위치 찾기
                while (j == sj || (sj >= 1 && board[i][sj] == 0))
                    sj--;

                // 서칭 위치가 범위 밖이면 탐색 종료
                if (sj < 1)
                    break;

                // 내 위치가 0일 경우 그냥 땡겨 오기
                if (board[i][j] == 0)
                {
                    answer = max(answer, board[i][j] = board[i][sj]);
                    board[i][sj] = 0;
                }
                // 내 위치에 숫자가 있고
                else
                {
                    // 서칭 위치 수랑 같을 경우 합치기
                    if (board[i][j] == board[i][sj])
                    {
                        answer = max(answer, board[i][j] *= 2);
                        board[i][sj--] = 0;
                    }
                    j--;
                }
            }
        }

    // 보드 테스트
    // cout << "[ " << count << " " << dir << " ]\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << board[i][j] << " ";
    //     cout << '\n';
    // }
    // cout << '\n';

    // 다음 4방향 탐색 5번 까지
    if (++count < 5)
        for (int i = 1; i <= 4; i++)
        {
            int nboard[n + 1][21];
            copy(&board[1][1], &board[n][n] + 1, &nboard[1][1]);
            game(nboard, count, i);
        }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;
    int board[n + 1][21];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    // Process
    if (n == 1)
        answer = board[1][1];
    else
        for (int i = 1; i <= 4; i++)
        {
            int nboard[n + 1][21];
            copy(&board[1][1], &board[n][n] + 1, &nboard[1][1]);
            game(nboard, 0, i);
        }

    // Output
    cout << answer << '\n';
    return 0;
}