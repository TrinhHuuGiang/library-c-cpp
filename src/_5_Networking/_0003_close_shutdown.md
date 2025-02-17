
# References:
- [man page: close()](https://man7.org/linux/man-pages/man2/close.2.html)
- [man page: shutdown()](https://man7.org/linux/man-pages/man2/shutdown.2.html)

# Content
- `close()`
    - [syntax](#syntax)
    - [description](#description)
    - [return value](#return-value)
    - [example](#example)
- `shutdown()`
    - [syntax](#syntax-1)
    - [description](#description-1)
    - [shutdown modes](#shutdown-modes)
    - [return value](#return-value-1)
    - [example](#example-1)

## close()
### Syntax:
```cpp
#include <unistd.h>
int close(int sockfd);
```

### Description:
- `close()` closes a socket or any file descriptor.
- When closing a socket:
  - If there is data not yet sent, the system may continue sending before actually closing.
  - For TCP, closing the socket sends a `FIN` packet, signaling the end of the connection.

### Return Value:
- Returns `0` on success.
- Returns `-1` on failure, and `errno` will be set to describe the error.

### Example:
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Close socket
    if (close(sockfd) == -1) {
        perror("close failed");
    }
    return 0;
}
```

## shutdown()
### Syntax:
```cpp
#include <sys/socket.h>
int shutdown(int sockfd, int how);
```

### Description:
- `shutdown()` only closes part of the TCP connection.
- Unlike `close()`, `shutdown()` can:
  - Stop sending data (`SHUT_WR`).
  - Stop receiving data (`SHUT_RD`).
  - Stop both sending and receiving data (`SHUT_RDWR`).

### Shutdown Modes:
- `SHUT_RD` (0): No more data can be received.
- `SHUT_WR` (1): No more data can be sent.
- `SHUT_RDWR` (2): No more data can be sent or received.

### Return Value:
- Returns `0` on success.
- Returns `-1` on failure, and `errno` will be set to describe the error.

### Example:
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // close
#include <sys/socket.h> // shutdown
#include <netinet/in.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Stop sending data but still receive
    if (shutdown(sockfd, SHUT_WR) == -1) {
        perror("shutdown failed");
    }
    
    close(sockfd);
    return 0;
}
```