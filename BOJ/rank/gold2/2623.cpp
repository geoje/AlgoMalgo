#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int n, m, inDegree[1001] = {0};
vector<vector<int>> seq;
queue<int> q, ans;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int a, b, c;
    cin >> n >> m;
    seq.resize(n + 1);
    while (m--)
    {
        cin >> a >> b;
        while (--a)
        {
            cin >> c;
            seq[b].push_back(c);
            inDegree[c]++;

            b = c;
        }
    }

    /* Process */
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push(cur);

        for (int next : seq[cur])
            if (--inDegree[next] == 0)
                q.push(next);
    }

    /* Output */
    if (ans.size() < n)
        cout << "0\n";
    else
        for (; !ans.empty(); ans.pop())
            cout << ans.front() << '\n';
    return 0;
}