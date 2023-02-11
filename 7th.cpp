#include <bits/stdc++.h>
using namespace std;

void deleteValue(list<int> &l, int value)
{
    for (list<int>::iterator i = l.begin(); i != l.end(); i++)
    {
        if (*i == value)
        {
            l.erase(i);
            break;
        }
    }
}

int main()
{
    list<int> l = {7, 3, 8, 4, 5, 4};
    int x;
    cout << "STL list containing [";
    for (int i : l)
        cout << i << " ";

    cout << "], value: ";
    cin >> x;

    deleteValue(l, x);
    cout << "STL list containing [";
    for (int i : l)
        cout << i << " ";
    cout << "]"
         << "\n";

    return 0;
}
