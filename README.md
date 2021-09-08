# Laboratorio 2 - Francisco Daniele
## GNU Toolchain y Linux Software
### SOI - FCEFyN - UNC - 2021

## Actividades
#### 1. Command line arguments

1.1  Resuelto en main.c.
Utilicé los archivos fuente del laboratorio anterior, guardados en la carpeta _/labs_, la función _getopt_long_ para seleccionar las opciones que se pasen como argumento correctamente, y la función _system_ para hacer llamadas al sistema, así ejecutar los laboratorios anteriores y obtener sus datos.
    
1.2  Ídem anterior.

#### 2. Static Library

2.1 Resuelto en _main.c_ y Makefile para la creación del archivo .a para la librería estática.
Para esta actividad me serví de _strtok_ y _read_ (funcion creada por mi en _read_text_file.c_) para obtener los datos y formatearlos para luego con la librería estatica _libjson.a_ (creada mediante ´ar cr´) mostrarlos como pedía la consigna.

#### 3. Dynamic Library

3.1 Resuelto en _infofs.c_.
Para este punto usé las funciones de _dlfcn.h_, linkeada al programa con el flag -ldl, para cargar y utilizar dinámicamente la librería _libinfofs.so_ creada a partir de _infofs.c_ y _cJSON.c_ en el Makefile. 

3.2 Ídem anterior.

#### 4. Cuestionario

4.1 En /proc/_id_/fd tendremos una entrada para cada archivo que abrió el proceso con el nombre de su file descriptor que es un número que provee el kernel y es un link simbólico al archivo. En el caso de sockets y pipes su entrada será un link simbólico junto con su inodo, y en caso de archivos sin inodos la entrada será de la forma anon_inode:"file-type". Los tipos que podemos encontrar son:
-    stdin (0)
-    stdout (1)
-    stderror (2)
-    pipes
-    sockets
-    FIFOs
-    Conexiones con periféricos (drivers)

4.2 La ejecución de dicho comando es válida, lo que hara es poner en su file descriptor stdout el mensaje “Hello, world.” y si no hay conflicto de permisos con el proceso se mostrará.    

4.3 Para cada recurso tenemos dos tipos de límites: hard y soft. 
Nos sirven para restringir el uso de recursos por parte de los procesos.
Las diferencias son que el hard limit solo puede ser cambiado por root y el soft limit puede ser cambiado por el proceso en cualquier momento. 
El hard define el limite fisico que el usuario puede alcanzar, y el soft nunca puede pasarlo.
