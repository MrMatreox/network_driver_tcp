# Cliente-Servidor con Sockets en C++

Este repositorio contiene la implementación de un simple sistema cliente-servidor en C++ que utiliza sockets para facilitar la comunicación eficiente a través de una red mediante el protocolo TCP.

## Archivos del Proyecto

### 1. `cliente.cpp`

Este archivo contiene el código del cliente, encargado de establecer una conexión con el servidor y recibir un mensaje.

### 2. `main.cpp`

Este archivo contiene el código del servidor, que crea un socket, espera conexiones entrantes y envía un mensaje al cliente cuando se establece la conexión.

## Instrucciones de Uso

1. **Compilación:**
   - Compila ambos programas utilizando un compilador de C++.

     ```bash
     g++ cliente.cpp -o cliente
     g++ main.cpp -o servidor
     ```

2. **Ejecución:**
   - Ejecuta el servidor en una terminal.

     ```bash
     ./servidor
     ```

   - En otra terminal, ejecuta el cliente.

     ```bash
     ./cliente
     ```
## Librerías Utilizadas

El proyecto hace uso de las siguientes librerías estándar de C++:

- `<iostream>`: Para la entrada y salida estándar.
- `<cstring>`: Para operaciones relacionadas con cadenas de caracteres.
- `<unistd.h>`: Proporciona acceso a funciones relacionadas con el sistema operativo, como `close`.
- `<arpa/inet.h>`: Contiene definiciones para manipular direcciones IP y funciones de red, como `socket`, `bind`, `listen`, `connect`, `send`, y `recv`.
