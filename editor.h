#include <stdint.h>
#define taille_niveau 50

struct selectionner { //permet une sélection multiple (ex : obstacle de cycle 1 et de taille grande et horizontal)
    int simple;
    int cycle;
    int size_element;
};
void type_selecter(struct selectionner *selection, int taille_graphics, int taille_disp) {
    POINT C;
    C = get_mouse();
    printf("is it going there ? \n");
    if (C.x < taille_graphics/10 && C.x > 0 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'empty';
    }
    if (C.x < 2*taille_graphics/10 && C.x > taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'background';
    }
    if (C.x < 3*taille_graphics/10 && C.x > 2*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'path';
    }
    if (C.x < 4*taille_graphics/10 && C.x > 3*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'start';
    }
    if (C.x < 5*taille_graphics/10 && C.x > 4*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'goal';
    }
    if (C.x < 6*taille_graphics/10 && C.x > 5*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'obstacle_x';
        selection->size_element = 'small';
    }
    if (C.x < 7*taille_graphics/10 && C.x > 6*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'obstacle_y';
        selection->size_element = 'small';
    }
    if (C.x < 8*taille_graphics/10 && C.x > 7*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'obstacle_x';
        selection->size_element = 'big';
    }
    if (C.x < 9*taille_graphics/10 && C.x > 8*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'obstacle_y';
        selection->size_element = 'big';
    }
    if (C.x < taille_graphics/10 && C.x > 0 && C.y > 5*taille_graphics/20 - taille_disp/(taille_niveau*10) && C.y < 7*taille_graphics/20 - taille_disp/(taille_niveau*10) ) {
        selection->cycle = 1;
    }
    if (C.x < taille_graphics/10 && C.x > 0 && C.y > 3*taille_graphics/20 - taille_disp/(taille_niveau*10) && C.y < 5*taille_graphics/20 - taille_disp/(taille_niveau*10) ) {
        selection->cycle = 2;
    }
    if (C.x < 10*taille_graphics/10 && C.x > 9*taille_graphics/10 && C.y > 0 && C.y < 3*taille_graphics/20 ) {
        selection->simple = 'save';
    }
}


void editor_main(int taille_graphics) {
    int tableau[taille_niveau][taille_niveau];
    level_reader(tableau, -1);
    int taille_disp = 8.5*taille_graphics/10;
    int level_finished = 0;
    int selected_type = 0;
    struct selectionner selection;
    selection.cycle = 1;
    selection.simple = 'path';
    selection.size_element = 'small';
    while (level_finished == 0) {
        disp_level_editor(tableau, taille_disp, taille_graphics);
        disp_menu(taille_graphics, taille_disp, selection);
        affiche_all();
        wait_clic();
        type_selecter(&selection, taille_graphics, taille_disp);
        if (selection.simple == 'save') {
            level_finished = 1;
            disp_menu(taille_graphics, taille_disp, selection);
            affiche_all();
        }
        else {
            selected_type = selection_converter(selection);
            level_writter(tableau, taille_disp, taille_graphics, selected_type);
            level_table_border_clear(tableau);
        }
        if (selection.simple == 'empty') {
            level_table_initiater(tableau);
        }
    }
    if (selection.simple == 'save') {
        level_saver(tableau);
        level_gest(taille_graphics, -1);
    }
}

void level_saver(int tableau_niveau[taille_niveau][taille_niveau]) {
    FILE* fichier;
    fichier = fopen("level_new.txt", "w");

    int x, y;
    for (y = 0;y < taille_niveau;y++) {
        for (x = 0;x < taille_niveau;x++) {
            fputc(tableau_niveau[x][y], fichier);
        }
        fputc('\n', fichier);
    }
    fclose(fichier);
}

