#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int baris = 3;
const int kolom = 8;

void tampilkanTabel(string data[baris][kolom]) {
    cout << "\n==================== TABEL DATA KTP ====================\n";
    cout << left << setw(5) << "No"
         << setw(20) << "NIK"
         << setw(20) << "Nama"
         << setw(15) << "Tgl Lahir" << endl;
    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < baris; i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << data[i][0]
             << setw(20) << data[i][1]
             << setw(15) << data[i][4] << endl;
    }

    cout << "---------------------------------------------------------\n";
}

void urutkanData(string data[baris][kolom], int kolomUrut) {
    for (int i = 0; i < baris - 1; i++) {
        for (int j = i + 1; j < baris; j++) {
            if (data[i][kolomUrut] > data[j][kolomUrut]) {
                for (int k = 0; k < kolom; k++) {
                    swap(data[i][k], data[j][k]);
                }
            }
        }
    }
}

int main() {
    string data[baris][kolom];
    char ulang;

    cout << "=== INPUT DATA KTP LENGKAP ===\n";
    for (int i = 0; i < baris; i++) {
        cout << "\nMasukkan data untuk KTP ke-" << i + 1 << ":\n";
        cout << "NIK            : "; 
		getline(cin, data[i][0]);
        cout << "Nama           : "; 
		getline(cin, data[i][1]);
        cout << "Alamat         : "; 
		getline(cin, data[i][2]);
        cout << "Golongan Darah : "; 
		getline(cin, data[i][3]);
        cout << "Tanggal Lahir (DD-MM-YYYY): "; 
		getline(cin, data[i][4]);
        cout << "Jenis Kelamin  : "; 
		getline(cin, data[i][5]);
        cout << "Agama          : "; 
		getline(cin, data[i][6]);
        cout << "Pekerjaan      : "; 
		getline(cin, data[i][7]);
    }

    do {
        int pilihan;
        cout << "\n=== PILIHAN PENGURUTAN ===\n";
        cout << "1. Urutkan berdasarkan NIK\n";
        cout << "2. Urutkan berdasarkan Nama\n";
        cout << "3. Urutkan berdasarkan Tanggal Lahir\n";
        cout << "Masukkan pilihan (1 - 3): ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) urutkanData(data, 0);
        else if (pilihan == 2) urutkanData(data, 1);
        else if (pilihan == 3) urutkanData(data, 4);
        else cout << "Pilihan tidak valid!\n";

        tampilkanTabel(data);

        cout << "Ingin mengulang pengurutan? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang != 'n' && ulang != 'N');

    cout << "\nTerima kasih!\n";
    return 0;
}
