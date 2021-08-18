#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

const int INF = 2e9;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps)
{
    // 정답 보관 // dist[pos][status]
    const int maxStatus = 2 << traps.size();
    int answer = INF;
    vector<vector<int>> dist;
    dist.assign(n + 1, vector<int>(maxStatus, INF));
    dist[start][0] = 0;

    // 트랩의 인덱싱 (나중에 찾을 때 시간복잡도 1을 위한 것)
    map<int, int> trapIdx;
    for (int i = 0; i < traps.size(); i++)
        trapIdx[traps[i]] = i + 1;

    // 길 입력 // cost, dest, forward
    vector<vector<tuple<int, int, bool>>> buses(n + 1);
    for (auto road : roads)
    {
        buses[road[0]].push_back({road[2], road[1], true});  // 가는 버스 넣기
        buses[road[1]].push_back({road[2], road[0], false}); // 오는 버스 넣기
    }

    // 방문 여부 // dist[pos][status]
    vector<vector<bool>> visited;
    visited.assign(n + 1, vector<bool>(maxStatus));

    // 모든 노드 탐색 // cost, status, pos
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, start});
    while (!pq.empty())
    {
        int cost[2], u, v, status;
        bool forward;
        tie(cost[0], status, u) = pq.top();
        pq.pop();

        // 방문 여부 확인
        if (visited[u][status])
            continue;
        visited[u][status] = true;

        // 현재 좌표의 모든 버스 보기
        for (auto bus : buses[u])
        {
            tie(cost[1], v, forward) = bus;
            bool inverse = (status & (1 << trapIdx[u])) > 0 != (status & (1 << trapIdx[v])) > 0;
            // 통행 가능 할 경우
            if (inverse != forward)
                // 비용 갱신이 가능할 경우
                if (cost[0] + cost[1] < dist[v][status])
                {
                    dist[v][status] = cost[0] + cost[1];
                    pq.push({dist[v][status], trapIdx[v] ? status ^ (1 << trapIdx[v]) : status, v});
                }
        }
    }

    // 정답 도출
    for (int i = maxStatus - 1; i >= 0; i--)
        if (dist[end][i] < answer)
            answer = dist[end][i];

    return answer;
}

int main()
{
    cout << solution(3, 1, 3, {{1, 2, 2}, {3, 2, 3}}, {2}) << '\n';
    cout << solution(4, 1, 4, {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}}, vector<int>{2, 3}) << '\n';
    return 0;
}