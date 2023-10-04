#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int i = 0;
    for (char c : s)
    {
        if (c == '(')
            i++;
        else if (i-- == 0)
            return false;
    }
    return i == 0;
}