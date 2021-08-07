#include <iostream>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input & Process
    cin >> n;
    bool result[n];
    fill_n(result, n, true);
    for (int i = 0; i < n; i++)
    {
        string ps;
        cin >> ps;
        int open = 0;
        for (char c : ps)
        {
            if (c == '(')
                open++;
            else if (open-- <= 0)
            {
                result[i] = false;
                break;
            }
        }
        if (open != 0)
            result[i] = false;
    }

    // Output
    for (int i = 0; i < n; i++)
        cout << (result[i] ? "YES\n" : "NO\n");
    return 0;
}