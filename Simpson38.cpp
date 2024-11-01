#include<iostream>
#include<math.h>
using namespace std;
#define f(x) 1/(1+pow(x,2))
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
    for(int i=1;i<n-1;i++)
    {
        k = a+i*h;
        if(i%3 == 0)
        {
            integration = integration + 2*f(k);
        }
        else{
            integration = integration + 3*f(k);
        }
    }
    integration = integration * h * (3/8);
    cout<<"Required value of integration is = "<<integration;
}
