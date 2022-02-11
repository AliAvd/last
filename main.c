#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#ifdef main
#undef main
#endif
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "potion.h"
#include "Map.h"
#include "menu.h"







int main(){
    FILE* file_map;
    int initialize = 0;
    int initialize_enely = 0;
    int sec_num = 0;
    int sec_num_enemy = 0;
    int soldiers_number = 0;
    int soldiers_number2 = 0;
    int mouse_1_x;
    int mouse_1_y;
    int mouse_2_x;
    int mouse_2_y;
    int pos_1_x;
    int pos_2_x;
    int pos_1_y;
    int pos_2_y;
    int mouse_clicks_count = 0;
    int manman = 0;
    float last_time = 0,current_time;
    float last_time2 = 0,current_time2;
    float last_time5 = 0,current_time5;
    struct soldier soldiers_enemy[100];
    struct soldier soldiers[100];
    struct ffile files[100];
    FILE* file;
    initialize_soldier(soldiers);
    initialize_soldier(soldiers_enemy);
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
        return 0;
    }
    SDL_Window *sdlWindow = SDL_CreateWindow("Test Window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bool Is_Running = true;
    bool menu_running = true;
    srand(time(NULL));
    int max_soldiers = 30;
    int score = 0;
    int initialize_enely_2 = 0;
    int guide = 0;
    int tedad_nahye_khodi;
    int tedad_nahye_harif;
    int tedad_nahye_bitaraf;
    int random_x[30];
    int random_y[30];
    int length[30];
    int random_count[30];
    int sign[30];
    struct Box* head = (struct Box*) malloc(sizeof(struct Box));
    struct Box* head2;
    struct Box* head_work_1;
    struct Box* head_work_2;
    struct Box* head_work_1_enemy;
    struct Box* head_work_2_enemy;
    struct majoons majoon;
    struct majoons majoon2;
    struct majoons_daste2 Majoon_2;
    struct majoon3 Majoon_3;
    initialize_majoon3(&Majoon_3);
    initialize_Majoon_2(&Majoon_2);
    initialize_majoon(&majoon);
    initialize_majoon(&majoon2);
    int flaaaaag = 0;
    int mousee_x;
    int mousee_y;
    bool map_choice = true;
    int hhh = 0;
    char text[30] = "";
    char text_name[30] = "";
    SDL_StartTextInput();
    menu(sdlRenderer,&flaaaaag,&hhh,text_name);
    SDL_StopTextInput();
    int map1 = 0;
    int map2 = 0;
    int map3 = 0;
    int new_map = 0;
    int mouse_map_x = 0;
    int mouse_map_y = 0;
    if (flaaaaag == 1){
        map_menu(sdlRenderer,&new_map,&map1,&map2,&map3,&Is_Running);
    }
    if (new_map == 1){
        printf("Enter tedad khane haye khodi:");
        scanf("%d",&tedad_nahye_khodi);
        printf("Enter tedad khane haye harif:");
        scanf("%d",&tedad_nahye_harif);
        printf("Enter tedad khane haye bitaraf:");
        scanf("%d",&tedad_nahye_bitaraf);
        for (int i = 0;i<30;i++){
            random_x[i] = rand() % 640;
            random_y[i] = rand() % 640;
            length[i] = rand() % 80 + 20;
            random_count[i] = rand () % max_soldiers + 1;
            if (In_Board(random_x[i],random_y[i],length[i]) == 0){
                manman = 1;
            }
            for (int j = i - 1;j>=0;j--){
                if (overlap(random_x[i],random_y[i],random_x[j],random_y[j],length[i],length[j])){
                    manman = 1;
                }
            }
            if (manman == 1){
                i--;
            }
            manman = 0;
        }
        head->x1 = random_x[0];
        head->y1 = random_y[0];
        head->length = length[0];
        head->sign = 0;
        head->count = random_count[0];
        head->is_add = 1;
        head->next = NULL;
        //printf("%d %d %d\n",random_x[0],random_y[0],head->sign);
        guide++;
        for (int i = guide;i<guide + tedad_nahye_bitaraf - 1;i++){
            add_at_tail(head,random_x[i],random_y[i],length[i],0,random_count[i]);
        }
        guide = guide + tedad_nahye_bitaraf - 1;
        for (int i = guide;i < guide + tedad_nahye_khodi;i++){
            add_at_tail(head,random_x[i],random_y[i],length[i],1,random_count[i]);
        }
        guide = guide + tedad_nahye_khodi;
        for (int i = guide;i<guide + tedad_nahye_harif;i++){
            add_at_tail(head,random_x[i],random_y[i],length[i],2,random_count[i]);
        }
        guide = guide + tedad_nahye_harif;
        head2 = head;
    }
    if (map1 == 1){
        tedad_nahye_khodi = 12;
        tedad_nahye_harif = 1;
        tedad_nahye_bitaraf = 0;
        make_map1_fromfile(file_map,random_x,random_y,length,sign);
        int z = 13;
        for (int i = 0;i<z;i++){
            random_count[i] = rand () % max_soldiers + 1;
        }
        initializing_map(head,random_x,random_y,length,sign,random_count,z);
        head2 = head;
    }
    if (map2 == 1){
        tedad_nahye_khodi = 3;
        tedad_nahye_harif = 3;
        tedad_nahye_bitaraf = 5;
        make_map2_fromfile(file_map,random_x,random_y,length,sign);
        int z = 11;
        for (int i = 0;i<z;i++){
            random_count[i] = rand () % max_soldiers + 1;
        }
        initializing_map(head,random_x,random_y,length,sign,random_count,z);
        head2 = head;
    }
    if (map3 == 1){
        tedad_nahye_harif = 3;
        tedad_nahye_khodi = 4;
        tedad_nahye_bitaraf = 2;
        make_map3_fromfile(file_map,random_x,random_y,length,sign);
        int z = 9;
        for (int i = 0;i<z;i++){
            random_count[i] = rand () % max_soldiers + 1;
        }
        initializing_map(head,random_x,random_y,length,sign,random_count,z);
        head2 = head;
    }

    if (flaaaaag == 1){
        while (Is_Running){
            win_lose(head2,&score,tedad_nahye_harif + tedad_nahye_bitaraf + tedad_nahye_khodi,&Is_Running);
            SDL_SetRenderDrawColor(sdlRenderer,255,255,255,SDL_ALPHA_OPAQUE);
            SDL_RenderClear(sdlRenderer);
            current_time = (float )SDL_GetTicks() / 1000;
            current_time2 = (float )SDL_GetTicks() / 1000;
            current_time5 = (float )SDL_GetTicks() / 1000;

            int random_time = rand() % 500;
            if (random_time == 100 && majoon.is_on == 0 && majoon.khodi == 0 && majoon.doshman == 0){
                majoon_pos(&majoon,tedad_nahye_bitaraf + tedad_nahye_khodi + tedad_nahye_harif,random_x,random_y,length);
                //printf("HELLO\n");
            }
            if (random_time == 200 && majoon2.is_on == 0 && majoon2.khodi == 0 && majoon2.doshman == 0){
                majoon_pos(&majoon,tedad_nahye_harif + tedad_nahye_khodi + tedad_nahye_bitaraf,random_x,random_y,length);
            }
            if (random_time == 300 && Majoon_2.is_on == 0 && Majoon_2.khodi == 0 && Majoon_2.doshman == 0){
                majoon_pos2(&Majoon_2,tedad_nahye_bitaraf + tedad_nahye_khodi + tedad_nahye_harif,random_x,random_y,length);
            }
            if (random_time == 400 && Majoon_3.is_on == 0 && Majoon_3.khodi == 0 && Majoon_3.doshman == 0){
                majoon_pos3(&Majoon_3,tedad_nahye_harif + tedad_nahye_khodi + tedad_nahye_bitaraf,random_x,random_y,length);
            }

            head2 = head;
            if (current_time5 > last_time5 + 5 && initialize_enely_2 == 0){
                int q = 0;
                while (head2!=NULL){
                    if (head2->sign == 2){
                        q++;
                    }
                    head2 = head2->next;
                }
                head2 = head;
                initialize_enely = 1;
                int s = rand() % q + 1;
                int p = 0;
                while (head2!=NULL){
                    if (head2->sign == 2){
                        p++;
                    }
                    if (p == s){
                        head_work_1_enemy = head2;
                        break;
                    }
                    head2 = head2->next;
                }
                soldiers_number2 = head_work_1_enemy->count;
                head2 = head;
                head_work_2_enemy = head2;
                do {
                    int ss = rand() % (tedad_nahye_bitaraf + tedad_nahye_khodi + tedad_nahye_harif);
                    for (int i = 0;i<ss;i++){
                        head2 = head2->next;
                    }
                    head_work_2_enemy = head2;
                    head2 = head;
                } while (head_work_1_enemy == head_work_2_enemy);
                head2 = head;
                last_time5 = current_time5;
            }
            head2 = head;
            if (current_time > last_time + 1){
                if (majoon.is_on == 1){
                    majoon.time++;
                }
                if (majoon.time >= 3 && majoon.is_on == 1){
                    majoon.khodi = 0;
                    majoon.doshman = 0;
                    majoon.is_on = 0;
                    majoon.time = 0;
                }
                if (majoon.doshman == 1 || majoon.khodi == 1){
                    majoon.time++;
                    printf("!\n");
                    //printf("%d\n",majoon.time);
                }
                if (majoon.time >= 5){
                    majoon.khodi = 0;
                    majoon.doshman = 0;
                    majoon.time = 0;
                    majoon.is_on = 0;
                    majoon.x = -10;
                    for (int i = 0;i<soldiers_number;i++){
                        soldiers[i].red = 0;
                        soldiers[i].green = 255;
                        soldiers[i].blue = 0;
                    }

                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].red = 0;
                        soldiers_enemy[i].green = 255;
                        soldiers_enemy[i].blue = 0;
                    }
                }
                ////////////
                if (majoon2.is_on == 1){
                    majoon2.time++;
                }
                if (majoon2.time >= 3 && majoon2.is_on == 1){
                    majoon2.khodi = 0;
                    majoon2.doshman = 0;
                    majoon2.is_on = 0;
                    majoon2.time = 0;
                }
                if (majoon2.doshman == 1 || majoon2.khodi == 1){
                    majoon2.time++;
                    //printf("%d\n",majoon.time);
                }
                if (majoon2.time >= 5){
                    majoon2.khodi = 0;
                    majoon2.doshman = 0;
                    majoon2.time = 0;
                    majoon2.is_on = 0;
                    majoon2.x = -10;
                    for (int i = 0;i<soldiers_number;i++){
                        soldiers[i].red = 0;
                        soldiers[i].green = 255;
                        soldiers[i].blue = 0;
                    }
                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].red = 0;
                        soldiers_enemy[i].green = 255;
                        soldiers_enemy[i].blue = 0;
                    }
                }
                ////////
                if (Majoon_2.is_on == 1){
                    Majoon_2.time++;
                }
                if (Majoon_2.time >= 3 && Majoon_2.is_on == 1){
                    Majoon_2.khodi = 0;
                    Majoon_2.doshman = 0;
                    Majoon_2.is_on = 0;
                    Majoon_2.time = 0;
                }
                if (Majoon_2.doshman == 1 || Majoon_2.khodi == 1){
                    Majoon_2.time++;
                    //printf("%d\n",majoon.time);
                }
                if (Majoon_2.time >= 5){
                    Majoon_2.khodi = 0;
                    Majoon_2.doshman = 0;
                    Majoon_2.time = 0;
                    Majoon_2.is_on = 0;
                    Majoon_2.x = -10;
                    for (int i = 0;i<soldiers_number;i++){
                        soldiers[i].red = 0;
                        soldiers[i].green = 255;
                        soldiers[i].blue = 0;
                    }
                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].red = 0;
                        soldiers_enemy[i].green = 255;
                        soldiers_enemy[i].blue = 0;
                    }
                }
                ///////////////
                if (Majoon_3.is_on == 1){
                    Majoon_3.time++;
                }
                if (Majoon_3.time >= 3 && Majoon_3.is_on == 1){
                    Majoon_3.khodi = 0;
                    Majoon_3.doshman = 0;
                    Majoon_3.is_on = 0;
                    Majoon_3.time = 0;
                }
                if (Majoon_3.doshman == 1 || Majoon_3.khodi == 1){
                    Majoon_3.time++;
                }
                if (Majoon_3.time >= 5){
                    Majoon_3.khodi = 0;
                    Majoon_3.doshman = 0;
                    Majoon_3.time = 0;
                    Majoon_3.is_on = 0;
                    Majoon_3.x = -10;
                    for (int i = 0;i<soldiers_number;i++){
                        soldiers[i].red = 0;
                        soldiers[i].green = 255;
                        soldiers[i].blue = 0;
                    }
                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].red = 0;
                        soldiers_enemy[i].green = 255;
                        soldiers_enemy[i].blue = 0;
                    }
                }
                if (mouse_clicks_count >=2){
                    sec_num++;
                }
                if (initialize_enely == 1){
                    sec_num_enemy++;
                }
                last_time = current_time;
            }
            if (current_time2 > last_time2 + 2){
                adding(head2,max_soldiers,Majoon_2,Majoon_3);
                last_time2 = current_time2;
            }

            head2 = head;
            while (head2!=NULL){
                SDL_Rect rect;
                rect.x = head2->x1;
                rect.y = head2->y1;
                rect.h= head2->length;
                rect.w = head2->length;
                if (head2->sign == 0){
                    SDL_SetRenderDrawColor(sdlRenderer,0,0,0,SDL_ALPHA_OPAQUE);
                }
                if (head2->sign == 1){
                    SDL_SetRenderDrawColor(sdlRenderer,255,0,0,SDL_ALPHA_OPAQUE);
                }
                if (head2->sign == 2){
                    SDL_SetRenderDrawColor(sdlRenderer,0,0,255,SDL_ALPHA_OPAQUE);
                }
                SDL_RenderDrawRect(sdlRenderer,&rect);
                if (head2->sign != 0){
                    SDL_RenderFillRect(sdlRenderer,&rect);
                }
                filledCircleRGBA(sdlRenderer,head2->x1 + (head2->length)/2,head2->y1 + (head2->length)/2,8,255,255,0,SDL_ALPHA_OPAQUE);
                itoa(head2->count,text,10);
                stringRGBA(sdlRenderer,head2->x1 + head2->length / 2,head2->y1 + head2->length / 2 + 10,text,128,0,128,SDL_ALPHA_OPAQUE);
                head2 = head2->next;
            }
            if (majoon.is_on == 1){
                filledCircleRGBA(sdlRenderer,majoon.x,majoon.y,8,0,0,0,SDL_ALPHA_OPAQUE);
            }
            if (majoon2.is_on == 1){
                filledCircleRGBA(sdlRenderer,majoon2.x,majoon2.y,8,255,182,193,SDL_ALPHA_OPAQUE);
            }
            if (Majoon_2.is_on == 1){
                filledCircleRGBA(sdlRenderer,Majoon_2.x,Majoon_2.y,8,255,255,0,SDL_ALPHA_OPAQUE);
            }
            if (Majoon_3.is_on == 1){
                filledCircleRGBA(sdlRenderer,Majoon_3.x,Majoon_3.y,8,255,0,127,SDL_ALPHA_OPAQUE);
            }

            head2 = head;
            if (initialize_enely == 1){
                if (initialize_enely_2 == 0){
                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].x = head_work_1_enemy->x1 + head_work_1_enemy->length / 2;
                        soldiers_enemy[i].y = head_work_1_enemy->y1 + head_work_1_enemy->length / 2;
                    }
                    head_work_1_enemy->count = 0;
                    initialize_enely_2 = 1;
                }
                draw_soldiers_enemy(sdlRenderer,&majoon,&majoon2,&Majoon_2,&Majoon_3,&initialize_enely_2,&initialize_enely,&sec_num_enemy,soldiers_enemy,head_work_1_enemy->x1 + head_work_1_enemy->length / 2,head_work_1_enemy->y1 + head_work_1_enemy->length / 2,head_work_2_enemy->x1 + head_work_2_enemy->length / 2,head_work_2_enemy->y1 + head_work_2_enemy->length / 2,&soldiers_number2,head_work_1_enemy,head_work_2_enemy);
                collision(soldiers,soldiers_enemy,soldiers_number,soldiers_number2,head_work_1,head_work_2,head_work_1_enemy,head_work_2_enemy);
                if (initialize_enely_2 == 0){
                    for (int i = 0;i<soldiers_number2;i++){
                        soldiers_enemy[i].is_move = 1;
                        soldiers_enemy[i].is_on = 1;
                    }
                    soldiers_number2 = 0;
                }
            }
            head2 = head;
            if (mouse_clicks_count == 2){

                if (initialize == 0){
                    struct soldier soldiers_test[100];
                    initialize_soldier(soldiers);
                    for (int i = 0;i<soldiers_number;i++){
                        soldiers[i].x = mouse_1_x;
                        soldiers[i].y = mouse_1_y;
                    }
                    initialize = 1;
                }
                draw_soldiers(sdlRenderer,&majoon,&majoon2,&Majoon_2,&Majoon_3,&initialize,&mouse_clicks_count,&sec_num,soldiers,mouse_1_x,mouse_1_y,mouse_2_x,mouse_2_y,soldiers_number,head_work_1,head_work_2,&score);
            }
            head2 = head;
            SDL_RenderPresent(sdlRenderer);
            SDL_Delay(1000 / FPS);
            SDL_Event Event;
            while (SDL_PollEvent(&Event)){
                if (Event.type == SDL_QUIT) {
                    Is_Running = false;
                }
                    if (Event.type == SDL_MOUSEBUTTONDOWN){
                        int az_1 = 0;
                        int az_2 = 0;
                        SDL_GetMouseState(&az_1,&az_2);
                        while (head2!=NULL){
                            if (az_1 >= head2->x1 + head2->length/2 - 8 && az_1 <= head2->x1 + head2->length/2 + 8 && az_2 <= head2->y1 + head2->length/2 + 8 && az_2 >= head2->y1 + head2->length/2 - 8){
                                if (mouse_clicks_count == 0 && head2->sign == 1){
                                    SDL_GetMouseState(&mouse_1_x,&mouse_1_y);
                                    soldiers_number = head2->count;
                                    head_work_1 = head2;
                                    mouse_clicks_count++;
                                }
                                if (mouse_clicks_count == 1 && ((az_1 - mouse_1_x > 16) || (az_1 - mouse_1_x < -16))){
                                    SDL_GetMouseState(&mouse_2_x,&mouse_2_y);
                                    head_work_1->count = 0;
                                    mouse_clicks_count++;
                                    head_work_2 = head2;
                                    break;
                                }
                            }
                            head2 = head2->next;
                        }
                    }

                    if (Event.type == SDL_QUIT) {
                            Is_Running = false;
                    }
                }
            head2 = head;
            }

        }

    if (flaaaaag == 2){
        //int u;
        sort_file(file,files);
        char reshte[100];
        while (Is_Running){
            show_leaderboard(sdlRenderer,&Is_Running,reshte,file);
        }
    }
    if (flaaaaag == 1){
        int flag = 0;
        char reshte[100];
        int u = 0;
        struct ffile files[100];
        FILE* file;
        score_update(&flag,files,reshte,&u,file,text_name,score);
        score_write(file,files,u,flag,score,text_name);
    }
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}