#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

ll countBits(ll n)
{
    n++;
    ll res = 0;

    for (ll i = 1; i < n; i *= 2)
    {
        ll q = n / i, r = n % i;
        res += (q / 2) * i;
        if (q % 2)
            res += r;
    }

    return res;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> a >> b;

    /* Process & Output */
    cout << countBits(b) - countBits(a - 1) << '\n';
    return 0;
}