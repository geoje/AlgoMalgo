// #include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2100000000;
int n, m, start, dest;

vector<vector<pair<int, int>>> buses; // first: weight, second: destination
vector<int> ans;
vector<bool> visited;

void dijkstra()
{
    ans[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ans[start], start});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        // 버스 도착지가 방문한 곳이면 안 봄
        if (visited[cur.second])
            continue;
        visited[cur.second] = true;

        // 내 버스의 도착지점의 노드에 연결된 모든 노드에 대해 보기
        for (auto next : buses[cur.second])
        {
            // 내가 next를 거쳐 다음 지점으로 가는것이 더 빠를 경우
            int newCost = cur.first + next.first;
            if (newCost < ans[next.second])
            {
                // ans에 업데이트
                ans[next.second] = newCost;
                // 내가 찾은 더 빠른 경로에 대한 가중치를 넣어서 버스 만든 것을 pq에 추가
                pq.push({newCost, next.second});
            }
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    ans.assign(n + 1, INF);
    visited.assign(n + 1, false);
    buses.assign(n + 1, vector<pair<int, int>>(0));
    for (int i = 0; i < m; i++)
    {
        int s, d, c;
        cin >> s >> d >> c;
        buses[s].push_back({c, d});
    }
    cin >> start >> dest;

    // Process
    dijkstra();

    // Output
    cout << ans[dest] << '\n';
    return 0;
}