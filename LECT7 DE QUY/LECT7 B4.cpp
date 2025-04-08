#include <iostream>
using namespace std;
int luythua( int x, int n )
{
if (x == 0){return 0;};
if (n == 0){return 1;}
else{return x * luythua(x, n - 1);}
}
int main()
{
int x, n;
cin >> x >> n;
cout << luythua(x, n)<< endl;
return 0;}
