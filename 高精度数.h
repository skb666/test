#include<bits/stdc++.h>
using namespace std;
struct Parted{
    string t="";
    int jw=0;
};
class HighPrecision{
    public:
        string integer="0";
        string decimal="0";
        int positive=1;

        HighPrecision(string a=""){
            int a_l=a.length(),bj=0;
            for(int i=0;i<a_l;i++){
                if((a[i]<'0'||a[i]>'9')&&a[i]!='.'&&a[i]!='-'&&a[i]!='+'){
                    bj=1;
                    break;
                }
            }
            if(bj==0){
                input(a);
            }else{
                try {
                    string yc="Value error, please enter purely numeric characters!";
                    yfyc(yc);
                }catch(invalid_argument& c){
                    cerr<<c.what()<<endl;
                    exit(0);
                }
            }
        }
        template<class T>
        HighPrecision(T a){
            string t=ntos<T>(a);
            if(t.length()>8){
                try {
                    string yc="Value error, please try using \"string\"!";
                    yfyc(yc);
                }catch(invalid_argument& c){
                    cerr<<c.what()<<endl;
                    exit(0);
                }
            }else{
                input(t);
            }
        }
        void abs(){
            this->positive=1;
        }
        int operator==(HighPrecision &obj){
            if(this->integer==obj.integer&&this->decimal==obj.decimal&&this->positive==obj.positive){
                return 1;
            }else{
                return 0;
            }
        }
        int operator>(HighPrecision &obj){
            if(!this->positive&&obj.positive)return 0;
            else if(this->positive&&!obj.positive)return 1;
            else if(this->positive&&obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal>obj.decimal)return 1;
                    else return 0;
                }else if(this->integer==bigger(this->integer,obj.integer)){
                    return 1;
                }else if(obj.integer==bigger(this->integer,obj.integer)){
                    return 0;
                }
            }
            else if(!this->positive&&!obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal>=obj.decimal)return 0;
                    else return 1;
                }else if(this->integer==bigger(this->integer,obj.integer)){
                    return 0;
                }else if(obj.integer==bigger(this->integer,obj.integer)){
                    return 1;
                }
            }
        }
        int operator>=(HighPrecision &obj){
            if(!this->positive&&obj.positive)return 0;
            else if(this->positive&&!obj.positive)return 1;
            else if(this->positive&&obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal>=obj.decimal)return 1;
                    else return 0;
                }else if(this->integer==bigger(this->integer,obj.integer)){
                    return 1;
                }else if(obj.integer==bigger(this->integer,obj.integer)){
                    return 0;
                }
            }
            else if(!this->positive&&!obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal>obj.decimal)return 0;
                    else return 1;
                }else if(this->integer==bigger(this->integer,obj.integer)){
                    return 0;
                }else if(obj.integer==bigger(this->integer,obj.integer)){
                    return 1;
                }
            }
        }
        int operator<(HighPrecision &obj){
            if(!this->positive&&obj.positive)return 1;
            else if(this->positive&&!obj.positive)return 0;
            else if(this->positive&&obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal<obj.decimal)return 1;
                    else return 0;
                }else if(this->integer==smaller(this->integer,obj.integer)){
                    return 1;
                }else if(obj.integer==smaller(this->integer,obj.integer)){
                    return 0;
                }
            }
            else if(!this->positive&&!obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal<=obj.decimal)return 0;
                    else return 1;
                }else if(this->integer==smaller(this->integer,obj.integer)){
                    return 0;
                }else if(obj.integer==smaller(this->integer,obj.integer)){
                    return 1;
                }
            }
        }
        int operator<=(HighPrecision &obj){
            if(!this->positive&&obj.positive)return 1;
            else if(this->positive&&!obj.positive)return 0;
            else if(this->positive&&obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal<=obj.decimal)return 1;
                    else return 0;
                }else if(this->integer==smaller(this->integer,obj.integer)){
                    return 1;
                }else if(obj.integer==smaller(this->integer,obj.integer)){
                    return 0;
                }
            }
            else if(!this->positive&&!obj.positive){
                if(this->integer==obj.integer){
                    if(this->decimal<obj.decimal)return 0;
                    else return 1;
                }else if(this->integer==smaller(this->integer,obj.integer)){
                    return 0;
                }else if(obj.integer==smaller(this->integer,obj.integer)){
                    return 1;
                }
            }
        }
        HighPrecision operator++(){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t+=1;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
            return t;
        }
        HighPrecision operator++(int){
            HighPrecision t,temp;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            temp=t;
            ++t;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
            return temp;
        }
        HighPrecision operator--(){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t-=1;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
            return t;
        }
        HighPrecision operator--(int){
            HighPrecision t,temp;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            temp=t;
            --t;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
            return temp;
        }
        HighPrecision operator+(){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            return t;
        }
        HighPrecision operator+(HighPrecision &obj){
            HighPrecision temp;
            Parted t;
            if((this->positive&&obj.positive)||(!this->positive&&!obj.positive)){
                int p,ys=0;
                temp.integer=integer_add(this->integer,obj.integer);
                t=decimal_add(this->decimal,obj.decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        p=(temp.integer[i]-'0')+t.jw;
                        t.jw=p/10;
                        ys=p%10;
                        d+='0'+ys;
                    }
                    if(t.jw!=0)d+='0'+t.jw;
                    reverse(d.begin(),d.end());
                    temp.integer=d;
                }
                if(!obj.positive)temp.positive=0;
            }else if(this->positive&&!obj.positive){
                int p=0;
                HighPrecision tt=obj;
                tt.abs();
                if(this->operator<(tt))temp.positive=0;
                temp.integer=integer_sub(this->integer,obj.integer);
                t=decimal_sub(this->decimal,obj.decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        if(t.jw==-1){
                            temp.integer[i]=(temp.integer[i]-'0'+t.jw)+'0';
                            t.jw=0;
                        }
                        p=temp.integer[i]-'0';
                        if(p<0){
                            p=temp.integer[i]-'0'+10;
                            t.jw=-1;
                        }
                        d+='0'+p;
                    }
                    while(d[d.length()-1]=='0'){d=d.substr(0,d.length()-1);}
                    reverse(d.begin(),d.end());
                    if(!d.length())d="0";
                    temp.integer=d;
                }
            }else if(!this->positive&&obj.positive){
                int p=0;
                HighPrecision tt;
                tt.integer=this->integer;
                tt.decimal=this->decimal;
                if(tt.operator>(obj))temp.positive=0;
                temp.integer=integer_sub(this->integer,obj.integer);
                t=decimal_sub(obj.decimal,this->decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        if(t.jw==-1){
                            temp.integer[i]=(temp.integer[i]-'0'+t.jw)+'0';
                            t.jw=0;
                        }
                        p=temp.integer[i]-'0';
                        if(p<0){
                            p=temp.integer[i]-'0'+10;
                            t.jw=-1;
                        }
                        d+='0'+p;
                    }
                    while(d[d.length()-1]=='0'){d=d.substr(0,d.length()-1);}
                    reverse(d.begin(),d.end());
                    if(!d.length())d="0";
                    temp.integer=d;
                }
            }
            return temp;
        }
        template<class T>
        HighPrecision operator+(const T &obj){
            T temp=obj;
            HighPrecision t=temp;
            return this->operator+(t);
        }
        HighPrecision operator-(){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            if(this->positive)t.positive=0;
            else t.positive=1;
            return t;
        }
        HighPrecision operator-(HighPrecision &obj){
            HighPrecision temp;
            Parted t;
            if((!this->positive&&obj.positive)||(this->positive&&!obj.positive)){
                int p,ys=0;
                temp.integer=integer_add(this->integer,obj.integer);
                t=decimal_add(this->decimal,obj.decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        p=(temp.integer[i]-'0')+t.jw;
                        t.jw=p/10;
                        ys=p%10;
                        d+='0'+ys;
                    }
                    if(t.jw!=0)d+='0'+t.jw;
                    reverse(d.begin(),d.end());
                    temp.integer=d;
                }
                if(!this->positive)temp.positive=0;
            }else if(this->positive&&obj.positive){
                int p=0;
                if(this->operator<(obj))temp.positive=0;
                temp.integer=integer_sub(this->integer,obj.integer);
                t=decimal_sub(this->decimal,obj.decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        if(t.jw==-1){
                            temp.integer[i]=(temp.integer[i]-'0'+t.jw)+'0';
                            t.jw=0;
                        }
                        p=temp.integer[i]-'0';
                        if(p<0){
                            p=temp.integer[i]-'0'+10;
                            t.jw=-1;
                        }
                        d+='0'+p;
                    }
                    while(d[d.length()-1]=='0'){d=d.substr(0,d.length()-1);}
                    reverse(d.begin(),d.end());
                    if(!d.length())d="0";
                    temp.integer=d;
                }
            }else if(!this->positive&&!obj.positive){
                int p=0;
                HighPrecision tt=obj;
                tt.abs();
                if(this->operator>(tt))temp.positive=0;
                temp.integer=integer_sub(this->integer,obj.integer);
                t=decimal_sub(obj.decimal,this->decimal);
                temp.decimal=t.t;
                if(t.jw!=0){
                    string d="";
                    for(int i=temp.integer.length()-1;i>=0;i--){
                        if(t.jw==-1){
                            temp.integer[i]=(temp.integer[i]-'0'+t.jw)+'0';
                            t.jw=0;
                        }
                        p=temp.integer[i]-'0';
                        if(p<0){
                            p=temp.integer[i]-'0'+10;
                            t.jw=-1;
                        }
                        d+='0'+p;
                    }
                    while(d[d.length()-1]=='0'){d=d.substr(0,d.length()-1);}
                    reverse(d.begin(),d.end());
                    if(!d.length())d="0";
                    temp.integer=d;
                }
            }
            return temp;
        }
        template<class T>
        HighPrecision operator-(const T &obj){
            T temp=obj;
            HighPrecision t=temp;
            return this->operator-(t);
        }
        void operator+=(HighPrecision &obj){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t=t+obj;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
        }
        template<class T>
        void operator+=(const T &obj){
            T temp=obj;
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t=t+temp;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
        }
        void operator-=(HighPrecision &obj){
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t=t-obj;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
        }
        template<class T>
        void operator-=(const T &obj){
            T temp=obj;
            HighPrecision t;
            t.integer=this->integer;
            t.decimal=this->decimal;
            t.positive=this->positive;
            t=t-temp;
            this->integer=t.integer;
            this->decimal=t.decimal;
            this->positive=t.positive;
        }
    private:
        int dot=-1;
        string bigger(string &a,string &b){
            if(a.length()!=b.length())return a.length()>b.length()?a:b;
            else return a>b?a:b;
        }
        string smaller(string &a,string &b){
            if(a.length()!=b.length())return a.length()<b.length()?a:b;
            else return a<b?a:b;
        }
        void yfyc(string &a){throw invalid_argument(a);}
        void input(string &a){
            int a_l=a.length(),bj=0,g=0;
            if(a_l)integer="";
            for(int i=0;i<a_l;i++){
                if(a[i]=='+')i++;
                if(a[i]=='-'){
                    positive=0;
                    i++;
                }
                if(a[i]=='.'){
                    bj=1;
                    dot=i;
                    i++;
                    decimal="";
                }
                if(bj==0){
                    integer+=a[i];
                }else{
                    decimal+=a[i];
                }
            }
            while(integer[0]=='0'){integer=integer.substr(1,integer.length()-1);}
            while(decimal[decimal.length()-1]=='0'){decimal=decimal.substr(0,decimal.length()-1);}
            if(!integer.length())integer="0";
            if(!decimal.length())decimal="0";
        }
        template<class T>
        string ntos(T &a){
            stringstream t;
            string s;
            t<<a;
            t>>s;
            return s;
        }
        string integer_add(string &a,string &b){
            string t="",longer=bigger(a,b),shorter=smaller(a,b);
            int l_l=longer.length()-1,s_l=shorter.length()-1,temp=0,jw=0,ys=0;
            for(int i=s_l;i>=0;i--){
                temp=(longer[l_l]-'0')+(shorter[i]-'0')+jw;
                jw=temp/10;
                ys=temp%10;
                t+='0'+ys;
                l_l--;
            }
            for(int j=l_l;j>=0;j--){
                temp=(longer[j]-'0')+jw;
                jw=temp/10;
                ys=temp%10;
                t+='0'+ys;
            }
            if(jw!=0)t+='0'+jw;
            reverse(t.begin(),t.end());
            return t;
        }
        Parted decimal_add(string &a,string &b){
            Parted p;
            string longer=bigger(a,b),shorter=smaller(a,b);
            int l_l=longer.length()-1,s_l=shorter.length()-1,temp=0,jw=0,ys=0;
            for(int i=l_l;i>s_l;i--){
                p.t+=longer[i];
            }
            for(int j=s_l;j>=0;j--){
                temp=(longer[j]-'0')+(shorter[j]-'0')+jw;
                jw=temp/10;
                ys=temp%10;
                p.t+='0'+ys;
            }
            if(jw!=0)p.jw=jw;
            reverse(p.t.begin(), p.t.end());
            while(p.t[p.t.length()-1]=='0'){p.t=p.t.substr(0,p.t.length()-1);}
            if(!p.t.length())p.t="0";
            return p;
        }
        string integer_sub(string &a,string &b){
            string t="",longer=bigger(a,b),shorter=smaller(a,b);
            int l_l=longer.length()-1,s_l=shorter.length()-1,temp=0,jw=0;
            for(int i=s_l;i>=0;i--){
                if(jw==-1){
                    longer[l_l]=((longer[l_l]-'0')+jw)+'0';
                    jw=0;
                }
                temp=(longer[l_l]-'0')-(shorter[i]-'0');
                if(temp<0){
                    temp=(longer[l_l]-'0'+10)-(shorter[i]-'0');
                    jw=-1;
                }
                t+='0'+temp;
                l_l-=1;
            }
            for(int j=l_l;j>=0;j--){
                if(jw==-1){
                    longer[j]=((longer[j]-'0')+jw)+'0';
                    jw=0;
                }
                temp=longer[j]-'0';
                if(temp<0){
                    temp=longer[j]-'0'+10;
                    jw=-1;
                }
                t+='0'+temp;
                l_l-=1;
            }
            while(t[t.length()-1]=='0'){t=t.substr(0, t.length()-1);}
            reverse(t.begin(),t.end());
            if(!t.length())t="0";
            return t;
        }
        Parted decimal_sub(string &a,string &b){
            Parted p;
            string aa=a,bb=b,s="";
            int l_l=bigger(a,b).length(),temp=0,jw=0;
            if(a.length()<l_l){for(int i=0;i<l_l-a.length();i++)aa+='0';}
            if(b.length()<l_l){for(int i=0;i<l_l-b.length();i++)bb+='0';}
            for(l_l--;l_l>=0;l_l--){
                if(jw==-1){
                    aa[l_l]=((aa[l_l]-'0')+jw)+'0';
                    jw=0;
                }
                temp=(aa[l_l]-'0')-(bb[l_l]-'0');
                if(temp<0){
                    temp=(aa[l_l]-'0'+10)-(bb[l_l]-'0');
                    jw=-1;
                }
                s+='0'+temp;
            }
            reverse(s.begin(),s.end());
            while(s[s.length()-1]=='0'){s=s.substr(0,s.length()-1);}
            if(!s.length())s="0";
            p.t=s;
            p.jw=jw;
            return p;
        }
};
ostream& operator<<(ostream &out,HighPrecision &obj){
    if(obj.positive==0)out<<'-';
    out<<obj.integer<<"."<<obj.decimal;
    return out;
}
istream& operator>>(istream &in,HighPrecision &obj){
    string temp;
    in>>temp;
    obj=HighPrecision(temp);
    return in;
}
/*
int main(){
    HighPrecision num=(string)"0",hh="2",v=3,t;
    t=--num+hh;
    cout<<num<<endl;
    cout<<hh<<endl;
    cout<<v<<endl;
    cout<<t<<endl;
    return 0;
}
*/
