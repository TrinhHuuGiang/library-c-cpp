//  tạo ra 1 file rác tự động có thể lưu
// đọc dữ liệu cần từ người dùng và xử lý \n \r
// Vì khi xóa 1 ký tự thì các ký tự sau sẽ dồn lại gây khó xử lý, giải pháp đặt ra là đọc file đến
// tìm thấy \n hoặc \r thì bỏ qua
// tạo 1 biến lưu số lượng \n\r đã tìm thấy
// sau đó ghi dữ liệu trước đó vào buffer
// nếu buffer chưa đầy thì tiếp tục xử lý dữ liệu bên kia
// nếu buffer đã đầy thì đẩy ra file mới
// cuối cùng khi gặp EOF thì đóng file cũ.
// xem xét biến tìm kiếm và đưa ra màn hình kết quả tìm được bao nhiêu \r, \n.
// kết thúc chương trình thì nếu !=0 ta xóa file cũ và giữ file mới bằng cách đổi tên.
// ngược lại ta xóa file mới.

// 📌 Quy trình tối ưu hóa xử lý file
// Duyệt file 1 lần để kiểm tra sự tồn tại của \n hoặc \r.

// Nếu file không chứa \n hoặc \r, ta không cần tạo file mới.
// Nếu có, ta tiếp tục xử lý.
// Đọc file theo từng block cố định (ví dụ: 4 KB).

// Bỏ qua \n, \r khi đọc vào buffer.
// Khi buffer đầy, ghi nó vào file mới.
// Flush dữ liệu khi EOF, đóng file cũ và thay thế file.


/***************************************
Definitions
***************************************/
#include "main_state.h"

/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/

/***************************************
Code
***************************************/
/**
 * @brief main fuction
 * 
 * @return
 * 0 - no problem
 * 
 * not 0 - call menu for more inform
 */
int main(int argc, char* argv[])
{
    // if input menu -> menu
    // if input sonething else -> check

    return 0;    
}
