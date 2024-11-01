#include<bits/stdc++.h>
using namespace std;
float func(float x,float y)
{
    float f;
    f = (y-x)/(y+x);
    return f;
}
int main()
{
    float a,b,x,y,h,t,k;
    cout<<"Enter Xo, Yo, h, Xn : ";
    cin>>a>>b>>h>>t;
    x = a;
    y = b;
    cout<<endl<<"x\ty"<<endl;
    while(x<t)
    {
        k = h * func(x,y);
        cout<<x<<"\t"<<y<<endl;
        y = y + k;
        x = x + h;
    }
}
