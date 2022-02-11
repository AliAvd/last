//
// Created by sama laptop on 2/11/2022.
//

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<stdlib.h>
#include "menu.h"
#include "potion.h"
void initialize_majoon(struct majoons* majoon){
    majoon->khodi = 0;
    majoon->doshman = 0;
    majoon->v = 2;
    majoon->is_on = 0;
    majoon->time = 0;
}
void initialize_Majoon_2(struct majoons_daste2* Majoon_2){
    Majoon_2->time = 0;
    Majoon_2->khodi = 0;
    Majoon_2->doshman = 0;
    Majoon_2->is_on = 0;
}
void initialize_majoon3(struct majoon3* Majoon_3){
    Majoon_3->time = 0;
    Majoon_3->khodi = 0;
    Majoon_3->doshman = 0;
    Majoon_3->is_on = 0;
    Majoon_3->multiply = 3;
}
void majoon_pos(struct majoons* majoon,int tedad_nahyeha,int random_x[],int random_y[],int length[]){
    int m = rand() % (tedad_nahyeha);
    int mm = rand() % (tedad_nahyeha);
    while (mm == m){
        mm = rand() % (tedad_nahyeha);
    }
    majoon->is_on = 1;
    majoon->x = (random_x[m] + length[m] / 2 + random_x[mm] + length[mm] / 2) / 2;
    majoon->y = (random_y[m] + length[m] / 2 + random_y[mm] + length[mm] / 2) / 2;
}
void majoon_pos2(struct majoons_daste2* Majoon,int tedad_nahyeha,int random_x[],int random_y[],int length[]){
    int m = rand() % (tedad_nahyeha);
    int mm = rand() % (tedad_nahyeha);
    while (mm == m){
        mm = rand() % (tedad_nahyeha);
    }
    Majoon->is_on = 1;
    Majoon->x = (random_x[m] + length[m] / 2 + random_x[mm] + length[mm] / 2) / 2;
    Majoon->y = (random_y[m] + length[m] / 2 + random_y[mm] + length[mm] / 2) / 2;
}
void majoon_pos3(struct majoon3* Majoon3,int tedad_nahyeha,int random_x[],int random_y[],int length[]){
    int m = rand() % (tedad_nahyeha);
    int mm = rand() % (tedad_nahyeha);
    while (mm == m){
        mm = rand() % (tedad_nahyeha);
    }
    Majoon3->is_on = 1;
    Majoon3->x = (random_x[m] + length[m] / 2 + random_x[mm] + length[mm] / 2) / 2;
    Majoon3->y = (random_y[m] + length[m] / 2 + random_y[mm] + length[mm] / 2) / 2;
}