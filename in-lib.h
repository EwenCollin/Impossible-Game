#include <stdint.h>
#define taille_niveau 50
/*
struct background { //structure de l'arrière plan
    POINT depart_a;
    POINT depart_b;
    POINT arrivee_a;
    POINT arrivee_b;
    POINT A;
    POINT B;
};
*/

struct obstacle {
    POINT origine;
    POINT actual;
    POINT vecteur;
    int amp;
};

void disp_level(int tableau[taille_niveau][taille_niveau], int taille_graphics) {//affichage basique
    affiche_auto_off();
    fill_screen(0x1F1F1F);
    int x, y;

    POINT A;
    POINT B;

    //bordures
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {

            if (tableau[x][y] == '1') {
                A.x = x*taille_graphics/taille_niveau - taille_graphics/(taille_niveau*10);
                A.y = taille_graphics - (y*taille_graphics/taille_niveau) + taille_graphics/(taille_niveau*10);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau + taille_graphics/(taille_niveau*10);
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) - taille_graphics/(taille_niveau*10);
                draw_fill_rectangle(A,B,whitesmoke);
            }
            if (tableau[x][y] == '2' || tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == '8' || tableau[x][y] == '9' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_graphics/taille_niveau - taille_graphics/(taille_niveau*10);
                A.y = taille_graphics - (y*taille_graphics/taille_niveau) + taille_graphics/(taille_niveau*10);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau + taille_graphics/(taille_niveau*10);
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) - taille_graphics/(taille_niveau*10);
                draw_fill_rectangle(A,B,whitesmoke);
            }
            if (tableau[x][y] == '3') {
                A.x = x*taille_graphics/taille_niveau - taille_graphics/(taille_niveau*10);
                A.y = taille_graphics - (y*taille_graphics/taille_niveau) + taille_graphics/(taille_niveau*10);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau + taille_graphics/(taille_niveau*10);
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) - taille_graphics/(taille_niveau*10);
                draw_fill_rectangle(A,B,whitesmoke);
            }
        }
    }
    //interieur du niveau (chemin)

    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {

            if (tableau[x][y] == '1') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau;
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau);
                draw_fill_rectangle(A,B,palegreen);
            }
            if (tableau[x][y] == '2' || tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == '8' || tableau[x][y] == '9' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau;
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau);
                draw_fill_rectangle(A,B,0x3F3F3F);
            }
            if (tableau[x][y] == '3') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau);
                B.x = x*taille_graphics/taille_niveau + taille_graphics/taille_niveau;
                B.y = taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau);
                draw_fill_rectangle(A,B,0x60FF60);
            }
        }
    }
    //affichage des nombres codes
    /*
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {

            if (tableau[x][y] == '1') {
                A.x = x*taille_graphics/taille_niveau + (0.1*taille_graphics)/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau - (0.1*taille_graphics)/taille_niveau);
                aff_pol("1", taille_graphics/taille_niveau, A, darkgray);

            }
            if (tableau[x][y] == '2') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau - (0.1*taille_graphics)/taille_niveau);
                aff_pol("2", taille_graphics/taille_niveau, A, darkgray);
            }
            if (tableau[x][y] == '3') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau - (0.1*taille_graphics)/taille_niveau);
                aff_pol("3", taille_graphics/taille_niveau, A, black);
            }
            if (tableau[x][y] == '0') {
                A.x = x*taille_graphics/taille_niveau;
                A.y = taille_graphics - (y*taille_graphics/taille_niveau - (0.1*taille_graphics)/taille_niveau);
                aff_pol("0", taille_graphics/taille_niveau, A, darkgray);
            }
        }
    }
    */
}

void disp_level_stats(int taille_graphics, int level_number, int fail_number) {
    POINT A;
    int text_size = taille_graphics/taille_niveau;

    A.x = (0.15*taille_graphics)/taille_niveau;
    A.y = taille_graphics/taille_niveau - (0 - (0.15*taille_graphics)/taille_niveau);
    aff_pol("Niveau :", text_size, A, white);
    A.x = 5*taille_graphics/taille_niveau + (0.15*taille_graphics)/taille_niveau;
    aff_int(level_number, text_size, A, white);

    A.x = 6*taille_graphics/taille_niveau + (0.15*taille_graphics)/taille_niveau;
    aff_pol("Tentatives :", text_size, A, white);
    A.x = 13*taille_graphics/taille_niveau + (0.15*taille_graphics)/taille_niveau;
    aff_int(fail_number, text_size, A, white);

    A.x = taille_graphics/2 - 2.6*taille_graphics/taille_niveau;
    A.y = taille_graphics - (0 - (0.2*taille_graphics)/taille_niveau);
    aff_pol("PathFinder", text_size, A, white);
}

