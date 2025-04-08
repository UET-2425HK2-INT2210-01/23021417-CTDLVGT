#include <iostream>
#include <cmath>
using namespace std;
int tongso(int x)
{
    x = abs(x);
if(x == 0){return 0;}
else{return x % 10 + tongso(x / 10);}
}
int main()
{
int x;
cin >> x;
cout << tongso(x) << endl;
return 0;
}
