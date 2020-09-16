#include <stdint.h>
#define taille_niveau 50

int main_menu(int taille_graphics, int animation) {

    int select = 0;
    if (animation == 1) {
        main_menu_onload(taille_graphics);
    }
    main_menu_disp(taille_graphics);
    select = main_menu_run(taille_graphics);

    return select;
}
int main_menu_run(int taille_graphics) {
	POINT ___MOUSE_POSITION = {0,0};
    int text_size;
    //int cant_disp_menu = 0;
    int selected_button = -1;
    int past_selected_button = -1;
    int still_run = 1;
    text_size = taille_graphics/10;
    //attendre(200);
	SDL_Event event;
    POINT P = ___MOUSE_POSITION;
	while (SDL_WaitEvent(&event) && still_run) {
        if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT) || event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RIGHT) {
            still_run = 0;
        }
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);

		/* Si l'utilisateur a appuyé sur une touche */

		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE : exit(0);
						default :	break;
					}

            /* détection de la sélection par flèche du clavier */
            if (event.key.keysym.sym == SDLK_DOWN && selected_button < 2) {
                attendre(120);
                selected_button++;
                main_menu_disp(taille_graphics);
            }
            if (event.key.keysym.sym == SDLK_UP && selected_button > 0) {
                attendre(120);
                selected_button--;
                main_menu_disp(taille_graphics);
            }
            if (event.key.keysym.sym == SDLK_DOWN && selected_button == -1) {
                attendre(120);
                selected_button = 2;
                main_menu_disp(taille_graphics);
            }
            if (event.key.keysym.sym == SDLK_UP && selected_button == -1) {
                attendre(120);
                selected_button = 0;
                main_menu_disp(taille_graphics);
            }
        }


		/* Si l'utilisateur a bougé la souris */
		if (event.type == SDL_MOUSEMOTION) {
			P.x = event.motion.x;
			P.y = HEIGHT-event.motion.y;
            affiche_auto_off();

            /*détection de la sélection par passage de la souris */
            if (P.y > 5.6*taille_graphics/10 && P.y < 6.6*taille_graphics/10) {
                selected_button = 0;
			}
            if (P.y > 4.3*taille_graphics/10 && P.y < 5.3*taille_graphics/10) {
                selected_button = 1;
			}
            if (P.y > 3*taille_graphics/10 && P.y < 4*taille_graphics/10) {
                selected_button = 2;
			}
            ___MOUSE_POSITION = P;

        }
        /* affichage de la sélection */
        if (past_selected_button != 0 && selected_button == 0) {
            main_menu_disp(taille_graphics);
            main_menu_btn_disp(taille_graphics, selected_button, text_size, "Jouer", 1);
            past_selected_button = 0;
        }
        if (past_selected_button != 1 && selected_button == 1) {
            main_menu_disp(taille_graphics);
            main_menu_btn_disp(taille_graphics, selected_button, text_size, "Niveaux", 1);
            past_selected_button = 1;
        }
        if (past_selected_button != 2 && selected_button == 2) {
            main_menu_disp(taille_graphics);
            main_menu_btn_disp(taille_graphics, selected_button, text_size, "Editeur", 1);
            past_selected_button = 2;
        }
        //cant_disp_menu = 0;
    }
    ___MOUSE_POSITION = P;
    return selected_button;
}
void main_menu_btn_disp(int taille_graphics, int btn_number, int text_size, int text_name,int is_selected) {
    POINT A;
    POINT B;

    COULEUR background_color = whitesmoke;
    COULEUR border_color = 0x000000;
    COULEUR text_color = 0x0B0B0B;
    if (is_selected == 1) {
        background_color = 0x909090;
        border_color = 0xFFFFFF;
        text_color = 0x080808;
    }

    A.x = taille_graphics/2 - 3*taille_graphics/10;
    A.y = 6.6*taille_graphics/10 - (btn_number*1.3*taille_graphics/10);
    B.x = taille_graphics/2 + 3*taille_graphics/10;
    B.y = 5.6*taille_graphics/10 - (btn_number*1.3*taille_graphics/10);
    draw_fill_rectangle(A, B, background_color);

    if (is_selected == 1) {
        draw_border_rectangle(A, B, 2, border_color);
    }

    A.x = taille_graphics/2 - 2.75*taille_graphics/10;
    A.y = 6.75*taille_graphics/10 - btn_number*1.3*taille_graphics/10;
    aff_pol(text_name, text_size, A, text_color);
    if (is_selected == 1) {
        affiche_all();
    }
}

