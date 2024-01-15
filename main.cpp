#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // Crear un socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error al crear el socket del servidor" << std::endl;
        return -1;
    }

    // Configurar la estructura de dirección del servidor
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(54000);

    // Vincular el socket al puerto
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error al vincular el socket al puerto" << std::endl;
        close(serverSocket);
        return -1;
    }

    // Escuchar conexiones entrantes
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error al escuchar conexiones entrantes" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Esperando conexiones entrantes..." << std::endl;

    // Aceptar la conexión entrante
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        std::cerr << "Error al aceptar la conexión entrante" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Conexión establecida con el cliente" << std::endl;

    // Enviar datos al cliente
    const char* message = "Hola desde el servidor";
    send(clientSocket, message, strlen(message), 0);

    // Cerrar los sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}

