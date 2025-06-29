#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahPenduduk;
    const int kolom = 11;
    string judul[kolom] = {
        "NIK", "Nama", "Tempat Lahir", "Tanggal Lahir", "Jenis Kelamin",
        "Gol. Darah", "Alamat", "Agama", "Status", "Pekerjaan", "Kewarganegaraan"
    };

    cout << "Masukkan jumlah data KTP yang ingin diinputkan: ";
    cin >> jumlahPenduduk;
    cin.ignore();

    string data[jumlahPenduduk][kolom];

    cout << "\n========== INPUT DATA KTP ==========\n";
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "\nData ke-" << i + 1 << ":\n";
        for (int j = 0; j < kolom; j++) {
            cout << judul[j] << " : ";
            getline(cin, data[i][j]);
        }
    }

    cout << "\n\n================ TABEL DATA KTP (Ringkas) ================\n";
    cout << "--------------------------------------------------------------\n";
    cout << "| No |        NIK        |        Nama        | Tanggal Lahir |\n";
    cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "| " << i + 1 << "  | ";
        cout << data[i][0] << " | ";
        cout << data[i][1] << " | ";
        cout << data[i][3] << " |\n";
    }
    cout << "--------------------------------------------------------------\n";

    cout << "\n========== DATA KTP LENGKAP ==========\n";
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "\nData ke-" << i + 1 << ":\n";
        for (int j = 0; j < kolom; j++) {
            cout << judul[j] << " : " << data[i][j] << endl;
        }
    }

    string cari;
    bool ditemukan = false;
    cout << "\n========== PENCARIAN DATA ==========\n";
    cout << "Cari berdasarkan NIK atau Nama: ";
    getline(cin, cari);

    for (int i = 0; i < jumlahPenduduk; i++) {
        if (data[i][0] == cari || data[i][1] == cari) {
            cout << "\nData ditemukan!\n";
            for (int j = 0; j < kolom; j++) {
                cout << judul[j] << " : " << data[i][j] << endl;
            }
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIK atau Nama \"" << cari << "\" tidak ditemukan.\n";
    }

    return 0;
}
