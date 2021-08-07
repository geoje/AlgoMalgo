#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> map; // first: weight, second: index
vector<int> ans;

const int INF = 10000000;
int v, e, k;

void dijkstra()
{
    ans[k] = 0; // v1에서 v1으로 가는 가중치는 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ans[k], k}); // v1 에서 v1으로 가는 가중치는 0
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        // 자신과 인접한 점들을 모두 입력
        for (auto next : map[current.second])
        {
            // 내가 가진 가중치로 다음 점까지
            // 가중치를 계산했을 때 최소이면 갱신
            int newWeight = next.first + current.first;
            if (newWeight < ans[next.second])
            {
                ans[next.second] = newWeight; // 정답 갱신
                pq.push({newWeight, next.second});
            }
        }
    }
}

int main()
{
    // Input
    cin >> v >> e >> k;
    map.assign(v + 1, vector<pair<int, int>>(0));
    ans.assign(v + 1, INF);

    int t, u, w;
    for (int i = 1; i <= e; i++)
    {
        cin >> t >> u >> w;
        map[t].push_back({w, u});
    }

    // Process
    dijkstra();

    // Output
    for (int i = 1; i <= v; i++)
        if (ans[i] == INF)
            cout << "INF\n";
        else
            cout << ans[i] << "\n";

    return 0;
}