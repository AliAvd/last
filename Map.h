//
// Created by sama laptop on 2/11/2022.
//

#ifndef MAIN_C_MAP_H
#define MAIN_C_MAP_H

struct Box* initializing_map(struct Box* head,int random_x[],int random_y[],int length[],int sign[],int random_count[],int u);
void make_map1_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]);
void make_map2_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]);
void make_map3_fromfile(FILE* file,int random_x[],int random_y[],int length[],int sign[]);
void add_at_tail(struct Box* head,int x1,int y1,int length,int sign,int count);
#endif //MAIN_C_MAP_H
