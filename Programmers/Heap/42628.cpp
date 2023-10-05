#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pi; // value, index

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    vector<int> vec;
    priority_queue<pi, vector<pi>> pqMax;
    priority_queue<pi, vector<pi>, greater<pi>> pqMin;

    for (string operation : operations)
    {
        if (operation[0] == 'I')
        {
            int v = stoi(operation.substr(2));
            pair<int, int> vp = make_pair(v, vec.size());
            vec.push_back(v);
            pqMin.push(vp);
            pqMax.push(vp);
        }
        else if (vec.size())
        {
            if (operation[2] == '1')
            {
                auto vp = pqMax.top();
                pqMax.pop();
                vec.erase(vec.begin() + vp.second);
                priority_queue<pi, vector<pi>, greater<pi>> pqTemp;
                for (int i = 0; i < vec.size(); i++)
                    pqTemp.push(make_pair(vec[i], i));
                pqMin.swap(pqTemp);
            }
            else
            {
                auto vp = pqMin.top();
                pqMin.pop();
                vec.erase(vec.begin() + vp.second);
                priority_queue<pi, vector<pi>> pqTemp;
                for (int i = 0; i < vec.size(); i++)
                    pqTemp.push(make_pair(vec[i], i));
                pqMax.swap(pqTemp);
            }
        }
    }

    answer.push_back(vec.size() ? pqMax.top().first : 0);
    answer.push_back(vec.size() ? pqMin.top().first : 0);
    return answer;
}

void print(vector<int> vs)
{
    cout << "[";
    for (auto v : vs)
        cout << v << ',';
    cout << "]\n";
}

int main()
{
    print(solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"}));
    print(solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"}));
}