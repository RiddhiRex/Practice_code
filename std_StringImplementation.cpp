

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class strings
{
    int len=0;
    char *in_st=NULL;
    public:
    
    strings()
    {
        //nothing?
    }
    strings(char *str, int l)
    {
        in_st=(char *)malloc(sizeof(char)*l);
        memcpy(in_st, str, l);
        len=l;
    }
    int length()
    {
        return len;
    }
    char * data()
    {
        return in_st;
    }
    strings(strings &obj)
    {
        char * s=obj.data();
        int l = obj.length();

        in_st=(char *)malloc(sizeof(char)*l);
        memcpy(in_st, s, l);
        len=obj.length();
        //delete s;
    }
    ~strings()
    {
        delete in_st;
    }
    strings& operator+(strings &obj)
    {
        
        int l = len+obj.length();
        char *tmpstr=(char *)malloc(l*sizeof(char));

        memcpy(tmpstr, in_st, len);

        char *s=obj.data();
        memcpy(tmpstr+len, s, obj.length());

        strings *newst = new strings(tmpstr,l);// = strings(tmpstr, l);

        delete tmpstr;
        return *newst;
        
    }
    bool operator==(strings &obj)
    {
        if(len!=obj.length())
            return false;
        char *s=obj.data();
        for(int i=0; i<len;i++)
        {
            if(in_st[i]!=s[i])
                //delete s;
                return false;
        }
        //delete s;
        return true;
    }
};
int main()
{
    char c1[6]="hello";
    char c2[6]="world";

    strings s1(c1, 5);
    strings s7(s1);

    strings s2(c2, 5);
    strings s3(s1+s2);// s1 + s2;

    strings s4(s3);

    cout<<(s3==s4);
    return 0;
}
