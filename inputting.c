#include "functions.h"
int command(char* cmd){
    if(!strcmp(cmd,"signup"))
        return 1;
    if(!strcmp(cmd,"login"))
        return 2;
    if(!strcmp(cmd,"logout"))
        return 3;
    if(!strcmp(cmd,"post"))
        return 4;
    if(!strcmp(cmd,"delete"))
        return 5;
    if(!strcmp(cmd,"info"))
        return 6;
    if(!strcmp(cmd,"find_user"))
        return 7;
    if(!strcmp(cmd,"like"))
        return 8;
    if(!strcmp(cmd,"help"))
        return 9;
    return -1;
}
char* input(char* str_inp){
    int i=0;
    char inp_tmp='x';
    while(1){ 
        inp_tmp=getchar();
        if(inp_tmp==' ' || inp_tmp=='\n') break;
        *(str_inp+i)=inp_tmp;
        i++;
        str_inp=(char*)realloc(str_inp,i+1);
    }
    str_inp[i]='\0';
    return str_inp;
}