rm -rf build/*.o
for file in $(ls src | grep .asm); do 
  nasm -felf32 -o build/$file.o src/$file;
done
ld -melf_i386 -T src/linker.ld -o build/PizdOS.bin build/*.asm.o
