#include <cmath>
#include <iostream>

using namespace std;

int tong(int a, int b) {
    return a + b;
}

long long giaithua(int n) {
    long long ketQua = 1;
    for (int i = 2; i <= n; i++) {
        ketQua *= i;
    }
    return ketQua;
}

long long luyThua(int x, int y) {
    long long ketQua = 1;
    for (int i = 0; i < y; i++) {
        ketQua *= x;
    }
    return ketQua;
}

void giaiPhuongTrinhBacHai() {
    double a, b, c;
    cout << "\n=== GIAI PHUONG TRINH BAC HAI ===\n";
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            cout << (c == 0 ? "Phuong trinh vo so nghiem.\n"
                            : "Phuong trinh vo nghiem.\n");
        } else {
            cout << "Phuong trinh co nghiem x = " << -c / b << '\n';
        }
        return;
    }

    const double delta = b * b - 4 * a * c;
    const double epsilon = 1e-9;

    if (delta < -epsilon) {
        cout << "Phuong trinh vo nghiem.\n";
    } else if (abs(delta) <= epsilon) {
        cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << '\n';
    } else {
        const double x1 = (-b + sqrt(delta)) / (2 * a);
        const double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1 = " << x1 << '\n';
        cout << "x2 = " << x2 << '\n';
    }
}

bool laSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        const int phanDu = a % b;
        a = b;
        b = phanDu;
    }
    return a;
}

long long bcnn(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return static_cast<long long>(abs(a / ucln(a, b))) * abs(b);
}

int main() {
    int luaChon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Tinh tong hai so nguyen\n";
        cout << "2. Tinh n!\n";
        cout << "3. Tinh x^y\n";
        cout << "4. Giai phuong trinh bac hai\n";
        cout << "5. Kiem tra va liet ke so nguyen to < n\n";
        cout << "6. Tim UCLN va BCNN\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            int a, b;
            cout << "Nhap a, b: ";
            cin >> a >> b;
            cout << "Tong = " << tong(a, b) << '\n';
            break;
        }
        case 2: {
            int n;
            cout << "Nhap n (0 <= n <= 20): ";
            cin >> n;
            if (n < 0 || n > 20) {
                cout << "n phai nam trong khoang tu 0 den 20.\n";
            } else {
                cout << n << "! = " << giaithua(n) << '\n';
            }
            break;
        }
        case 3: {
            int x, y;
            cout << "Nhap x va y (y >= 0): ";
            cin >> x >> y;
            if (y < 0) {
                cout << "So mu y phai lon hon hoac bang 0.\n";
            } else {
                cout << x << "^" << y << " = " << luyThua(x, y) << '\n';
            }
            break;
        }
        case 4:
            giaiPhuongTrinhBacHai();
            break;
        case 5: {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            cout << "Cac so nguyen to nho hon " << n << ": ";
            bool coSoNguyenTo = false;
            for (int i = 2; i < n; i++) {
                if (laSoNguyenTo(i)) {
                    cout << i << ' ';
                    coSoNguyenTo = true;
                }
            }
            if (!coSoNguyenTo) {
                cout << "Khong co";
            }
            cout << '\n';
            break;
        }
        case 6: {
            int a, b;
            cout << "Nhap a, b: ";
            cin >> a >> b;
            cout << "UCLN(" << a << ", " << b << ") = " << ucln(a, b) << '\n';
            cout << "BCNN(" << a << ", " << b << ") = " << bcnn(a, b) << '\n';
            break;
        }
        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 0);

    return 0;
}
