#include "terminal.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
using PizdOS::terminal;
 
uint8_t terminal::vga_entry_color(enum terminal::vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
uint16_t terminal::vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
 
size_t terminal::strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
 
void terminal::initialize(void) 
{
	terminal::row = 0;
	terminal::column = 0;
	terminal::color = terminal::vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal::buffer = (uint16_t*) 0xC03FF000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			buffer[index] = vga_entry(' ', color);
		}
	}
}
 
void terminal::setcolor(uint8_t color) 
{
	terminal::color = color;
}
 
void terminal::putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = vga_entry(c, color);
}
 
void terminal::putchar(char c) 
{
    if (c == '\n') {
        terminal::row++;
        terminal::column = 0;
        return;
    }
	terminal::putentryat(c, terminal::color, terminal::column, terminal::row);
	if (++terminal::column == VGA_WIDTH) {
		terminal::column = 0;
        if (++terminal::row == VGA_HEIGHT) {
            terminal::row = 0;
        }
	}
}
 
void terminal::write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal::putchar(data[i]);
}
 
void terminal::writestring(const char* data) 
{
	terminal::write(data, terminal::strlen(data));
}