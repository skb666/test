#include<iostream>
using namespace std;

void Swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
void QuickSort(int a[],int start,int end){
    if(start>=end)return;
    int k=a[start],i=start,j=end;
    while(i!=j){
        while(i<j&&a[j]>=k)j--;
        Swap(a[i],a[j]);
        while(i<j&&a[i]<=k)i++;
        Swap(a[i],a[j]);
    }
    QuickSort(a,start,i-1);
    QuickSort(a,i+1,end);
}
int main(){
    int n[]={1,6,4,8,9,4,60,59,4345,847,23,4,55,935,34,89};
    QuickSort(n,0,15);
    for(int i=0;i<=15;i++)cout<<n[i]<<' ';    
    cout<<endl;
    return 0;
}
