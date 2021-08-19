#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_MEMORY 0xa0000
#define SCREEN_WIDTH 320

void fill_rect(int x,int y,int w,int h,char color);
void trace_rect(int x,int y,int w,int h,char color);
void draw_image(int x,int y,char* color,char* mask,char color0,char color1);

#endif
