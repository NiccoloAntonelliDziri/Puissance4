#pragma once

#define SCREEN_WIDHT 1152
#define SCREEN_HEIGHT 648

#define SPLASH_STATE_SHOW_TIME 2

// NE PAS DEPASSER UNE GRILLE DE 10 x 10
// POUR POUVOIR GAGNER PUISSANCE DOIT ETRE COHERENT POUR LA GRILLE
// ->TROP GRAND PEUT CASSER CERTAINS BOTS 
#define LARGEUR_PAR_DEFAUT 7
#define HAUTEUR_PAR_DEFAUT 6
#define PUISSANCE_PAR_DEFAUT 4

#define MAX_LARGEUR 10
#define MAX_HAUTEUR 10
#define MIN_HAUTEUR 2
#define MIN_LARGEUR 2

#define SPLASH_SCENE_BACKGROUD_FILEPATH "Ressources/res/Splash Screen Background.png"
#define SPLASH_SCREEN_LOGO_PATH "Ressources/res/Logo.png"

#define MAIN_MENU_BACKGROUD_FILEPATH "Ressources/res/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "Ressources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "Ressources/res/Pause Background.png"

#define MAIN_MENU_TITLE_PATH "Ressources/res/Game Title.png"

//Copier ce lien là ou l'app est disponible à telecharger
// UIcons by <a href="https://www.flaticon.com/uicons">Flaticon</a>
#define MAIN_MENU_PLAY_BUTTON "Ressources/res/play.png"
#define RESUME_BUTTON "Ressources/res/resume.png"
#define HOME_BUTTON "Ressources/res/home.png"
#define RETRY_BUTTON "Ressources/res/retry.png"
#define GITHUB_BUTTON "Ressources/res/github.png"
#define SETTINGS_BUTTON "Ressources/res/settings.png"

#define ARROW_UP "Ressources/res/up arrow.png"
#define ARROW_DOWN "Ressources/res/down arrow.png"

// <a href="https://www.freepik.com/icon/play_104635#fromView=search&term=play+button&page=4&position=15">Icon by Freepik</a>
#define SELECT_MENU_PLAY_BUTTON "Ressources/res/play selectmenu.png"

#define TEXT_SELECT_LARGEUR L"Largeur = "
#define TEXT_SELECT_HAUTEUR L"Hauteur = "
#define TEXT_SELECT_PUISSANCE L"Puissance = "

#define PAUSE_BUTTON "Ressources/res/pause.png"

#define GAME_GRID_TILES "Ressources/res/Empty Grid Cells.png"
#define RED_AND_YELLOW_PIECES "Ressources/res/Red and Yellow cells.png"

#define FONT_CHAKRAPETCH_REGULAR_PATH "Ressources/fonts/ChakraPetch-Regular.ttf"
#define FONT_CHAKRAPETCH_BOLD_PATH "Ressources/fonts/ChakraPetch-Bold.ttf"

#define TAILLE_BOUTONS_STANDARD 64

#define RED_PIECE 8
#define YELLOW_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE RED_PIECE
#define AI_PIECE YELLOW_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define TIME_BEFORE_SHOWING_GAME_OVER 2