#include "gmain.h"
#include "logic.h"
#include "graphics.h"
#include "../kernel/screen.h"
#include "../kernel/keyboard.h"

int cursor_x = 3;
int cursor_y = 3;
int selected_x = -1;
int selected_y = -1;
char last_code = 0;
/*char pieces[] = {
  3, 5, 4, 2, 1, 4, 5, 3,
  6, 6, 6, 6, 6, 6, 6, 6,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  6, 6, 6, 6, 6, 6, 6, 6,
  3, 5, 4, 2, 1, 4, 5, 3
};
char sides[] = {
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};*/
char pieces[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 6, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 3, 0, 5, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};
char sides[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};
int turn = 0;
int tick = 0;

void gmain() {
  init_board();

  while ( 1 ) {
    if ( last_code != 0 ) {
      int turn_y_scale = 1;
      if ( turn == 1 ) turn_y_scale = -1;
      if ( last_code == W_CODE && (cursor_y > 0 || turn != 0) && (cursor_y < 7 || turn != 1) ) move_cursor(cursor_x,cursor_y - turn_y_scale);
      if ( last_code == S_CODE && (cursor_y < 7 || turn != 0) && (cursor_y > 0 || turn != 1) ) move_cursor(cursor_x,cursor_y + turn_y_scale);
      if ( last_code == A_CODE && cursor_x > 0 ) move_cursor(cursor_x - 1,cursor_y);
      if ( last_code == D_CODE && cursor_x < 7 ) move_cursor(cursor_x + 1,cursor_y);
      if ( last_code == SPACE_CODE ) {
        if ( selected_x != -1 ) {
          if ( cursor_x != selected_x || cursor_y != selected_y ) {
            if (
              (pieces[INDEX(cursor_x,cursor_y)] == 0 || sides[INDEX(cursor_x,cursor_y)] != turn) &&
              apply_move()
            ) {
              tick = 0;
              while ( tick < 10 ) {}
              turn = (turn + 1) % 2;
              init_board();
            }
            clear_selected();
          }
          selected_x = -1;
        } else {
          if ( pieces[INDEX(cursor_x,cursor_y)] != 0 && sides[INDEX(cursor_x,cursor_y)] == turn ) {
            selected_x = cursor_x;
            selected_y = cursor_y;
          }
        }
      }
      last_code = 0;
    }
  }
}

void ginput_event(char code) {
  last_code = code;
}

void gtick_event() {
  tick++;
}
