#include "functions.h"
int posting(char* text,user* user){
    int pst_id=(user->lastid)+1;
    user->lastid+=1; //updates the last id 
    post* newpost=(post*)malloc(sizeof(post));
    newpost->text=(char*)malloc(strlen(text)+1);
    newpost->username=(char*)malloc(strlen(user->username)+1);
    strcpy(newpost->text,text);
    strcpy(newpost->username,user->username);
    newpost->likes=0;
    newpost->id=pst_id;
    newpost->next=NULL;
    post* cur_post=user->posts;
    if(pst_id==0) //adds the new post to the end of the linked list
        user->posts=newpost;
    else{
        while(cur_post->next!=NULL){
            cur_post=cur_post->next;
        }
        cur_post->next=newpost;
    }
    return 0;
}
int del_post(int pst_id,user* user){
    if(pst_id==user->posts->id){
        free(user->posts);
        user->posts=user->posts->next;
        return 0;
    }else if(find_post(user,pst_id)!=NULL){
        post* cur_post=find_post(user,pst_id);
        free(cur_post->next);
        cur_post->next=cur_post->next->next;
        return 0;
    }
    return 1;
}