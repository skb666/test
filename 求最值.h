/*
    #include "cpp.cpp"
    int main(){
        int a=4,b=1,c=2,d=3,e[]={1,2,3,4,5,6,7,8};
        double aa=3.12,bb=3.14,cc=4.55,dd=5.57,ee[]={1,2,3,4,5,6,7,8};
        char aaa[]="1234",bbb[]="295",ccc[]="sddsf",ddd[]="hello",eee[4][8]={"1234","295","sddsf","hello"};
        string f="1234",g="295",h="ssddsf",i="hello",j[]={"1234","295","ssddsf","hello"},eeee[4]={eee[0],eee[1],eee[2],eee[3]};
        cout<<limit<int>(MAX,4,a,b,c,d)<<endl;
        cout<<limit<int>(MIN,4,a,b,c,d)<<endl;
        cout<<limit<double>(MAX,4,aa,bb,cc,dd)<<endl;
        cout<<limit<double>(MIN,4,aa,bb,cc,dd)<<endl;
        cout<<limit<int>(MAX,e,0,7)<<endl;
        cout<<limit<int>(MIN,e,0,7)<<endl;
        cout<<limit<double>(MAX,ee,0,7)<<endl;
        cout<<limit<double>(MIN,ee,0,7)<<endl;
        cout<<limit<char>(MAX,aaa,0,3)<<endl;
        cout<<limit<char>(MIN,bbb,0,2)<<endl;
        cout<<limit(MAX,4,f,g,h,i)<<endl;
        cout<<limit(MIN,4,f,g,h,i)<<endl;
        cout<<limit(MAX,j,0,3)<<endl;
        cout<<limit(MIN,j,0,3)<<endl;
        cout<<limit(MAX,4,(string)aaa,(string)bbb,(string)ccc,(string)ddd)<<endl;
        cout<<limit(MIN,4,(string)aaa,(string)bbb,(string)ccc,(string)ddd)<<endl;
        cout<<limit(MAX,eeee,0,3)<<endl;
        cout<<limit(MIN,eeee,0,3)<<endl;
        return 0;
    }
*/
#include<bits/stdc++.h>
#define MAX "max"
#define MIN "min"
using namespace std;

template<class T>
T bigger(T a,T b){return a>b?a:b;}

template<class T>
T smaller(T a,T b){return a<b?a:b;}

string bigger(string a,string b){return a.length()!=b.length()?(a.length()>b.length()?a:b):(a>b?a:b);}

string smaller(string a,string b){return a.length()!=b.length()?(a.length()<b.length()?a:b):(a<b?a:b);}

string limit(string ty,int n,...){
    va_list unkown;
    va_start(unkown,n);
    string a,b,value,temp;
    a=va_arg(unkown,string);
    b=va_arg(unkown,string);
    value=ty==MAX?bigger(a,b):smaller(a,b);
    for(int i=0;i<n-2;i++){
        temp=va_arg(unkown,string);
        value=ty==MAX?bigger(value,temp):smaller(value,temp);
    }
    va_end(unkown);
    return value;
}

string limit(string ty,string* acc,int start,int end){
    string value=acc[start];
    for(int i=start+1;i<=end;i++){
        value=ty==MAX?(acc[i]==bigger(acc[i],value)?acc[i]:value):(acc[i]==smaller(acc[i],value)?acc[i]:value);
    }
    return value;
}

//类型最值
template<class T>
T limit(string ty,int n,...){
    va_list unkown;
    va_start(unkown,n);
    T a,b,value,temp;
    a=va_arg(unkown,T);
    b=va_arg(unkown,T);
    value=ty==MAX?bigger<T>(a,b):smaller<T>(a,b);
    for(int i=0;i<n-2;i++){
        temp=va_arg(unkown,T);
        value=ty==MAX?bigger<T>(value,temp):smaller<T>(value,temp);
    }
    va_end(unkown);
    return value;
}

//数组最值
template<class T>
T limit(string ty,T* acc,int start,int end){
    T value=acc[start];
    for(int i=start+1;i<=end;i++){
        value=ty==MAX?(acc[i]==bigger<T>(acc[i],value)?acc[i]:value):(acc[i]==smaller<T>(acc[i],value)?acc[i]:value);
    }
    return value;
}

