#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, map<int, set<int>>> rank_map;
    for (int i = 0; i < genres.size(); i++)
        rank_map[genres[i]][plays[i]].insert(i);

    map<int, string> total_plays;
    for (auto it1 : rank_map)
    {
        int total = 0;
        for (auto it2 : it1.second)
            total += it2.first * it2.second.size();
        total_plays[total] = it1.first;
    }

    vector<int> answer;
    for (auto rit1 = total_plays.rbegin(); rit1 != total_plays.rend(); ++rit1)
    {
        auto rank = rank_map[rit1->second];
        auto rit2 = rank.rbegin();
        for (int i = 0; i < 2 && rit2 != rank.rend(); ++rit2)
        {
            for (auto id : rit2->second)
            {
                answer.push_back(id);
                if (++i >= 2)
                    break;
            }
        }
    }

    return answer;
}

int main()
{
    for (auto e : solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}))
        cout << e << ' ';
    cout << '\n';
}