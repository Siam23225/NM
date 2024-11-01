#include<bits/stdc++.h>
using namespace std;
#define f(x) log(x)
int main()
{
    float a,b,integration,h,k;
    int n;
    cout<<"Enter lower limit : ";
    cin>>a;
    cout<<"Enter upper limit : ";
    cin>>b;
    cout<<"Enter the sub-interval : ";
    cin>>n;
    h = (b-a)/n;
    integration = f(a) + f(b);
    for(int i=1; i<=n;i++)
    {
        k = a + i*h;
        integration = integration + 2*f(k);
    }
    integration = integration * (h/2);
    cout<<"Required value of integration is = "<<integration;
}