void obstacle_displayer(struct obstacle t_obstacles[taille_niveau*taille_niveau], int taille_graphics) {
    int i;
    POINT A;
    for(i = 0;i < taille_niveau*taille_niveau;i++) {
        if (t_obstacles[i].amp != 0) {
            A.x = t_obstacles[i].actual.x;
            A.y = t_obstacles[i].actual.y;
            draw_fill_circle(A, taille_graphics/(taille_niveau*5), 0xABABAB);
            draw_fill_circle(A, taille_graphics/(taille_niveau*7), 0x1111FF);
        }
    }
}

void p_displayer(int taille_graphics, POINT O) {
    affiche_auto_off();
    POINT A;
    A.x = O.x - (taille_graphics/(taille_niveau*5));
    A.y = O.y + (taille_graphics/(taille_niveau*5));
    POINT B;
    B.x = O.x + (taille_graphics/(taille_niveau*5));
    B.y = O.y - (taille_graphics/(taille_niveau*5));
    draw_fill_rectangle(A,B,black);
    A.x = O.x - (taille_graphics/(taille_niveau*7));
    A.y = O.y + (taille_graphics/(taille_niveau*7));
    B.x = O.x + (taille_graphics/(taille_niveau*7));
    B.y = O.y - (taille_graphics/(taille_niveau*7));
    draw_fill_rectangle(A,B,0xFF0000);
}

POINT p_level_origin(int tableau[taille_niveau][taille_niveau], int taille_graphics) {
    int x,y;
    POINT O;

    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            if (tableau[x][y] == '1') {
                O.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                O.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
            }
        }
    }
    return O;
}

struct obstacle obstacle_origin(struct obstacle t_obstacles[taille_niveau*taille_niveau], int t_niveau[taille_niveau][taille_niveau], int taille_graphics) {
    int x, y, i;
    i = 0;

    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            if (t_niveau[x][y] == '4') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.x < 1) {
                    t_obstacles[i].vecteur.x = 1;
                }
                t_obstacles[i].vecteur.y = 0;
                t_obstacles[i].amp = 2.5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == '5') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = 0;
                t_obstacles[i].vecteur.y = taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.y < 1) {
                    t_obstacles[i].vecteur.y = 1;
                }
                t_obstacles[i].amp = 2.5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == '6') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = - taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.x > -1) {
                    t_obstacles[i].vecteur.x = -1;
                }
                t_obstacles[i].vecteur.y = 0;
                t_obstacles[i].amp = 2.5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == '7') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = 0;
                t_obstacles[i].vecteur.y = - taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.y > -1) {
                    t_obstacles[i].vecteur.y = -1;
                }
                t_obstacles[i].amp = 2.5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == '8') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.x < 1) {
                    t_obstacles[i].vecteur.x = 1;
                }
                t_obstacles[i].vecteur.y = 0;
                t_obstacles[i].amp = 5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == '9') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = 0;
                t_obstacles[i].vecteur.y = taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.y < 1) {
                    t_obstacles[i].vecteur.y = 1;
                }
                t_obstacles[i].amp = 5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == 'A') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = - taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.x > -1) {
                    t_obstacles[i].vecteur.x = -1;
                }
                t_obstacles[i].vecteur.y = 0;
                t_obstacles[i].amp = 5*taille_graphics/taille_niveau;i++;
            }
            if (t_niveau[x][y] == 'B') {
                t_obstacles[i].origine.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].origine.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].actual.x = x*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2;
                t_obstacles[i].actual.y = taille_graphics - (y*taille_graphics/taille_niveau + (taille_graphics/taille_niveau)/2);
                t_obstacles[i].vecteur.x = 0;
                t_obstacles[i].vecteur.y = - taille_graphics/(taille_niveau*40);
                if (t_obstacles[i].vecteur.y > -1) {
                    t_obstacles[i].vecteur.y = 11;
                }
                t_obstacles[i].amp = 5*taille_graphics/taille_niveau;i++;
            }
        }
    }
    return t_obstacles[taille_niveau*taille_niveau];
}

