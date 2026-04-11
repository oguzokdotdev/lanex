#include "idt.h"
#include "pic.h"
#include "tty.h"

void kmain();
void _start() { kmain(); }

void kmain() {
  /* Initialize terminal interface */
  terminal_initialize();
  idt_install();
  pic_remap();
  __asm__ __volatile__("sti");

  terminal_writestring("Hello, kernel World!\n");
  while(1) {
  }
}
