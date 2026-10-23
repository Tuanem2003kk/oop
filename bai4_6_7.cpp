#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void giaiPhuongTrinhBacNhat() {
    double a, b;

    cout << "\n=== BAI 4: GIAI PHUONG TRINH BAC NHAT ===\n";
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem.\n";
        } else {
            cout << "Phuong trinh vo nghiem.\n";
        }
    } else {
        cout << "Nghiem x = " << fixed << setprecision(2) << -b / a << '\n';
    }
}

void kiemTraTamGiac() {
    double a, b, c;

    cout << "\n=== BAI 6: KIEM TRA TAM GIAC ===\n";
    cout << "Nhap canh a: ";
    cin >> a;
    cout << "Nhap canh b: ";
    cin >> b;
    cout << "Nhap canh c: ";
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a) {
        cout << "Ba canh khong tao thanh tam giac.\n";
        return;
    }

    const double chuVi = a + b + c;
    const double nuaChuVi = chuVi / 2;
    const double dienTich =
        sqrt(nuaChuVi * (nuaChuVi - a) * (nuaChuVi - b) *
             (nuaChuVi - c));

    cout << fixed << setprecision(2);
    cout << "Ba canh tao thanh tam giac.\n";
    cout << "Chu vi: " << chuVi << '\n';
    cout << "Dien tich: " << dienTich << '\n';
}

void tinhDiemVaXepLoai() {
    double diemLyThuyet, diemThucHanh;

    cout << "\n=== BAI 7: TINH DIEM VA XEP LOAI ===\n";
    cout << "Nhap diem ly thuyet: ";
    cin >> diemLyThuyet;
    cout << "Nhap diem thuc hanh: ";
    cin >> diemThucHanh;

    if (diemLyThuyet < 0 || diemLyThuyet > 10 ||
        diemThucHanh < 0 || diemThucHanh > 10) {
        cout << "Diem phai nam trong khoang tu 0 den 10.\n";
        return;
    }

    const double diemTrungBinh = (diemLyThuyet + diemThucHanh) / 2;

    cout << fixed << setprecision(2);
    cout << "Diem trung binh: " << diemTrungBinh << '\n';

    if (diemTrungBinh >= 8) {
        cout << "Xep loai: Gioi\n";
    } else if (diemTrungBinh >= 6.5) {
        cout << "Xep loai: Kha\n";
    } else if (diemTrungBinh >= 5) {
        cout << "Xep loai: Trung binh\n";
    } else if (diemTrungBinh >= 3.5) {
        cout << "Xep loai: Yeu\n";
    } else {
        cout << "Xep loai: Kem\n";
    }
}

int main() {
    int luaChon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Bai 4 - Giai phuong trinh bac 1\n";
        cout << "2. Bai 6 - Kiem tra tam giac\n";
        cout << "3. Bai 7 - Tinh diem va xep loai\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            giaiPhuongTrinhBacNhat();
            break;
        case 2:
            kiemTraTamGiac();
            break;
        case 3:
            tinhDiemVaXepLoai();
            break;
        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 0);

    return 0;
}
