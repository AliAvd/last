//
// Created by sama laptop on 2/11/2022.
//
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#ifdef main
#undef main
#endif
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "menu.h"
#include "Map.h"
void make_map1_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]){
    char reshte[100];
    int i = 0;
    file = fopen("Map1.txt","r");
    while (fgets(reshte,100,file)!=NULL){
        sscanf(reshte,"%d %d %d %d",&random_x[i],&random_y[i],&length[i],&sign[i]);
        i++;
    }
    fclose(file);
}
void make_map2_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]){
    char reshte[100];
    int i = 0;
    file = fopen("Map2.txt","r");
    while (fgets(reshte,100,file)!=NULL){
        sscanf(reshte,"%d %d %d %d",&random_x[i],&random_y[i],&length[i],&sign[i]);
        i++;
    }
    fclose(file);
}
void make_map3_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]){
    char reshte[100];
    int i = 0;
    file = fopen("Map3.txt","r");
    while (fgets(reshte,100,file)!=NULL){
        sscanf(reshte,"%d %d %d %d",&random_x[i],&random_y[i],&length[i],&sign[i]);
        i++;
    }
    fclose(file);
}
void add_at_tail(struct Box* head,int x1,int y1,int length,int sign,int count){
    while (head->next!=NULL){
        head = head->next;
    }
    head->next= (struct Box*)malloc(sizeof(struct Box));
    head->next->is_add = 1;
    head->next->count = 0;
    head->next->x1 = x1;
    head->next->y1 = y1;
    head->next->length = length;
    head->next->sign = sign;
    head->next->count = count;
    head->next->next = NULL;
}
struct Box* initializing_map(struct Box* head,int random_x[],int random_y[],int length[],int sign[],int random_count[],int z){
    head->x1 = random_x[0];
    head->y1 = random_y[0];
    head->length = length[0];
    head->sign = sign[0];
    head->count = random_count[0];
    head->is_add = 1;
    head->next = NULL;
    for (int i = 1;i < z;i++){
        add_at_tail(head,random_x[i],random_y[i],length[i],sign[i],random_count[i]);
    }
    return head;
}