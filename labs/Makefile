default:	
		gcc -Wall -Werror -pedantic meminfo.c -o meminfo
		gcc -Wall -Werror -pedantic cpuinfo.c -o cpuinfo
		gcc -Wall -Werror -pedantic arreglos.c -o arreglos
		
cpuinfo: cpuinfo.c read_text_file.c read_text_file.h 
		gcc -Wall -Werror -pedantic cpuinfo.c -o cpuinfo

meminfo: meminfo.c read_text_file.c read_text_file.h 
		gcc -Wall -Werror -pedantic meminfo.c -o meminfo

arreglos: arreglos.c arreglos.h read_text_file.c read_text
		gcc -Wall -Werror -pedantic arreglos.c -o arreglos

clean:
		rm -f arreglos cpuinfo meminfo