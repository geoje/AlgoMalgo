// #include <cstdio> // For Test
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1e9;
int n, e;
int dist[801];
// bool visited[801];
vector<vector<pair<int, int>>> edges; // first: distance, second: destination
priority_queue<pair<int, int>> nodes;

int dijkstra(int start, int end)
{
    fill_n(dist, n + 1, INF);
    // fill_n(visited, n + 1, false);
    dist[start] = 0;

    nodes.push({0, start});
    while (!nodes.empty())
    {
        auto node = nodes.top();
        nodes.pop();

        // 양방향 크래프에서 다익스트라를 방문 여부로 판단하여 계속 8%에서 틀렸었다.
        // if (visited[node.second])
        // continue;
        // visited[node.second] = true;
        if (dist[node.second] < node.first)
            continue;

        for (auto edge : edges[node.second])
        {
            int newDist = node.first + edge.first;
            if (newDist < dist[edge.second])
            {
                dist[edge.second] = newDist;
                nodes.push({newDist, edge.second});
            }
        }
    }

    return dist[end];
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> e;
    edges.resize(n + 1);

    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }

    int wp1, wp2;
    cin >> wp1 >> wp2;

    // Process
    int result[2][3] = {{dijkstra(1, wp1), dijkstra(wp1, wp2), dijkstra(wp2, n)},
                        {dijkstra(1, wp2), dijkstra(wp2, wp1), dijkstra(wp1, n)}};
    int ans = INF, sum[2] = {0, 0};
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (result[i][j] == INF)
            {
                sum[i] = 0;
                break;
            }
            sum[i] += result[i][j];
        }
        if (sum[i] && sum[i] < ans)
            ans = sum[i];
    }
    if (ans == INF)
        ans = -1;

    // Output
    cout << ans << '\n';
    return 0;
}