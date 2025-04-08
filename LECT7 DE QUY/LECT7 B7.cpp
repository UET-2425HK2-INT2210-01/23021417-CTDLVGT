#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int daonguoc(int x, int kq) {
    if (x == 0) return kq;
    return daonguoc(x / 10, kq * 10 + x % 10);
}
int main()
{
int x, kq;
cin >> x;
cout << daonguoc(x, kq) << endl;
return 0;
}
