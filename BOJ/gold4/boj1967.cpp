// #include <cstdio> // For Test
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n, ans = 0;
vector<pair<int, int>> tree[10001]; // first: node_num, second: weight

int dfs(int idx)
{
    priority_queue<int> values;
    for (auto node : tree[idx])
        values.push(node.second + dfs(node.first));

    // 자식들끼리 늘렸을 때 가장 긴지 체크 후 갱신
    int longest[2] = {0};
    for (int i = 0; i < 2 && values.size(); i++)
    {
        longest[i] = values.top();
        values.pop();
    }
    if (longest[0] + longest[1] > ans)
        ans = longest[0] + longest[1];

    // 체크 후엔 자식들 중 가잔 긴 것 반환
    return longest[0];
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;
    int a, b, c;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
    }

    // Process
    dfs(1);

    // Output
    cout << ans << '\n';
    return 0;
}