//
// Created by sama laptop on 2/11/2022.
//
#include "Map.h"
#ifndef MAIN_C_POTION_H
#define MAIN_C_POTION_H
struct majoons{
    int time;
    int khodi;
    int doshman;
    int v;
    int x;
    int y;
    int is_on;
};
struct majoons_daste2{
    int time;
    int khodi;
    int doshman;
    int x;
    int y;
    int is_on;
};
struct majoon3{
    int time;
    int khodi;
    int doshman;
    int x;
    int y;
    int is_on;
    int multiply;
};
void initialize_majoon3(struct majoon3* Majoon_3);
void initialize_Majoon_2(struct majoons_daste2* Majoon_2);
void initialize_majoon(struct majoons* majoon);
void majoon_pos(struct majoons* majoon,int tedad_nahyeha,int random_x[],int random_y[],int length[]);
void majoon_pos2(struct majoons_daste2* Majoon,int tedad_nahyeha,int random_x[],int random_y[],int length[]);
void majoon_pos3(struct majoon3* Majoon3,int tedad_nahyeha,int random_x[],int random_y[],int length[]);






#endif //MAIN_C_POTION_H
