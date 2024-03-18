// #include <cstdio> // For Test
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, num[8], ans[8];
bool used[8] = {0};

void sequence(int count, int idx)
{
    ans[count] = num[idx];
    used[idx] = true;

    if (++count == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else
        for (int mem = 0, i = 0; i < n; i++)
            if (!used[i] && mem != num[i])
            {
                sequence(count, i);
                mem = num[i];
            }

    used[idx] = false;
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
    for (int mem = 0, i = 0; i < n; i++)
        if (mem != num[i])
        {
            sequence(0, i);
            mem = num[i];
        }
    return 0;
}