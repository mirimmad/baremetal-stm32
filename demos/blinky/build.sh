#!/bin/bash

# list of files
FILE_LIST=("../../startup.c" "../../drivers/clk/clk.c" "../../drivers/gpio/gpio.c" "main.c" ) 

if [ "$1" == "clean" ]; then
  echo "Cleaning build directory..."
  # Remove all files in the build directory
  rm  build/*
  rm main.bin
  exit 0
fi

if [ "$1" == "flash" ]; then
    echo "flashing..."
    st-flash write main.bin 0x08000000
    exit 0
fi

mkdir "build"

echo "Compiling..."
# Compile each file in the list
for i in ${!FILE_LIST[@]}; do
  base_name=$(basename -s .c "${FILE_LIST[i]}")
   #echo $base_name
  # Build the complete command with filename
  obj_command="arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -g -Wall --specs=nosys.specs"
  obj_command+=" -I../../drivers/"
  obj_command+=" -c ${FILE_LIST[i]} -o build/$base_name.o"
  
  # Execute the command and handle errors
  #echo "Compiling: ${FILE_LIST[i]}"
  #echo $obj_command
  if ! ($obj_command); then
    echo "Error: Compilation failed for $file!"
    exit 1
  fi
done
echo "Compilation successful"

echo "Linking...."
link_cmd="arm-none-eabi-gcc -T../../linker.ld -mcpu=cortex-m4 -mthumb --specs=nosys.specs -nostdlib -lgcc build/*.o -o build/main.elf"
#echo $link_cmd
if ! ($link_cmd); then
    echo "Linking failed"
    exit -1
fi
echo "ELF created successfully"
echo "creating binary,,,"
bin_cmd="arm-none-eabi-objcopy -S -O binary build/main.elf ./main.bin"
if ! ($bin_cmd); then
    echo "binary creation failed"
    exit -1
fi
arm-none-eabi-size build/main.elf






