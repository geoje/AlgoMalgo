// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

struct node
{
    char c = 0;
    int left = -1, right = -1;
};

struct node tree[26];

void preorder(int nodeNum)
{
    if (nodeNum == -1)
        return;
    cout << tree[nodeNum].c;
    preorder(tree[nodeNum].left);
    preorder(tree[nodeNum].right);
}
void inorder(int nodeNum)
{
    if (nodeNum == -1)
        return;
    inorder(tree[nodeNum].left);
    cout << tree[nodeNum].c;
    inorder(tree[nodeNum].right);
}
void postorder(int nodeNum)
{
    if (nodeNum == -1)
        return;
    postorder(tree[nodeNum].left);
    postorder(tree[nodeNum].right);
    cout << tree[nodeNum].c;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    int n;
    cin >> n;
    char c[3];
    for (int i = 0; i < n; i++)
    {
        cin >> c[0] >> c[1] >> c[2];
        int idx = c[0] - 'A';
        tree[idx].c = c[0];
        if (c[1] != '.')
            tree[idx].left = c[1] - 'A';
        if (c[2] != '.')
            tree[idx].right = c[2] - 'A';
    }

    // Process
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    // Output
    return 0;
}