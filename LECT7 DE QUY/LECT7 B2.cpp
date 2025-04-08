#include <iostream>
using namespace std;
int giaithua(int x)
{
if(x == 0)
{
return 1;}
else{
return x * giaithua(x -1);}
}
int main()
{
int x;
cin >> x;
giaithua(x);
cout << giaithua(x) << endl;
return 0;}
