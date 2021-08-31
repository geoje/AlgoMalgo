#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string new_id)
{
    string answer = "";

    for (char c : new_id)
        if (c >= 'A' && c <= 'Z')
            answer.push_back(tolower(c));
        else if (c == '.')
        {
            if (answer.empty() || answer.back() == '.')
                continue;

            answer.push_back(c);
        }
        else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_')
            answer.push_back(c);

    // 4
    if (answer.back() == '.')
        answer.pop_back();

    // 5
    if (answer.empty())
        answer = "a";

    // 6
    if (answer.length() >= 16)
    {
        answer = answer.substr(0, 15);
        if (answer.back() == '.')
            answer.pop_back();
    }

    // 7
    while (answer.length() <= 2)
        answer.push_back(answer.back());

    return answer;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    cout << solution("...!@BaT#*..y.abcdefghijklm") << '\n';
    cout << solution("z-+.^.") << '\n';
    cout << solution("=.=") << '\n';
    cout << solution("123_.def") << '\n';
    cout << solution("abcdefghijklmn.p") << '\n';
    return 0;
}