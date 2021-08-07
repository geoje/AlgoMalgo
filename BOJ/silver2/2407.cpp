// #include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;

int n, r;
string result, c[101][101];

string add(string a, string b)
{
    int sum = 0;
    result.clear();

    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back(sum % 10 + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r)
{
    if (!c[n][r].empty())
        return c[n][r];
    if (n == r || r == 0)
        return "1";
    else
        return c[n][r] = add(combination(n - 1, r - 1), combination(n - 1, r));
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> r;

    // Process & Output
    cout << combination(n, r) << '\n';
    return 0;
}