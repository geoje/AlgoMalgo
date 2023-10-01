#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> map;
    string part;
    for (string p : phone_book)
    {
        if (map[p] == 1)
            return false;
        map[p] = 2;

        for (int i = p.length() - 1; i > 0; i--)
        {
            part = p.substr(0, i);
            if (map[part] == 2)
                return false;
            else
                map[part] = 1;
        }
    }
    return true;
}

int main()
{
    cout << solution({"119", "97674223", "1195524421"}) << '\n';
    cout << solution({"123", "456", "789"}) << '\n';
    cout << solution({"12", "123", "1235", "567", "88"}) << '\n';
    return 0;
}