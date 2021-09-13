#include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll liquid[5000];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> liquid[i];
    sort(liquid, liquid + n);

    /* Process */
    ll result = 3e9, sum, ans[3];

    for (int p1 = 0; p1 < n - 2; p1++)
    {
        int p2 = p1 + 1;
        int p3 = n - 1;
        while (p2 < p3)
        {
            sum = liquid[p1] + liquid[p2] + liquid[p3];
            if (abs(sum) < abs(result))
            {
                result = sum;
                ans[0] = liquid[p1];
                ans[1] = liquid[p2];
                ans[2] = liquid[p3];
            }
            if (sum >= 0)
                p3--;
            else
                p2++;
        }
    }
    sort(ans, ans + 3);

    /* Output */
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}