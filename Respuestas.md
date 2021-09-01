# Laboratorio 2 - Francisco Daniele
## GNU Toolchain y Linux Software
### SOI - FCEFyN - UNC - 2021

## Actividades
#### 1. Command line arguments

    1.1  Resuelto en main.c
    
    1.2  Ídem anterior

#### 2. Static Library

    2.1 Resuelto en main.c

#### 3. Dynamic Library

    3.1 Resuelto en

    3.2 Resuelto en

#### 4. Cuestionario

    4.1 En /proc/<id>/fd tendremos una entrada para cada archivo que abrió el proceso con el nombre de su file descriptor que es un número que provee el kernel y es un link simbólico al archivo. Los tipos que podemos encontrar son:
        -stdin (0)
        -stdout (1)
        -stderror (2)
        -pipes
        -sockets
        -inodos
        -FIFOs
        -Conexiones con periféricos (drivers)

    4.2 La ejecución de dicho comando es válida, lo que hara es poner en su file descriptor stdout el mensaje “Hello, world.” y si no hay conflicto de permisos con el proceso se mostrará.    

    4.3 Para cada recurso tenemos dos tipos de límites: hard y soft. Nos sirven para restringir el uso de recursos por parte de los procesos.
    Las diferencias son que el hard limit solo puede ser cambiado por root y el soft limit puede ser cambiado por el proceso en cualquier momento. El hard define el limite fisico que el usuario puede alcanzar, y el soft nunca puede pasarlo.