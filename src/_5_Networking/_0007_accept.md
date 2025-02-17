# References:
- [man page: accept()](https://man7.org/linux/man-pages/man2/accept.2.html)

# Content
- `accept()`
    - [syntax](#syntax)
    - [description](#description)
    - [return value](#return-value)
    - [example](#example)

## accept()
### Syntax:
```c++
#include <sys/socket.h>
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

### Description:
- `accept()` chấp nhận một kết nối đến từ hàng đợi của `listen()`.
- Hàm này sẽ tạm dừng chương trình cho đến khi có một kết nối được chấp nhận.
- `accept()` trả về một socket mới (file descriptor) được sử dụng để giao tiếp với client. Socket ban đầu vẫn được dùng để lắng nghe các kết nối khác.

### Return Value:
- Trả về một socket mới (file descriptor) nếu thành công.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

### Example:
```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Tạo một socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Khởi tạo cấu trúc sockaddr_in
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Gắn socket với địa chỉ
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Lắng nghe kết nối
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Chấp nhận kết nối
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (new_sockfd == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Giao tiếp với client thông qua new_sockfd

    close(new_sockfd);
    close(sockfd);
    return 0;
}
```

### Explanation:
- **client_addr**: `sockaddr` structure để lưu trữ địa chỉ của client.
- **client_len**: Con trỏ đến biến kiểu `socklen_t` để lưu trữ kích thước của `client_addr`.
- **new_sockfd**: Socket mới được trả về bởi `accept()` để giao tiếp với client.
- **Sau accept()**: Sau khi chấp nhận kết nối, server có thể sử dụng `new_sockfd` để gửi và nhận dữ liệu từ client.
