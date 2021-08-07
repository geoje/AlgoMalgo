#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int l, c;
vector<char> chars;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
// pw: 현재까지 만들어진 비밀번호
// vowelNum: pw에서의 모음 개수
void Attack(string pw, int vowelNum)
{
    // 조건이 충족 되면 출력
    // 조건1: 만들어진 단어 길이가 원했던 길이일 경우
    // 조건2: 모음 개수가 1개 이상일 경우
    // 조건3: 자음 개수가 2개 이상일 경우
    if (pw.length() == l && vowelNum >= 1 && l - vowelNum >= 2)
    {
        cout << pw << "\n";
        return;
    }

    // 단어가 미완성일 경우 오름차순일 때 재귀 호출
    for (int i = 0; i < chars.size(); i++)
        if (chars[i] > pw.back())
            Attack(pw + chars[i], isVowel(chars[i]) ? vowelNum + 1 : vowelNum);
}

int main()
{
    // Input
    cin >> l >> c;
    char tmp;
    for (int i = 0; i < c; i++)
    {
        cin >> tmp;
        chars.push_back(tmp);
    }
    sort(chars.begin(), chars.end());

    // Process && Output
    for (char c : chars)
    {
        string s;
        s += c;
        Attack(s, isVowel(c) ? 1 : 0);
    }
    return 0;
}