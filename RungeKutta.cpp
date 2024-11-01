#include<bits/stdc++.h>
using namespace std;
float f(float x,float y)
{
    return x-y;
}
int main()
{
    int n;
    float x0,y0,h,x,k1,k2,k3,k4;
    cout<<"Enter the value of x : ";
    cin>>x;
    cout<<"Enter the initial value of x and y : ";
    cin>>x0>>y0;
    cout<<"Enter the value of h : ";
    cin>>h;
    cout<<"x0 = "<<x0<<"\ty0 = "<<y0<<"\th = "<<h<<endl;
    n = (x - x0)/h;
    for(int i=1;i<=n;i++)
    {
        k1 = h * f(x0,y0);
        k2 = h * f(x0+h/2, y0+k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 = x0 + h;
    }
    cout<<"At x = "<<x<<" y = "<<y0;
}
