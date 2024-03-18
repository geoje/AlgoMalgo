// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, k, last;
vector<int> cost, dp;
vector<vector<int>> road;

int build(int cur)
{
    // 메모이제이션
    if (dp[cur] != -1)
        return dp[cur];

    // 연결된 이전 건물 중 가장 최적 시간 에 내 건설시간 추가해서 리턴
    int result = 0;
    for (int prev : road[cur])
        result = max(result, build(prev));
    return dp[cur] = cost[cur] + result;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    int t;
    cin >> t;
    while (t--)
    {
        /* Input */
        // 건물 및 도로 수 입력
        cin >> n >> k;
        cost.assign(n + 1, 0);
        dp.assign(n + 1, -1);
        road.assign(n + 1, vector<int>(0));

        // 건설 시간 입력
        for (int i = 1; i <= n; i++)
            cin >> cost[i];

        // 도로 입력
        int a, b;
        for (int i = 1; i <= k; i++)
        {
            cin >> a >> b;
            road[b].push_back(a);
        }

        // 마지막 건물 번호 입력
        cin >> last;

        /* Process & Output */
        cout << build(last) << '\n';
    }
    return 0;
}