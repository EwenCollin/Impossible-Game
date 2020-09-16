#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "graphics.h"
#include "in-lib.h"
#include "menu_gui.h"
#include "editor.h"
#define taille_niveau 50

int main(int argc, char *argv[])
{
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    int taille_graphics;

    printf("Quelle taille de fenetre voulez-vous ? (fenetre carree)\n");
    scanf("%d", &taille_graphics);
    printf("Taille graphics : %d\n", taille_graphics);
    init_graphics(taille_graphics,taille_graphics);


    int select;
    int run = 1;

    while (run == 1) {

        select = main_menu(taille_graphics, 0);
        if (select == 0) {
            play_all_levels(taille_graphics);
        }
        if (select == 1) {
            level_gest(taille_graphics, -1);
        }
        if (select == 2) {
            editor_main(taille_graphics);
        }
    }

    wait_escape();
    return 0;
}

void play_all_levels(int taille_graphics) {
    int i;
    for (i = 0; i < 5; i++) {
        level_gest(taille_graphics, i);
        printf("Level exited\n");
    }
    printf("Game exiting\n");
}