void main_menu_disp(int taille_graphics) {
    POINT A;
    POINT B;
    int text_size;

    affiche_auto_off();

    fill_screen(0x0F0F0F);

    //titre
    int i;

    fill_screen(0x0F0F0F);
    text_size = taille_graphics/8;
    A.x = taille_graphics/2 - 3.5*taille_graphics/10;
    A.y = 9*taille_graphics/10;
    B.x = taille_graphics/2 + 3.5*taille_graphics/10;
    B.y = 7*taille_graphics/10;
    draw_fill_rectangle(A, B, whitesmoke);
    A.x = taille_graphics/2 - 3.35*taille_graphics/10;
    A.y = 8.87*taille_graphics/10;
    aff_pol("PathFinder", text_size, A, 0x0D0D0D);

    //bouttons

    text_size = taille_graphics/10;

    main_menu_btn_disp(taille_graphics, 0, text_size, "Jouer", 0);
    main_menu_btn_disp(taille_graphics, 1, text_size, "Niveaux", 0);
    main_menu_btn_disp(taille_graphics, 2, text_size, "Editeur", 0);
    affiche_all();

}
void main_menu_onload(int taille_graphics) {
    POINT A;
    POINT B;
    int text_size;

    affiche_auto_off();

    fill_screen(0x0F0F0F);

    //titre
    int i;
    int temps_anim = 200;
    for (i = 1;i <= temps_anim;i++) {
        fill_screen(0x0F0F0F);
        text_size = taille_graphics/8;
        A.x = taille_graphics/2 - 3.5*taille_graphics/10;
        A.y = 9*taille_graphics/10 + temps_anim-i;
        B.x = taille_graphics/2 + 3.5*taille_graphics/10;
        B.y = 7*taille_graphics/10 + temps_anim-i;
        draw_fill_rectangle(A, B, whitesmoke);
        A.x = taille_graphics/2 - 3.35*taille_graphics/10;
        A.y = 8.87*taille_graphics/10 - temps_anim+i;
        aff_pol("PathFinder", text_size, A, 0x0D0D0D);
        affiche_all();
    }
    affiche_auto_off();

    //bouttons

    for (i = 3*taille_graphics/10; i < taille_graphics/2 + 3*taille_graphics/10;i++) {
        text_size = taille_graphics/10;

        A.x = taille_graphics/2 - 3*taille_graphics/10;
        A.y = 6.6*taille_graphics/10;
        B.x = i;
        B.y = 5.6*taille_graphics/10;
        draw_fill_rectangle(A, B, whitesmoke);
        A.x = taille_graphics/2 - 2.75*taille_graphics/10;
        A.y = 6.75*taille_graphics/10;
        aff_pol("Jouer", text_size, A, 0x0B0B0B);

        affiche_all();
    }
    for (i = 3*taille_graphics/10; i < taille_graphics/2 + 3*taille_graphics/10;i++) {
        text_size = taille_graphics/10;
        A.x = taille_graphics/2 - 3*taille_graphics/10;
        A.y = 5.3*taille_graphics/10;
        B.x = i;
        B.y = 4.3*taille_graphics/10;
        draw_fill_rectangle(A, B, whitesmoke);
        A.x = taille_graphics/2 - 2.75*taille_graphics/10;
        A.y = 5.45*taille_graphics/10;
        aff_pol("Niveaux", text_size, A, 0x0B0B0B);
        affiche_all();
    }
    for (i = 3*taille_graphics/10; i < taille_graphics/2 + 3*taille_graphics/10;i++) {
        text_size = taille_graphics/10;
        A.x = taille_graphics/2 - 3*taille_graphics/10;
        A.y = 4*taille_graphics/10;
        B.x = i;
        B.y = 3*taille_graphics/10;
        draw_fill_rectangle(A, B, whitesmoke);
        A.x = taille_graphics/2 - 2.75*taille_graphics/10;
        A.y = 4.15*taille_graphics/10;
        aff_pol("Editeur", text_size, A, 0x0B0B0B);
        affiche_all();
    }
}
