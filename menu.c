#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<stdlib.h>
#include "potion.h"
#include "menu.h"
int check(struct Box* head,int x,int y){
    if ((head->x1 + head->length/2 - x > 10 || head->x1 + head->length/2 - x < -10) && (head->y1 + head->length/2 - y > 10 || head->y1 + head->length/2 - y < -10)){
        return 1;
    }
    else {
        return 0;
    }
}
int check_ground(struct Box* head_work_1,struct Box* head_work_2,struct Box* head_work_enemy_1,struct Box* head_work_enemy_2,int x,int y){
    if (check(head_work_1,x,y) == 1 && check(head_work_2,x,y) == 1 && check(head_work_enemy_1,x,y) == 1 && check(head_work_enemy_2,x,y) == 1){
        return 1;
    }
    else {
        return 0;
    }
}
void initialize_soldier(struct soldier soldiers[100]){
    for (int i = 0;i<100;i++){
        soldiers[i].x = 0;
        soldiers[i].y = 0;
        soldiers[i].is_move = 1;
        soldiers[i].green = 255;
        soldiers[i].red = 0;
        soldiers[i].blue = 0;
        soldiers[i].r = 8;
        soldiers[i].is_on = 1;
    }
}
int fasele(int x,int y,int x_c,int y_c,int com){
    if ((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) <= com * com){
        return 1;
    }
    return 0;
}
void collision(struct soldier soldiers[],struct soldier soldiers_enemy[],int soldiers_number,int soldiers_number_enemy,struct Box* head_work_1,struct Box* head_work_2,struct Box* head_work_enemy_1,struct Box* head_work_enemy_2){
    for (int i = 0;i<soldiers_number;i++){
        for (int j = 0;j<soldiers_number_enemy;j++){
            if (soldiers[i].x - soldiers_enemy[j].x < 16 && soldiers_enemy[j].x - soldiers[i].x < 16 && soldiers[i].y - soldiers_enemy[j].y < 16 && soldiers_enemy[j].y - soldiers[i].y < 16 && soldiers[i].is_move == 1 && soldiers_enemy[j].is_move == 1 && soldiers[i].is_on == 1 && soldiers_enemy[j].is_on == 1){
                if (check_ground(head_work_1,head_work_2,head_work_enemy_1,head_work_enemy_2,soldiers[i].x,soldiers[i].y)){
                    soldiers[i].is_on = 0;
                    soldiers_enemy[j].is_on = 0;
                }
            }
        }
    }
}
/*void collision(struct soldier soldiers[],struct soldier soldiers_enemy[],int soldiers_number,int soldiers_number_enemy,struct Box* head_work_1,struct Box* head_work_2,struct Box* head_work_enemy1,struct Box* head_work_enemy_2){
    *//*if (head_work_2->x1 == head_work_enemy1->x1 && head_work_2->y1 == head_work_enemy1->y1 && head_work_1->x1 == head_work_enemy_2->x1 && head_work_1->y1 == head_work_enemy_2->y1){
        return;
    }*//*
        for (int i = 0;i<soldiers_number;i++){
            for (int j = 0;j<soldiers_number_enemy;j++){
                if (soldiers[i].x - soldiers_enemy[j].x < 16 && soldiers_enemy[j].x - soldiers[i].x < 16 && soldiers[i].y - soldiers_enemy[j].y < 16 && soldiers_enemy[j].y - soldiers[i].y < 16 && soldiers[i].is_move == 1 && soldiers_enemy[j].is_move == 1){
                    if (check_ground())
                    *//*if (head_work_2->x1!=head_work_enemy_2->x1 && head_work_2->y1 != head_work_enemy_2->y1){
                        if ((head_work_2->x1 != head_work_enemy1->x1 && head_work_2->y1 != head_work_enemy1->y1) || (head_work_1->x1 != head_work_enemy_2->x1 && head_work_1->y1 != head_work_enemy_2->y1)){
                            soldiers[i].is_on = 0;
                            soldiers_enemy[j].is_on = 0;
                            soldiers[i].x = -10;
                        }
                    }*//*
                    //////////////////////////////////////////////////////jodaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
                    *//*if (soldiers[i].x - soldiers_enemy[j].x < 16 && soldiers_enemy[j].x - soldiers[i].x < 16 && soldiers[i].y - soldiers_enemy[j].y < 16 && soldiers_enemy[j].y - soldiers[i].y < 16 && soldiers[i].is_move == 1 && soldiers_enemy[j].is_move == 1){
                        while (head2!=NULL){
                            if ((soldiers[i].x - (head2->x1 + head2->length / 2) > head2->length / 2) && ((head2->x1 + head2->length / 2) - soldiers[i].x > head2->length / 2) && (soldiers[i].y - (head2->y1 + head2->length / 2) > head2->length / 2) && ((head2->y1 + head2->length / 2) - soldiers[i].y > head2->length / 2)){
                                head2 = head2->next;
                            }
                            else {
                                break;
                            }
                        }*//*
                    *//*if (head2 == NULL){
                        soldiers[i].is_on = 0;
                        soldiers_enemy[j].is_on = 0;
                    }*//*

                    *//*soldiers[i].green = 0;
                    soldiers[i].blue = 255;*//*
                    //printf("1\n");
                }
                *//*if (soldiers[i].x - soldiers_enemy[j].x < 16 && soldiers_enemy[j].x - soldiers[i].x < 16 && soldiers[i].y - soldiers_enemy[j].y < 16 && soldiers_enemy[j].y - soldiers[i].y < 16 && soldiers[i].is_move == 1 && soldiers_enemy[j].is_move == 1){
                    if (head_work_enemy_2->x1 == head_work_1->x1 && head_work_enemy_2->y1 == head_work_1->y1){
                        if (head_work_enemy1->x1 == head_work_2->x1 && head_work_enemy1->y1 == head_work_2->y1){
                            printf("HIIIIIII\n");
                            if (soldiers[i].x - head_work_1->x1 > 10 && soldiers[i].x - head_work_1->x1 < -10 && soldiers[i].y - head_work_1->y1 > 10 && soldiers[i].y - head_work_1->y1 < -10){
                                printf("HI\n");
                                //if (soldiers_enemy[j].x - head_work_enemy1->x1 > 10 && soldiers_enemy[j].x - head_work_enemy1->x1 < -10 && soldiers_enemy[j].y - head_work_enemy1->y1 > 10 && soldiers[j].y - head_work_enemy1->y1 < -10){
                                    soldiers[i].is_on = 0;
                                    soldiers_enemy[j].is_on = 0;
                                //}
                            }
                        }
                    }
                }*//*
            }
        }



}*/
void draw_soldiers(SDL_Renderer *sdlRenderer,struct majoons* majoon,struct majoons* majoon2,struct majoons_daste2* Majoon_2,struct majoon3* Majoon_3,int *initialize,int *mouse_click_buttons,int *sec_num,struct soldier soldiers[],int mouse_1_x,int mouse_1_y,int mouse_2_x,int mouse_2_y,int soldier_numbers,struct Box* head1,struct Box* head2,int* score) {
    //printf("%d\n",majoon->khodi);
    static int flag = 0;
    float opx = ((float) (mouse_2_x - mouse_1_x)) / 100;
    float opy = ((float) (mouse_2_y - mouse_1_y)) / 100;
    if (majoon->khodi == 1){
        opx = opx * majoon->v;
        opy = opy * majoon->v;
        //printf("hello\n");
    }
    if (majoon2->doshman == 1){
        opx = opx * majoon2->v;
        opy = opy * majoon2->v;
    }
    for (int i = 0; i < soldier_numbers; i++) {
        if (soldiers[i].is_on == 1){
            filledCircleRGBA(sdlRenderer, soldiers[i].x, soldiers[i].y, soldiers[i].r, soldiers[i].red, soldiers[i].green,
                             soldiers[i].blue, SDL_ALPHA_OPAQUE);
        }

        //printf("%d\n",soldiers[i].x);
    }
    for (int i = 0;i<soldier_numbers;i++){
        //printf("%d\n",soldiers[i].x);
        if (((int )soldiers[i].x - majoon->x < 16 && (int )soldiers[i].x - majoon->x > -16) && ((int )soldiers[i].y - majoon->y < 16 && (int )soldiers[i].y - majoon->y > -16) && majoon2->khodi == 0 && majoon->khodi == 0 && Majoon_2->khodi == 0 && Majoon_3->khodi == 0 && majoon->is_on == 1){
            //printf("%d %d\n",soldiers[i].x);
            majoon->is_on = 0;
            majoon->khodi = 1;
            majoon->time = 0;
            for (int i = 0;i<soldier_numbers;i++){
                soldiers[i].red = 0;
                soldiers[i].green = 0;
                soldiers[i].blue = 0;
            }
        }
        if (((int )soldiers[i].x - majoon2->x < 16 && (int )soldiers[i].x - majoon2->x > -16) && ((int )soldiers[i].y - majoon2->y < 16 && (int )soldiers[i].y - majoon2->y > -16) && majoon->khodi == 0 && majoon2->khodi == 0 && Majoon_2->khodi == 0 && Majoon_3->khodi == 0 && majoon2->is_on == 1){
            //printf("%d %d\n",soldiers[i].x);
            majoon2->is_on = 0;
            majoon2->khodi = 1;
            majoon2->time = 0;
            for (int i = 0;i<soldier_numbers;i++){
                soldiers[i].red = 255;
                soldiers[i].green = 182;
                soldiers[i].blue = 193;
            }
        }
        if (((int )soldiers[i].x - Majoon_2->x < 16 && (int )soldiers[i].x - Majoon_2->x > -16) && ((int )soldiers[i].y - Majoon_2->y < 16 && (int )soldiers[i].y - Majoon_2->y > -16) && majoon->khodi == 0 && majoon2->khodi == 0 && Majoon_2->khodi == 0 && Majoon_3->khodi == 0 && Majoon_2->is_on == 1){
            //printf("%d %d\n",soldiers[i].x);
            Majoon_2->is_on = 0;
            Majoon_2->khodi = 1;
            Majoon_2->time = 0;
            for (int i = 0;i<soldier_numbers;i++){
                soldiers[i].red = 255;
                soldiers[i].green = 255;
                soldiers[i].blue = 0;
            }
        }
        if (((int )soldiers[i].x - Majoon_3->x < 16 && (int )soldiers[i].x - Majoon_3->x > -16) && ((int )soldiers[i].y - Majoon_3->y < 16 && (int )soldiers[i].y - Majoon_3->y > -16) && majoon->khodi == 0 && majoon2->khodi == 0 && Majoon_2->khodi == 0 && Majoon_3->khodi == 0 && Majoon_3->is_on == 1){
            //printf("%d %d\n",soldiers[i].x);
            Majoon_3->is_on = 0;
            Majoon_3->khodi = 1;
            Majoon_3->time = 0;
            for (int i = 0;i<soldier_numbers;i++){
                soldiers[i].red = 255;
                soldiers[i].green = 0;
                soldiers[i].blue = 127;
            }
        }
    }
    for (int i = 0; i < *sec_num; i++) {
        if (soldiers[i].is_move == 1){
            soldiers[i].x = soldiers[i].x + opx;
            soldiers[i].y = soldiers[i].y + opy;
            //printf("%d %d\n",majoon->x,majoon->y);
        }
    }
    for (int i = 0;i<soldier_numbers;i++){
        if (opx >= 0){
            for (int i = 0;i<soldier_numbers;i++){
                if (soldiers[i].x >= mouse_2_x){
                    if (head2->sign != 1 && soldiers[i].is_move == 1 && soldiers[i].is_on == 1){
                        head2->count = head2->count - 1;
                    }
                    if (head2->sign == 1 && soldiers[i].is_move == 1 && soldiers[i].is_on == 1){
                        head2->count = head2->count + 1;
                    }
                    if (head2->count == 0){
                        if (flag == 0){
                            *score = *score + 50;
                        }
                        head2->sign = 1;
                        head2->is_add = 0;
                        flag = 1;
                    }
                    soldiers[i].is_move = 0;
                    soldiers[i].is_on = 0;
                    if (i == soldier_numbers - 1){
                        *mouse_click_buttons = 0;
                        *initialize = 0;
                        *sec_num = 0;
                        for (int i = 0;i<soldier_numbers;i++){
                            //soldiers[i].is_move = 1;
                            //soldiers[i].is_touch = 0;
                        }
                        head2->is_add = 1;
                        //soldiers[soldier_numbers - 1].is_touch = 1;
                    }
                }
            }
        }
        else if (opx <= 0){
            for (int i = 0;i<soldier_numbers;i++){
                if (soldiers[i].x <= mouse_2_x){
                    if (head2->sign != 1 && soldiers[i].is_move == 1 && soldiers[i].is_on == 1){
                        head2->count = head2->count - 1;
                    }
                    if (head2->sign == 1 && soldiers[i].is_move == 1 && soldiers[i].is_on == 1){
                        head2->count = head2->count + 1;
                    }
                    if (head2->count == 0){
                        if (flag == 0){
                            *score = *score + 50;
                        }
                        head2->sign = 1;
                        head2->is_add = 0;
                        flag = 1;
                    }
                    soldiers[i].is_move = 0;
                    soldiers[i].is_on = 0;
                    if (i == soldier_numbers - 1){
                        *mouse_click_buttons = 0;
                        *initialize = 0;
                        *sec_num = 0;
                        for (int i = 0;i<soldier_numbers;i++){
                            //soldiers[i].is_move = 1;
                            //soldiers[i].is_touch = 0;
                        }
                        head2->is_add = 1;
                        //soldiers[soldier_numbers - 1].is_touch = 1;
                    }
                }
            }
        }
    }
    //for (int i = 0;i<soldier_numbers;i++){
    //  soldiers[i].is_touch = 0;
    //}
    //soldiers[soldier_numbers - 1].is_touch = 0;
}
void draw_soldiers_enemy(SDL_Renderer *sdlRenderer,struct majoons* majoon,struct majoons* majoon2,struct majoons_daste2* Majoon_2,struct majoon3* Majoon_3,int *initialize_enemy_2,int *initialize_enemy,int *sec_num_enemy,struct soldier soldiers_enemy[],int pos_1_x,int pos_1_y,int pos_2_x,int pos_2_y,int* soldier_numbers,struct Box* head1,struct Box* head2) {
    //printf("%d\n",majoon->khodi);
    float opx = ((float) (pos_2_x - pos_1_x)) / 100;
    float opy = ((float) (pos_2_y - pos_1_y)) / 100;
    if (majoon->doshman == 1) {
        opx = opx * majoon->v;
        opy = opy * majoon->v;
        //printf("hello\n");
    }
    if (majoon2->khodi == 1){
        opx = opx * majoon2->v;
        opy = opy * majoon2->v;
    }
    for (int i = 0; i < *soldier_numbers; i++) {
        if (soldiers_enemy[i].is_on == 1){
            filledCircleRGBA(sdlRenderer, soldiers_enemy[i].x, soldiers_enemy[i].y, soldiers_enemy[i].r,
                             soldiers_enemy[i].red, soldiers_enemy[i].green,
                             soldiers_enemy[i].blue, SDL_ALPHA_OPAQUE);
        }

        //printf("%d\n",soldiers[i].x);
    }
    for (int i = 0; i < *soldier_numbers; i++) {
        //printf("%d\n",soldiers[i].x);
        if (((int) soldiers_enemy[i].x - majoon->x < 16 && (int) soldiers_enemy[i].x - majoon->x > -16) &&
            ((int) soldiers_enemy[i].y - majoon->y < 16 && (int) soldiers_enemy[i].y - majoon->y > -16) && majoon->doshman == 0 && majoon2->doshman == 0 && Majoon_2->doshman == 0 && Majoon_3->doshman == 0 && majoon->is_on == 1) {
            //printf("%d %d\n",soldiers[i].x);
            majoon->is_on = 0;
            majoon->doshman = 1;
            majoon->time = 0;
            for (int i = 0;i<*soldier_numbers;i++){
                soldiers_enemy[i].red = 0;
                soldiers_enemy[i].green = 0;
                soldiers_enemy[i].blue = 0;
            }
        }
        if (((int) soldiers_enemy[i].x - majoon2->x < 16 && (int) soldiers_enemy[i].x - majoon2->x > -16) &&
            ((int) soldiers_enemy[i].y - majoon2->y < 16 && (int) soldiers_enemy[i].y - majoon2->y > -16) && majoon->doshman == 0 && majoon2->doshman == 0 && Majoon_2->doshman == 0 && Majoon_3->doshman == 0 && majoon2->is_on == 1) {
            //printf("%d %d\n",soldiers[i].x);
            majoon2->is_on = 0;
            majoon2->doshman = 1;
            majoon2->time = 0;
            for (int i = 0;i<*soldier_numbers;i++){
                soldiers_enemy[i].red = 255;
                soldiers_enemy[i].green = 182;
                soldiers_enemy[i].blue = 193;
            }
        }
        if (((int) soldiers_enemy[i].x - Majoon_2->x < 16 && (int) soldiers_enemy[i].x - Majoon_2->x > -16) &&
            ((int) soldiers_enemy[i].y - Majoon_2->y < 16 && (int) soldiers_enemy[i].y - Majoon_2->y > -16) && majoon->doshman == 0 && majoon2->doshman == 0 && Majoon_2->doshman == 0 && Majoon_3->doshman == 0 && Majoon_2->is_on == 1) {
            //printf("%d %d\n",soldiers[i].x);
            Majoon_2->is_on = 0;
            Majoon_2->doshman = 1;
            Majoon_2->time = 0;
            for (int i = 0;i<*soldier_numbers;i++){
                soldiers_enemy[i].red = 255;
                soldiers_enemy[i].green = 255;
                soldiers_enemy[i].blue = 0;
            }
        }
        if (((int) soldiers_enemy[i].x - Majoon_3->x < 16 && (int) soldiers_enemy[i].x - Majoon_3->x > -16) &&
            ((int) soldiers_enemy[i].y - Majoon_3->y < 16 && (int) soldiers_enemy[i].y - Majoon_3->y > -16) && majoon->doshman == 0 && majoon2->doshman == 0 && Majoon_2->doshman == 0 && Majoon_3->doshman == 0 && Majoon_3->is_on == 1) {
            //printf("%d %d\n",soldiers[i].x);
            Majoon_3->is_on = 0;
            Majoon_3->doshman = 1;
            Majoon_3->time = 0;
            for (int i = 0;i<*soldier_numbers;i++){
                soldiers_enemy[i].red = 255;
                soldiers_enemy[i].green = 182;
                soldiers_enemy[i].blue = 193;
            }
        }
    }
    for (int i = 0; i < *sec_num_enemy; i++) {
        if (soldiers_enemy[i].is_move == 1) {
            soldiers_enemy[i].x = soldiers_enemy[i].x + opx;
            soldiers_enemy[i].y = soldiers_enemy[i].y + opy;
            //printf("%d %d\n",majoon->x,majoon->y);
        }
    }
    for (int i = 0; i < *soldier_numbers; i++) {
        if (opx >= 0) {
            for (int i = 0; i < *soldier_numbers; i++) {
                if (soldiers_enemy[i].x >= pos_2_x) {
                    if (head2->sign != 2 && soldiers_enemy[i].is_move == 1 && soldiers_enemy[i].is_on == 1) {
                        head2->count = head2->count - 1;
                    }
                    if (head2->sign == 2 && soldiers_enemy[i].is_move == 1 && soldiers_enemy[i].is_on == 1) {
                        head2->count = head2->count + 1;
                    }
                    if (head2->count <= 0) {
                        head2->sign = 2;
                        head2->is_add = 0;
                    }
                    soldiers_enemy[i].is_move = 0;
                    soldiers_enemy[i].is_on = 0;
                    if (i == *soldier_numbers - 1) {
                        *initialize_enemy = 0;
                        *initialize_enemy_2 = 0;
                        *sec_num_enemy = 0;
                        head2->is_add = 1;
                        //soldiers[soldier_numbers - 1].is_touch = 1;
                    }
                }
            }
        } else if (opx <= 0) {
            for (int i = 0; i < *soldier_numbers; i++) {
                if (soldiers_enemy[i].x <= pos_2_x) {
                    if (head2->sign != 2 && soldiers_enemy[i].is_move == 1 && soldiers_enemy[i].is_on == 1) {
                        head2->count = head2->count - 1;
                    }
                    if (head2->sign == 2 && soldiers_enemy[i].is_move == 1 && soldiers_enemy[i].is_on == 1) {
                        head2->count = head2->count + 1;
                    }
                    if (head2->count == 0) {
                        head2->sign = 2;
                        head2->is_add = 0;
                    }
                    soldiers_enemy[i].is_move = 0;
                    soldiers_enemy[i].is_on = 0;
                    if (i == *soldier_numbers - 1) {
                        *initialize_enemy = 0;
                        *initialize_enemy_2 = 0;
                        *sec_num_enemy = 0;
                        head2->is_add = 1;
                        //soldiers[soldier_numbers - 1].is_touch = 1;
                    }
                }
            }
        }
    }
}
void change_sign(struct Box* head){
    head->sign = 1;
}
int min(int num1,int num2){
    if (num1 <= num2){
        return num1;
    }
    if (num2 <= num1){
        return num2;
    }
}
int max(int num1,int num2){
    if (num1 >= num2){
        return num1;
    }
    if (num2 >= num1){
        return num2;
    }
}
int In_Board(int x1,int y1,int length){
    if (x1 + length <= SCREEN_WIDTH && y1 + length <= SCREEN_HEIGHT){
        return 1;
    }
    return 0;
}
bool overlap(int x1,int y1,int x2,int y2,int length1,int length2){
    if (x1 <= x2){
        if (x1 + length1 <= x2 + length2 && x1 + length1 >= x2){
            return true;
        }
    }
    if (x1 >= x2){
        if (x2 + length2 <= x1 + length1 && x2 + length2 >= x1){
            return true;
        }
    }
    if (y1 >= y2){
        if (y2 + length2 >= y1 && y1 + length1 >= y2 + length2){
            return true;
        }
    }
    if (y1 <= y2){
        if (y1 + length1 >= y2 && y1 + length1 <= y2 + length2){
            return true;
        }
    }
    if (x1 >= x2 && x1 <= x2 + length2 && y1 >= y2 && y1 <= y2 + length2){
        return true;
    }
    if (x2 >= x1 && x2 <= x1 + length1 && y2 >= y1 && y2 <= y1 + length1){
        return true;
    }
    return false;
}


