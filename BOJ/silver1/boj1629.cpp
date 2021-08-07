// #include <cstdio> // For Test
#include <iostream>
using namespace std;

typedef long long ll;

ll mod(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;
    if (b % 2)
    {
        return mod(a, b / 2 + 1, c) * mod(a, b / 2, c) % c;
    }
    else
    {
        ll res = mod(a, b / 2, c);
        return res * res % c;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    ll a, b, c;
    cin >> a >> b >> c;

    // Process & Output
    cout << mod(a, b, c) << '\n';
    return 0;
}