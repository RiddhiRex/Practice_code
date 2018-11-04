int compareVersion(char* version1, char* version2) {
    int i=0;
    int j=0;
    while(version1[i] || version2[j]){
        int v1=0;
        int v2=0;
        while(version1[i] && version1[i]!='.') {
            v1=v1*10 + version1[i]-'0';
            i+=1;
        }
        if(version1[i]=='.')
            i+=1;
        while(version2[j] && version2[j]!='.') {
            v2=v2*10 + version2[j]-'0';
            j+=1;
        }
        if(version2[j]=='.')
            j+=1;
        if(v1>v2)
            return 1;
        else if(v1<v2)
            return -1;
    }
    return 0;
}
