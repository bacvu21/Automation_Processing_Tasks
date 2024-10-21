# Automation Processing Tasks

## Mô Tả Dự Án

Dự án **Automation Processing Tasks** nhằm mục đích tự động hóa các tác vụ liên quan đến việc tạo process, kết nối với proxy và mở trình duyệt. Dự án này sử dụng ngôn ngữ lập trình C để thực hiện các thao tác này, giúp tiết kiệm thời gian và tăng hiệu suất làm việc.

## Tính Năng

- **Tạo Process**: Cho phép tạo process mới trên hệ thống.
- **Kết Nối Proxy**: Tự động kết nối tới một proxy server để bảo mật và ẩn danh khi truy cập internet.
- **Mở Trình Duyệt**: Mở trình duyệt web mặc định để thực hiện các tác vụ trực tuyến sau khi kết nối proxy.

## Cài Đặt

### Yêu Cầu Hệ Thống

- Hệ điều hành: Windows, Linux hoặc macOS
- Compiler: GCC hoặc bất kỳ compiler nào hỗ trợ C
- Thư viện: `<winsock2.h>` (trên Windows) hoặc các thư viện socket tương ứng trên các hệ điều hành khác.

### Hướng Dẫn Cài Đặt

1. **Clone Repository**:

   ```bash
   git clone https://github.com/your_username/Automation_Processing_Tasks.git
   cd Automation_Processing_Tasks