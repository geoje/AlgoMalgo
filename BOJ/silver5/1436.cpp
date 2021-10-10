#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, num[10001];

bool isEndNum(int x)
{
    int c = 0;
    for (; x; x /= 10)
        if (x % 10 == 6)
        {
            if (++c == 3)
                return true;
        }
        else
            c = 0;
    return false;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process */
    int i = 665;
    while (true)
        if (isEndNum(++i) && --n == 0)
            break;

    /* Output */
    cout << i << '\n';
    return 0;
}