// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int n, inDegree[32001] = {0};
vector<int> infos[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int m, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        infos[a].push_back(b);
        inDegree[b]++;
    }

    /* Process & Output */
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        cout << x << ' ';

        for (int next : infos[x])
            if (--inDegree[next] == 0)
                pq.push(next);
    }
    cout << '\n';
    return 0;
}