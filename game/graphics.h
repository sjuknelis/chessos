#ifndef GRAPHICS_H
#define GRAPHICS_H

#define TILE_SIZE 20
#define BOARD_ORIGIN_X 79
#define BOARD_ORIGIN_Y 19

void init_board();
void move_cursor(int x,int y);
void clear_selected();
void move_piece();

#endif
