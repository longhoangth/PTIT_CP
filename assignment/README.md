# CUSTOMER MANAGEMENT ASSIGNMENT

 - Quản lý khách hàng sử dụng `Terminal`, lưu trữ thông tin trong `File`.
 - Danh sách chức năng:
```text
1. Load Data.
2. Add New Customer.
3. Find Customer.
4. Modify A Customer.
5. Delete A Customer.
6. Update Everything.
7. Exit (Log Out)
```

```text
    Các trường thông tin của khách hàng:
1. ID(card sequence number)
2. Họ tên
3. Địa chỉ Email
4. Số điện thoại
5. Số dư
```
`1. Load Data`
    - Mỗi dòng trong `File` chứa thông tin của một khách hàng.
    - Mỗi một trường thông tin của khách hàng được phân cách với nhau và kết thức bằng ký tự '$'.
    - Mỗi khách hàng là một `Object` được lưu chung vào một `Vector`.
`2. Thêm khách hàng mới`
    - Thêm một `Object` vào `Vector` lưu trữ.
`3. Tìm kiếm`
    - Tìm kiếm theo ID, tên, email, số điện thoại.
`4. Chỉnh sửa`
    - Chỉnh sửa thông tin của khách hàng.
`5. Xóa`
    - Xóa khách hàng khỏi `File`.

`Note`: 
    - Mỗi khi mở lại `Terminal`, cần chọn `1. Load Data` để đồng bộ thông tin từ `File` vào `Vector` lưu trữ.
    - Cần phải lựa chọn `6. Update Everything` sau mỗi lần thao tác với thông tin của khách hàng, nếu không chỉnh sửa sẽ không được lưu lại.