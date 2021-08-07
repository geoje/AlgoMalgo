// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m, v[8] = {0};

void sequence(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
    else
        for (int i = v[idx - 1] + 1; i <= n; i++)
        {
            v[idx] = i;
            sequence(idx + 1);
        }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;

    // Process & Output
    for (int i = 1; i <= n - m + 1; i++)
    {
        v[0] = i;
        sequence(1);
    }
    return 0;
}