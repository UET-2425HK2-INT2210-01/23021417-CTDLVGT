#include <iostream>
using namespace std;
int tongdequy(int x)
{
if( x == 0 ){return 0;}
else
{
return x + tongdequy(x - 1);
}
}
int main()
{
int x;
cin >> x;
cout << tongdequy(x) << endl;
return 0;
}
