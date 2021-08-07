// #include <cstdio> // For Test
#include <iostream>
#include <stack>
using namespace std;

string expression;
stack<string> operands;
stack<char> operators;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool canEvaluate()
{
    // 피 연산자가 2개 이상이고 연산자 인 것이 존재할 경우
    return operands.size() >= 2 && !operators.empty() && isOperator(operators.top());
}

void evaluate()
{
    string str;
    str = operands.top(); // 우측 피연산자
    operands.pop();
    str = operands.top() + str; // 좌측 피연산자
    operands.pop();
    str.push_back(operators.top()); // 연산자
    operators.pop();

    operands.push(str);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input & Process
    cin >> expression;
    for (char c : expression)
    {
        if (c >= 'A' && c <= 'Z')
        {
            char str[2] = {c, '\0'};
            operands.push(str);
        }
        else if (c == '(')
            operators.push(c);
        else if (c == ')')
            while (true)
            {
                if (operators.top() == '(')
                {
                    operators.pop();
                    break;
                }
                evaluate();
            }
        else if (c == '+' || c == '-')
        {
            while (canEvaluate())
                evaluate();
            operators.push(c);
        }
        else if (c == '*' || c == '/')
        {
            if (!operators.empty() && (operators.top() == '*' || operators.top() == '/'))
                evaluate();
            operators.push(c);
        }
    }

    // Output
    while (canEvaluate())
        evaluate();
    cout << operands.top() << '\n';
    return 0;
}