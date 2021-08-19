#include "timer.h"

void init_timer() {
  unsigned int divisor = 1193180 / TICKS_PER_SECOND;
  unsigned char low = (unsigned char) (divisor & 0xff);
  unsigned char high = (unsigned char) ((divisor >> 8) & 0xff);
  port_byte_out(0x43,0x36);
  port_byte_out(0x40,low);
  port_byte_out(0x40,high);
}
