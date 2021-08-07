// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m;
int sum[1025][1025] = {
    0,
}; // x행, y열

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    int num;
    cin >> n >> m;
    for (int i = 1, rSum = 0; i <= n; i++, rSum = 0)
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            rSum += num;
            sum[i][j] = sum[i - 1][j] + rSum;
        }

    // Input & Process & Output
    int x1, y1, x2, y2, ans;
    for (int k = 0; k < m; k++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        ans = sum[x2][y2];
        if (x1 > 1)
            ans -= sum[x1 - 1][y2];
        if (y1 > 1)
            ans -= sum[x2][y1 - 1];
        if (x1 > 1 && y1 > 1)
            ans += sum[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }
    return 0;
}