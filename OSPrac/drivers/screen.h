// https://wiki.osdev.org/Printing_To_Screen
// "will have write directly to 'video' memory." 
#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 40
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

/* Screen i/o ports */
// http://www.jamesmolloy.co.uk/tutorial_html/3.-The%20Screen.html
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

/* Public kernel API */
void clear_screen();
