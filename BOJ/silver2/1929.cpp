#include <cstdio> // For Test
#include <iostream>
using namespace std;

int m, n;
bool primes[1000001] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> m >> n;
    fill_n(primes + 1, n, 1);

    /* Process */
    primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        for (int j = i * i; j <= n; j += i)
            primes[j] = false;

    /* Output */
    for (; m <= n; m++)
        if (primes[m])
            cout << m << '\n';
    return 0;
}