mkdir -p build
rm -rf build/*.o
i686-elf-as src/boot.s -o build/boot.o
for file in $(ls src | grep .cpp); do
  i686-elf-g++ -c src/$file -o build/$file.o -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti
done
i686-elf-gcc -T src/linker.ld -o build/PizdOS.bin -ffreestanding -nostdlib build/*.o -lgcc
