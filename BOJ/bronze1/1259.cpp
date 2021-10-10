#include <cstdio> // For Test
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process * Output */
    string s;
    while (true)
    {
        cin >> s;
        if (s == "0")
            break;

        int l = 0, r = s.length() - 1;
        for (; l < r && s[l] == s[r]; l++, r--)
            ;

        cout << (l < r ? "no\n" : "yes\n");
    }
    return 0;
}