#include "keyboard.h"
#include "kernel.h"
#include "../cpu/ports.h"

void keyboard_event() {
  unsigned char scancode = port_byte_in(0x60);
  if ( scancode > 57 ) return;
  if (
    scancode == W_CODE ||
    scancode == A_CODE ||
    scancode == S_CODE ||
    scancode == D_CODE ||
    scancode == SPACE_CODE
  ) input_event((char) scancode);
}
