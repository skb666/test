#include<iostream>
using namespace std;

void Merge(int a[],int start,int mid,int end,int t[]){
    int p=0,p1=start,p2=mid+1;
    while(p1<=mid&&p2<=end){
        if(a[p1]<a[p2])t[p++]=a[p1++];
        else t[p++]=a[p2++];
    }
    while(p1<=mid)t[p++]=a[p1++];
    while(p2<=end)t[p++]=a[p2++];
    for(int i=0;i<=end-start;i++)a[start+i]=t[i];
}
void MergeSort(int a[],int start,int end,int t[]){
    if(start<end){
        int mid=start+(end-start)/2;
        MergeSort(a,start,mid,t);
        MergeSort(a,mid+1,end,t);
        Merge(a,start,mid,end,t);
    }
}
int main(){
    int n[]={1,6,4,8,9,4,60,59,4345,847,23,4,55,935,34,89};
    int t[20];
    MergeSort(n,0,15,t);
    for(int i=0;i<=15;i++)cout<<t[i]<<' ';    
    cout<<endl;
    return 0;
}
