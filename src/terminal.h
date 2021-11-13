#ifndef TERMINAL_H
#define TERMINAL_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
namespace PizdOS {
    class terminal {
        public:
            enum vga_color {
	            VGA_COLOR_BLACK = 0,
	            VGA_COLOR_BLUE = 1,
	            VGA_COLOR_GREEN = 2,
	            VGA_COLOR_CYAN = 3,
	            VGA_COLOR_RED = 4,
	            VGA_COLOR_MAGENTA = 5,
	            VGA_COLOR_BROWN = 6,
	            VGA_COLOR_LIGHT_GREY = 7,
	            VGA_COLOR_DARK_GREY = 8,
	            VGA_COLOR_LIGHT_BLUE = 9,
	            VGA_COLOR_LIGHT_GREEN = 10,
	            VGA_COLOR_LIGHT_CYAN = 11,
	            VGA_COLOR_LIGHT_RED = 12,
	            VGA_COLOR_LIGHT_MAGENTA = 13,
	            VGA_COLOR_LIGHT_BROWN = 14,
	            VGA_COLOR_WHITE = 15,
            };
            static const size_t VGA_WIDTH = 80;
            static const size_t VGA_HEIGHT = 25;
            size_t row;
            size_t column;
            void initialize(void);
            void setcolor(uint8_t color);
            void putentryat(char c, uint8_t color, size_t x, size_t y);
            void putchar(char c);
            void write(const char* data, size_t size);
            void writestring(const char* data);
        private:
            uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
            uint16_t vga_entry(unsigned char uc, uint8_t color);
            size_t strlen(const char* str);
            uint8_t color;
            uint16_t* buffer;
    };
}
#endif