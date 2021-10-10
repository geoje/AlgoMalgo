#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef long long ll;

ll n, r = 1, ans = 0;
const ll m = 1234567891;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process */
    char c;
    cin >> n;
    while (n--)
    {
        cin >> c;
        ans = (ans + (c - 'a' + 1) * r) % m;
        r = (r * 31) % m;
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}