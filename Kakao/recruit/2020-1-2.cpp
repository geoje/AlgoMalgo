#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool isWrapped(const string &str)
{
    int t = 0;
    for (char c : str)
    {
        if (c == '(')
            t++;
        else
            t--;

        if (t < 0)
            return false;
    }
    return t == 0;
}

string solution(string p)
{
    if (p.empty())
        return "";

    int b[2] = {0};

    // 균형잡힌 괄호 문자열 u와 v로 분리
    int i = 1;
    b[p[0] == '(' ? 0 : 1]++;
    for (; i < p.length(); i++)
    {
        if (b[0] == b[1])
            break;
        b[p[i] == '(' ? 0 : 1]++;
    }

    string u = p.substr(0, i);
    string v = i < p.length() ? p.substr(i) : "";

    // 올바른 괄호 문자열 이라면
    if (isWrapped(u))
        return u + solution(v);
    // 아니라면
    else
    {
        string result = '(' + solution(v) + ')';
        string sub = u.substr(1, u.length() - 2);
        for (char c : sub)
            result += c == '(' ? ')' : '(';
        return result;
    }
}

int main()
{
    cout << solution("(()())()") << '\n';
    cout << solution(")(") << '\n';
    cout << solution("()))((()") << '\n';
    cout << solution("()") << '\n';
    cout << solution("())(()") << '\n';
    cout << solution("((()(()()())))") << '\n';
    cout << solution(")((())(())") << '\n';
    return 0;
}