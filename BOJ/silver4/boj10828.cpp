#include <iostream>
using namespace std;

int sz = 0, stack[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input & Process & Output
    int n, num;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str[0] == 'p')
        {
            // push //
            if (str[1] == 'u')
            {
                cin >> num;
                stack[sz++] = num;
            }
            // pop //
            else
            {
                if (sz)
                    cout << stack[--sz] << '\n';
                else
                    cout << "-1\n";
            }
        }
        // size //
        else if (str[0] == 's')
        {
            cout << sz << '\n';
        }
        // empty
        else if (str[0] == 'e')
        {
            cout << !sz << '\n';
        }
        // top
        else
        {
            if (sz)
                cout << stack[sz - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}