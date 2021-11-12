PizdOS:
	./build.sh
makeiso:
	rm -rf build/iso
	mkdir -p build/iso/boot/grub
	echo "menuentry \"PizdOS\" {\nmultiboot /boot/PizdOS.bin\n}" >> build/iso/boot/grub/grub.cfg
	cp build/PizdOS.bin build/iso/boot
	grub-mkrescue -o build/PizdOS.iso build/iso
