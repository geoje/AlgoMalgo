// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

const int INF = 1000000000;
int n, m, w;

struct edge
{
    int start, end, time;
};

vector<edge> edges;
vector<int> dist;

bool BellmanFord()
{
    dist[1] = 0;

    // vertex * edge 번의 반복을 돌아 최적의 경로 구하기
    for (int v = 1; v <= n; v++)
        for (auto e : edges)
        {
            // 이걸 주석처리 안해서 14%에서 틀렸었다.
            // if (dist[e.start] == INF)
            //     continue;
            dist[e.end] = min(dist[e.end], dist[e.start] + e.time);
        }

    // 연산이 끝났고 음의 사이클 체크
    for (auto e : edges)
    {
        // 이걸 주석처리 안해서 7%에서 틀렸었다.
        // if (dist[e.start] == INF)
        //     continue;
        if (dist[e.start] + e.time < dist[e.end])
            return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    int tc, s, e, t;
    cin >> tc;

    for (; tc > 0; tc--)
    {
        // Input
        cin >> n >> m >> w;
        dist.assign(n + 1, INF);
        edges.resize(n + 1);
        edges.clear();

        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        // Process & Output
        cout << (BellmanFord() ? "YES\n" : "NO\n");
    }
    return 0;
}