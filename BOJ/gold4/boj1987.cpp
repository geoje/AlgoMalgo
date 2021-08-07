#include <iostream>
#include <queue>
using namespace std;

int r, c;
// ...[0]: 실제 맵의 문자
// ...[1]: 방문 여부
char map[20][20][2];
const pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string text;

int move(int row, int col)
{
    // 내 위치 문자 추가 후 방문했다고 표시
    text.push_back(map[row][col][0]);
    map[row][col][1] = true;

    // 동서남북 방향으로 새로운 탐색 추가
    int best = text.length();
    for (auto dir : dirs)
    {
        // 방문할 위치 계산
        int nextRow = row + dir.first,
            nextCol = col + dir.second;

        // 내 위치가 맵 밖이라면 탐색 안함
        if (nextRow < 0 || nextCol < 0 || nextRow >= r || nextCol >= c)
            continue;

        // 다음 방문할 곳이 방문을 안한 곳이고 탐색 가능한 문자가 있으면 탐색
        if (!map[nextRow][nextCol][1] && text.find(map[nextRow][nextCol]) == string::npos)
            best = max(best, move(nextRow, nextCol));
    }

    // 방문했다는거 제거 후 리턴
    map[row][col][1] = false;
    text.pop_back();
    return best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> map[i][j][0];

    // Process & Output
    cout << move(0, 0) << '\n';
    return 0;
}