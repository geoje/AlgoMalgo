#include <cstdio> // For Test
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m, parent[1000][1000] = {0}, set = 0;
char map[1000][1000] = {0};
bool visited[1000][1000] = {0};

const pii dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 갈 수 있는 위치들
vector<pii> bfs(int i, int j)
{
    vector<pii> points;
    queue<pii> q;
    q.push({i, j});

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();

        // 방문 또는 벽 여부
        bool &v = visited[p.first][p.second];
        if (v || map[p.first][p.second] == '1')
            continue;
        v = true;

        // 결과에 추가
        points.push_back(p);

        // 다음 지점 상하좌우 입력
        for (pii dir : dirs)
        {
            int ni = p.first + dir.first;
            int nj = p.second + dir.second;

            // 다음 지점 맵 밖이면 패스
            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            q.push({ni, nj});
        }
    }
    return points;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            parent[i][j] = -1;
        }

    /* Process */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '0')
            {
                vector<pii> points = bfs(i, j);
                int size = points.size() % 10;
                for (pii p : points)
                {
                    map[p.first][p.second] = size;
                    // 각 연결 집합마다 고유번호 set을 부여!
                    parent[p.first][p.second] = set;
                }
                set++;
            }

    /* Output */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != '1')
                cout << '0';
            // 현재 위치가 벽이면 주변 영역 전부 더하는 계산하기
            else
            {
                int sum = 1;
                vector<int> vs;
                for (pii dir : dirs)
                {
                    int ni = i + dir.first;
                    int nj = j + dir.second;

                    // 다음 지점 맵 밖이거나 벽일 경우 패스
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || map[ni][nj] == '1')
                        continue;

                    // 이미 방문한 집합일 경우 패스
                    if (find(vs.begin(), vs.end(), parent[ni][nj]) != vs.end())
                        continue;

                    sum += map[ni][nj];
                    vs.push_back(parent[ni][nj]);
                }
                cout << sum % 10;
            }
        }
        cout << '\n';
    }
    return 0;
}