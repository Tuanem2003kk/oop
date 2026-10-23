#include <iostream>

using namespace std;

int tong(int a, int b) {
    return a + b;
}

int tong(int a, int b, int c) {
    return a + b + c;
}

int tong(const int arr[], int n) {
    int ketQua = 0;
    for (int i = 0; i < n; i++) {
        ketQua += arr[i];
    }
    return ketQua;
}

int main() {
    int a, b, c;

    cout << "=== TONG HAI SO NGUYEN ===\n";
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong hai so = " << tong(a, b) << '\n';

    cout << "\n=== TONG BA SO NGUYEN ===\n";
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    cout << "Tong ba so = " << tong(a, b, c) << '\n';

    int n;
    cout << "\n=== TONG DAY SO NGUYEN ===\n";
    cout << "Nhap so phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu phai lon hon 0.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Tong day so = " << tong(arr, n) << '\n';

    delete[] arr;
    return 0;
}
