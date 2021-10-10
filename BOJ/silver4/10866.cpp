#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int n, x;
deque<int> q;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process & Output */
    string s;
    while (n--)
    {
        cin >> s;
        if (s[0] == 'p')
        {
            if (s[5] == 'f')
            {
                cin >> x;
                q.push_front(x);
            }
            else if (s[5] == 'b')
            {
                cin >> x;
                q.push_back(x);
            }
            else
            {
                if (q.empty())
                    cout << "-1\n";
                else
                {
                    if (s[4] == 'f')
                    {
                        cout << q.front() << '\n';
                        q.pop_front();
                    }
                    else if (s[4] == 'b')
                    {
                        cout << q.back() << '\n';
                        q.pop_back();
                    }
                }
            }
        }
        else if (s[0] == 's')
            cout << q.size() << '\n';
        else if (s[0] == 'e')
            cout << q.empty() << '\n';
        else if (s[0] == 'f')
            cout << (q.empty() ? -1 : q.front()) << '\n';
        else if (s[0] == 'b')
            cout << (q.empty() ? -1 : q.back()) << '\n';
    }
    return 0;
}