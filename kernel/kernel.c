#include "../cpu/isr.h"
#include "../game/gmain.h"

void main() {
  isr_install();
  asm volatile("sti");
  gmain();
}

void input_event(char code) {
  ginput_event(code);
}

void tick_event() {
  gtick_event();
}
