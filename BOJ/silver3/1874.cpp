#include <cstdio> // For Test
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int n;
queue<int> q;
stack<int> s;
string ans;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        q.push(a);
    }

    /* Process */
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        ans += "+\n";

        while (!q.empty() && !s.empty() && q.front() == s.top())
        {
            q.pop();
            s.pop();
            ans += "-\n";
        }
    }

    /* Output */
    cout << (q.empty() ? ans : "NO\n");
    return 0;
}