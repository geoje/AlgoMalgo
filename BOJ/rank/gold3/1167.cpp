// #include <cstdio> // For Test
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, ans = 0;
vector<pair<int, int>> tree[100001]; // first: destination, second: length
bool visited[100001] = {0};

int dfs(int idx)
{
    visited[idx] = true;

    priority_queue<int> values;
    for (auto node : tree[idx])
        if (!visited[node.first])
            values.push(node.second + dfs(node.first));

    int longest[2] = {0};
    for (int i = 0; i < 2 && !values.empty(); i++)
    {
        longest[i] = values.top();
        values.pop();
    }

    if (longest[0] + longest[1] > ans)
        ans = longest[0] + longest[1];

    visited[idx] = false;
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
    int a, b = 0, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        while (b != -1)
        {
            cin >> c;
            tree[a].push_back({b, c});
            cin >> b;
        }
    }

    // Process
    dfs(1);

    // Output
    cout << ans << '\n';
    return 0;
}