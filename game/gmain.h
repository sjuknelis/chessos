#ifndef GMAIN_H
#define GMAIN_H

#define INDEX(x,y) (y * 8 + x)

void gmain();
void ginput_event(char scancode);
void gtick_event();

extern int cursor_x;
extern int cursor_y;
extern int selected_x;
extern int selected_y;
extern char pieces[];
extern char sides[];
extern int turn;

#endif
