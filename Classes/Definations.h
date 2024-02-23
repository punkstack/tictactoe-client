#pragma once

USING_NS_CC;

#define SCENE_TRANSITION_TIME 0.5f
#define SPLASH_SCENE_SHOW_TIME 0.5f


#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/SplashScreen.jpg"
#define MAIN_MENU_BACKGROUND_FILEPATH "res/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "res/Main Menu Background.png"

#define MAIN_MENU_TITLE_FILEPATH "res/Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "res/Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_PRESSED "res/Play Button.png"
#define SOUND_ON_BUTTON "res/Sound On.png"
#define SOUND_ON_BUTTON_PRESSED "res/Sound On.png"
#define SOUND_OFF_BUTTON "res/Sound Off.png"
#define SOUND_OFF_BUTTON_PRESSED "res/Sound Off.png"
#define ACHIEVEMENTS_BUTTON "res/Achievements.png"
#define ACHIEVEMENTS_BUTTON_PRESSED "res/Achievements.png"

#define MAIN_MENU_PLAY_BUTTON_OUTER "res/Play Button Outer.png"

#define GRID_FILEPATH "res/Grid.png"

#define X_PIECE_FILEPATH "res/X.png"
#define O_PIECE_FILEPATH "res/O.png"
#define X_WINNING_PIECE_FILEPATH "res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "res/O Win.png"

#define TAG_MAIN_MENU_PLAY_BUTTON 0
#define TAG_ACHIEVEMENTS_BUTTON 1

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94

#define PIECE_FADE_IN_TIME 0.5

#define SERVER_ADDRESS "ws://localhost:8080/ws"

#define MAIN_SCENE "main"
#define GAME_SCENE "game"
#define SPLASH_SCENE "splash"


#define USERNAME "manojbojja"
#define DEVICEID "1234456789"


#define CONNECT_PACKET "connect"
#define UPDATE_PACKET "gameUpdate"
#define START_PACKET "gameStart"
#define END_PACKET "gameEnd"
#define ERROR_PACKET "error"

#define CONNECTED "connected"

