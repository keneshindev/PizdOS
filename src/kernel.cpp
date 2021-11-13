#include "terminal.h"
using PizdOS::terminal;
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
#if !defined(__i386__)
#error "PizdOS can't be compiled without ix86 compiler."
#endif
extern "C" void kernel_main(void) {
	terminal term;
	/* Initialize terminal interface */
	term.initialize();
	term.writestring("Hello, kernel World!\nSus");
}