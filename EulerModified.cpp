#include<bits/stdc++.h>
using namespace std;
float f(float x,float y);
int main()
{
    float x0,y0,x1,y1,h,yp;
    int n;
    cout<<"Enter the values of x0 and y0 : ";
    cin>>x0>>y0;
    cout<<"Enter the difference between x value : ";
    cin>>h;
    cout<<"Enter the number of iteration : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        x1 = x0 + h;
        yp = y0 + h*f(x0,y0);
        y1 = y0 + (f(x0,y0) + f(x1,yp))/2;
        x0 = x1;
        y0 = y1;
        cout<<"y("<<x1<<") = "<<y1;
    }
}
 float f(float x,float y)
    {
        float z;
        z = 1 + x*y;
        return z;
    }
