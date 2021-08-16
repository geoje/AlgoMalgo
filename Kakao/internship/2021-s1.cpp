#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0, i = 0;
    while (i < s.length())
    {
        answer *= 10;
        if (s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i] - '0';
            i += 1;
        }
        else if (s[i] == 'z')
            i += 4;
        else if (s[i] == 'o')
        {
            answer += 1;
            i += 3;
        }
        else if (s[i] == 't')
        {
            answer += s[i + 1] == 'w' ? 2 : 3;
            i += s[i + 1] == 'w' ? 3 : 5;
        }
        else if (s[i] == 'f')
        {
            answer += s[i + 1] == 'o' ? 4 : 5;
            i += 4;
        }
        else if (s[i] == 's')
        {
            answer += s[i + 1] == 'i' ? 6 : 7;
            i += s[i + 1] == 'i' ? 3 : 5;
        }
        else if (s[i] == 'e')
        {
            answer += 8;
            i += 5;
        }
        else
        {
            answer += 9;
            i += 4;
        }
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s) << '\n';
    return 0;
}