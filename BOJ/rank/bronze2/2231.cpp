#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process & Output */
    for (int i = 1; i <= n; i++)
    {
        int m = i;
        for (int j = i; j > 0; j /= 10)
            m += j % 10;

        if (n == m)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}