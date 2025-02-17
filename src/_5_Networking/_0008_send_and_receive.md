# References:
- [man page: send()](https://man7.org/linux/man-pages/man2/send.2.html)
- [man page: recv()](https://man7.org/linux/man-pages/man2/recv.2.html)

# Content
- `send()`
    - [syntax](#syntax-send)
    - [description](#description-send)
    - [return value](#return-value-send)
    - [example](#example-send)
- `recv()`
    - [syntax](#syntax-recv)
    - [description](#description-recv)
    - [return value](#return-value-recv)
    - [example](#example-recv)

## send()
### Syntax:
```c++
#include <sys/socket.h>
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```

### Description:
- `send()` được sử dụng để gửi dữ liệu qua socket.
- `sockfd` là socket đã được kết nối.
- `buf` là con trỏ đến dữ liệu cần gửi.
- `len` là số byte cần gửi.
- `flags` là các tùy chọn (thường là 0).

### Return Value:
- Trả về số byte đã gửi thành công.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

### Example:
```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main() {
    // ... (code tạo và kết nối socket như các ví dụ trước) ...

    char message[] = "Hello from client";
    ssize_t bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    printf("Sent %ld bytes\n", bytes_sent);

    close(sockfd);
    return 0;
}
```

## recv()
### Syntax:
```c++
#include <sys/socket.h>
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

### Description:
- `recv()` được sử dụng để nhận dữ liệu qua socket.
- `sockfd` là socket đã được kết nối.
- `buf` là con trỏ đến vùng nhớ để lưu dữ liệu nhận được.
- `len` là số byte tối đa có thể nhận.
- `flags` là các tùy chọn (thường là 0).

### Return Value:
- Trả về số byte đã nhận được.
- Trả về `0` nếu kết nối bị đóng bởi đối phương.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

### Example:
```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // ... (code tạo và kết nối socket như các ví dụ trước) ...

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    } else if (bytes_received == 0) {
        printf("Connection closed by peer\n");
    } else {
        printf("Received %ld bytes: %s\n", bytes_received, buffer);
    }

    close(sockfd);
    return 0;
}
```

### Giải thích chung:
- `send()` và `recv()` là hai hàm cơ bản để giao tiếp qua socket.
- Chúng cho phép ứng dụng gửi và nhận dữ liệu một cách linh hoạt.
- Cần kiểm tra giá trị trả về của chúng để xử lý các trường hợp lỗi hoặc kết nối bị đóng.
