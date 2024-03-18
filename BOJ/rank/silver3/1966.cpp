#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, m;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    int t, imp;
    cin >> t;

    while (t--)
    {
        /* Init */
        int ans = 1;
        queue<pii> q;
        priority_queue<int> pq;

        /* Input */
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> imp;
            q.push({imp, i});
            pq.push(imp);
        }

        /* Process & Output */
        while (!q.empty())
        {
            while (q.front().first < pq.top())
            {
                q.push(q.front());
                q.pop();
            }

            if (q.front().second == m)
                break;

            q.pop();
            pq.pop();

            ans++;
        }

        /* Output */
        cout << ans << '\n';
    }
    return 0;
}