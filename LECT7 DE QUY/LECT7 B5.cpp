#include <iostream>
#include <cmath>
using namespace std;
int demso(int x)
{
x = abs(x);
if(x < 10){return 1;}
else{return 1 + demso(x / 10);}
}
int main()
{
int x;
cin >> x;
cout << demso(x) << endl;
return 0;
}
