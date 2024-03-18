#include <cstdio> // For Test
#include <iostream>
using namespace std;

long long n, k, ans = 1;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> k;

    /* Process */
    if (k > n / 2)
        k = n - k;

    for (int i = 0; i < k; i++)
        ans *= n - i;

    for (int i = 1; i <= k; i++)
        ans /= i;

    /* Output */
    cout << ans << '\n';
    return 0;
}