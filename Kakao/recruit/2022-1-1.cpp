#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct info
{
    int idx, count;
    unordered_set<int> report_idx;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, info> infos;

    // 사용자 인덱스 매핑
    for (int i = 0; i < id_list.size(); i++)
        infos[id_list[i]].idx = i;

    // 신고 처리
    for (string s : report)
    {
        // 사용자 분리
        auto it = s.find(' ');
        string id[2] = {s.substr(0, it), s.substr(it + 1, s.length() - it)};

        // 신고된 횟수 증가 및 신고자 기록
        auto &info = infos[id[1]];
        if (info.report_idx.find(infos[id[0]].idx) == info.report_idx.end())
        {
            info.count++;
            info.report_idx.insert(infos[id[0]].idx);
        }
    }

    // 정지 처리
    for (auto it = infos.begin(); it != infos.end(); it++)
        if (it->second.count >= k)
            for (int idx : it->second.report_idx)
                answer[idx]++;

    return answer;
}

int main()
{
    for (int n : solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3))
        cout << n << ' ';
    cout << '\n';
}