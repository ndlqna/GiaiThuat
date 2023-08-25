#include <iostream>
#include <string>

using namespace std;

class Cell {
public:
    int donvi; // Chứa chữ số hàng đơn vị của mỗi ô trong ma trận
    int chuc;  // Chứa chữ số hàng chục của mỗi ô trong ma trận
};

const int MAX_SIZE = 20;
Cell a[MAX_SIZE + 1][MAX_SIZE + 1]; // Tạo ma trận 20x20 chứa các đối tượng Cell

void Fill(string x, string y) {
    int m = x.length(); // Độ dài của số thứ nhất
    int n = y.length(); // Độ dài của số thứ hai
    for (int i = 1; i <= m; ++i) {
        int u = x[i - 1] - '0'; // Lấy chữ số tại vị trí i - 1 trong số thứ nhất
        for (int j = 1; j <= n; ++j) {
            int v = y[j - 1] - '0'; // Lấy chữ số tại vị trí j - 1 trong số thứ hai
            a[i][j].chuc = u * v / 10; // Tính và gán chữ số hàng chục vào ma trận
            a[i][j].donvi = u * v % 10; // Tính và gán chữ số hàng đơn vị vào ma trận
        }
    }
}

void View(int m, int n) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j].chuc << '/' << a[i][j].donvi << ' ';
        }
        cout << '\n';
    }
}

string NhanArap(string x, string y, int m, int n) {
    string z = "";
    char c = a[m][n].donvi + 48; // Chuyển số hàng đơn vị thành ký tự ASCII tương ứng
    z = c + z;
    int schuc = a[m][n].chuc; // Lấy giá trị hàng chục tại vị trí (m, n)

    // Tính toán và cập nhật các giá trị cho số kết quả
    // Duyệt từ hàng cuối cùng của ma trận đến hàng đầu tiên
    for (int i = m - 1; i >= 1; --i) {
        int s = schuc;
        int sdonvi = 0;
        schuc = 0;
        int u = i, v = n;
        while (u <= m) {
            sdonvi += a[u][v].donvi;
            schuc += a[u][v].chuc;
            u += 1;
            v -= 1;
        }
        s += sdonvi;
        int nho = s / 10;
        c = s % 10 + 48;
        z = c + z;
    }

    // Duyệt từ cột cuối cùng của ma trận đến cột đầu tiên
    for (int j = n - 1; j >= 1; --j) {
        int s = schuc;
        int sdonvi = 0;
        schuc = 0;
        int u = 1, v = j;
        while (v > 0) {
            sdonvi += a[u][v].donvi;
            schuc += a[u][v].chuc;
            u += 1;
            v -= 1;
        }
        s += sdonvi;
        int nho = s / 10;
        c = s % 10 + 48;
        z = c + z;
    }

    int s = schuc + nho;
    if (s > 0) {
        c = s + 48;
        z = c + z;
    }
    return z;
}

int main() {
    string x, y;
    cout << "Nhập Số Đầu Tiên: ";
    cin >> x;
    cout << "Nhập Số Thứ Hai : ";
    cin >> y;
    int m = x.length(); // Độ dài của số thứ nhất
    int n = y.length(); // Độ dài của số thứ hai
    Fill(x, y); // Điền thông tin vào ma trận
    View(m, n); // Hiển thị ma trận
    string result = NhanArap(x, y, m, n); // Thực hiện phép nhân Arap
    cout << result << '\n'; // Hiển thị kết quả

    return 0;
}
