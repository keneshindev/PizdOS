# PizdOS
Bare bones ASM kernel, copy-pasted from OSDev. Unusable, only prints `Hello, Kernel World!` and some mysterious character.  
# Dependencies
You should install NASM, Make and Grub, unless you're compiled that type of kernels before.  
## Arch Linux
```
sudo pacman -S nasm make grub xorriso mformat
```
## Ubuntu/Debian
```
sudo apt-get install nasm make grub xorriso
```
## Other distros
I actually have no idea how to install these dependencies on other distros like Fedora or OpenSUSE.  
But, if you have basic knowledge of what you use, you should be able to install these.  
## Windows
No idea how you should run this on Windows, maybe WSL or Cygwin.
# Compiling
Actually, compiling this thing is very easy. Just write `make` in the project's directory, and you're ready to go!
# Generating ISO
Generating ISO also is very easy. Write `make makeiso` and run it with QEMU, or write it to a usb stick.  
# Running
There are 2 ways of running this thing. The first one is Qemu, the second one is real computer.  
## QEMU
Running with qemu is easy:
```
qemu-system-i386 -cdrom build/PizdOS.iso
```
## Real computer
To run it on a real computer, you need to make a bootable medium, which you are going to boot. Making it is easy.
```
sudo dd if=/dev/sdX of=build/PizdOS.iso status=progress
```
Then, reboot and select boot medium in the BIOS, and you're ready to see GRUB and realise, that you've just did the most useless thing on the planet.  
# Contributing
Contributions are open through the Pull Requests.  
I'm not going to maintain this, unless I'll rewrite it on C++.
