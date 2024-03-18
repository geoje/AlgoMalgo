#include <iostream>
#include <vector>
using namespace std;

const vector<vector<vector<int>>> tetrominos = {
    {{1, 1, 1, 1}}, // 1-1
    {{1},
     {1},
     {1},
     {1}}, // 1-2
    {{1, 1},
     {1, 1}}, // 2
    {{1, 0},
     {1, 0},
     {1, 1}}, // 3-1
    {{0, 1},
     {0, 1},
     {1, 1}}, // 3-2
    {{1, 1},
     {1, 0},
     {1, 0}}, // 3-3
    {{1, 1},
     {0, 1},
     {0, 1}}, // 3-4
    {{0, 0, 1},
     {1, 1, 1}}, // 3-5
    {{1, 1, 1},
     {0, 0, 1}}, // 3-6
    {{1, 1, 1},
     {1, 0, 0}}, // 3-7
    {{1, 0, 0},
     {1, 1, 1}}, // 3-8
    {{1, 0},
     {1, 1},
     {0, 1}}, // 4-1
    {{0, 1},
     {1, 1},
     {1, 0}}, // 4-2
    {{1, 1, 0},
     {0, 1, 1}}, // 4-3
    {{0, 1, 1},
     {1, 1, 0}}, // 4-4
    {{1, 0},
     {1, 1},
     {1, 0}}, // 5-1
    {{0, 1},
     {1, 1},
     {0, 1}}, // 5-2
    {{1, 1, 1},
     {0, 1, 0}}, // 5-3
    {{0, 1, 0},
     {1, 1, 1}}, // 5-4
};
int n, m, map[500][500];

int solve()
{
    int answer = 0;

    for (auto mino : tetrominos)
        for (int i = n - mino.size(); i >= 0; i--)
            for (int j = m - mino[0].size(); j >= 0; j--)
            {
                int sum = 0;
                for (int di = 0; di < mino.size(); di++)
                    for (int dj = 0; dj < mino[0].size(); dj++)
                        if (mino[di][dj])
                            sum += map[i + di][j + dj];

                if (sum > answer)
                    answer = sum;
            }

    return answer;
}
int main()
{
    // Input
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    // Process & Output
    cout << solve();
    return 0;
}