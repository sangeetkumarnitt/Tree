#include<iostream>
using namespace std;

static  int DP[10001][10001];
int min(int a,int b,int c)
{

    if(a>b)
        return a>c ?a:c;
    else
        return b>c ?b:c;
}
int main()
{
    int n;
    cin >> n;
    int a[n+1];
    int i;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        DP[i][0]=1;
        DP[0][i]=1;
    }
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            DP[i][i]=+1;
            DP[i][i-1]=+1;
            DP[i-1][i]=+1;
        }
        else
        {
            DP[i][i]=min(DP[i-1][i-1],DP[i][i-1],DP[i-1][i]);
        }
    }
    cout << DP[n-1][n-1];
    return 0;
}