struct obstacle obstacle_mover(struct obstacle t_obstacles[taille_niveau*taille_niveau], int taille_graphics) {
    int i;
    for(i = 0;i < taille_niveau*taille_niveau;i++) {
        if (t_obstacles[i].amp != 0) {

            if (t_obstacles[i].vecteur.x == 0 && t_obstacles[i].actual.y >= t_obstacles[i].origine.y + t_obstacles[i].amp/2) {
                t_obstacles[i].vecteur.y = t_obstacles[i].vecteur.y*-1;
            }
            if (t_obstacles[i].vecteur.y == 0 && t_obstacles[i].actual.x >= t_obstacles[i].origine.x + t_obstacles[i].amp/2) {
                t_obstacles[i].vecteur.x = t_obstacles[i].vecteur.x*-1;
            }
            if (t_obstacles[i].vecteur.x == 0 && t_obstacles[i].actual.y <= t_obstacles[i].origine.y - t_obstacles[i].amp/2) {
                t_obstacles[i].vecteur.y = t_obstacles[i].vecteur.y*-1;
            }
            if (t_obstacles[i].vecteur.y == 0 && t_obstacles[i].actual.x <= t_obstacles[i].origine.x - t_obstacles[i].amp/2) {
                t_obstacles[i].vecteur.x = t_obstacles[i].vecteur.x*-1;
            }

            t_obstacles[i].actual.x = t_obstacles[i].actual.x + t_obstacles[i].vecteur.x;
            t_obstacles[i].actual.y = t_obstacles[i].actual.y + t_obstacles[i].vecteur.y;
        }
    }
    return t_obstacles[taille_niveau*taille_niveau];
}

POINT p_direct_mover(POINT O, POINT vecteur) {
    //joueur (curseur)
    //récupère un point d'origine du curseur pour renvoyer un point d'arrivée
    O.x = O.x + vecteur.x;
    O.y = O.y + vecteur.y;
    //affiche_all();
    return O;
}

int p_fail_test(POINT player, struct obstacle t_obstacles[taille_niveau*taille_niveau], int taille_graphics) {
    int i;
    int death_distance = 0;
    int death = 0;
    for(i = 0;i < taille_niveau*taille_niveau;i++) {
        if (t_obstacles[i].amp != 0) {
            death_distance = distance(player,t_obstacles[i].actual);
            if (death_distance <= taille_graphics/(taille_niveau*2.5)) {
                death = 1;
            }
        }
    }
    return death;
}

int level_reader(int tableau_niveau[taille_niveau][taille_niveau], int level_access) {

    //Ouverture du fichier en fonction du numero obtenu car la variable doit rester constante

    FILE* fichier;
    if (level_access == -1) {
        fichier = fopen("level_new.txt", "r");
    }
    if (level_access == 0) {
        fichier = fopen("level_0.txt", "r");
    }
    if (level_access == 1) {
        fichier = fopen("level_1.txt", "r");
    }
    if (level_access == 2) {
        fichier = fopen("level_2.txt", "r");
    }
    if (level_access == 3) {
        fichier = fopen("level_3.txt", "r");
    }

    //

    int x = 0;
    int y = 0;
    int buff = 1;

    while (y < taille_niveau) {

        x = 0;

        while (x < taille_niveau) {
            buff = fgetc(fichier);
            if (buff != '\n') {

                tableau_niveau[x][y] = buff;
                //printf("Buff : %c \n",buff);
                printf("%c",tableau_niveau[x][y]);
                x++;
            }
        }
        printf("\n");
        y++;
    }
    //printf("x = 8, y = 8 : %c\n",tableau_niveau[8][8]);
    fclose(fichier);
    return tableau_niveau;
}


