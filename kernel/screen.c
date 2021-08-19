#include "screen.h"

void fill_rect(int x,int y,int w,int h,char color) {
  char* vmem = (char*) VIDEO_MEMORY;
  for ( int dy = 0; dy < h; dy++ ) {
    for ( int dx = 0; dx < w; dx++ ) {
      *(vmem + SCREEN_WIDTH * (y + dy) + x + dx) = color;
    }
  }
}

void trace_rect(int x,int y,int w,int h,char color) {
  char* vmem = (char*) VIDEO_MEMORY;
  for ( int dx = -1; dx <= w; dx++ ) {
    *(vmem + SCREEN_WIDTH * (y - 1) + x + dx) = color;
    *(vmem + SCREEN_WIDTH * (y + h) + x + dx) = color;
  }
  for ( int dy = 0; dy < h; dy++ ) {
    *(vmem + SCREEN_WIDTH * (y + dy) + x - 1) = color;
    *(vmem + SCREEN_WIDTH * (y + dy) + x + w) = color;
  }
}

void draw_image(int x,int y,char* color,char* mask,char color0,char color1) {
  char* vmem = (char*) VIDEO_MEMORY;
  int dx = 0;
  for ( int i = 0; i < 32; i++ ) {
    char cb = color[i];
    char mb = mask[i];
    for ( int j = 0; j < 8; j++ ) {
      if ( mb & (1 << (7 - j)) ) {
        char color;
        if ( cb & (1 << (7 - j)) ) color = color1;
        else color = color0;
        *(vmem + SCREEN_WIDTH * (y + (int) (i / 2)) + x + dx + j) = color;
      }
    }
    dx = (dx + 8) % 16;
  }
}

void debug_byte(char b,int offset) {
  for ( int i = 0; i < 8; i++ ) {
    char color;
    if ( b & (1 << i) ) color = 0x0c;
    else color = 0x08;
    fill_rect((7 - i) * 6,offset * 8,4,4,color);
  }
}
