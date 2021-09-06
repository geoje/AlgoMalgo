#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = 1000;

    for (int len = 1; len <= s.length() / 2; len++)
    {
        int result = 0, count = 1;

        string tokens[2] = {""};
        for (int i = 0; i < s.length(); i += len)
        {
            if (i + len > s.length())
            {
                result += s.length() - i;
                break;
            }

            tokens[1] = s.substr(i, len);
            if (tokens[0] == tokens[1])
                count++;
            else
            {
                result += len;

                // 숫자 길이 만큼 증가
                if (count >= 2)
                {
                    result += to_string(count).length();
                    count = 1;
                }
            }
            tokens[0] = tokens[1];
        }

        // 숫자 길이 만큼 증가
        if (count >= 2)
            result += to_string(count).length();

        answer = min(answer, result);
    }

    return answer;
}

int main()
{
    cout << solution("aabbaccc") << '\n';
    cout << solution("ababcdcdababcdcd") << '\n';
    cout << solution("abcabcdede") << '\n';
    cout << solution("abcabcabcabcdededededede") << '\n';
    cout << solution("xababcdcdababcdcd") << '\n';
    cout << solution("acacacbacacac") << '\n';
    cout << solution("acacacacacacbacacacacacac") << '\n';
    cout << solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << '\n';
    return 0;
}