#include <cstdio> // For Test
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    string s;
    while (true)
    {
        getline(cin, s);
        if (s == ".")
            break;

        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    s.clear();
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    s.clear();
                    break;
                }
                st.pop();
            }
        }

        cout << (s.empty() || !st.empty() ? "no\n" : "yes\n");
    }

    return 0;
}