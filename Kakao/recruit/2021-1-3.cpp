#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> typeSets = {
    {{'c', 4},
     {'j', 5},
     {'p', 7}},
    {{'b', 8},
     {'f', 9}},
    {{'j', 7},
     {'s', 7}},
    {{'c', 8},
     {'p', 6}}};

vector<int> refineInfo(string str)
{
    vector<int> result;
    int i = 0;

    for (auto set : typeSets)
        for (int t = 0; t < set.size(); t++)
            if (str[i] == set[t].first)
            {
                i += set[t].second;
                result.push_back(t + 1);
                break;
            }

    result.push_back(stoi(str.substr(i)));
    return result;
}
vector<int> refineQuery(string str)
{
    vector<int> result;
    int i = 0;

    for (auto set : typeSets)
        for (int t = 0; t < set.size(); t++)
            if (str[i] == '-')
            {
                i += 6;
                result.push_back(0);
                break;
            }
            else if (str[i] == set[t].first)
            {
                i += set[t].second + 4;
                result.push_back(t + 1);
                break;
            }

    result.push_back(stoi(str.substr(i - 4)));
    return result;
}

vector<int> solution(vector<string> infos, vector<string> querys)
{
    vector<int> answer, scores[4][3][3][3];

    // 점수 처리
    for (string info : infos)
    {
        auto p = refineInfo(info);
        for (int i = 0; i <= p[0]; i += p[0])
            for (int j = 0; j <= p[1]; j += p[1])
                for (int k = 0; k <= p[2]; k += p[2])
                    for (int l = 0; l <= p[3]; l += p[3])
                        scores[i][j][k][l].push_back(p[4]);
    }

    // 이분 탐색을 위한 정렬
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                    sort(scores[i][j][k][l].begin(), scores[i][j][k][l].end());

    // 쿼리 처리
    for (string query : querys)
    {
        vector<int> p = refineQuery(query);
        vector<int> &sc = scores[p[0]][p[1]][p[2]][p[3]];

        auto it = lower_bound(sc.begin(), sc.end(), p[4]);
        answer.push_back(it == sc.end() ? 0 : sc.end() - it);
    }

    return answer;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);

    // for (int num : solution({"java backend junior pizza 150",
    //                          "python frontend senior chicken 210",
    //                          "python frontend senior chicken 150",
    //                          "cpp backend senior pizza 260",
    //                          "java backend junior chicken 80",
    //                          "python backend senior chicken 50"},
    //                         {"java and backend and junior and pizza 100",
    //                          "python and frontend and senior and chicken 200",
    //                          "cpp and - and senior and pizza 250",
    //                          "- and backend and senior and - 150",
    //                          "- and - and - and chicken 100",
    //                          "- and - and - and - 150"}))
    //     cout << num << ' ';

    srand(time(0));
    vector<string> infos, querys;
    for (int i = 0; i < 50000; i++)
    {
        string a = rand() % 3 ? (rand() % 2 ? "cpp " : "java ") : "python ";
        string b = rand() % 2 ? "backend " : "frontend ";
        string c = rand() % 2 ? "junior " : "senior ";
        string d = rand() % 2 ? "pizza " : "chicken ";
        infos.push_back(a + b + c + d + to_string(rand() % 100 * 10));
    }
    for (int i = 0; i < 100000; i++)
    {
        string a = rand() % 2 ? (rand() % 2 ? "cpp" : "java") : (rand() % 2 ? "python" : "-");
        string b = rand() % 3 ? (rand() % 2 ? "backend" : "frontend") : "-";
        string c = rand() % 3 ? (rand() % 2 ? "junior" : "senior") : "-";
        string d = rand() % 3 ? (rand() % 2 ? "pizza " : "chicken ") : "- ";
        querys.push_back(a + " and " + b + " and " + c + " and " + d + to_string(rand() % 100 * 10));
    }
    for (int &num : solution(infos, querys))
        cout << num << ' ';

    cout << '\n';
    return 0;
}