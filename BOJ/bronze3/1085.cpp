#include <cstdio> // For Test
#include <iostream>
using namespace std;

int x, y, w, h, ans = 500;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> x >> y >> w >> h;
    ans = min(ans, x);
    ans = min(ans, y);
    ans = min(ans, w - x);
    ans = min(ans, h - y);

    /* Output */
    cout << ans << '\n';
    return 0;
}