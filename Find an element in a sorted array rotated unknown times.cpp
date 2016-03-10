#include<iostream>
using namespace std;
int FindPivot(int a[],int n)
{
    int i,l,h,m;
    l=0;h=n-1;
    if(a[l]<a[h])
        return 0;
    while(l<h)
    {
        m=(h+l)/2;
        if(a[l]<a[m])
            l=m;
        else
            h=m;
    }
    return m+1;
}
int BinarySearch(int a[],int l,int h,int data)
{
    int mid;
   while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==data)
            return mid;
        if(data>a[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;

}
int FindElement(int a[],int n,int data)
{
    int pivot=FindPivot(a,n);
    int index=-1;
    if(pivot==0)
        index=BinarySearch(a,0,n-1,data);
    else
    {
        if(data>a[0])
            index=BinarySearch(a,0,pivot-1,data);
        else
            index=BinarySearch(a,pivot,n-1,data);
    }
    return index;
}
int main()
{
    int i,n,*a,data;
    cin >> n;
    a=new int [n];
    for(i=0;i<n;i++)
        cin >> a[i];
        cin >> data;

    cout <<FindElement(a,n,data);
    return 0;
}
