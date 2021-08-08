// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct bus
{
    int cost, dest;
};
struct node
{
    int cost, pos;
    vector<int> waypoint;
};
struct compare
{
    bool operator()(node const &a, node const &b)
    {
        // if (a.cost == b.cost)
        // {
        //     if (a.waypoint.size() == b.waypoint.size())
        //     {
        //         for (int i = 0; i < a.waypoint.size(); i++)
        //         {
        //             if (a.waypoint[i] == b.waypoint[i])
        //                 continue;
        //             return a.waypoint[i] > b.waypoint[i];
        //         }
        //         return true;
        //     }
        //     else
        //         return a.waypoint.size() > b.waypoint.size();
        // }
        // else
        return a.cost > b.cost;
    }
};

int n,
    start, dest;
node ans;
bool visited[1001] = {0};
vector<vector<bus>> buses;
priority_queue<node, vector<node>, compare> nodes;

void dijkstra()
{
    nodes.push({0, start, {start}});
    while (!nodes.empty())
    {
        auto nd = nodes.top();
        nodes.pop();

        // 방문 했을 경우 패스
        if (visited[nd.pos])
            continue;
        visited[nd.pos] = true;

        // 목적지에 도착했을 경우
        if (nd.pos == dest)
        {
            ans = nd;
            break;
        }

        // 현재 좌표의 모든 버스를 타고 목적지와 비용 갱신한 노드 추가
        for (auto bus : buses[nd.pos])
        {
            node newNode = {nd.cost + bus.cost, bus.dest};
            newNode.waypoint.assign(nd.waypoint.begin(), nd.waypoint.end());
            newNode.waypoint.push_back(bus.dest);
            nodes.push(newNode);
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    int m;
    cin >> n >> m;
    buses.resize(n + 1);

    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        buses[a].push_back({c, b});
    }
    cin >> start >> dest;

    // Process
    dijkstra();

    // Output
    cout << ans.cost << '\n'
         << ans.waypoint.size() << '\n';
    for (int p : ans.waypoint)
        cout << p << ' ';
    cout << '\n';
    return 0;
}