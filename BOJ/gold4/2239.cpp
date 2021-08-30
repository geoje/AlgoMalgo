#include <cstdio> // For Test
#include <iostream>
using namespace std;

// placed[row][col]
char map[9][9];
bool solved = false;

bool promising(int r, int c, char n)
{
    int mr = r / 3 * 3 + 3;
    int mc = c / 3 * 3 + 3;

    for (int i = mr - 3; i < mr; i++)
        for (int j = mc - 3; j < mc; j++)
            if (map[i][j] == n)
                return false;

    for (int i = 0; i < 9; i++)
    {
        if (map[i][c] == n)
            return false;
        if (map[r][i] == n)
            return false;
    }
    return true;
}

void sudoku(int r, int c)
{
    // 다음 위치를 탐색할 수 있도록 위치 갱신
    if (c >= 9)
    {
        r++;
        c = 0;

        // 마지막 탐색 이었으면 보드에 0 이 없을 때 해결됨
        if (r >= 9)
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    if (map[i][j] == '0')
                        return;
            solved = true;
            return;
        }
    }

    // 입력 때 이미 놓여진 경우 다음으로 패스
    if (map[r][c] != '0')
    {
        sudoku(r, c + 1);
        return;
    }

    // 숫자 1부터 9를 해결 될 때 까지 탐색
    for (char n = '1'; n <= '9'; n++)
        if (promising(r, c, n))
        {
            // 해당 자리에 n을 입력하고
            map[r][c] = n;

            // 다음 경우를 탐색
            sudoku(r, c + 1);

            // 해결 되었을 경우 탐색 종료
            if (solved)
                return;
        }
    map[r][c] = '0';
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    char c;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> map[i][j];

    /* Process */
    sudoku(0, 0);

    /* Output */
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << map[i][j];
        cout << '\n';
    }
    return 0;
}