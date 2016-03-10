#include<iostream>
using namespace std;
int FindMazorityElement(int a[],int n)
{
    int maj_index=0,count=1,i;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[maj_index])
            count++;
        else
            count--;
        if(count==0)
        {
            count=1;
            maj_index=i;
        }
    }
    return maj_index;
}
void printMazorityElement(int a[],int n)
{
    int count =0;
    int index;
    index=FindMazorityElement(a,n);
    for(int i=0;i<n;i++)
        if(a[index]==a[i])
        count++;
    cout << a[index] <<" Frequency :" << count << endl;
}
int main()
{
    int l,r,n,*a;
    cin >> n;
    a=new int [n];
    l=0;r=n-1;
    for(int i=0;i<n;i++)
        cin >> a[i];
    printMazorityElement(a,n);
    return 0;
}

