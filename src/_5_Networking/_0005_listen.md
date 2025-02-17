# References:
- [man page: listen()](https://man7.org/linux/man-pages/man2/listen.2.html)

# Content
- `listen()`
    - [syntax](#syntax)
    - [description](#description)
    - [return value](#return-value)
    - [example](#example)

## listen()
### Syntax:
```c++
#include <sys/socket.h>
int listen(int sockfd, int backlog);
```

### Description:
- `listen()` cho phép socket lắng nghe các kết nối đến.
- Hàm này thường được gọi sau `bind()` để chuẩn bị cho việc chấp nhận các kết nối từ client.
- Tham số `backlog` chỉ định số lượng kết nối tối đa có thể được xếp hàng đợi trong khi server đang xử lý các kết nối khác.

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

#define PORT 8080
#define BACKLOG 10 // Số lượng kết nối tối đa trong hàng đợi

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

    // Tiếp tục với các bước khác như accept()

    close(sockfd);
    return 0;
}
```

### Explanation:
- **Backlog**: Tham số `backlog` quan trọng trong `listen()`. Nó xác định số lượng kết nối tối đa mà server có thể giữ trong hàng đợi. Nếu có nhiều kết nối đến hơn `backlog`, các kết nối đó sẽ bị từ chối.
- **listen()**: Hàm `listen()` chuyển socket sang trạng thái lắng nghe, sẵn sàng chấp nhận các kết nối đến.
- **Sau listen()**: Sau khi gọi `listen()`, server thường sẽ sử dụng hàm `accept()` để chấp nhận từng kết nối từ hàng đợi.

