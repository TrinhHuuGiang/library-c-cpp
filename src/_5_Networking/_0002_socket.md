
### References:
- [man page: socket()](https://man7.org/linux/man-pages/man2/socket.2.html)

# Content
- `socket()`
    - [syntax](#syntax)
    - [description](#description)
    - [return value](#return-value)
    - [example](#example)

## socket()
### Syntax:
```cpp
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
```

### Description:
- The `socket()` function creates a new socket.
- A socket is an endpoint for communication, and this function is used to create one before data transmission.
- The function returns a socket descriptor, which can then be used with other socket functions (like `bind()`, `connect()`, `send()`, and `recv()`).

### Parameters:
- `domain`:
    - Specifies the communication domain (address family) used for the socket. Common values include:
      - `AF_INET` for IPv4
      - `AF_INET6` for IPv6
      - `AF_UNIX` for local communication using Unix domain sockets.
  
- `type`:
    - Specifies the socket type. Common types include:
      - `SOCK_STREAM` for TCP sockets (connection-oriented).
      - `SOCK_DGRAM` for UDP sockets (connectionless).
  
- `protocol`:
    - Specifies the protocol to be used with the socket. Common values include:
      - `0` for the default protocol (e.g., `IPPROTO_TCP` for TCP and `IPPROTO_UDP` for UDP).
      - A specific protocol if needed (e.g., `IPPROTO_ICMP` for ICMP).

### Return Value:
- Returns a socket descriptor (a positive integer) if the socket is created successfully.
- Returns `-1` if an error occurs, and `errno` is set to indicate the error.
  - Common errors include:
    - `EINVAL`: Invalid domain or type.
    - `EMFILE`: The process has reached its maximum number of open sockets.
    - `ENFILE`: The system has reached its maximum number of open files.

### Example:
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully
");

    // Example code to bind, connect, or send/receive data can go here

    close(sockfd); // Don't forget to close the socket when done
    return 0;
}
```

### Additional Notes:
- A socket must be created before it can be used for communication.
- The `socket()` function does not automatically connect the socket to a remote host; this must be done separately using the `connect()` function (for client-side connections).
- Similarly, on the server side, a socket must be bound to a specific address and port using `bind()` before it can start accepting connections.