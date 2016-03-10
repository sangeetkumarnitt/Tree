#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    cout << *a <<" "<<*b <<endl;
}
int main()
{
    int l,r,n,*a;
    cin >> n;
    a=new int [n];
    l=0;r=n-1;
    for(int i=0;i<n;i++)
        cin >> a[i];

     while(l<r)
     {
         while(a[l]%2==1 && l<r)
            l++;
         while(a[r]%2==0 && l<r)
            r--;
         if(l<r)
         {
             swap(&a[l],&a[r]);
             l++;
             r--;
         }

     }
        for(int i=0;i<n;i++)
        cout << a[i] <<" ";
    return 0;
}
