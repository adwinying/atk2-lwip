#!/bin/sh
rm objdump.csv
echo "Filename,.text,.data,.bss" >> objdump.csv

for file in `find -name "*.o"`; do
	echo -n '.'
	echo -n $file | rev | cut -d "/" -f 1 | rev | tr -d '\n' >> objdump.csv
	echo -n ',' >> objdump.csv
	nios2-elf-objdump -h $file | grep -E '\.text |\.data |\.bss ' | cut -c 19-26 | tr '\n' ','>> objdump.csv
	echo '' >> objdump.csv
done

echo 'done.'