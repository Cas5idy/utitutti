#include "functions.h"
int pw_checker(user* head,char* pw){
    if(head==NULL) return 0;
    user* cur_user=(user*)malloc(sizeof(user)); 
    cur_user=head->next;
    while(cur_user!=NULL){
        if(strcmp(cur_user->password,pw)==0){ //checks whether the password is matched
            return 1;
        }
        cur_user=cur_user->next;
    }
    return 0;
}
int signup(char* un,char* pw,user* head){
    if(find_user(head,un)!=NULL)
        return 1;
    if(pw_checker(head,pw)==1)
        return 2;
    user* new_user=(user*)malloc(sizeof(user)); //creates a new user node
    new_user->username=(char*)malloc(301);
    new_user->password=(char*)malloc(301);
    strcpy(new_user->username,un);
    strcpy(new_user->password,pw);
    new_user->lastid=-1;
    new_user->next=NULL;
    new_user->postcnt=0;
    new_user->posts=NULL;
    new_user->likes=NULL;
    user* cur_user=head;
    while(cur_user->next!=NULL) //adds it to the end of the linked list
        cur_user=cur_user->next;
    cur_user->next=new_user;
    return 0;
}
user* login(char* un,char* pw,user* head){
    if(find_user(head,un)==NULL || strcmp(find_user(head,un)->password,pw)!=0) //checks whether the username or the password is matched
        return NULL;
    return find_user(head,un);
}