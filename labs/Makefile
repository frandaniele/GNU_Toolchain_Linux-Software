OFLAGS = -Wall -Werror -pedantic

all:	cpuinfo		meminfo		arreglos	
		
cpuinfo: cpuinfo.c read_text_file.c read_text_file.h 
		gcc $(OFLAGS) cpuinfo.c -o cpuinfo

meminfo: meminfo.c read_text_file.c read_text_file.h 
		gcc $(OFLAGS) meminfo.c -o meminfo

arreglos: arreglos.c arreglos.h read_text_file.c read_text_file.h
		gcc $(OFLAGS) arreglos.c -o arreglos

clean:
		rm -f arreglos cpuinfo meminfo