void sort_file(FILE* file,struct ffile files[100]){
    int u = 0;
    char reshte[100] = "";
    file = fopen("test.txt","r");
    char ch[100];
    int number;
    while (fgets(reshte,100,file)!=NULL){
        sscanf(reshte,"%d%[^\t\n]",&files[u].score,files[u].name);
        u++;
    }
    for (int i = 0;i<u;i++){
        int j = i;
        while (files[j].score > files[j - 1].score && j>=1){
            struct ffile temp;
            temp = files[j];
            files[j] = files[j - 1];
            files[j - 1] = temp;
            j--;
        }
    }
    fclose(file);
    file = fopen("test.txt","w");
    for (int i = 0;i<u;i++){
        fprintf(file,"%d%s\n",files[i].score,files[i].name);
    }
    fclose(file);
}

void win_lose(struct Box* head,int* score,int tedad_nahyeha,bool* is_running){
    int win = 0;
    int lose = 0;
    while(head!=NULL){
        if (head->sign == 1){
            win++;
        }
        if (head->sign == 2){
            lose++;
        }
        if (head->sign == 0){
            win++;
            lose++;
        }
        head = head->next;
    }
    if (win == tedad_nahyeha){
        *score = *score + 1000;
        *is_running = false;
        printf("%d\n",win);
    }
    if (lose == tedad_nahyeha){
        *score = *score - 1000;
        *is_running = false;
    }
}

