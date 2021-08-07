#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

// map // 0: 내부, 1: 치즈, 2: 외부
int n, m, map[101][101] = {0};
queue<pair<int, int>> melt, nodes;
bool visited[101][101] = {0};

const pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void spread(int r, int c, int type)
{
    nodes.push({r, c});
    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();

        // 이미 방문 한 경우 패스
        if (visited[node.first][node.second])
            continue;

        // 방문 및 확산 표시
        visited[node.first][node.second] = true;
        map[node.first][node.second] = type;

        // 주변에 탐색 안된 부분 추가
        for (auto dir : dirs)
        {
            r = node.first + dir.first;
            c = node.second + dir.second;
            if (!map[r][c])
                nodes.push({r, c});
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    // Process
    // 테두리를 둘러보며 치즈가 없으면 연결된 곳을 전부 외부로 지정
    for (int i = 1; i <= n; i++)
    {
        if (!map[i][1]) // 위
            spread(i, 1, 2);
        if (!map[i][n]) // 아래
            spread(i, n, 2);
    }
    for (int j = 2; j < m; j++)
    {
        if (!map[1][j]) // 좌
            spread(1, j, 2);
        if (!map[n][j]) // 우
            spread(n, j, 2);
    }

    // Output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}