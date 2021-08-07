// #include <cstdio> // For Test
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1000000000;
int n, m, x;

// [0]: 실제 반대 길(친구집 갈 때), [1]: 실제 길(집 돌아올 때)
int times[2][1001];
// bool visited[1001];
vector<vector<pair<int, int>>> roads[2]; // first: time, second: destination
priority_queue<pair<int, int>> nodes;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m >> x;
    roads[0].resize(n + 1);
    roads[1].resize(n + 1);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        roads[0][b].push_back({c, a});
        roads[1][a].push_back({c, b});
    }

    // Process
    for (int k = 0; k <= 1; k++)
    {
        fill_n(&times[k][0], n + 1, INF);
        // fill_n(visited, n + 1, 0);
        times[k][x] = 0;
        nodes.push({0, x});

        while (!nodes.empty())
        {
            auto node = nodes.top();
            nodes.pop();

            // 방문 여부
            // if (visited[k])
            //     continue;
            // visited[k] = true;

            for (auto road : roads[k][node.second])
            {
                // 현재 node에서 현재 road를 타고 가는 것이 이미 저장되있는 것보다 빠르다면 갱신
                int newTime = node.first + road.first;
                if (newTime < times[k][road.second])
                {
                    times[k][road.second] = newTime;
                    nodes.push({newTime, road.second});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (times[0][i] + times[1][i] > ans)
            ans = times[0][i] + times[1][i];

    // Output
    cout << ans << '\n';
    return 0;
}