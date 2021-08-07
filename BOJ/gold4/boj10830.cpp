#include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

typedef vector<vector<int>> matrix;
matrix operator*(matrix &a, matrix &b)
{
    int s = a.size();
    matrix c(s, vector<int>(s));
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            for (int k = 0; k < s; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

int n, b;
matrix ans, base;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> b;
    ans.assign(n, vector<int>(n));
    base.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 1; // 항등 행렬 만들기
        for (int j = 0; j < n; j++)
            cin >> base[i][j];
    }

    // Process
    for (; b > 0; b /= 2)
    {
        if (b & 1)
            ans = ans * base;
        base = base * base;
    }

    // Output
    for (int i = 0; i < n; i++, cout << '\n')
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
    return 0;
}