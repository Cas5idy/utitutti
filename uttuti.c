#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
int main(){
    user* head=(user*)malloc(sizeof(user)); //head of the users linked list
    user* cur_user=(user*)malloc(sizeof(user)); //current logged in user
    cur_user->next=NULL;
    cur_user=NULL;
    head->username=(char*)malloc(2);
    head->password=(char*)malloc(2);
    head->next=NULL;
    head->posts=NULL;
    head->likes=NULL;
    strcpy(head->username,"x");
    strcpy(head->password,"x");
    while(1){
        char* cmd=(char*)malloc(1); 
        cmd=input(cmd);
        int cmd_id=command(cmd);
        free(cmd);
        if(cmd_id==1){ //signup
            char* un=(char*)malloc(1);
            un=input(un);
            char* pw=(char*)malloc(1); 
            pw=input(pw);
            int id_tmp=signup(un,pw,head);
            if(id_tmp==1)
                printf("username already exists\n");
            else if(id_tmp==2)
                printf("password already exists\n");
            else
                printf("user %s successfully signed up with %s as the password\n",un,pw);
            free(un);
            free(pw);
        }else if(cmd_id==2){ //login
                char* un=(char*)malloc(1);
                un=input(un);
                char* pw=(char*)malloc(1); 
                pw=input(pw);
                if(cur_user==NULL){
                    cur_user=login(un,pw,head);
                    if(cur_user==NULL){
                        printf("wrong username or password\n");
                    }else{
                        printf("user %s successfully logged in,welcome bro\n",un);
                    }
                }else
                    printf("another user is currently logged in\n");
                free(un);
                free(pw);
        }else if(cmd_id==3){ //logout
            printf("user %s successfully logged out\n",cur_user->username);
            cur_user=NULL;
        }else if(cmd_id==4){ //post
            char* text=(char*)malloc(1);
            int i=0;
            char inp_tmp='x';
            while(1){ //the reason we are not using the input function is that we don't have to end the allocation with spaces
                inp_tmp=getchar();
                if(inp_tmp=='\n') break;
                *(text+i)=inp_tmp;
                i++;
               text=(char*)realloc(text,i+1);
            }
            text[i]='\0';
            if(cur_user!=NULL){
                posting(text,cur_user);
                printf("your post has been submited\n");
            }else{
                printf("no user is currently logged on\n");
            }
            free(text);
        }else if(cmd_id==5){ //delete
            int id;
            scanf("%d",&id);
            if(cur_user==NULL)
                printf("no user is currently logged on\n");
            else{
                int del_tmp=del_post(id,cur_user);
                if(del_tmp==1)
                    printf("no post was found with given id, oops\n");
                else
                    printf("the post with %d as its id has been deleted\n",id);
            }
        }else if(cmd_id==6){ //info
            if(cur_user==NULL)
                printf("no user is currently logged on\n");
            else
                show_info(cur_user,1);
        }else if(cmd_id==7){ //find_user
            char* un=(char*)malloc(1);
            un=input(un);
            if(find_user(head,un)==NULL)
                printf("no such user was found\n");
            else
                show_info(find_user(head,un),0);
            free(un);
        }else if(cmd_id==8){
            char* un=(char*)malloc(1);
            un=input(un);
            int id;
            scanf("%d",&id);
            int like_tmp=liking(cur_user,head,un,id);
            if(like_tmp==0)
                printf("you liked %s's post with %d as it's id\n",un,id);
            else if(like_tmp==1)
                printf("you've alreadly liked this post\n");
            else if(like_tmp==2)
                printf("no such user was found\n");
            else
                printf("no such post was found, type find_user <username> to see the user's post\n");
            free(un);
        }else if(cmd_id==9){
            printf("to signup: signup <username> <password>\nto login: login <username> <password>\nto logout: logout\nto post: post <text>\nto delete a certain post: delete <post_id>\nto like a certain post: like <username> <post_id>\nto show your info: info\nto find a certain user: find_user <username>\nto bring up this page: help\n");
        }else{
            printf("no such command exists, type help to see the valid commands list\n");
        }
    }
}