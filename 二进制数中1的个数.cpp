#include
using namespace std;
int main()
{
    int i, n=0;
    cin >> i;
    while (i >= 1)
    {
    if (i % 2 == 1)
        n++;
        i /= 2;
    }
    cout << n << endl;
    return 0;
}