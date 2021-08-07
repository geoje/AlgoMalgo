// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 100000000;
int n, m, map[101][101];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    fill(&map[1][1], &map[n][n], INF);
    for (int i = 1; i <= n; i++)
        map[i][i] = 0;
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (c < map[a][b])
            map[a][b] = c;
    }

    // Process
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != k && j != k && i != j)
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

    // Output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (map[i][j] == INF ? 0 : map[i][j]) << ' ';
        cout << '\n';
    }
    return 0;
}