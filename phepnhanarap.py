#Nhân Ả Rập
class Cell:
    def __init__(self):
        self.donvi = 0  # Chứa chữ số hàng đơn vị của mỗi ô trong ma trận
        self.chuc = 0   # Chứa chữ số hàng chục của mỗi ô trong ma trận

a = [[Cell() for _ in range(20)] for _ in range(20)]  # Tạo ma trận 20x20 chứa các đối tượng Cell

def Fill(x, y):
    global a
    m = len(x)  # Độ dài của số thứ nhất
    n = len(y)  # Độ dài của số thứ hai
    for i in range(1, m + 1):
        u = int(x[i - 1])  # Lấy chữ số tại vị trí i - 1 trong số thứ nhất
        for j in range(1, n + 1):
            v = int(y[j - 1])  # Lấy chữ số tại vị trí j - 1 trong số thứ hai
            a[i][j].chuc = u * v // 10  # Tính và gán chữ số hàng chục vào ma trận
            a[i][j].donvi = u * v % 10   # Tính và gán chữ số hàng đơn vị vào ma trận

def View(m, n):
    global a
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            print(f"{a[i][j].chuc}/{a[i][j].donvi} ", end="\t")  # Hiển thị giá trị hàng chục và hàng đơn vị của mỗi ô
        print("\n")

def NhanArap(x, y, m, n):
    global a
    z = ""
    c = chr(a[m][n].donvi + 48)  # Chuyển số hàng đơn vị thành ký tự ASCII tương ứng
    z = c + z
    schuc = a[m][n].chuc  # Lấy giá trị hàng chục tại vị trí (m, n)

    # Tính toán và cập nhật các giá trị cho số kết quả
    # Duyệt từ hàng cuối cùng của ma trận đến hàng đầu tiên
    for i in range(m - 1, 0, -1):
        s = schuc
        sdonvi = 0
        schuc = 0
        u, v = i, n
        while u <= m:
            sdonvi += a[u][v].donvi
            schuc += a[u][v].chuc
            u += 1
            v -= 1
        s += sdonvi
        nho = s // 10
        c = chr(s % 10 + 48)
        z = c + z

    # Duyệt từ cột cuối cùng của ma trận đến cột đầu tiên
    for j in range(n - 1, 0, -1):
        s = schuc
        sdonvi = 0
        schuc = 0
        u, v = 1, j
        while v > 0:
            sdonvi += a[u][v].donvi
            schuc += a[u][v].chuc
            u += 1
            v -= 1
        s += sdonvi
        nho = s // 10
        c = chr(s % 10 + 48)
        z = c + z

    s = schuc + nho
    if s > 0:
        c = chr(s + 48)
        z = c + z
    return z

def main():
    x = input("Nhập Số Đầu Tiên: ")
    y = input("Nhập Số Thứ Hai : ")
    m = len(x)  # Độ dài của số thứ nhất
    n = len(y)  # Độ dài của số thứ hai
    Fill(x, y)  # Điền thông tin vào ma trận
    View(m, n)  # Hiển thị ma trận
    result = NhanArap(x, y, m, n)  # Thực hiện phép nhân Arap
    print(result)  # Hiển thị kết quả

if __name__ == "__main__":
    main()  # Gọi hàm main khi chạy chương trình