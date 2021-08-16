// #include <cstdio> // For Test
#include <iostream>
using namespace std;

typedef long long ll;
const ll divisor = 1e9 + 7;
ll a, b, ans = 0;

// ll gcd(ll num1, ll num2)
// {
//     return num2 ? gcd(num2, num1 % num2) : num1;
// }
ll pow(ll num, ll e)
{
    ll res = 1;
    for (; e > 0; e /= 2)
    {
        if (e & 1)
            res = (res * num) % divisor;
        num = (num * num) % divisor;
    }
    return res;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input & Process
    int m;
    cin >> m;

    while (m--)
    {
        cin >> b >> a;
        // 약분
        // ll abbreviation = a > b ? gcd(a, b) : gcd(b, a);
        // a /= abbreviation;
        // b /= abbreviation;

        ans = (ans + a * pow(b, divisor - 2)) % divisor;
    }

    // Output
    cout << ans << '\n';
    return 0;
}