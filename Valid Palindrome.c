#include<string.h>
bool isPalindrome(char* s) {
    int r = strlen(s)-1;
    int l=0;

    while(l<=r){
        while(l<=r && !isdigit(s[l]) && (tolower(s[l])<'a' || tolower(s[l])>'z')){
            l+=1;
        }
        while(r>=l && !isdigit(s[r]) && (tolower(s[r])<'a' || tolower(s[r]>'z')))
            r-=1;
        if(l<=r && tolower(s[l])!=tolower(s[r]))
            return false;
        l+=1;
        r-=1;
    }
    return true;
}
