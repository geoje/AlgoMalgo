#include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
matrix operator*(matrix &a, matrix &b)
{
    int s = a.size();
    matrix c(s, vector<ll>(s));
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < s; k++)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= 1'000'000'007;
        }
    return c;
}

matrix ans;
matrix base = {
    {0, 1, 0, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0},
};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int d;
    cin >> d;
    ans.assign(8, vector<ll>(8));
    for (int i = 0; i < 8; i++)
        ans[i][i] = 1;

    /* Process */
    for (; d; d /= 2)
    {
        if (d | 1)
            ans = ans * base;
        base = base * base;
    }

    /* Output */
    cout << ans[0][0] << '\n';
    return 0;
}