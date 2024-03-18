#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n;
long long sx, sy, a, b, c, d, s = 0;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process */
    cin >> n >> sx >> sy;
    a = sx;
    b = sy;
    while (--n)
    {
        cin >> c >> d;
        s += a * d - b * c;

        a = c;
        b = d;
    }
    s += a * sy - b * sx;
    if (s < 0)
        s = -s;

    /* Output */
    cout << s / 2 << ((s % 2) ? ".5" : ".0") << '\n';
    return 0;
}