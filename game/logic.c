#include "gmain.h"
#include "../kernel/screen.h"

char king_test();
char rook_test();
char bishop_test();
char knight_test();
char pawn_test();
char in_check();

char under_attack_x[64];
char under_attack_y[64];

char apply_move() {
  int piece = pieces[INDEX(selected_x,selected_y)];
  char can_move;
  if ( piece == 1 ) can_move = king_test();
  else if ( piece == 2 ) can_move = rook_test() || bishop_test();
  else if ( piece == 3 ) can_move = rook_test();
  else if ( piece == 4 ) can_move = bishop_test();
  else if ( piece == 5 ) can_move = knight_test();
  else if ( piece == 6 ) can_move = pawn_test();
  if ( ! can_move ) return 0;

  char captured = pieces[INDEX(cursor_x,cursor_y)];
  pieces[INDEX(cursor_x,cursor_y)] = piece;
  sides[INDEX(cursor_x,cursor_y)] = turn;
  pieces[INDEX(selected_x,selected_y)] = 0;

  if ( in_check(turn) ) {
    pieces[INDEX(selected_x,selected_y)] = piece;
    pieces[INDEX(cursor_x,cursor_y)] = captured;
    sides[INDEX(cursor_x,cursor_y)] = (turn + 1) % 2;
    return 0;
  } else {
    draw_piece_move(piece);
    return 1;
  }
}

char king_test() {
  if (
    abs(selected_x - cursor_x) <= 1 &&
    abs(selected_y - cursor_y) <= 1
  ) return 1;
  else return 0;
}

char rook_test() {
  if ( cursor_x == selected_x ) {
    int d = sign(cursor_y - selected_y);
    for ( int y = selected_y + d; y != cursor_y; y += d ) {
      debug_byte(y);
      if ( pieces[INDEX(selected_x,y)] != 0 ) return 0;
    }
    return 1;
  } else if ( cursor_y == selected_y ) {
    int d = sign(cursor_x - selected_x);
    for ( int x = selected_x + d; x != cursor_x; x += d ) {
      if ( pieces[INDEX(x,selected_y)] != 0 ) return 0;
    }
    return 1;
  } else {
    return 0;
  }
}

char bishop_test() {
  int dx = cursor_x - selected_x;
  int dy = cursor_y - selected_y;
  if ( abs(dx) != abs(dy) ) return 0;

  dx = sign(dx);
  dy = sign(dy);
  for ( int x = selected_x + dx,y = selected_y + dy; x != cursor_x; x += dx,y += dy ) {
    if ( pieces[INDEX(x,y)] != 0 ) return 0;
  }
  return 1;
}

char knight_test() {
  if (
    (abs(selected_x - cursor_x) == 2 && abs(selected_y - cursor_y) == 1) ||
    (abs(selected_x - cursor_x) == 1 && abs(selected_y - cursor_y) == 2)
  ) return 1;
  else return 0;
}

char pawn_test() {
  if (
    abs(selected_x - cursor_x) > 1 ||
    (abs(selected_x - cursor_x) == 1 && pieces[INDEX(cursor_x,cursor_y)] == 0) ||
    (selected_x == cursor_x && pieces[INDEX(cursor_x,cursor_y)] != 0)
  ) return 0;
  if ( turn == 0 ) {
    if (
      cursor_y - selected_y == -1 ||
      (cursor_y - selected_y == -2 && selected_y == 6 && selected_x == cursor_x)
    ) return 1;
    else return 0;
  } else {
    if (
      cursor_y - selected_y == 1 ||
      (cursor_y - selected_y == 2 && selected_y == 1 && selected_x == cursor_x)
    ) return 1;
    else return 0;
  }
}