int selection_converter(struct selectionner selection, int selected_type) {

    if (selection.simple == 'empty') {
        selected_type = '0';
    }
    if (selection.simple == 'background') {
        selected_type = '0';
    }
    if (selection.simple == 'path') {
        selected_type = '2';
    }
    if (selection.simple == 'start') {
        selected_type = '1';
    }
    if (selection.simple == 'goal') {
        selected_type = '3';
    }
    if (selection.simple == 'obstacle_x' && selection.size_element == 'small' && selection.cycle == 1) {
        selected_type = '4';
    }
    if (selection.simple == 'obstacle_y' && selection.size_element == 'small' && selection.cycle == 1) {
        selected_type = '5';
    }
    if (selection.simple == 'obstacle_x' && selection.size_element == 'small' && selection.cycle == 2) {
        selected_type = '6';
    }
    if (selection.simple == 'obstacle_y' && selection.size_element == 'small' && selection.cycle == 2) {
        selected_type = '7';
    }
    if (selection.simple == 'obstacle_x' && selection.size_element == 'big' && selection.cycle == 1) {
        selected_type = '8';
    }
    if (selection.simple == 'obstacle_y' && selection.size_element == 'big' && selection.cycle == 1) {
        selected_type = '9';
    }
    if (selection.simple == 'obstacle_x' && selection.size_element == 'big' && selection.cycle == 2) {
        selected_type = 'A';
    }
    if (selection.simple == 'obstacle_y' && selection.size_element == 'big' && selection.cycle == 2) {
        selected_type = 'B';
    }
    return selected_type;
}

int level_table_initiater(int tableau[taille_niveau][taille_niveau]) {
    int x, y;
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            tableau[x][y] = '0';
        }
    }
    return tableau;
}
int level_table_border_clear(int tableau[taille_niveau][taille_niveau]) {
    int x, y;
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            if (y == 0 || y == taille_niveau - 1 || x == 0 || x == taille_niveau - 1) {
                tableau[x][y] = '0';
            }

        }
    }
    return tableau;
}

int level_writter(int tableau_niveau[taille_niveau][taille_niveau], int taille_disp, int taille_graphics, int selected_type) {
    int x, y;
    int click_x, click_y;
    POINT C;
    C = get_mouse();
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            if (C.x < x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55 && C.x > x*taille_disp/taille_niveau  + 4*taille_graphics/55 && C.y > taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau)  + 3*taille_graphics/20  && C.y < taille_disp - (y*taille_disp/taille_niveau)  + 3*taille_graphics/20 ) {
                tableau_niveau[x][y] = selected_type;
            }
        }
    }
    return tableau_niveau;
}

