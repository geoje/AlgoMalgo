#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 4e7;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;

    // Init
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        cost[i][i] = 0;

    // Reflect fares
    for (auto &fare : fares)
    {
        cost[fare[0]][fare[1]] = fare[2];
        cost[fare[1]][fare[0]] = fare[2];
    }

    // Floyd Warshall
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];

    // Process
    for (int i = 1; i <= n; i++)
        if (cost[s][i] + cost[i][a] + cost[i][b] < answer)
            answer = cost[s][i] + cost[i][a] + cost[i][b];

    return answer;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cout << solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << '\n';
    cout << solution(7, 3, 4, 1, {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << '\n';
    cout << solution(6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}}) << '\n';
    return 0;
}