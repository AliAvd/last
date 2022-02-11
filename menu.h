//
// Created by sama laptop on 2/9/2022.
//
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<stdlib.h>
#include "potion.h"
#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H
static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 640;
static int FPS = 60;
struct Box{
    int is_add;
    int count;
    int sign;
    int x1;
    int y1;
    int length;
    struct Box* next;
};
int fasele(int x,int y,int x_c,int y_c,int com);
struct soldier{
    float x;
    float y;
    int r;
    int is_move;
    int red;
    int green;
    int blue;
    int is_on;
};
void initialize_soldier(struct soldier soldier[100]);
struct ffile{
    char name[100];
    int score;
};




int check_mouse_map(int mouse_x,int mouse_y,int rect_x,int rect_y);
int check(struct Box* head,int x,int y);
int check_ground(struct Box* head_work_1,struct Box* head_work_2,struct Box* head_work_enemy_1,struct Box* head_work_enemy_2,int x,int y);
void win_lose(struct Box* head,int* score,int tedad_nahyeha,bool* is_running);
void collision(struct soldier soldiers[],struct soldier soldiers_enemy[],int soldiers_number,int soldiers_number_enemy,struct Box* head_work_1,struct Box* head_work_2,struct Box* head_work_enemy_1,struct Box* head_work_enemy_2);
void draw_soldiers(SDL_Renderer *sdlRenderer,struct majoons* majoon,struct majoons* majoon2,struct majoons_daste2* Majoon_2,struct majoon3* Majoon_3,int *initialize,int *mouse_click_buttons,int *sec_num,struct soldier soldiers[],int mouse_1_x,int mouse_1_y,int mouse_2_x,int mouse_2_y,int soldier_numbers,struct Box* head1,struct Box* head2,int* score);
void draw_soldiers_enemy(SDL_Renderer *sdlRenderer,struct majoons* majoon,struct majoons* majoon2,struct majoons_daste2* Majoon_2,struct majoon3* Majoon_3,int *initialize_enemy_2,int *initialize_enemy,int *sec_num_enemy,struct soldier soldiers_enemy[],int pos_1_x,int pos_1_y,int pos_2_x,int pos_2_y,int* soldier_numbers,struct Box* head1,struct Box* head2);
void change_sign(struct Box* head);
int min(int num1,int num2);
int max(int num1,int num2);
int In_Board(int x1,int y1,int length);
bool overlap(int x1,int y1,int x2,int y2,int length1,int length2);

void sort_file(FILE* file,struct ffile files[100]);

void menu(SDL_Renderer* sdlRenderer,int* flaaaaag,int* hhh,char* text_name);
void map_menu(SDL_Renderer* sdlRenderer,int* new_map,int* map1,int* map2,int* map3,bool* Is_Running);
void adding(struct Box* head2,int max_soldiers,struct majoons_daste2 Majoon_2,struct majoon3 Majoon_3);
void show_leaderboard(SDL_Renderer* sdlRenderer,bool* Is_Running,char reshte[100],FILE* file);
void score_update(int* flag,struct ffile files[100],char reshte[100],int* u,FILE* file,char text_name[],int score);
void score_write(FILE* file,struct ffile files[],int u,int flag,int score,char text_name[]);
#endif //MAIN_C_MENU_H
