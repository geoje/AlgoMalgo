#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct group
{
    bool sorted = false;
    vector<int> scores;
};

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
pair<int, int> refineInfo(string str)
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
        if (str[i] == types[t].first)
        {
            person |= 1 << t;
            i += types[t].second + 1;
            t += t % 2 ? 2 : 1;
        }
        else
            t++;

    return {stoi(str.substr(i)), person};
}
pair<int, int> refineQuery(string str)
{
    int person = 0, t = 1, i = 0;

    // 2개씩 처리를 위해 첫번째를 미리 처리
    if (str[0] == types[0].first)
    {
        person = 1;
        t = 3;
        i = types[0].second + 5;
    }

    while (t <= 8)
        // wildcard for query
        if (str[i] == '-')
        {
            t += 2;
            i += 6;
        }
        else if (str[i] == types[t].first)
        {
            person |= 1 << t;
            i += types[t].second + 5;
            t += t % 2 ? 2 : 1;
        }
        else
            t++;

    return {stoi(str.substr(i - 4)), person};
}

int lower_bound(vector<int> &nums, int key)
{
    int left = 0, mid, right = nums.size();

    while (left < right)
    {
        mid = (left + right) / 2;
        if (key <= nums[mid])
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

vector<int> solution(vector<string> infos, vector<string> querys)
{
    vector<int> answer;
    unordered_map<int, group> people;

    // 사용자 정제
    for (string info : infos)
    {
        auto person = refineInfo(info);
        vector<int> groups, bits;

        // 비트 위치 파악
        for (int n = 1 << 8; n; n >>= 1)
            if (person.second & n)
                bits.push_back(n);

        // 모든 그룹에 점수 입력
        for (int a = 0; a <= bits[0]; a += bits[0])
            for (int b = 0; b <= bits[1]; b += bits[1])
                for (int c = 0; c <= bits[2]; c += bits[2])
                    for (int d = 0; d <= bits[3]; d += bits[3])
                        people[a + b + c + d].scores.push_back(person.first);
    }

    // 쿼리 처리
    for (string query : querys)
    {
        pair<int, int> rq = refineQuery(query);
        group g = people[rq.second];
        if (!g.sorted)
        {
            g.sorted = true;
            sort(g.scores.begin(), g.scores.end());
        }
        answer.push_back(g.scores.size() - lower_bound(g.scores, rq.first));
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