void disp_menu(int taille_graphics, int taille_disp, struct selectionner selection) {
    affiche_auto_off();
    POINT A;
    POINT B;

    A.x = 0;
    A.y = 0;
    B.x = taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,red);
    draw_border_rectangle(A, B, 5, black);
    A.x = A.x + taille_graphics/55;
    A.y = 2*taille_graphics/15;
    aff_pol("X", taille_graphics/10, A,white);

    A.x = taille_graphics/10;
    A.y = 0;
    B.x = 2*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,red);
    if (selection.simple == 'background') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }

    A.x = 2*taille_graphics/10;
    A.y = 0;
    B.x = 3*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x3F3F3F);
    if (selection.simple == 'path') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }

    A.x = 3*taille_graphics/10;
    A.y = 0;
    B.x = 4*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,palegreen);
    if (selection.simple == 'start') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }

    A.x = 4*taille_graphics/10;
    A.y = 0;
    B.x = 5*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x60FF60);
    if (selection.simple == 'goal') {
        draw_border_rectangle(A, B, 4, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }

    A.x = 5*taille_graphics/10;
    A.y = 0;
    B.x = 6*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x3F3F3F);
    if (selection.simple == 'obstacle_x' && selection.size_element == 'small') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = 52*taille_graphics/100;
    A.y = 1.75*taille_graphics/30 - taille_disp/(taille_niveau*10);
    B.x = 58*taille_graphics/100;
    B.y = 2.75*taille_graphics/30 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    draw_border_rectangle(A, B, 4, 0xABABAB);


    A.x = 6*taille_graphics/10;
    A.y = 0;
    B.x = 7*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x3F3F3F);
    if (selection.simple == 'obstacle_y' && selection.size_element == 'small') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = 19*taille_graphics/30;
    A.y = 4*taille_graphics/100 - taille_disp/(taille_niveau*10);
    B.x = 20*taille_graphics/30;
    B.y = 11*taille_graphics/100 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    draw_border_rectangle(A, B, 4, 0xABABAB);

    A.x = 7*taille_graphics/10;
    A.y = 0;
    B.x = 8*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x3F3F3F);
    if (selection.simple == 'obstacle_x' && selection.size_element == 'big') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = 71*taille_graphics/100;
    A.y = 1.75*taille_graphics/30 - taille_disp/(taille_niveau*10);
    B.x = 79*taille_graphics/100;
    B.y = 2.75*taille_graphics/30 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    draw_border_rectangle(A, B, 4, 0xABABAB);

    A.x = 8*taille_graphics/10;
    A.y = 0;
    B.x = 9*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x3F3F3F);
    if (selection.simple == 'obstacle_y' && selection.size_element == 'big') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = 25*taille_graphics/30;
    A.y = 2*taille_graphics/100 - taille_disp/(taille_niveau*10);
    B.x = 26*taille_graphics/30;
    B.y = 13*taille_graphics/100 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    draw_border_rectangle(A, B, 4, 0xABABAB);

    A.x = 9*taille_graphics/10;
    A.y = 0;
    B.x = 10*taille_graphics/10;
    B.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,green);
    if (selection.simple == 'save') {
        draw_border_rectangle(A, B, 5, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }

    A.x = A.x + taille_graphics/55;
    A.y = 2*taille_graphics/15;
    aff_pol("V", taille_graphics/10, A,white);

    A.x = 0;
    A.y = 5*taille_graphics/20 - taille_disp/(taille_niveau*10);
    B.x = taille_graphics/10;
    B.y = 7*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    if (selection.cycle == 1) {
        draw_border_rectangle(A, B, 4, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = A.x + 1.3*taille_graphics/55;
    A.y = A.y + taille_graphics/10;
    aff_pol("1", taille_graphics/12, A,white);

    A.x = 0;
    A.y = 3*taille_graphics/20 - taille_disp/(taille_niveau*10);
    B.x = taille_graphics/10;
    B.y = 5*taille_graphics/20 - taille_disp/(taille_niveau*10);
    draw_fill_rectangle(A,B,0x1111FF);
    if (selection.cycle == 2) {
        draw_border_rectangle(A, B, 4, white);
    }
    else {
        draw_border_rectangle(A, B, 5, black);
    }
    A.x = A.x + 1.25*taille_graphics/55;
    A.y = A.y + taille_graphics/10;
    aff_pol("2", taille_graphics/12, A,white);


}
void draw_border_rectangle(POINT A, POINT B, int pixels, COULEUR color) {
    int i;
    for(i = 0; i < pixels;i++) {
        draw_rectangle(A, B, color);
        A.x++;
        A.y++;
        B.x--;
        B.y--;
    }
}

void disp_level_editor(int tableau[taille_niveau][taille_niveau], int taille_disp, int taille_graphics) {//affichage basique
    affiche_auto_off();
    fill_screen(0x1F1F1F);
    //draw_fill_rectangle(Env.depart_a,Env.depart_b,lime);
    //draw_fill_rectangle(Env.arrivee_a,Env.arrivee_b,green);
    //draw_fill_rectangle(Env.A,Env.B,white);
    //
    int x, y;

    POINT A;
    POINT B;

    //bordures
    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {

            if (tableau[x][y] == '1') {
                A.x = x*taille_disp/taille_niveau - taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,whitesmoke);
            }
            if (tableau[x][y] == '2' || tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == '8' || tableau[x][y] == '9' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_disp/taille_niveau - taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,whitesmoke);
            }
            if (tableau[x][y] == '3') {
                A.x = x*taille_disp/taille_niveau - taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,whitesmoke);
            }
        }
    }
    //interieur du niveau (chemin)

    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {

            if (tableau[x][y] == '1') {
                A.x = x*taille_disp/taille_niveau + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,palegreen);
            }
            if (tableau[x][y] == '2' || tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == '8' || tableau[x][y] == '9' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_disp/taille_niveau + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,0x3F3F3F);
            }
            if (tableau[x][y] == '3') {
                A.x = x*taille_disp/taille_niveau + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,0x60FF60);
            }
        }
    }

    //obstacles (editeur uniquement)

    for(y = 0;y < taille_niveau;y++) {
        for(x = 0;x < taille_niveau;x++) {
            if (tableau[x][y] == '4' || tableau[x][y] == '6') {
                A.x = (x-1)*taille_disp/taille_niveau + 4*taille_graphics/55 + (2*taille_disp/taille_niveau)/10;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + 3*taille_graphics/20 - (taille_disp/taille_niveau)/3;
                B.x = (x+1)*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55 - (2*taille_disp/taille_niveau)/10;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20 + (taille_disp/taille_niveau)/3;
                draw_fill_rectangle(A,B,0x1111FF);
                draw_border_rectangle(A, B, 2, 0xABABAB);
            }
            if (tableau[x][y] == '5' || tableau[x][y] == '7') {
                A.x = x*taille_disp/taille_niveau + 4*taille_graphics/55 + (taille_disp/taille_niveau)/3;
                A.y = taille_disp - ((y-1)*taille_disp/taille_niveau) + 3*taille_graphics/20 - (2*taille_disp/taille_niveau)/10;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55 - (taille_disp/taille_niveau)/3;
                B.y = taille_disp - ((y+1)*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20 + (2*taille_disp/taille_niveau)/10;
                draw_fill_rectangle(A,B,0x1111FF);
                draw_border_rectangle(A, B, 2, 0xABABAB);
            }
            if (tableau[x][y] == '8' || tableau[x][y] == 'A') {
                A.x = (x-2)*taille_disp/taille_niveau + 4*taille_graphics/55 + (1*taille_disp/taille_niveau)/10;
                A.y = taille_disp - (y*taille_disp/taille_niveau) + 3*taille_graphics/20 - (taille_disp/taille_niveau)/3;
                B.x = (x+2)*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55 - (1*taille_disp/taille_niveau)/10;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20 + (taille_disp/taille_niveau)/3;
                draw_fill_rectangle(A,B,0x1111FF);
                draw_border_rectangle(A, B, 2, 0xABABAB);
            }
            if (tableau[x][y] == '9' || tableau[x][y] == 'B') {
                A.x = x*taille_disp/taille_niveau + 4*taille_graphics/55 + (taille_disp/taille_niveau)/3;
                A.y = taille_disp - ((y-2)*taille_disp/taille_niveau) + 3*taille_graphics/20 - (1*taille_disp/taille_niveau)/10;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau + 4*taille_graphics/55 - (taille_disp/taille_niveau)/3;
                B.y = taille_disp - ((y+2)*taille_disp/taille_niveau + taille_disp/taille_niveau) + 3*taille_graphics/20 + (1*taille_disp/taille_niveau)/10;
                draw_fill_rectangle(A,B,0x1111FF);
                draw_border_rectangle(A, B, 2, 0xABABAB);
            }
            if (tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == '8' || tableau[x][y] == '9' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                B.x = x*taille_disp/taille_niveau + taille_disp/taille_niveau - taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                B.y = taille_disp - (y*taille_disp/taille_niveau + taille_disp/taille_niveau) + taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                draw_fill_rectangle(A,B,0xDDDDDD);
                draw_border_rectangle(A, B, 2, 0xABABAB);
            }
            if (tableau[x][y] == '4' || tableau[x][y] == '5' || tableau[x][y] == '8' || tableau[x][y] == '9') {
                A.x = x*taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                A.x = A.x + taille_disp/140;
                A.y = A.y + taille_disp/120;
                aff_pol("1", taille_graphics/25, A,0x333333);
            }
            if (tableau[x][y] == '6' || tableau[x][y] == '7' || tableau[x][y] == 'A' || tableau[x][y] == 'B') {
                A.x = x*taille_disp/taille_niveau + taille_disp/(taille_niveau*10) + 4*taille_graphics/55;
                A.y = taille_disp - (y*taille_disp/taille_niveau) - taille_disp/(taille_niveau*10) + 3*taille_graphics/20;
                A.x = A.x + taille_graphics/150;
                A.y = A.y + taille_graphics/120;
                aff_pol("2", taille_graphics/25, A,0x333333);
            }
        }
    }
}
