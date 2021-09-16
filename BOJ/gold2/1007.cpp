#include <cstdio> // For Test
#include <cmath>
#include <iostream>
using namespace std;

int n;
pair<int, int> p[20];

double ans = 2e6;

// i: 번째, x: 현재까지 x값, y: 현재까지 y값, plus: 더해진 횟수, minus: 빼진 횟수
void dfs(int i, double x, double y, int plus, int minus)
{
    if (i == n)
    {
        double res = sqrt(x * x + y * y);
        if (res < ans)
            ans = res;
        return;
    }

    if (plus < n / 2)
        dfs(i + 1, x + p[i].first, y + p[i].second, plus + 1, minus);
    if (minus < n / 2)
        dfs(i + 1, x - p[i].first, y - p[i].second, plus, minus + 1);
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    int tc;
    cin >> tc;
    while (tc--)
    {
        /* Input */
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i].first >> p[i].second;

        /* Process */
        dfs(0, 0, 0, 0, 0);

        /* Output */
        cout << fixed << ans << '\n';
        ans = 2e6;
    }
    return 0;
}