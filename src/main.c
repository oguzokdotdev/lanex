#include "main.h"
#include "vga.h"
#include "idt.h"
#include "pic.h"
#include "tty.h"
#include "keyboard.h"
#include "pit.h"
#include "sh.h"
#include "messages.h"

void _start() { kmain(); }

void kmain() {
  tty_initialize();
  idt_install();
  pic_remap();
  pit_init(1000);

  asm volatile("sti"); /* enabling interrupts */

  welcome();
  sh_main(); /* 'pid 1' */
  for(;;) {
    kpanic("Entering in infinity loop");
  }
}
