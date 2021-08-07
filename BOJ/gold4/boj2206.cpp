// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

struct node
{
    int x, y, b;
};
int dir[4][2] = {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n, m;
char map[1001][1001];
// [0]...: 부수기 전 방문 여부
// [1]...: 부순 후 방문 여부
int dist[2][1001][1001] = {0};
queue<node> q;

int bfs()
{
    dist[0][1][1] = 1;
    q.push({1, 1, false});
    while (!q.empty())
    {
        node nd = q.front();
        q.pop();

        if (nd.y == n && nd.x == m)
            return dist[nd.b][nd.y][nd.x];

        for (int i = 0; i < 4; i++)
        {
            bool b = nd.b;
            int dy = nd.y + dir[i][0];
            int dx = nd.x + dir[i][1];

            if (dy >= 1 && dx >= 1 && dy <= n && dx <= m && !dist[b][dy][dx])
            {
                if (map[dy][dx] == '1')
                {
                    if (b)
                        continue;
                    b = 1;
                }
                dist[b][dy][dx] = dist[nd.b][nd.y][nd.x] + 1;
                q.push({dx, dy, b});
            }
        }
    }
    return -1;
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
            cin >> map[i][j];

    // Process & Output
    cout << bfs() << '\n';
    return 0;
}