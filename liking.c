#include "functions.h"
int liking(user* cur_user,user* head,char* un,int id){
    int post_flag=0; //the flag that checks whether the post exists or not 
    user* target_user=find_user(head,un);
    if(target_user==NULL) //checsk whether the user exists or not
        return 2;
    post* target_post=target_user->posts;
    while(target_post!=NULL){
        if(target_post->id==id){
            post_flag=1;
            break;
        }
        target_post=target_post->next;
    }
    if(post_flag==0)
        return 3;
    if(cur_user->likes!=NULL){ //checks if this like is the user's first like
        liked* like_list=cur_user->likes;
        if(cur_user->likes->id==id && strcmp(cur_user->likes->username,un)==0) //checks if the post is alrealy liked by this user
            return 1;
        while(like_list!=NULL){
            printf("%s",like_list->username);
            if(like_list->id==id && strcmp(like_list->username,un)==0)
                return 1;
            like_list=like_list->next;
        }
        liked* new_liked=(liked*)malloc(sizeof(liked));
        new_liked->username=(char*)malloc(strlen(un)+1);
        strcpy(new_liked->username,un);
        new_liked->id=id;
        new_liked->next=NULL;
        liked* cur_liked=(liked*)malloc(sizeof(liked));
        cur_liked=cur_user->likes;
        while(cur_liked->next!=NULL){
            cur_liked=cur_liked->next;
        }   
        cur_liked->next=new_liked;
    }else{
        liked* new_liked=(liked*)malloc(sizeof(liked));
        new_liked->username=(char*)malloc(strlen(un)+1);
        strcpy(new_liked->username,un);
        new_liked->next=NULL;
        new_liked->id=id;
        cur_user->likes=new_liked;
    }
    if(!id) //increases the like count of that post
        (target_user->posts->likes)++;
    else{
        post* cur_post=find_post(target_user,id);
        (cur_post->next->likes)++;
    }
    return 0;
}