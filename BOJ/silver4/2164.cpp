#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int n;
queue<int> q;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);

    /* Process */
    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    /* Output */
    cout << q.front() << '\n';
    return 0;
}