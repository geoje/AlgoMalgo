#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// refine 함수를 위한 선별때 필요한 상수배열
const pair<char, int> types[] = {
    {'c', 3}, // 0: cpp
    {'j', 4}, // 1: java
    {'p', 6}, // 2: python
    {'b', 7}, // 3: backend
    {'f', 8}, // 4: frontend
    {'j', 6}, // 5: junior
    {'s', 6}, // 6: senior
    {'c', 7}, // 7: chicken
    {'p', 5}, // 8: pizza
};

// string을 선별해 비트 마스킹된 int로 변환
// left: score
// right: bit masking | 1: cpp, 2: java, 4: python, 8: backend, 16: frontend
//                    | 32: junior, 64: senior, 128:chicken, 256: pizza
//                    | pizza / chicken/sen/jun/front / back/py/java/cpp
pair<int, int> refine(string str)
{
    int person = 0, t = 1, i = 0;

    // 2개씩 처리를 위해 첫번째를 미리 처리
    if (str[0] == types[0].first)
    {
        person = 1;
        t = 3;
        i = types[0].second + 1;
    }

    while (t <= 8)
        // "and" for query
        if (str[i] == 'a')
            i += 4;
        // wildcard for query
        else if (str[i] == '-')
        {
            t += 2;
            i += 2;
        }
        else if (str[i] == types[t].first)
        {
            person |= 1 << t;
            i += types[t].second + 1;
            t += t % 2 ? 2 : 1;
        }
        else
            t++;

    return {stoi(str.substr(i)), person};
}

void combination(vector<int> &picked, vector<int> &bits, int cur, int i)
{
    if (i == bits.size())
    {
        picked.push_back(cur);
        return;
    }

    combination(picked, bits, cur, i + 1);
    combination(picked, bits, cur | (1 << bits[i]), i + 1);
}

vector<int> solution(vector<string> infos, vector<string> querys)
{
    vector<int> answer;
    map<int, multiset<int>> people;

    // 사용자 정제
    for (string info : infos)
    {
        auto person = refine(info);
        vector<int> groups, bits;

        // 비트 위치 파악
        for (int n = person.second, j = 0; n > 0; n /= 2, j++)
            if (n & 1)
                bits.push_back(j);

        // 모든 그룹에 점수 입력
        combination(groups, bits, 0, 0);
        for (int group : groups)
            people[group].insert(person.first);
    }

    // 쿼리 처리
    for (string query : querys)
    {
        answer.push_back(0);
        pair<int, int> rq = refine(query);
        auto s = people[rq.second];
        for (auto it = s.upper_bound(rq.first - 1); it != s.end(); it++)
            answer.back()++;
    }

    return answer;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    for (int num : solution({"java backend junior pizza 150",
                             "python frontend senior chicken 210",
                             "python frontend senior chicken 150",
                             "cpp backend senior pizza 260",
                             "java backend junior chicken 80",
                             "python backend senior chicken 50"},
                            {"java and backend and junior and pizza 100",
                             "python and frontend and senior and chicken 200",
                             "cpp and - and senior and pizza 250",
                             "- and backend and senior and - 150",
                             "- and - and - and chicken 100",
                             "- and - and - and - 150"}))
        cout << num << ' ';
    cout << '\n';
    return 0;
}