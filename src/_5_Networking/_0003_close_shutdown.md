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
- `close()` đóng một socket hoặc một file descriptor bất kỳ.
- Khi đóng một socket:
  - Nếu có dữ liệu chưa gửi, hệ thống có thể tiếp tục gửi trước khi thực sự đóng.
  - Đối với TCP, đóng socket sẽ gửi gói `FIN`, báo hiệu kết thúc kết nối.

### Return Value:
- Trả về `0` nếu thành công.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

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
- `shutdown()` chỉ đóng một phần của kết nối TCP.
- Không giống `close()`, `shutdown()` có thể:
  - Ngăn gửi dữ liệu (`SHUT_WR`).
  - Ngăn nhận dữ liệu (`SHUT_RD`).
  - Ngăn cả hai (`SHUT_RDWR`).

### Shutdown Modes:
- `SHUT_RD` (0): Không nhận thêm dữ liệu.
- `SHUT_WR` (1): Không gửi thêm dữ liệu.
- `SHUT_RDWR` (2): Không gửi và không nhận dữ liệu.

### Return Value:
- Trả về `0` nếu thành công.
- Trả về `-1` nếu có lỗi, và `errno` sẽ được thiết lập để mô tả lỗi.

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
    
    // Ngừng gửi dữ liệu nhưng vẫn có thể nhận
    if (shutdown(sockfd, SHUT_WR) == -1) {
        perror("shutdown failed");
    }
    
    close(sockfd);
    return 0;
}
```

