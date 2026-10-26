#include<bits/stdc++.h>
using namespace std;

int main()
{
    double ac_num,d_digit,frac,mult,power,result;
    int n;
    cin>>ac_num>>d_digit;
    power = pow(10,d_digit);
    mult = ac_num*power;
    n=(int)floor(mult);
    frac = mult-n;
    if(frac<0.5)
    {
      result=n;
    }
    else if(frac>0.5)
    {
        result=n+1;
    }
    else
    {
      if(n%2==0)
      {
        result=n;
      }
      else
      {
        result=n+1;
      }
    }
    cout<<(result/power)<<endl;


}
