// #include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[10000], use[10000] = {0}, ans[10000];

void sequence(int count, int idx)
{
    ans[count++] = num[idx];
    use[idx] = 1;

    if (count == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        use[idx] = 0;
        return;
    }

    for (int i = 0; i < n; i++)
        if (!use[i])
            sequence(count, i);

    use[idx] = 0;
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