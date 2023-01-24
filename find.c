#include "functions.h"
user* find_user(user* head,char* un){
    user* cur_user=head->next;
    while(cur_user!=NULL){
        if(!strcmp(cur_user->username,un)){ //checks whether the username is matched
            return cur_user;
        }
        cur_user=cur_user->next;
    }
    return NULL;
}
post* find_post(user* cur_user,int pst_id){
    post* cur_post=cur_user->posts;
    while(cur_post->next!=NULL){
        if((cur_post->next->id)==pst_id){ //checks whether the post id is matched         
            return cur_post;
        }
        cur_post=cur_post->next;
    }
    return NULL;
}