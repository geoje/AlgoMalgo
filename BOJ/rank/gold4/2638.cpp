// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// map // 0: 내부, 1: 치즈, 2: 외부
int n, m, hour = 0, map[101][101] = {0};
queue<pair<int, int>> nodes;
vector<pair<int, int>> melt, cheese;
bool visited[101][101] = {0};

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

            // 다음 좌표가 맵 안 이고 내부라 했을 경우
            if (r >= 1 && c >= 1 && r <= n && c <= m && map[r][c] == 0)
                nodes.push({r, c});
        }
    }
    // 방문 초기화
    fill_n(&visited[0][0], 101 * 101, 0);
}
int surround(int r, int c)
{
    int result = 0;
    for (auto dir : dirs)
    {
        int nr = r + dir.first;
        int nc = c + dir.second;

        // 다음 좌표가 맵 안 이고 내부라 했을 경우
        if (nr >= 1 && nc >= 1 && nr <= n && nc <= m && map[nr][nc] == 2)
            result++;
    }
    return result;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j])
                cheese.push_back({i, j});
        }

    // Process
    // 테두리를 둘러보며 치즈가 없으면 연결된 곳을 전부 외부로 지정
    for (int i = 1; i <= n; i++)
    {
        if (map[i][1] == 0) // 위
            spread(i, 1, 2);
        if (map[i][n] == 0) // 아래
            spread(i, n, 2);
    }
    for (int j = 2; j < m; j++)
    {
        if (map[1][j] == 0) // 좌
            spread(1, j, 2);
        if (map[n][j] == 0) // 우
            spread(n, j, 2);
    }

    // 치즈가 있을 경우 시간을 흐른다.
    while (!cheese.empty())
    {
        // 녹는거 진행
        for (int i = cheese.size() - 1; i >= 0; i--)
        {
            // 외부 접촉이 2 이상 일 경우
            if (surround(cheese[i].first, cheese[i].second) >= 2)
            {
                melt.push_back(cheese[i]);
                map[cheese[i].first][cheese[i].second] = 0;
                cheese.erase(cheese.begin() + i);
            }
        }

        // 녹은 부분 공기 확산
        for (auto p : melt)
            if (!map[p.first][p.second])
                spread(p.first, p.second, 2);

        // 시간 추가
        hour++;
    }

    // Output
    cout << hour << '\n';
    return 0;
}