void under_attack(int s,char include_king) {
  for ( int i = 0; i < 64; i++ ) {
    under_attack_x[i] = -1;
    under_attack_y[i] = -1;
  }
  int index = 0;
  for ( int i = 0; i < 64; i++ ) {
    if ( pieces[i] != 0 && sides[i] == s ) {
      int p = pieces[i];
      int x = i % 8;
      int y = (int) (i / 8);
      if ( p == 1 ) {
        if ( include_king ) {
          index += add_to_under_attack(x - 1,y - 1,index);
          index += add_to_under_attack(x,y - 1,index);
          index += add_to_under_attack(x + 1,y - 1,index);
          index += add_to_under_attack(x - 1,y,index);
          index += add_to_under_attack(x + 1,y,index);
          index += add_to_under_attack(x - 1,y + 1,index);
          index += add_to_under_attack(x,y + 1,index);
          index += add_to_under_attack(x + 1,y + 1,index);
        }
      } else if ( p == 3 ) {
        int j;
        for ( j = x - 1; j >= 0 && pieces[INDEX(j,y)] == 0; j-- ) {
          index += add_to_under_attack(j,y,index);
        }
        if ( x > 0 ) index += add_to_under_attack(j,y,index);
        for ( j = x + 1; x < 8 && pieces[INDEX(j,y)] == 0; j++ ) {
          index += add_to_under_attack(j,y,index);
        }
        if ( x < 7 ) index += add_to_under_attack(j,y,index);
        for ( j = y - 1; j > 0 && pieces[INDEX(x,j)] == 0; j-- ) {
          index += add_to_under_attack(x,j,index);
        }
        if ( y > 0 ) index += add_to_under_attack(x,j,index);
        for ( j = y + 1; j < 8 && pieces[INDEX(x,j)] == 0; j++ ) {
          index += add_to_under_attack(x,j,index);
        }
        if ( y < 7 ) index += add_to_under_attack(x,j,index);
      } else if ( p == 4 ) {
        /*debug_byte(i,0);
        int j;
        if ( i % 8 > 0 ) {
          for ( j = i + 7; j < 56 && j % 8 > 0 && pieces[j] == 0; j += 7 ) {
            index += add_to_under_attack(j,index);
          }
          if ( i < 56 ) index += add_to_under_attack(j,index);
          for ( j = i - 9; j > 7 && j % 8 > 0 && pieces[j] == 0; j -= 9 ) {
            index += add_to_under_attack(j,index);
          }
          if ( i > 7 ) index += add_to_under_attack(j,index);
        }
        if ( i % 8 < 7 ) {
          for ( j = i + 9; j < 56 && j % 8 < 7 && pieces[j] == 0; j += 9 ) {
            index += add_to_under_attack(j,index);
          }
          if ( i < 56 ) index += add_to_under_attack(j,index);
          for ( j = i - 7; j > 7 && j % 8 < 7 && pieces[j] == 0; j -= 7 ) {
            index += add_to_under_attack(j,index);
          }
          if ( i > 7 ) index += add_to_under_attack(j,index);
        }
      } else if ( p == 5 ) {
        if ( i % 8 > 0 ) {
          index += add_to_under_attack(i - 17,index);
          index += add_to_under_attack(i + 15,index);
          if ( i % 8 > 1 ) {
            index += add_to_under_attack(i - 10,index);
            index += add_to_under_attack(i + 6,index);
          }
        }
        if ( i % 8 > 0 ) {
          index += add_to_under_attack(i - 17,index);
          index += add_to_under_attack(i + 15,index);
          if ( i % 8 > 1 ) {
            index += add_to_under_attack(i - 10,index);
            index += add_to_under_attack(i + 6,index);
          }
        }
        if ( i % 8 < 7 ) {
          index += add_to_under_attack(i - 15,index);
          index += add_to_under_attack(i + 17,index);
          if ( i % 8 < 6 ) {
            index += add_to_under_attack(i - 6,index);
            index += add_to_under_attack(i + 10,index);
          }
        }
      } else if ( p == 6 ) {
        if ( s == 0 ) {
          if ( i % 8 > 0 ) index += add_to_under_attack(i - 9,index);
          if ( i % 8 < 7 ) index += add_to_under_attack(i - 7,index);
        } else {
          if ( i % 8 > 0 ) index += add_to_under_attack(i + 7,index);
          if ( i % 8 < 7 ) index += add_to_under_attack(i + 9,index);
        }*/
      }
    }
  }
}

int add_to_under_attack(int x,int y,int index) {
  if ( x < 0 || x >= 8 || y < 0 || y >= 8 ) return 0;
  for ( int i = 0; i < 64; i++ ) {
    if ( under_attack_x[i] == x && under_attack_y[i] == y ) return 0;
  }
  under_attack_x[index] = x;
  under_attack_y[index] = y;
  return 1;
}

char in_check(int s) {
  int king_index;
  for ( int i = 0; i < 64; i++ ) {
    if ( pieces[i] == 1 && sides[i] == s ) {
      king_index = i;
      break;
    }
  }
  under_attack((s + 1) % 2,1);
  for ( int i = 0; i < 64 && under_attack_x[i] != -1; i++ ) {
    if ( under_attack_x[i] + under_attack_y[i] * 8 == king_index ) return 1;
  }
  return 0;
}

char checkmate(int s) {
  int king_index;
  for ( int i = 0; i < 64; i++ ) {
    if ( pieces[i] == 1 && sides[i] == s ) {
      king_index = i;
      break;
    }
  }
  under_attack((s + 1) % 2,0);
}

int sign(int x) {
  if ( x < 0 ) return -1;
  else if ( x > 0 ) return 1;
  else return 0;
}

int abs(int x) {
  return x * sign(x);
}
