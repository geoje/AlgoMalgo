#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void combination(vector<string> &picked, const string &order, const int &size, string cur, int i)
{
    if (cur.length() == size)
    {
        picked.push_back(cur);
        return;
    }

    for (; i < order.length(); i++)
        combination(picked, order, size, cur + order[i], i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int &size : course)
    {
        int maxNum = 0;
        map<string, int> prefers;

        // 모든 주문에 대하여 정해진 사이즈에 따라 조합을 만들어 map 자료구조에 횟수 추가하면서
        // 해당 횟수가 최고값이 되는 것을 기록
        for (string &order : orders)
        {
            vector<string> picked;
            combination(picked, order, size, "", 0);

            for (string &comb : picked)
                if (++prefers[comb] >= maxNum)
                    maxNum = prefers[comb];
        }

        // 주문 조합이 2번 이상일 때 제일 많은 것들을 정답에 추가
        if (maxNum >= 2)
            for (auto it = prefers.begin(); it != prefers.end(); it++)
                if (it->second == maxNum)
                    answer.push_back(it->first);
    }

    // 정답 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    for (string str : solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4}))
        cout << str << ' ';
    cout << '\n';
    for (string str : solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5}))
        cout << str << ' ';
    cout << '\n';
    for (string str : solution({"XYZ", "XWY", "WXA"}, {2, 3, 4}))
        cout << str << ' ';
    cout << '\n';
    return 0;
}