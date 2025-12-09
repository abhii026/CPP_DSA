#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char aux, char to)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, from, to);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
