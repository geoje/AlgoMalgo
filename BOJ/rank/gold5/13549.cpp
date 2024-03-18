// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int n, k, ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes; // first: time, second: position
bool visited[100001] = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> k;

    // Process
    nodes.push({0, n});
    while (!nodes.empty())
    {
        auto node = nodes.top();
        nodes.pop();

        // 이미 방문 했다면 체크 안함
        if (visited[node.second])
            continue;

        // 도착 했다면 종료
        if (k == node.second)
        {
            ans = node.first;
            break;
        }

        // 방문 표시
        visited[node.second] = true;

        // 좌측 이동
        if (node.second > 0)
            nodes.push({node.first + 1, node.second - 1});
        // 우측 이동
        if (node.second < 100000)
            nodes.push({node.first + 1, node.second + 1});
        // 순간 이동
        if (node.second < k && node.second <= 50000)
            nodes.push({node.first, node.second * 2});
    }

    // Output
    cout << ans << '\n';
    return 0;
}