#include "functions.h"
int show_post(post* post){
    printf("user: %s\n",post->username);
    printf("post_id: %d\n",post->id);
    printf("likes: %d\n",post->likes);
    printf("post: %s\n",post->text);
}
int show_info(user* user,int sec_flag){
    printf("username: %s\n",user->username);
    if(sec_flag==1)
        printf("password: %s\n",user->password);
    post* user_post=user->posts;
    while(user_post!=NULL){
        show_post(user_post);
        user_post=user_post->next;
        printf("\n");    
    }
}