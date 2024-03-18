// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int num[10000];

void bt(int left, int right)
{
    int root = num[left], mid = left + 1;
    while (mid <= right && num[mid] < root)
        mid++;

    if (left + 2 <= mid)
        bt(left + 1, mid - 1);
    if (mid <= right)
        bt(mid, right);

    cout << root << ' ';
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    int t, n = 0;
    while (cin >> t)
        num[n++] = t;

    // Process & Output
    bt(0, n - 1);
    return 0;
}