# Essential Networking Concepts for Sockets

## Required Libraries

```c
#include <sys/types.h>      // Definitions for data types (used in sockets)
#include <sys/socket.h>     // socket(), bind(), connect(), listen(), accept(), send(), recv(), sendto(), recvfrom(), shutdown()
#include <netinet/in.h>     // htons(), htonl(), ntohs(), ntohl(), struct sockaddr_in, struct in_addr, struct sockaddr_in6, struct in6_addr
#include <arpa/inet.h>      // inet_pton(), inet_ntop()
#include <netdb.h>          // getaddrinfo(), freeaddrinfo(), getnameinfo(), gethostbyname(), gethostbyaddr()
#include <unistd.h>         // close()
```

## 1. Byte Order Conversion Functions
- `htons()`, `htonl()`: Convert values from host byte order to network byte order (short/long).
- `ntohs()`, `ntohl()`: Convert values from network byte order to host byte order (short/long).

## 2. Socket Descriptor
A socket descriptor (`sockfd`) is an integer that represents a network connection endpoint.

## 3. Address Structures
### IPv4
- `struct sockaddr_in`: Used for IPv4 addresses.
- `struct in_addr`: Represents an IPv4 address.

### IPv6
- `struct sockaddr_in6`: Used for IPv6 addresses.
- `struct in6_addr`: Represents an IPv6 address.

### General Purpose
- `struct sockaddr`: Generic socket address structure (used for both IPv4 and IPv6).
- `struct sockaddr_storage`: Large enough to store any address type.
- `struct addrinfo`: Used with `getaddrinfo()` to obtain address information.
    - [->more](./_0001_get_address_inform.md)

## 4. Address Conversion Functions
- `inet_pton()`: Convert IP address from text to binary.
- `inet_ntop()`: Convert IP address from binary to text.

## 5. Socket API Functions
### Creating and Binding a Socket
- `socket()`: Creates a socket.
- `bind()`: Binds the socket to a specific IP and port.

### Establishing a Connection
- `connect()`: Connects a client socket to a remote server.
- `listen()`: Marks a socket as a passive listener for incoming connections.
- `accept()`: Accepts an incoming connection on a listening socket.

### Data Transmission
- `send()`, `recv()`: Send/receive data over a connected socket.
- `sendto()`, `recvfrom()`: Used for UDP communication.

### Closing a Connection
- `close()`: Closes the socket completely.
- `shutdown()`: Partially or fully shuts down communication on a socket.
    - [->more](./_0001_get_address_inform.md)

## 6. Additional Utility Functions
- `getpeername()`: Gets the IP and port of the remote peer connected to the socket.
- `gethostname()`: Retrieves the local machine's hostname.