/*
int level_reader(int * tableau_niveau, size_t N, size_t M) {
    FILE* fichier;
    fichier = fopen("level_0.txt","r");
    int buff[0];

    size_t j, i;

    j = 0;
    while(j < N)
    {

        printf("Exiting the function : lol, crashing at next line ahahah\n");
        buff[0] = fgetc(fichier);
        printf("buff[0]: %c\n", buff[0]);

        i = 0;
        while(i < M)
        {
            tableau_niveau[M * j + i] = (int)j;
            printf("Full in\n");
            printf("Valeur de tableau_niveau : %d\n",tableau_niveau[M * j + i]);
        i++;
        }

    printf("Exiting the function : still in main loop\n");
    j = j+1;
    printf("Almost exiting\n");
    }

    printf("Exiting the function : close to\n");
    //printf("x = 8, y = 8 : %c",tableau_niveau[8][8]);
    fclose(fichier);
    return tableau_niveau;
}
void level_reader(int T[])
{
    //int T[100];
    FILE* fichier;
    int taille_grille = taille_niveau;
    fichier = fopen("level_0.txt","r");
    int a = 0;
    int buff;

    //enregistrement du niveau sous une variable tableau x y (grille)
    while(a < taille_grille*taille_grille) {

        buff = fgetc(fichier);

        if (buff != '\n') {
            a++;
            T[a] = buff;
            //printf("Buff : %c \n",buff);
            printf("%c",T[a]);
            if ((a + 0) % taille_grille == 0) {
                printf("\n");

            }
        }
    }
    fclose(fichier);
}
*/
int p_check_background(int tableau_niveau[taille_niveau][taille_niveau], int taille_graphics, POINT P) {

    int x = 0;
    int y = 0;
    int depassement = 0;
    int testy = 0;
    int testglo = 0;

    for(y = 0; y < taille_niveau;y++) {
        for(x = 0; x < taille_niveau;x++) {
            if (tableau_niveau[x][y] == '0') {
                if (P.x - (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x - (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau && P.y + (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y + (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) || P.x - (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x - (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau && P.y - (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y - (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) ) {
                    //testy = P.x - (taille_graphics/(taille_niveau*5));
                    //testglo = x*taille_graphics/taille_niveau;
                    //printf("Testy : %d\nP(%d,%d)\nGlobal : %d\n",testy,P.x,P.y,testglo);
                    depassement = 1;
                }
                if (P.x + (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x + (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau && P.y + (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y + (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) || P.x + (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x + (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau && P.y - (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y - (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) ) {
                    depassement = 1;
                }
                if (P.y - (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y - (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) && P.x + (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x + (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau || P.y - (taille_graphics/(taille_niveau*5)) > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y - (taille_graphics/(taille_niveau*5)) < taille_graphics - (y*taille_graphics/taille_niveau) && P.x - (taille_graphics/(taille_niveau*5)) < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x - (taille_graphics/(taille_niveau*5)) > x*taille_graphics/taille_niveau ) {
                    depassement = 1;
                }
            }
        }
    }
    return depassement;

}
int p_check_goal(int tableau_niveau[taille_niveau][taille_niveau], int taille_graphics, POINT P) {
    int x = 0;
    int y = 0;
    int goal = 0;

    for(y = 0; y < taille_niveau;y++) {
        for(x = 0; x < taille_niveau;x++) {
            if (tableau_niveau[x][y] == '3') {
                if (P.x < x*taille_graphics/taille_niveau + taille_graphics/taille_niveau && P.x > x*taille_graphics/taille_niveau && P.y > taille_graphics - (y*taille_graphics/taille_niveau + taille_graphics/taille_niveau) && P.y < taille_graphics - (y*taille_graphics/taille_niveau) ) {
                    goal = 1;
                }
            }
        }
    }
    return goal;
}
void level_gest(int taille_graphics, int level_access) {

    int tableau[taille_niveau][taille_niveau] = {0};
    struct obstacle t_obstacles[taille_niveau*taille_niveau] = {0};
    POINT D;//déplacement
    D.x = D.y = 0;

    POINT vecteur_deplacement;
    vecteur_deplacement.x = vecteur_deplacement.y = 0;

    POINT M;//coordonnées joueur
    int i;
    int depassement;
    int goal;
    int fail_number = 0;
    int fail = 0;

    level_reader(tableau, level_access);
    obstacle_origin(t_obstacles, tableau, taille_graphics);
    M = p_level_origin(tableau, taille_graphics);

    disp_level(tableau, taille_graphics);
    p_displayer(taille_graphics, M);
    obstacle_displayer(t_obstacles, taille_graphics);
    affiche_all();

    for (i = 0; i == fail; i=i) {
        affiche_auto_off();
        obstacle_mover(t_obstacles, taille_graphics);
        disp_level(tableau, taille_graphics);

        D = vecteur_deplacement = get_arrow(vecteur_deplacement);
        if (D.x != 0 || D.y != 0) {
            //printf("Coordonnees:\nD.x = %d\nD.y = %d\nM.x = %d\nM.y = %d\n",D.x,D.y,M.x,M.y);
            D = p_direct_mover(M, D);
            //printf("Coordonnees:\nD.x = %d\nD.y = %d\nM.x = %d\nM.y = %d\n",D.x,D.y,M.x,M.y);
            depassement = p_check_background(tableau, taille_graphics, D);
            //printf("Dep checked, depassement = %d\n",depassement);
            if (depassement == 0) {
                //printf("Display D\n");
                //printf("M : %4d %4d \n", M.x, M.y);
                //p_displayer(taille_graphics, D);
                M.x = D.x;
                M.y = D.y;
            }
        }

        obstacle_displayer(t_obstacles, taille_graphics);
        p_displayer(taille_graphics, M);
        disp_level_stats(taille_graphics, level_access, fail_number+1);
        affiche_all();
        fail = p_fail_test(M, t_obstacles, taille_graphics);
        goal = p_check_goal(tableau, taille_graphics, M);
        if (fail == 1) {
            printf("YOU FAILED\n");
            M = p_level_origin(tableau, taille_graphics);
            printf("Restarted\n");
            fail = 0;
            fail_number++;
        }
        if (goal == 1) {
            fail = 1;
            printf("YOU WON\n");
        }
    }
}
