#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int n, m;
queue<int> q;
string s;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process & Output */
    while (n--)
    {
        cin >> s;
        if (s[0] == 'p')
        {
            if (s[1] == 'u')
            {
                cin >> m;
                q.push(m);
            }
            else
            {
                if (q.empty())
                    cout << "-1\n";
                else
                {
                    cout << q.front() << '\n';
                    q.pop();
                }
            }
        }
        else if (s[0] == 's')
            cout << q.size() << '\n';
        else if (s[0] == 'e')
            cout << q.empty() << '\n';
        else if (s[0] == 'f')
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << '\n';
        }
        else if (s[0] == 'b')
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << '\n';
        }
    }
    return 0;
}