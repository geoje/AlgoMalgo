#include <cstdio> // For Test
#include <bitset>
#include <vector>
#include <iostream>
using namespace std;

long long a, b;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> a >> b;

    /* Process */
    int len = 0;
    long long i = a;
    vector<string> strs;
    for (; i <= b; i++)
    {
        bitset<100> bs(i);
        string s = bs.to_string();
        s = s.substr(s.find('1'));

        len = max(len, (int)s.length());
        strs.push_back(s);
    }

    /* Output */
    i = a;
    for (string s : strs)
    {
        cout << i << '\t';
        for (int j = s.length(); j < len; j++)
            cout << ' ';
        cout << s << '\n';
        i++;
    }
    return 0;
}