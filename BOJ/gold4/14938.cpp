// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 1e9;
int n, m, r, ans = 0;
int items[101], map[101][101];

void FloydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
}

void KwangwoonGround()
{
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            if (map[i][j] <= m)
                sum += items[j];
        if (sum > ans)
            ans = sum;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    fill_n(&map[0][0], 101 * 101, INF);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i];
        map[i][i] = 0;
    }

    int a, b, c;
    while (r--)
    {
        cin >> a >> b >> c;
        map[a][b] = map[b][a] = c;
    }

    // Process
    FloydWarshall();
    KwangwoonGround();

    // Output
    cout << ans << '\n';
    return 0;
}