int check_mouse_map(int mouse_x,int mouse_y,int rect_x,int rect_y){
    if (mouse_x >= rect_x && mouse_x <= rect_x + 80){
        if (mouse_y >= rect_y && mouse_y <= rect_y + 40){
            return 1;
        }
    }
    return 0;
}


void menu(SDL_Renderer* sdlRenderer,int* flaaaaag,int* hhh,char text_name[]) {
    bool menu_running = true;
    int mousee_x = 0;
    int mousee_y = 0;
    while (menu_running) {
        SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(sdlRenderer);
        SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_Rect rect;
        rect.x = 315;
        rect.y = 310;
        rect.h = 20;
        rect.w = 150;
        SDL_RenderDrawRect(sdlRenderer, &rect);
        SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_Rect leaderboard;
        leaderboard.x = 200;
        leaderboard.y = 400;
        leaderboard.h = 20;
        leaderboard.w = 120;
        SDL_RenderDrawRect(sdlRenderer, &leaderboard);
        SDL_RenderFillRect(sdlRenderer, &leaderboard);
        stringRGBA(sdlRenderer, 200, 400, "Leaderboards", 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_Rect rectt;
        rectt.x = 400;
        rectt.y = 400;
        rectt.h = 20;
        rectt.w = 80;
        SDL_RenderDrawRect(sdlRenderer, &rectt);
        stringRGBA(sdlRenderer, 320, 320, text_name, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(sdlRenderer, &rectt);
        stringRGBA(sdlRenderer, 400, 400, "PLAY!", 0, 0, 0, SDL_ALPHA_OPAQUE);
        if (mousee_x >= 400 && mousee_x <= 480 && mousee_y >= 400 && mousee_y <= 420) {
            mousee_x = 0;
            mousee_y = 0;
            *flaaaaag = 1;
            menu_running = false;
            //printf("%d\n",clicksss);
        }
        if (mousee_x >= 200 && mousee_x <= 320 && mousee_y >= 400 && mousee_y <= 420) {
            *flaaaaag = 2;
            menu_running = false;
        }
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / FPS);

        SDL_Event Event;
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT) {
                menu_running = false;
            }
            if (Event.type == SDL_TEXTINPUT) {
                strcat(text_name, Event.text.text);
                *hhh = *hhh + 1;
            }
            if (Event.type == SDL_KEYDOWN) {
                switch (Event.key.keysym.sym) {
                    case SDLK_BACKSPACE:
                        if (*hhh >= 0) {
                            *hhh = *hhh - 1;
                        }
                        text_name[*hhh] = '\0';
                        break;
                    case SDLK_DELETE:
                        if (*hhh >= 0) {
                            *hhh = *hhh - 1;
                        }
                        text_name[*hhh] = '\0';
                        break;
                }
            }
            if (Event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mousee_x, &mousee_y);
            }
        }
    }
}
void map_menu(SDL_Renderer* sdlRenderer,int* new_map,int* map1,int* map2,int* map3,bool* Is_Running){
    bool map_choice = true;
    int mouse_map_x = 0;
    int mouse_map_y = 0;
    while(map_choice){
        SDL_SetRenderDrawColor(sdlRenderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(sdlRenderer);
        SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_Rect rect1;
        rect1.x = 120;
        rect1.y = 300;
        rect1.w = 80;
        rect1.h = 40;
        SDL_Rect rect2;
        rect2.x = 280;
        rect2.y = 300;
        rect2.w = 80;
        rect2.h = 40;
        SDL_Rect rect3;
        rect3.x = 480;
        rect3.y = 300;
        rect3.w = 80;
        rect3.h = 40;
        SDL_Rect rect4;
        rect4.x = 280;
        rect4.y = 500;
        rect4.w = 80;
        rect4.h = 40;
        SDL_RenderDrawRect(sdlRenderer,&rect1);
        SDL_RenderDrawRect(sdlRenderer,&rect2);
        SDL_RenderDrawRect(sdlRenderer,&rect3);
        SDL_RenderDrawRect(sdlRenderer,&rect4);
        SDL_RenderFillRect(sdlRenderer,&rect1);
        SDL_RenderFillRect(sdlRenderer,&rect2);
        SDL_RenderFillRect(sdlRenderer,&rect3);
        SDL_RenderFillRect(sdlRenderer,&rect4);
        stringRGBA(sdlRenderer,130,320,"MAP 1",0,255,0,SDL_ALPHA_OPAQUE);
        stringRGBA(sdlRenderer,290,320,"MAP 2",0,255,0,SDL_ALPHA_OPAQUE);
        stringRGBA(sdlRenderer,490,320,"MAP 3",0,255,0,SDL_ALPHA_OPAQUE);
        stringRGBA(sdlRenderer,290,520,"NEW MAP!",0,255,0,SDL_ALPHA_OPAQUE);
        if (check_mouse_map(mouse_map_x,mouse_map_y,rect1.x,rect1.y) == 1){
            *map1 = 1;
            map_choice = false;
        }
        if (check_mouse_map(mouse_map_x,mouse_map_y,rect2.x,rect2.y) == 1){
            *map2 = 1;
            map_choice = false;
        }
        if (check_mouse_map(mouse_map_x,mouse_map_y,rect3.x,rect3.y) == 1){
            *map3 = 1;
            map_choice = false;
        }
        if (check_mouse_map(mouse_map_x,mouse_map_y,rect4.x,rect4.y) == 1){
            *new_map = 1;
            map_choice = false;
        }
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / FPS);

        SDL_Event Event;
        while (SDL_PollEvent(&Event)){
            switch (Event.type){
                case SDL_QUIT:
                    map_choice = false;
                    Is_Running = false;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&mouse_map_x,&mouse_map_y);
            }
        }
    }
}
void adding(struct Box* head2,int max_soldiers,struct majoons_daste2 Majoon_2,struct majoon3 Majoon_3){
    while (head2!=NULL){
        if (head2->sign == 1 && head2->is_add == 1 && Majoon_2.khodi == 1 && head2->count >= max_soldiers){
            head2->count = head2->count + 1;
        }
        if (head2->sign == 2 && head2->is_add == 1 && Majoon_2.doshman == 1 && head2->count >= max_soldiers){
            head2->count = head2->count + 1;
        }
        if (head2->sign != 0 && head2->is_add == 1 && head2->count < max_soldiers && Majoon_3.khodi == 0 && Majoon_3.doshman == 0){
            head2->count = head2->count + 1;
        }
        if (head2->sign != 0 && head2->is_add == 1 && head2->count < max_soldiers - 3 && (Majoon_3.khodi == 1 || Majoon_3.doshman == 1)){
            if (head2->sign == 1){
                head2->count = head2->count + 1 * Majoon_3.multiply;
            }
            if (head2->sign == 2){
                head2->count = head2->count + 1 * Majoon_3.multiply;
            }
        }
        head2 = head2->next;
    }
}
void show_leaderboard(SDL_Renderer* sdlRenderer,bool* Is_Running,char reshte[100],FILE* file){
    file = fopen("test.txt","r");
    int x = 50;
    int y = 50;
    SDL_SetRenderDrawColor(sdlRenderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(sdlRenderer);
    while (fgets(reshte,100,file)!=NULL){
        int score;
        char user[100];
        char score_text[10];
        sscanf(reshte,"%d%[^\t\n]",&score,user);
        stringRGBA(sdlRenderer,x,y,user,255,0,0,SDL_ALPHA_OPAQUE);
        stringRGBA(sdlRenderer,x + 200,y,itoa(score,score_text,10),255,0,0,SDL_ALPHA_OPAQUE);
        y+=50;
    }
    SDL_RenderPresent(sdlRenderer);
    SDL_Delay(1000 / FPS);
    SDL_Event Event;
    while (SDL_PollEvent((&Event))){
        if (Event.type == SDL_QUIT){
            *Is_Running = false;
        }
    }
    fclose(file);
}
void score_update(int* flag,struct ffile files[100],char reshte[100],int* u,FILE* file,char text_name[],int score){
    file = fopen("test.txt","r");
    while (fgets(reshte,100,file)!=NULL){
        sscanf(reshte,"%d%[^\t\n]",&files[*u].score,files[*u].name);
        *u = *u + 1;
    }
    for (int i = 0;i<*u;i++){
        int count = 0;
        for (int j = 0;j<strlen(files[i].name);j++){
            if (text_name[j] == files[i].name[j]){
                count++;
            }
        }
        if (count == strlen(files[i].name)){
            files[i].score = files[i].score + score;
            *flag = 1;
            break;
        }
    }
    fclose(file);
}
void score_write(FILE* file,struct ffile files[],int u,int flag,int score,char text_name[]){
    if (flag == 1){
        file = fopen("test.txt","w");
        for (int i = 0;i<u;i++){
            fprintf(file,"%d%s\n",files[i].score,files[i].name);
        }
        fclose(file);
    }
    if (flag == 0){
        file = fopen("test.txt","a");
        fprintf(file,"%d%s\n",score,text_name);
        fclose(file);
    }
}