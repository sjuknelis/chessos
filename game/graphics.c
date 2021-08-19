#include "graphics.h"
#include "gmain.h"
#include "../kernel/screen.h"
#include "graphics_data.h"

char colors[][32] = {KING_COLOR,QUEEN_COLOR,ROOK_COLOR,BISHOP_COLOR,KNIGHT_COLOR,PAWN_COLOR};
char masks[][32] = {KING_MASK,QUEEN_MASK,ROOK_MASK,BISHOP_MASK,KNIGHT_MASK,PAWN_MASK};

void init_board() {
  if ( turn == 0 ) {
    fill_rect(0,0,320,100,0x00);
    fill_rect(0,100,320,100,0x0f);
  } else {
    fill_rect(0,0,320,100,0x0f);
    fill_rect(0,100,320,100,0x00);
  }

  for ( int x = 0; x < 8; x++ ) {
    for ( int y = 0; y < 8; y++ ) {
      char color;
      if ( x % 2 == (y + turn) % 2 ) color = LIGHT_COLOR;
      else color = DARK_COLOR;
      fill_rect(
        BOARD_ORIGIN_X + TILE_SIZE * x,
        BOARD_ORIGIN_Y + TILE_SIZE * y,
        TILE_SIZE,
        TILE_SIZE,
        color
      );
    }
  }

  trace_rect(BOARD_ORIGIN_X,BOARD_ORIGIN_Y,TILE_SIZE * 8,TILE_SIZE * 8,0x00);
  trace_rect(BOARD_ORIGIN_X - 1,BOARD_ORIGIN_Y - 1,TILE_SIZE * 8 + 2,TILE_SIZE * 8 + 2,0x00);
  int emu_y = cursor_y;
  if ( turn == 1 ) emu_y = 7 - emu_y;
  trace_rect(BOARD_ORIGIN_X + TILE_SIZE * cursor_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_y + 2,TILE_SIZE - 4,TILE_SIZE - 4,0x0c);

  for ( int i = 0; i < 64; i++ ) {
    if ( pieces[i] != 0 ) {
      char color0,color1;
      if ( sides[i] == 0 ) {
        color0 = 0x00;
        color1 = 0x0f;
      } else {
        color0 = 0x0f;
        color1 = 0x00;
      }
      int y = (int) (i / 8);
      if ( turn == 1 ) y = 7 - y;
      draw_image(BOARD_ORIGIN_X + TILE_SIZE * (i % 8) + 2,BOARD_ORIGIN_Y + TILE_SIZE * y + 2,colors[pieces[i] - 1],masks[pieces[i] - 1],color0,color1);
    }
  }
}

void move_cursor(int x,int y) {
  char bg;
  if ( cursor_x == selected_x && cursor_y == selected_y ) bg = 0x0a;
  else if ( cursor_x % 2 == cursor_y % 2 ) bg = LIGHT_COLOR;
  else bg = DARK_COLOR;
  int emu_y = cursor_y;
  if ( turn == 1 ) emu_y = 7 - emu_y;
  trace_rect(BOARD_ORIGIN_X + TILE_SIZE * cursor_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_y + 2,TILE_SIZE - 4,TILE_SIZE - 4,bg);
  cursor_x = x;
  cursor_y = y;
  emu_y = cursor_y;
  if ( turn == 1 ) emu_y = 7 - emu_y;
  trace_rect(BOARD_ORIGIN_X + TILE_SIZE * cursor_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_y + 2,TILE_SIZE - 4,TILE_SIZE - 4,0x0c);
}

void clear_selected() {
  char bg;
  if ( selected_x % 2 == selected_y % 2 ) bg = LIGHT_COLOR;
  else bg = DARK_COLOR;
  int emu_y = selected_y;
  if ( turn == 1 ) emu_y = 7 - emu_y;
  trace_rect(BOARD_ORIGIN_X + TILE_SIZE * selected_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_y + 2,TILE_SIZE - 4,TILE_SIZE - 4,bg);
}

void draw_piece_move(char piece) {
  char bg;
  if ( cursor_x % 2 == cursor_y % 2 ) bg = LIGHT_COLOR;
  else bg = DARK_COLOR;
  int emu_cy = cursor_y;
  if ( turn == 1 ) emu_cy = 7 - emu_cy;
  fill_rect(BOARD_ORIGIN_X + TILE_SIZE * cursor_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_cy + 2,TILE_SIZE - 4,TILE_SIZE - 4,bg);
  if ( selected_x % 2 == selected_y % 2 ) bg = LIGHT_COLOR;
  else bg = DARK_COLOR;
  int emu_sy = selected_y;
  if ( turn == 1 ) emu_sy = 7 - emu_sy;
  fill_rect(BOARD_ORIGIN_X + TILE_SIZE * selected_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_sy + 2,TILE_SIZE - 4,TILE_SIZE - 4,bg);

  char color0,color1;
  if ( turn == 0 ) {
    color0 = 0x00;
    color1 = 0x0f;
  } else {
    color0 = 0x0f;
    color1 = 0x00;
  }
  draw_image(BOARD_ORIGIN_X + TILE_SIZE * cursor_x + 2,BOARD_ORIGIN_Y + TILE_SIZE * emu_cy + 2,colors[piece - 1],masks[piece - 1],color0,color1);
}
