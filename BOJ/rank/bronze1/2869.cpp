#include <cstdio> // For Test
#include <cmath>
#include <iostream>
using namespace std;

int a, b, v;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> a >> b >> v;

    /* Process & Output */
    cout << (long)ceil((double)(v - a) / (a - b)) + 1 << '\n';
    return 0;
}