// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int a, b, ans = 1;
queue<int> q;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> a >> b;

    // Process
    while (b > a)
    {
        if (b & 1 && b % 10 == 1) break;
        b /= b & 1 ? 10 : 2;
        ans++;
    }

    // Output
    cout << (a == b ? ans : -1) << '\n';
    return 0;
}
