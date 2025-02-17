# References:
- [man page: connect()](https://man7.org/linux/man-pages/man2/connect.2.html)

# Content
- `connect()`
    - [syntax](#syntax)
    - [description](#description)
    - [return value](#return-value)
    - [example](#example)

## connect()
### Syntax:
```c++
#include <sys/socket.h>
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

### Description:
- `connect()` được sử dụng bởi client để thiết lập kết nối đến một server.
- Hàm này cần địa chỉ của server (IP và cổng) để biết nơi kết nối đến.
- `connect()` sẽ cố gắng thiết lập kết nối TCP với server.

### Return Value:
- Trả về `0` nếu thành công.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

### Example:
```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // Cho inet_pton()

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Tạo một socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Khởi tạo cấu trúc sockaddr_in
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Chuyển đổi địa chỉ IP từ dạng chuỗi sang dạng nhị phân
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Kết nối đến server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Giao tiếp với server thông qua sockfd

    close(sockfd);
    return 0;
}
```

### Explanation:
- **Địa chỉ server**: Client cần biết địa chỉ IP và cổng của server để kết nối.
- **inet_pton()**: Hàm `inet_pton()` được sử dụng để chuyển đổi địa chỉ IP từ dạng chuỗi (ví dụ: "127.0.0.1") sang dạng nhị phân mà `sockaddr_in` cần.
- **connect()**: Hàm `connect()` được gọi để thiết lập kết nối đến server.

