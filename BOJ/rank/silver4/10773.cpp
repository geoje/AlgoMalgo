#include <cstdio> // For Test
#include <stack>
#include <iostream>
using namespace std;

int k, n;
stack<int> s;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> k;
    while (k--)
    {
        cin >> n;
        if (n)
            s.push(n);
        else
            s.pop();
    }

    /* Process */
    int ans = 0;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}