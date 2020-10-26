#include "screen.h"
#include "ports.h"

int print_char(char c, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);

int get_offset(int col, int row) { return 2 * (row * MAX_COLS + col); }
int get_offset_row(int offset) { return offset / (2 * MAX_COLS); }
int get_offset_col(int offset) { return (offset - (get_offset_row(offset)*2*MAX_COLS))/2; }

void sayHello(char *message) {
    int offset = get_cursor_offset();
    int row = get_offset_row(offset);
    int col = get_offset_col(offset);
    
    int i = 0;
    while (message[i] != 0) {
        offset = print_char(message[i++], col, row, WHITE_ON_BLACK);
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }
}

int print_char(char c, int col, int row, char attr) {
    unsigned char *vidmem = (unsigned char*) VIDEO_ADDRESS;

    int offset;
    if (col >= 0 && row >= 0) { 
        // (y * 80 + x) * 2
        // http://www.jamesmolloy.co.uk/tutorial_html/3.-The%20Screen.html
        offset = 2 * (row * MAX_COLS + col);
    } else { 
        offset = get_cursor_offset();
    }

    vidmem[offset] = c; // This actually prints the character at that specific place.
    offset += 2;
    return offset;
}

// This, I have no clue what's going on.
int get_cursor_offset() {
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8; /* High byte: << 8 */
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset * 2; /* Position * size of character cell */
}

void clear_screen() {
    int screen_size = MAX_COLS * MAX_ROWS;
    int i;
    char *screen = VIDEO_ADDRESS; // Literally, my screen here.

    for (i = 0; i < screen_size; i++) {
        screen[i*2] = ' '; // Empty out every pre-existing characters.
                           // Intuitively, one could be expecting 2 dimensional array, but no,
                           // memory is just like the "tape" we see in the turing machine.
    }
}