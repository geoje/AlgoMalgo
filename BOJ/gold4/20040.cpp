#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m, parent[500000], ans = 0;

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    /* Process */
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (find(a) == find(b))
        {
            ans = i;
            break;
        }
        else
            parent[find(a)] = find(b);
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}