// #include <cstdio> // For Test
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, num[8], ans[8];

void sequence(int count, int idx)
{
    ans[count] = num[idx];

    if (++count == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else
        for (; idx < n; idx++)
            sequence(count, idx);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    // Process & Output
    for (int i = 0; i < n; i++)
        sequence(0, i);
    return 0;
}