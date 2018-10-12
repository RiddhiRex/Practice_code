

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class strings
{
    int len=0;
    char *in_st=NULL;
    public:

    strings(char *str, int l)
    {
        //malloc syntax-> (type casting)malloc(sizeof(datatype_to_store)*length)
        in_st=(char *)malloc(sizeof(char)*l); //assign memory of length l*size of character(1). Not size of character *(which is 8)
        memcpy(in_st, str, l); //syntax of memcpy(dest, src, length)
        len=l;
    }
    int length()
    {
        return len; //since len is private, public method to access it
    }
    char * data()
    {
        return in_st; //since in_st is private. public method to access it
    }
    //copy constructor
    strings(strings &obj)
    {
        char * s=obj.data(); //get the data of object that is passed as arg
        int l = obj.length(); //get len of obj 

        in_st=(char *)malloc(sizeof(char)*l); //allocate memory to store a copy of obj's data.
        memcpy(in_st, s, l);
        len=obj.length();
        //delete s; don't delete s as s contains the copy of obj data and no new memory is newly created to delete here.
    }
    //desctructor
    ~strings()
    {
        delete in_st; //delete name of char*. this deallocates the memory created by malloc function.
    }
    //Operator overloading (+)
    strings& operator+(strings &obj) 
     //return type is string& as we assign the result to another object. Else, return type is just string.
     //Always objects are passed by address(using &)
    {
        int l = len+obj.length(); //size of new string will be len of both strings
        char *tmpstr=(char *)malloc(l*sizeof(char)); //allocate memory to store the new combined longer string

        memcpy(tmpstr, in_st, len); //copy the in_st value into tmpstr
        char *s=obj.data(); //create a char * to store the value of obj's string.
        memcpy(tmpstr+len, s, obj.length()); //copy the obj's string to tmpstr from the position tmpstr[len].
        strings *newst = new strings(tmpstr,l); //create a object using the concatanated string.
        //Here we create new strings object and assign it to a pointer and we finally return the object using this pointer.
        //Here we use new keyword because when a object is created within a function and its scope/lifetime will be within this function only.
        //So we wont be able to access the object's members after we exit this function in future.
        //By using new ,we create object and allocate memory to it, so it will be persistant memory and can be accessed later and outside too.
 
        delete tmpstr; //we have newly allocated memory here. so deallocate it.
        return *newst; //return the value pointed by the pointer(which is strings object). Since it is assigned to another object.
        
    }
    //operator overloading
    bool operator==(strings &obj)
    {
        if(len!=obj.length())
            return false;
        char *s=obj.data();
        //compare each string index by index
        for(int i=0; i<len;i++)
        {
            if(in_st[i]!=s[i])
                //delete s; no need to delete s since no new memory is newly created for it.
                return false;
        }
        //delete s; no need to delete s since no new memory is newly created for it.
        return true;
    }
};
int main()
{
    //initialize new strings
    char c1[6]="hello"; //len is 5 and extra 1 for storing '\0'
    char c2[6]="world"; 

    //create objects
    strings s1(c1, 5);
    strings s2(c2, 5);
    
    strings s3(s1+s2);// not s3= s1 + s2; it will throw error
    //copy constructor
    strings s4(s3);

    cout<<(s3==s4);
    return 0;
}
