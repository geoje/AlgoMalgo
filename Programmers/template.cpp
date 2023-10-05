#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> vs)
{
    return vs;
}

void print(vector<int> vs)
{
    cout << "{";
    if (vs.size())
        cout << vs.front();
    for (int i = 1; i < vs.size(); i++)
        cout << ',' << vs.at(i);
    cout << "}\n";
}

int main()
{
    print(solution({}));
}