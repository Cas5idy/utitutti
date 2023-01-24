#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct liked{
    char* username;
    int id;
    struct liked* next;
}liked;
typedef struct post{
    char* text;
    int likes;
    int id;
    char* username;
    struct post* next;
}post;
typedef struct user{
    char* username;
    char* password;
    int lastid;
    int postcnt;
    struct user* next;
    post* posts;
    liked* likes;
}user;
user* find_user(user* head,char* un);
post* find_post(user* cur_user,int pst_id);
int pw_checker(user* head,char* pw);
int signup(char* un,char* pw,user* head);
user* login(char* un,char* pw,user* head);
int liking(user* cur_user,user* head,char* un,int id);
int show_post(post* post);
int show_info(user* user,int sec_flag);
int posting(char* text,user* user);
int del_post(int pst_id,user* user);
int command(char* cmd);
char* input(char* str_inp);