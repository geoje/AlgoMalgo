#include <cstdio> // For Test
#include <unordered_map>
#include <iostream>
using namespace std;

int n;
unordered_map<int, bool> exists;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        exists[a] = true;
    }

    /* Process & Output */
    cin >> n;
    while (n--)
    {
        cin >> a;
        cout << exists[a] << '\n';
    }
    return 0;
}