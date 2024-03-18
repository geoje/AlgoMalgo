#include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;

int n[3];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    while (true)
    {
        cin >> n[0] >> n[1] >> n[2];
        if (n[0] == 0 && n[1] == 0 && n[2] == 0)
            break;
        sort(n, n + 3);

        bool res = n[0] * n[0] + n[1] * n[1] == n[2] * n[2];
        cout << (res ? "right\n" : "wrong\n");
    }
    return 0;
}