#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string maSV, hoTen, nganhHoc;
    double diemToan, diemTin, diemCpp;

public:
    void nhap() {
        cout << "Ma sinh vien: ";
        getline(cin >> ws, maSV);

        cout << "Ho ten: ";
        getline(cin, hoTen);

        cout << "Nganh hoc: ";
        getline(cin, nganhHoc);

        cout << "Diem toan cao cap: ";
        cin >> diemToan;

        cout << "Diem tin dai cuong: ";
        cin >> diemTin;

        cout << "Diem C++: ";
        cin >> diemCpp;
    }

    double tinhDiemTrungBinh() const {
        return (diemToan + diemTin + diemCpp) / 3.0;
    }

    bool coMonDuoi5() const {
        return diemToan < 5 || diemTin < 5 || diemCpp < 5;
    }

    bool duocHocBong() const {
        return tinhDiemTrungBinh() >= 8 && !coMonDuoi5();
    }

    bool duocLenLop() const {
        return tinhDiemTrungBinh() >= 7 && !coMonDuoi5();
    }

    bool phaiThiLai() const {
        return coMonDuoi5();
    }

    void xuat() const {
        cout << fixed << setprecision(2);
        cout << "Ma SV: " << maSV
             << "\nHo ten: " << hoTen
             << "\nNganh hoc: " << nganhHoc
             << "\nDiem toan: " << diemToan
             << "\nDiem tin: " << diemTin
             << "\nDiem C++: " << diemCpp
             << "\nDiem trung binh: " << tinhDiemTrungBinh()
             << "\n------------------------------\n";
    }
};

int main() {
    int n;

    do {
        cout << "Nhap so luong sinh vien (n > 0): ";
        cin >> n;
    } while (n <= 0);

    vector<SinhVien> danhSach(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        danhSach[i].nhap();
    }

    bool coSinhVien = false;
    cout << "\n=== SINH VIEN CO DIEM TRUNG BINH >= 7 ===\n";
    for (const SinhVien& sv : danhSach) {
        if (sv.tinhDiemTrungBinh() >= 7) {
            sv.xuat();
            coSinhVien = true;
        }
    }
    if (!coSinhVien) cout << "Khong co sinh vien.\n";

    coSinhVien = false;
    cout << "\n=== SINH VIEN DUOC HOC BONG ===\n";
    for (const SinhVien& sv : danhSach) {
        if (sv.duocHocBong()) {
            sv.xuat();
            coSinhVien = true;
        }
    }
    if (!coSinhVien) cout << "Khong co sinh vien.\n";

    coSinhVien = false;
    cout << "\n=== SINH VIEN DUOC LEN LOP ===\n";
    for (const SinhVien& sv : danhSach) {
        if (sv.duocLenLop()) {
            sv.xuat();
            coSinhVien = true;
        }
    }
    if (!coSinhVien) cout << "Khong co sinh vien.\n";

    coSinhVien = false;
    cout << "\n=== SINH VIEN PHAI THI LAI ===\n";
    for (const SinhVien& sv : danhSach) {
        if (sv.phaiThiLai()) {
            sv.xuat();
            coSinhVien = true;
        }
    }
    if (!coSinhVien) cout << "Khong co sinh vien.\n";

    return 0;
}