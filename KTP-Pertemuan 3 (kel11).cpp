#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
 
using namespace std;
struct KTP {
    long long nik;
    string nama;
    string tmptTgl;
    string jenisKlmn;
    char gol[2];
    string alamat;
    string rtRw;
    string kelDesa;
    string kecamatan;
    string agama;
    string kawin;
    string kerja;
    string kewarganegaraan;
    string berlaku;
};
 
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
 
void isiKTP(KTP &ktp) {
    cout << "Masukkan NIK: ";
    cin >> ktp.nik;
    clearInputBuffer();
 
    cout << "Masukkan Nama: ";
    getline(cin, ktp.nama);
    cout << "Masukkan Tempat/Tgl Lahir: ";
    getline(cin, ktp.tmptTgl);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, ktp.jenisKlmn);
    cout << "Masukkan Golongan Darah (A/B/AB/O): ";
    cin >> ktp.gol;
    clearInputBuffer();
 
    cout << "Masukkan Alamat: ";
    getline(cin, ktp.alamat);
    cout << "Masukkan RT/RW: ";
    getline(cin, ktp.rtRw);
    cout << "Masukkan Kelurahan/Desa: ";
    getline(cin, ktp.kelDesa);
    cout << "Masukkan Kecamatan: ";
    getline(cin, ktp.kecamatan);
    cout << "Masukkan Agama: ";
    getline(cin, ktp.agama);
    cout << "Masukkan Status Perkawinan: ";
    getline(cin, ktp.kawin);
    cout << "Masukkan Pekerjaan: ";
    getline(cin, ktp.kerja);
    cout << "Masukkan Kewarganegaraan: ";
    getline(cin, ktp.kewarganegaraan);
    cout << "Masukkan Berlaku Hingga: ";
    getline(cin, ktp.berlaku);
}
 
void cetakBingkaiAtasBawah(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "=";
    }
    cout << endl;
}
 
void displayKTP(const KTP &ktp) {
    cout << "=========================================="<<endl;
    cout << "\tKARTU TANDA PENDUDUK (KTP)" << endl;
    cout << "=========================================="<<endl;
    cout << "|NIK: " << ktp.nik << endl;
    cout << "|Nama : " << ktp.nama << endl;
    cout << "|Tempat/Tgl Lahir : " << ktp.tmptTgl << endl;
    cout << "|Jenis Kelamin : " << ktp.jenisKlmn << 
	cout << "|Gol Darah: " << ktp.gol<< endl;
    cout << "|Alamat : " << ktp.alamat << endl;
    cout << "|RT/RW : " << ktp.rtRw << endl;
    cout << "|Kel/Desa : " << ktp.kelDesa << endl;
    cout << "|Kecamatan : " << ktp.kecamatan << endl;
    cout << "|Agama : " << ktp.agama << endl;
    cout << "|Status Perkawinan : " << ktp.kawin << endl;
    cout << "|Pekerjaan" << ": " << ktp.kerja << endl;
    cout << "|Kewarganegaraan : " << ktp.kewarganegaraan << endl;
    cout << "|Berlaku Hingga : " << ktp.berlaku<< endl;
    cout << "=========================================="<<endl;
 
}
 
void editKTP(KTP &ktp) {
    int pilihan;
    do {
        cout << "\n== MENU EDIT DATA KTP ==\n";
        cout << "1. Nama\n";
        cout << "2. Tempat/Tgl Lahir\n";
        cout << "3. Jenis Kelamin\n";
        cout << "4. Golongan Darah\n";
        cout << "5. Alamat\n";
        cout << "6. RT/RW\n";
        cout << "7. Kelurahan/Desa\n";
        cout << "8. Kecamatan\n";
        cout << "9. Agama\n";
        cout << "10. Status Perkawinan\n";
        cout << "11. Pekerjaan\n";
        cout << "12. Kewarganegaraan\n";
        cout << "13. Berlaku Hingga\n";
        cout << "0. Selesai Edit\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        clearInputBuffer();
 
        switch (pilihan) {
            case 1: cout << "Nama baru: "; getline(cin, ktp.nama); break;
            case 2: cout << "Tempat/Tgl Lahir baru: "; getline(cin, ktp.tmptTgl); break;
            case 3: cout << "Jenis Kelamin baru: "; getline(cin, ktp.jenisKlmn); break;
            case 4: cout << "Golongan Darah baru (A/B/AB/O): "; cin >> ktp.gol; clearInputBuffer(); break;
            case 5: cout << "Alamat baru: "; getline(cin, ktp.alamat); break;
            case 6: cout << "RT/RW baru: "; getline(cin, ktp.rtRw); break;
            case 7: cout << "Kelurahan/Desa baru: "; getline(cin, ktp.kelDesa); break;
            case 8: cout << "Kecamatan baru: "; getline(cin, ktp.kecamatan); break;
            case 9: cout << "Agama baru: "; getline(cin, ktp.agama); break;
            case 10: cout << "Status Perkawinan baru: "; getline(cin, ktp.kawin); break;
            case 11: cout << "Pekerjaan baru: "; getline(cin, ktp.kerja); break;
            case 12: cout << "Kewarganegaraan baru: "; getline(cin, ktp.kewarganegaraan); break;
            case 13: cout << "Berlaku Hingga baru: "; getline(cin, ktp.berlaku); break;
            case 0: cout << "Selesai mengedit data.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while (pilihan != 0);
}
 
int main() {
    KTP ktp;
 
    cout << "Input Data KTP\n";
    isiKTP(ktp);
 
    displayKTP(ktp);
 
    char edit;
    cout << "\nApakah Anda ingin mengedit data? (y/n): ";
    cin >> edit;
    clearInputBuffer();
 
    if (edit == 'y' || edit == 'Y') {
        editKTP(ktp);
        displayKTP(ktp);
    }
 
    return 0;
}
