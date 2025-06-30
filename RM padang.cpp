#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

//struktur
class loginSistem {
public:
    bool loginPegawai() {
	    string username, password;
	    int percobaan = 3;
	    while (percobaan > 0) {
	        cout << "\n=== Login Pegawai ===\n";
	        cout << "Username (ketik '0' untuk keluar): ";
	        cin >> username;
	        if (username == "0") {
	            cout << "Login dibatalkan.\n";
	            return false;
	        }
	
	        cout << "Password: ";
	        cin >> password;
	
	        if (username == "pegawai" && password == "1234") {
	            cout << "Login berhasil sebagai Pegawai.\n";
	            return true;
	        } else {
	            percobaan--;
	            cout << "Login gagal. Sisa percobaan: " << percobaan << endl;
	        }
	    }
	    
	
	    cout << "Anda telah melebihi batas percobaan login.\n";
	    return false;
	    

    }

    bool loginCustomer() {
	    string nama;
	    cout << "\n=== Masuk Sebagai Customer ===\n";
	    cout << "Masukkan nama Anda: ";
	    getline(cin, nama);
	    cout << "Selamat datang, " << nama << "!\n";
	    return true;

    }

    int menuLogin() {
        int pilih;
        cout << "\n==== SELAMAT DATANG DI RESTO PADANG ====" << endl;
        cout << "1. Login sebagai Pegawai\n";
        cout << "2. Masuk sebagai Customer\n";
        cout << "Pilihan: ";
        cin >> pilih;
        return pilih;
    }
};

class Pegawai {
public:
    string nama[5] = {"Sita", "Dewi", "Citra", "Rita", "Eka"};
    string nip[5] = {"P001", "P002", "P003", "P004", "P005"};
    string jabatan[5] = {"Kasir", "Koki", "Pelayan", "Cleaning Service", "Manajer"};

    void cariByNama() {
        string cari;
        cin.ignore();
        cout << "\nMasukkan nama pegawai yang dicari: ";
        getline(cin, cari);
        bool ditemukan = false;

        for (int i = 0; i < 5; i++) {
            if (nama[i] == cari) {
                cout << "\nPegawai ditemukan:\n";
                cout << "Nama   : " << nama[i] << endl;
                cout << "NIP    : " << nip[i] << endl;
                cout << "Jabatan: " << jabatan[i] << endl;
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
            cout << "Pegawai tidak ditemukan.\n";
    }

    void cariByNIP() {
        string cari;
        cout << "\nMasukkan NIP pegawai yang dicari: ";
        cin >> cari;
        bool ditemukan = false;

        for (int i = 0; i < 5; i++) {
            if (nip[i] == cari) {
                cout << "\nPegawai ditemukan:\n";
                cout << "Nama   : " << nama[i] << endl;
                cout << "NIP    : " << nip[i] << endl;
                cout << "Jabatan: " << jabatan[i] << endl;
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
            cout << "Pegawai tidak ditemukan.\n";
    }

    void cariByJabatan() {
        string cari;
        cin.ignore();
        cout << "\nMasukkan jabatan yang dicari: ";
        getline(cin, cari);

        string tempNama[5], tempNIP[5], tempJabatan[5];
        for (int i = 0; i < 5; i++) {
            tempNama[i] = nama[i];
            tempNIP[i] = nip[i];
            tempJabatan[i] = jabatan[i];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (tempJabatan[i] > tempJabatan[j]) {
                    swap(tempJabatan[i], tempJabatan[j]);
                    swap(tempNama[i], tempNama[j]);
                    swap(tempNIP[i], tempNIP[j]);
                }
            }
        }

        int kiri = 0, kanan = 4, tengah, index = -1;
        while (kiri <= kanan) {
            tengah = (kiri + kanan) / 2;
            if (tempJabatan[tengah] == cari) {
                index = tengah;
                break;
            } else if (tempJabatan[tengah] < cari) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }

        if (index != -1) {
            cout << "\nPegawai ditemukan:\n";
            for (int i = index; i < 5 && tempJabatan[i] == cari; i++) {
                cout << "Nama   : " << tempNama[i] << endl;
                cout << "NIP    : " << tempNIP[i] << endl;
                cout << "Jabatan: " << tempJabatan[i] << "\n";
            }
        } else {
            cout << "Tidak ada pegawai dengan jabatan \"" << cari << "\".\n";
        }
    }
};


class RestoPadang {
public:
    //deklarasi atribut array, isi elemen array 20
        string menu[100] = {
        "Ayam Pop", 
        "Ayam Goreng", 
        "Ayam Bakar", 
        "Ayam Gulai", 
        "Rendang Daging",
        "Dendeng Balado", 
        "Dendeng Batokoko", 
        "Paru Goreng", 
        "Paru Balado", 
        "SOP Iga",
        "Iga Bakar", 
        "Gulai Kepala Kakap", 
        "Gulai Tunjang", 
        "Gulai Otak", 
        "Gulai Ikan Mas",
        "Gulai Ikan Tenggiri", 
        "Gulai Babat", 
        "Gulai Usus", 
        "Gulai Cumi", 
        "Kikil Cabe Ijo",
        "Telur Balado", 
        "Telur Gulai", 
        "Telur Dadar", 
        "Telur Barendo", 
        "Perkedel",
        "Tempe Goreng", 
        "Tahu Goreng", 
        "Jengek", 
        "Gulai Cincang Kambing", 
        "Ikan Kembung Bakar",
        "Ikan Kembung Goreng", 
        "Ikan Nila Bakar", 
        "Ikan Bawal Bakar", 
        "Ikan Mas Bakar", 
        "Ikan Nila Goreng",
        "Ikan Bawal Goreng", 
        "Ikan Mas Goreng", 
        "Ikan Sepat Cabe Hijau", 
        "Ikan Asin Gabus Cabe Hijau",
        "Ikan Asam Pade", 
        "Ikan Nila Dabu Dabu", 
        "Telur Ikan", 
        "Udang Tofu", 
        "Sambal Udang",
        "Udang Goreng Tepung", 
        "Sambal Terong Cumi Asin", 
        "Cumi Goreng Tepung", 
        "Nasi Putih",
        "Nasi Rames",
        "Sayur Nangka/Singkong",
        "Tumis Kangkung", 
        "Daun Ubi Tumbuk", 
        "Sambal ijo/merah", 
        "Sambal ati", 
        "sambal teri", 
        "sambal terasi", 
        "sambal matah",
        "sambal bawang", 
        "Lalapan", 
        "Sate Padang", 
        "Martabak Telur", 
        "Roti Cane", 
        "Soto Padang", 
        "Es/hot tea", 
        "lechy tea",
        "orange tea", 
        "strawberry tea", 
        "air kelapa", 
        "es cendol", 
        "es dawet", 
        "teh tarik", 
        "soda gembira", 
        "coffe latte",
        "Americano", 
        "cappucino", 
        "espresso", 
        "latte macchiato", 
        "matcha latte", 
        "milk greentea", 
        "red Velvet rose",
        "taro milk tea", 
        "es teller", 
        "es buah", 
        "Juice Durian", 
        "Juice Kopyor", 
        "Juice Alpukat", 
        "Juice Buah Naga",
        "Juice Terong Belanda", 
        "Juice Sirsak", 
        "Juice Mangga", 
        "Juice Jambu", 
        "Juice Belimbing", 
        "Juice Jeruk",
        "Juice Apel", 
        "Juice Tomat", 
        "Juice Melon", 
        "Juice Pepaya",     
        "Juice Timun", 
        "Juice Wortel", 
        "Juice Kedondong",
};
    int harga[100] = {
        20000, 
        18000, 
        18000, 
        20000, 
        34000,
        32000, 
        30000,     
        27000, 
        27500, 
        43000,
        48000, 
        87000, 
        73000, 
        44000, 
        35500,
        35500, 
        42000, 
        46500, 
        33500,     
        23000,
        15000, 
        15000, 
        12500, 
        18000, 
        10500,
        10000, 
        10000, 
        18000, 
        24500, 
        18000,
        16500, 
        18000, 
        18000, 
        18000, 
        16500,
        16500, 
        16500, 
        15000, 
        15000, 
        17000,
        17500, 
        20000, 
        55000,     
        26500, 
        33000,
        30500, 
        30000, 
        10000, 
        25000, 
        10000,
        15000,
        15000,
        5000,
        5000,
        5000,
        5000,
        5000,
        5000,
        5000,
        17000,
        20000,
        15000,
        10000,
        5000,
        6000,
        5000,
        7000,
        10000,
        7000,
        8000,
        7000,
        8000,
        10000,    
        10000,
        12000,
        13000,
        14000,
        15000,
        16000,
        16000,
        15000,
        10000,
        10000,
        17000,
        10000,
        12000,
        11000,
        10000,
        10000,
        12000,
        10000,
        10000,
        8000,
        8000,
        7000,
        10000,
        7000,
        7000,
        6000,
        7000
};

    string olehnama[40] = {
        // 1. Keripik dan Makanan Ringan
        "Keripik Sanjai Balado",
        "Keripik Sanjai Tawar",
        "Keripik Sanjai Asin",
        "Keripik Kentang Balado",
        "Keripik Ubi",
        "Keripik Pisang Coklat",
        "Karak Kaliang",
        "Kerupuk Jangek",

        // 2. Daging Olahan Kering
        "Rendang Kering",
        "Rendang Ayam",
        "Dendeng Balado",
        "Dendeng Batoko",
        "Paru Goreng Kering",
        "Gulai Kering Tunjang",
        "Gulai Kering Otak",
        "Gulai Kering Kepala Ikan",

        // 3. Kue Tradisional
        "Lamang Tapai",
        "Bika Padang",
        "Galamai",
        "Bareh Randang",
        "Kue Sapik",
        "Kue Pinyaram",
        "Kue Sagon",
        "Kue Kacimuih",

        // 4. Sambal
        "Sambal Ijo Botolan",
        "Sambalado Tanak",
        "Sambal Lado Mudo",

        // 5. Minuman & Oleh-oleh Unik
        "Teh Talua Instan",
        "Kopi Solok",
        "Kopi Minang Tradisional",
        "Sirup Pinang",
        "Minuman Asam Padeh Botolan",
        "Minuman Teh Daun Gambir",
        "Rendang Kemasan Kaleng",
        "Gulai Kepala Kakap Kemasan",
        "Kopi Kawa Daun",
        "Gulai Tunjang Kaleng",
        "Dendeng Batokok Kaleng",
        "Sambal Ikan Teri Kering"
    };

    int olehharga[40] = {
        // 1. Keripik dan Makanan Ringan
        25000, 
        23000, 
        23000, 
        25000, 
        20000, 
        22000, 
        18000, 
        19000,

        // 2. Daging Olahan Kering
        50000, 
        45000, 
        40000, 
        40000, 
        42000, 
        43000, 
        43000, 
        45000,

        // 3. Kue Tradisional
        30000, 
        25000, 
        28000, 
        27000, 
        22000, 
        22000, 
        20000, 
        21000,

        // 4. Sambal
        20000, 
        21000, 
        21000,

        // 5. Minuman & Oleh-oleh Unik
        40000, 
        35000, 
        38000,    
        30000, 
        32000, 
        31000,     
        60000, 
        55000, 
        35000, 
        50000, 
        48000, 
        27000
    };

    //di inisialusasi ke 0
    //untuk menyimpan jumlah pesanan
    int pesanan[100] = {0};
    int olehpesan[40] = {0};
    bool klaimBirthday = false;
    int biayaParkir = 0;
    string jenisKendaraan = "-";
    bool pesanPaket1 = false;
    bool pesanPaket2 = false;
    bool pesanPaket3 = false;
    bool pesanPaket4 = false;
    bool pesanPaket5 = false;

    //function dalam class ada void...
    void tampilkanMenu() {
        cout << "\n===== Daftar Menu Resto Padang ====\n";
        for (int i = 0; i < 100; i++) {
            cout << i + 1 << ". " << menu[i] << " - Rp" << harga[i] << endl;
        }
        cout << "===================================\n";
    }

    void pilihMenu() {
        int pilihan, jumlah;
        char ulang;
        do {
            cout << "\nPilih nomor menu : ";
            cin >> pilihan;
            if (pilihan >= 1 && pilihan <= 100) {
                //pilihan - 1 karena array dimulai dari 0, misal ayam pop array ke 1 - 1 menjadi index ke 0, maka yg akan dipanggil index ke 0
                cout << "Jumlah pesanan " << menu[pilihan - 1] << ": ";
                cin >> jumlah;
                if (jumlah > 0) {
                    pesanan[pilihan - 1] += jumlah;
                } else {
                    cout << "Jumlah tidak masuk akal!\n";
                }
            } else {
                cout << "Pilihan tidak valid.\n";
            }
            cout << "Tambah menu lain? (y/n): ";
            cin >> ulang;
        } while (ulang == 'y' || ulang == 'Y');
    }

    int hitungTotal() {
        //untuk pesanan menu
        int total = 0;
        for (int i = 0; i < 100; i++) {
            total += harga[i] * pesanan[i];
        }

        //untuk paket hemat
        if (pesanPaket1) {
            total += 215000;
        }
        if (pesanPaket2) {
            total += 115000;
        }
        if (pesanPaket3) {
            total += 450000;
        }
        if (pesanPaket4) {
            total += 370000;
        }
        if (pesanPaket5) {
            total += 57000;
        }
        
        //untuk oleh oleh
        for (int i = 0; i < 40; i++) {
            total += olehpesan[i] * olehharga[i];
        }

        return total;
    }

    void prosesPesanan(bool bayarSekarang) {
        int total = hitungTotal();
        int packing = 0;
        int ongkir = 0;
        int diskon = 0;
        int totalBayar = 0;
        float jarak;
        char takeAway, online;

        if (bayarSekarang) {
            cout << "\nApakah take away? (y/n): ";
            cin >> takeAway;
            if (takeAway == 'y' || takeAway == 'Y') {
                packing = 3000;
            }

            cout << "Apakah pesan online? (y/n): ";
            cin >> online;
            if (online == 'y' || online == 'Y') {
                cout << "Masukkan jarak rumah (km): ";
                cin >> jarak;
                if (jarak > 0) {
                    ongkir = jarak * 2000;
                } else {
                    cout << "Jarak tidak masuk akal!\n";
                }
            }
        }

        if (bayarSekarang){
            cout << "Apakah anda menggunakan kendaraan? (y/n): ";
            char ya;
            int pil;
            cin >> ya;
            if (ya == 'y' || ya == 'Y') {
                cout << "Jenis Kendaraan:\n";
                cout << "1. Sepeda (Rp1000)\n";
                cout << "2. Motor (Rp2000)\n";
                cout << "3. Mobil (Rp5000)\n";
                cout << "4. Bus (Rp20000)\n";
                cout << "Pilihan: ";
                cin >> pil;

                switch (pil) {
                    case 1:
                        biayaParkir = 1000;
                        jenisKendaraan = "Sepeda";
                        break;
                    case 2:
                        biayaParkir = 2000;
                        jenisKendaraan = "Motor";
                        break;
                    case 3:
                        biayaParkir = 5000;
                        jenisKendaraan = "Mobil";
                        break;
                    case 4:
                        biayaParkir = 20000;
                        jenisKendaraan = "Bus";
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                        biayaParkir = 0;
                        jenisKendaraan = "-";
                }
            }
        }

        if (total >= 500000) {
            diskon = total * 10 / 100;
        }

        totalBayar = total + biayaParkir + packing + ongkir - diskon;

        int jumlahItem = 0;
        for (int i = 0; i < 20; i++) {
            jumlahItem += pesanan[i];
        }
        int estimasiWaktu = jumlahItem * 5;

        int nmr;
        string metodeBayar;
        if (bayarSekarang) {
            cout << "\n==================================\n";
            cout << "\n=====Pilih metode pembayaran======\n";
            cout << "\n==================================\n";
            cout << "|1. Tunai\t\t\t|\n";
            cout << "|2. Transfer Bank\t\t|\n";
            cout << "|3. QRIS\t\t\t|\n";
            cout << "|Pilihan: ";
            int pil;
            cin >> pil;

            switch (pil) {
                case 1:
                    metodeBayar = "Tunai";
                    break;
                case 2:
                    metodeBayar = "Transfer Bank";
                    cout << "Masukan nomer rekening anda : ";
                    cin >> nmr;
                    break;
                case 3:
                    metodeBayar = "QRIS";
                    break;
                default:
                    metodeBayar = "Pilihan tidak valid";
            }
        }

        cout << "\n====== STRUK PEMBELIAN ======\n";
        for (int i = 0; i < 100; i++) {
            if (pesanan[i] > 0) {
                cout << menu[i] << " x" << pesanan[i] << " = Rp" << harga[i] * pesanan[i] << endl;
            }
        }
        if (pesanPaket1) {
            cout << "PAKET HEMAT 1\t= Rp215000\n";
        }
        if (pesanPaket2) {
            cout << "PAKET HEMAT 2\t= Rp115000\n";
        }
        if (pesanPaket3) {
            cout << "PAKET HEMAT 3\t= Rp450000\n";
        }
        if (pesanPaket4) {
            cout << "PAKET HEMAT 4\t= Rp370000\n";
        }
        if (pesanPaket5) {
            cout << "PAKET HEMAT 5\t= Rp57000\n";
        }
        
        bool adaOleh = false;
        for (int i = 0; i < 40; i++) {
            if (olehpesan[i] > 0) {
                cout << olehnama[i] << " x" << olehpesan[i] << " = Rp" << olehpesan[i] * olehharga[i] << endl;
                adaOleh = true;
            }
        }
    
        cout << "-------------------------------\n";
        cout << "Ongkir + packing: " << ongkir + packing << endl;
        cout << "Packing\t\t: Rp" << packing << endl;
        cout << "Subtotal\t: Rp" << total << endl;
        cout << "Diskon 10%\t: Rp" << diskon << endl;
        
        if (klaimBirthday) {
            cout << "Birthday Treat\t: 1x Ayam Pop Rp0\n";
        } else {
            cout << "Birthday Treat\t: -\n";
        }

        cout << "Biaya Parkir (" << jenisKendaraan << "): Rp" << biayaParkir << endl;

        if (bayarSekarang) {
            cout << "-------------------------------\n";
            cout << "Total Bayar\t: Rp" << totalBayar << endl;

            int bayar;
            cout << "Uang pembayaran\t: Rp";
            cin >> bayar;

            if (bayar >= totalBayar) {
                cout << "Kembalian\t: Rp" << bayar - totalBayar << endl;
            } else {
                cout << "Uang tidak cukup.\n";
            }

            cout << "Metode bayar\t: " << metodeBayar << endl;
            cout << "Estimasi\t: " << estimasiWaktu << " menit\n";
        }
    }


    void lihatPesanan() {
        cout << "\n=== Daftar Pesanan Anda ===\n";     
        bool ada = false;
        for (int i = 0; i < 100; i++) {
            if (pesanan[i] > 0) {
                cout << "- " << menu[i] << " x" << pesanan[i] << " = Rp" << harga[i] * pesanan[i] << endl;
                ada = true;
            }
        }
        if (!ada) {
            cout << "ANDA BELUM MEMESAN!!!.\n";
        }
    }

    void hapusPesanan() {
        int hapus;
        cout << "\n=== Hapus Pesanan ===\n";            
        bool adaPesanan = false;
        for (int i = 0; i < 100; i++) {
            if (pesanan[i] > 0) {
                cout << i + 1 << ". " << menu[i] << " x" << pesanan[i] << endl;
                adaPesanan = true;
            }
        }

        if (!adaPesanan) {
            cout << "Belum ada pesanan.\n";
            return;
        }

        cout << "Masukkan nomor menu yang ingin dihapus: ";         
        cin >> hapus;
        if (hapus >= 1 && hapus <= 100 && pesanan[hapus - 1] > 0) {
            pesanan[hapus - 1] = 0;
            cout << "Pesanan berhasil dihapus.\n";
        } else {
            cout << "Nomor tidak valid atau belum dipesan.\n";
        }
    }

    void rating() {
        int rate;
        string komen;
        cout << "\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout << "|===== BERIKAN RATING ^0^ =====|";   
        cout << "\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        cout << "Berapa bintang yang ingin Anda berikan? (1 - 5): ";
        cin >> rate;

        cin.ignore(); 
        cout << "Tulis komentar Anda: ";
        getline(cin, komen);

        cout << "\nTerima kasih atas penilaian Anda!\n";
        cout << "Rating: ";
        for (int i = 0; i < rate; i++){
            cout << "*";
        }
        cout << "\nKomentar: " << komen << "\n";
    }


    void tampilkanLirik(const string& lirik, int jeda) {
        cout << lirik << endl;
        Sleep(jeda); 
    }
    
    
    void birthday(){
        int tgl = 16;
        int bln = 6;
        int tgll;
        int blnn;
        string nm;
        int beat = 1300;
    
        cout << "\n===== CLAIM BIRTHDAY TREAT =====\n";
        cout << "    ***       **   **       ***    " << endl;
        cout << "   *   *     **** ****     *   *   " << endl;
        cout << "   *   *     *********     *   *   " << endl;
        cout << "   *   *      *******      *   *   " << endl;
        cout << "    ***        *****        ***    " << endl;
        cout << "     |          ***          |     " << endl;
        cout << "     |           *           |     " << endl;
        cout << "     |                       |    " << endl;
    
        cin.ignore();
        cout << "Tanggal saat ini : " << tgl << " - " << bln;
        cout << "\nMasukan Nama Anda : ";
        getline(cin, nm);
        cout << "Masukan tanggal lahir anda\t: ";
        cin >> tgll;
        cout << "Masukan bulan lahir anda\t: ";
        cin >> blnn;
    
        if(tgll == tgl && blnn == bln){
            klaimBirthday = true;
    
            cout << "=================================" << endl;
            cout << "\n\tHappy Birthday\n" << endl;
            cout << "=================================" << endl;
            tampilkanLirik("Happy birthday to you", beat);
            tampilkanLirik("Happy birthday to you", beat);
            tampilkanLirik("Happy birthday " +nm, beat);
            tampilkanLirik("Happy birthday to you!", beat);
    
            cout << endl << "Semoga hari Anda menyenangkan!" << endl;
            cout << endl;
            cout << "***********************************************" << endl;
            cout << "*                                             *" << endl;
            cout << "*               HAPPY BIRTHDAY                *" << endl;
            cout << "*                                             *" << endl;
            cout << "                " << nm << "                 " << endl;
            cout << "*                                             *" << endl;
            cout << "*       Semoga panjang umur dan sehat         *" << endl;
            cout << "*             Sukses selalu ya!               *" << endl;
            cout << "*                                             *" << endl;
            cout << "***********************************************" << endl;
            cout << endl;
    
            cout << "         i   i   i   i   i   i   i" << endl;
            cout << "        ***************************" << endl;
            cout << "       *  SILAHKAN CLAIM KE KASIR  *" << endl;
            cout << "       *     GRATIS 1 AYAM POP     *" << endl;
            cout << "        **************************" << endl;
            cout << "       |        |        |        |" << endl;
            cout << "       |        |        |        |" << endl;
            cout << "       |________|________|________|" << endl;
    
        }else{
            klaimBirthday = false;
            cout << "Claim birthday treat harus sesuai dengan tanggal dan bulan saat ini!!!";
        }
    }


    void reservasi() {
        string nama, tgl;
        string nomor;
        float jam;
        int jml, nml, nmr;
        string metodeBayar;

        cin.ignore();
        cout << "\n|==============================|\n";
        cout << "|======= RESERVASI MEJA =======|";
        cout << "\n|==============================|\n";
        cout << "Nama\t\t\t: ";
        getline(cin, nama);
        cout << "Nomor HP\t\t: ";
        getline(cin, nomor);
        cout << "Tanggal Pemesanan\t: ";
        getline(cin, tgl);
        cout << "Jam Pemesanan\t\t: ";
        cin >> jam;
        cout << "Jumlah orang\t\t: ";
        cin >> jml;

        tampilkanMenu();
        pilihMenu();
        lihatPesanan();
        cout << "Total Harga : " << hitungTotal() << endl;
        cout << "Pilih metode pembayaran:\n";
        cout << "1. Tunai\n";
        cout << "2. Transfer Bank\n";
        cout << "3. QRIS\n";
        cout << "Pilihan: ";
        int pil;
        cin >> pil;

        switch (pil) {
            case 1:
                metodeBayar = "Tunai";
                break;
            case 2:
                metodeBayar = "Transfer Bank";
                cout << "Masukan nomer rekening anda : ";
                cin >> nmr;
                break;
            case 3:
                metodeBayar = "QRIS";
                break;
            default:
                metodeBayar = "Pilihan tidak valid";
        }
        cout << "Metode pembayaran : " << metodeBayar << endl;
        cout << "Masukan Nominal : Rp";
        cin >> nml;

        cout << "\n|==============================|\n";
        cout << "|===== RESERVASI BERHASIL =====|";
        cout << "\n|==============================|\n";
        cout << "Nama\t\t: " << nama << endl;
        cout << "Nomor HP\t: " << nomor << endl;
        cout << "Tanggal\t\t: " << tgl << endl;
        cout << "Jam\t\t: " << jam << endl;
        cout << "Jumlah orang\t: " << jml << endl;
        lihatPesanan();
        cout << "Total Harga : " << hitungTotal() << endl;
        cout << "Metode : "<< metodeBayar << endl;
        cout << "Uang Pembayaran : Rp" << nml << endl;
        if(nml >= hitungTotal()){
            cout << "Kembalian : Rp" << nml - hitungTotal() << endl;
        }else {
            cout << "Uang Tidak Cukup!!!" << endl;
        }

    exit(0);

    }

    void paket(){
        int pilpaket; 

        cout << "\n   =============================\n";
        cout << "\n ======PAKET HEMAT KELUARGA=======\n";
        cout << "\n========= RESTORAN PADANG ==========\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n     Paket Hemat 1 (Rp 215000)       \n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "|1. Nasi Putih x5\t\t |\n";
        cout << "|2. Ayam GUlai x3\t\t |\n";
        cout << "|3. Telur Barendo x2\t\t |\n";
        cout << "|4. Ikan Nila Bakar x1\t\t |\n";
        cout << "|5. Sambal terasi x1\t\t |\n";
        cout << "|6. Sambal Bawang x1\t\t |\n";
        cout << "|7. Gulai tunjang x1\t\t |\n";
        cout << "\n_____________________________________\n";

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n     Paket Hemat 2 (Rp 115000)\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Nasi Putih x3\t\t |\n";
        cout << "2. Ayam bakar x1\t\t |\n";
        cout << "4. Udang goreng tepung x1\t |\n";
        cout << "5. Paru Goreng x1\t\t |\n";
        cout << "6. Sambal matah x1\t\t |\n";
        cout << "7. Sambal ijo x1\t\t |\n";
        cout << "\n_____________________________________\n";

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n     Paket Hemat 3 (Rp 450000)\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Nasi Putih x10\t\t |\n";
        cout << "2. Ayam Pop x4\t\t\t |\n";
        cout << "3. Telur Barendo x3\t\t |\n";
        cout << "4. Iga Bakar x1\t\t\t |\n";
        cout << "5. Rendang daging x2\t\t |\n";
        cout << "6. Udang tofu x1\t\t |\n";
        cout << "7. Gulai Tunjang x1\t\t |\n";
        cout << "8. Tumis Kangkung x2\t\t |\n";
        cout << "9. Sambal terasi x1\t\t |\n";
        cout << "10. Sambal matah x1\t\t |\n";
        cout << "11. Sambal ijo x1\t\t |\n";
        cout << "12. Sambal merah x1\t\t |\n";
        cout << "\n_____________________________________\n";

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n     Paket Hemat 4 (Rp 370000)\n";                                   
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Nasi Putih x5\t\t |\n";
        cout << "2. Dendeng Balado x2\t\t |\n";
        cout << "3. SOP Iga x2\t\t\t |\n";
        cout << "4. Gulai Kepala Kakap x1\t |\n";
        cout << "5. Perkedel x2\t\t\t |\n";
        cout << "6. Jengek x2\t\t\t |\n";
        cout << "7. Sayur Singkong x1\t\t |\n";
        cout << "8. Tumis Kangkung x1\t\t |\n";
        cout << "9. Sambal Udang x1\t\t |\n";
        cout << "10. Sambal Ati x1\t\t |\n";
        cout << "11. Sambal Merah x1\t\t |\n";
        cout << "\n_____________________________________\n";

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n     Paket Hemat 5 (Rp 57000)\n";                                    
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Nasi Putih x2\t\t |\n";
        cout << "2. Ikan Nila Bakar x1\t\t |\n";
        cout << "3. Ayam Gulai x1\t\t |\n";
        cout << "4. Tempe Goreng x1\t\t |\n";
        cout << "5. Sambal Ijo x1\t\t |\n";
        cout << "\n_____________________________________\n";

        cout << "Batal (0)\n";
        cout << "Pilihan Paket : ";
        cin >> pilpaket;

        switch(pilpaket){
            case 1:
                pesanPaket1 = true;
                cout << "Paket 1 berhasil dipesan.\n";
                break;
            case 2:
                pesanPaket2 = true;
                cout << "Paket 2 berhasil dipesan.\n";
                break;
            case 3:
                pesanPaket3 = true;
                cout << "Paket 3 berhasil dipesan.\n";
                break;
            case 4:
                pesanPaket4 = true;
                cout << "Paket 4 berhasil dipesan\n";
                break;
            case 5:
                pesanPaket5 = true;
                cout << "Paket 5 berhasil dipesan\n";
            case 0:
                cout << "Tidak jadi pesan paket.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                
            
        }
    }

    void oleh() {
        int kategori, pilih, jumlah;
        char lagi;
    
        do {
            cout << "\n|=======================================|\n";
            cout << "|========OLEH-OLEH KHAS MINANG =========|";    
            cout << "\n|=======================================|\n";
            cout << "|1. Keripik dan Makanan Ringan\t\t|\n";
            cout << "|2. Daging Olahan Kering\t\t|\n";
            cout << "|3. Kue Tradisional\t\t\t|\n";
            cout << "|4. Sambal\t\t\t\t|\n";
            cout << "|5. Minuman Tradisional & Oleh-oleh Unik|\n";
            cout << "|Pilih kategori (1-5): ";
            cin >> kategori;
    
            switch (kategori) {
                case 1:
                    cout << "\n-- Keripik dan Makanan Ringan --\n";
                    for (int i = 0; i < 8; i++) {
                        cout << i + 1 << ". " << olehnama[i] << " - Rp" << olehharga[i] << endl;
                    }
                    cout << "Pilih nomor oleh-oleh: ";
                    cin >> pilih;
                    if (pilih >= 1 && pilih <= 8) {
                        cout << "Jumlah: ";
                        cin >> jumlah;
                        olehpesan[pilih - 1] += jumlah;
                    }
                    break;
                case 2:
                    cout << "\n-- Daging Olahan Kering --\n";
                    for (int i = 8; i < 16; i++) {
                        cout << i - 7 << ". " << olehnama[i] << " - Rp" << olehharga[i] << endl;
                    }
                    cout << "Pilih nomor oleh-oleh: ";
                    cin >> pilih;
                    if (pilih >= 1 && pilih <= 8) {
                        cout << "Jumlah: ";
                        cin >> jumlah;
                        olehpesan[pilih - 1 + 8] += jumlah;
                    }
                    break;
                case 3:
                    cout << "\n-- Kue Tradisional --\n";
                    for (int i = 16; i < 24; i++) {
                        cout << i - 15 << ". " << olehnama[i] << " - Rp" << olehharga[i] << endl;
                    }
                    cout << "Pilih nomor oleh-oleh: ";
                    cin >> pilih;
                    if (pilih >= 1 && pilih <= 8) {
                        cout << "Jumlah: ";
                        cin >> jumlah;
                        olehpesan[pilih - 1 + 16] += jumlah;
                    }
                    break;
                case 4:
                    cout << "\n-- Sambal --\n";
                    for (int i = 24; i < 27; i++) {
                        cout << i - 23 << ". " << olehnama[i] << " - Rp" << olehharga[i] << endl;
                    }
                    cout << "Pilih nomor oleh-oleh: ";
                    cin >> pilih;
                    if (pilih >= 1 && pilih <= 3) {
                        cout << "Jumlah: ";
                        cin >> jumlah;
                        olehpesan[pilih - 1 + 24] += jumlah;
                    }
                    break;
                case 5:
                    cout << "\n-- Minuman Tradisional & Oleh-oleh Unik --\n";
                    for (int i = 27; i < 35; i++) {
                        cout << i - 26 << ". " << olehnama[i] << " - Rp" << olehharga[i] << endl;
                    }
                    cout << "Pilih nomor oleh-oleh: ";
                    cin >> pilih;
                    if (pilih >= 1 && pilih <= 8) {
                        cout << "Jumlah: ";
                        cin >> jumlah;
                        olehpesan[pilih - 1 + 27] += jumlah;
                    }
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
    
            cout << "Ingin menambah oleh-oleh lagi? (y/n): ";
            cin >> lagi;
        } while (lagi == 'y' || lagi == 'Y');
    }

    //Materi searching
    string toLower(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = tolower(str[i]);
        }
        return str;
    }

    void cariMenu() {           
        string kunci;
        bool ditemukan = false;
        cin.ignore();
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nMasukkan nama menu yang ingin dicari: "; 
        getline(cin, kunci);
    
        string kunciLower = toLower(kunci);
    
        cout << "\nHasil pencarian untuk \"" << kunci << "\":\n";
        for (int i = 0; i < 100; i++) {
            if (toLower(menu[i]).find(kunciLower) != string::npos) {
                cout << i + 1 << ". " << menu[i] << " - Rp" << harga[i] << endl;
                ditemukan = true;
            }
        }
    
        if (!ditemukan) {
            cout << "Menu tidak ditemukan.\n";
        }
    }


    //Materi sorting
    void urutkanMenuNama() {                 
        for (int i = 0; i < 99; i++) {
            for (int j = i + 1; j < 100; j++) {
                if (menu[i] > menu[j]) {
                    swap(menu[i], menu[j]);
                    swap(harga[i], harga[j]);
                }
            }
        }
        cout << "\n===================================================\n";
        cout << "Menu berhasil diurutkan berdasarkan nama (A-Z):";
        tampilkanMenu();
    }
    void urutkanMenuHarga() {                 
        for (int i = 0; i < 99; i++) {
            for (int j = i + 1; j < 100; j++) {
                if (harga[i] > harga[j]) {
                    swap(menu[i], menu[j]);
                    swap(harga[i], harga[j]);
                }
            }
        }
        cout << "\n===================================================\n";
        cout << "\nMenu berhasil diurutkan berdasarkan harga termurah:\n";
        tampilkanMenu();
    }

};

int main() {
	Pegawai dataPegawai;
    RestoPadang resto;
    loginSistem login;
    int pilihan;
	int pilihPegawai;
	int role = login.menuLogin();
	
	if (role == 1) {
	    if (!login.loginPegawai()) {
	        return 0; 
	    }
	} else if (role == 2) {
	    login.loginCustomer();
	} else {
	    cout << "Pilihan tidak valid.\n";
	    return 0;
	}


	cout << "\n=== MENU PEGAWAI ===\n";
	cout << "1. Cari Pegawai Berdasarkan Nama\n";
	cout << "2. Cari Pegawai Berdasarkan NIP\n";
	cout << "3. Cari Pegawai Berdasarkan Jabatan\n";
	cout << "Pilihan: ";
	cin >> pilihPegawai;
	
	switch (pilihPegawai) {
	    case 1: 
			dataPegawai.cariByNama(); 
			break;
	    case 2: 
			dataPegawai.cariByNIP(); 
			break;
	    case 3: 
			dataPegawai.cariByJabatan(); 
			break;
	    default: 
			cout << "Pilihan tidak valid.\n";
	}

    do {
        cout << "\n   =============================\n";
        cout << "\n ======== RESTORAN PADANG ========\n";
        cout << "\n===================================\n";
        cout << " |1. Lihat Menu\t\t\t |\n";
        cout << " |2. Pilih Menu\t\t\t |\n";
        cout << " |3. Lihat Pesanan\t\t |\n";
        cout << " |4. Hapus Pesanan\t\t |\n";
        cout << " |5. Reservasi Meja\t\t |\n";
        cout << " |6. Pesan Menu Paket\t\t |\n";
        cout << " |7. Oleh - oleh khas Minang\t |\n";
        cout << " |8. Cari Menu\t\t\t |\n";
        cout << " |9. Urutan Menu (Nama/Harga)\t |\n";
        cout << " |10. Claim Birthday Treat\t |\n";
        cout << " |11. Selesai dan Bayar\t\t |\n";
        cout << " |12. Keluar\t\t\t |\n";
        cout << " |Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                resto.tampilkanMenu();
                system("pause"); 
                system("cls");
                break;
            case 2:
                resto.pilihMenu();
                system("pause"); 
                system("cls");
                break;
            case 3:
                resto.lihatPesanan();
                system("pause"); 
                system("cls");
                break;
            case 4:
                resto.hapusPesanan();
                system("pause"); 
                system("cls");
                break;
            case 5:
                resto.reservasi();
                system("pause"); 
                system("cls");
                break;
            case 6:
                resto.paket();
                system("pause"); 
                system("cls");
                break;
            case 7:
                resto.oleh();
                system("pause"); 
                system("cls");
                break;
            case 8:
                resto.cariMenu();//searching
                system("pause"); 
                system("cls");
                break;
            case 9:
                int metodeSort;//sorting
                cout << "\nUrutkan berdasarkan:\n";
                cout << "1. Nama (A-Z)\n";
                cout << "2. Harga (Termurah - Termahal)\n";
                cout << "Pilihan: ";
                cin >> metodeSort;
                if (metodeSort == 1) {
                    resto.urutkanMenuNama();
                } else if (metodeSort == 2) {
                    resto.urutkanMenuHarga();
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
                system("pause"); 
                system("cls");
                break;
            case 10:
                resto.birthday();
                system("pause"); 
                system("cls");
                break;
            case 11:
                resto.prosesPesanan(true); 
                system("pause"); 
                system("cls");
                break;
            case 12:
                if (resto.hitungTotal() > 0) {
                    cout << "\nSebelum keluar, berikut struk pesanan Anda:\n";
                    resto.prosesPesanan(false);
                    char rtg;
                    cout << "Apakah ingin memberi rating ^0^? (y/n) : ";                
                    cin >> rtg;
                    if (rtg == 'y' || rtg == 'Y'){
                        resto.rating();
                    }
                } else {
                    cout << "Tidak ada pesanan yang perlu dibayar.\n";
                }
                cout << "\n|-----------------------------------|\n";
                cout << "|   Terima kasih telah berkunjung!  |";
                cout << "\n|___________________________________|\n";
                system("pause"); 
                system("cls");

                cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                        S E L A M A T     M E N I K M A T I                                         |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                      T E R I M A     K A S I H     A T A S     K U N J U N G A N     A N D A                       |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                  S E M O G A     A N D A     P U A S     D E N G A N     L A Y A N A N     K A M I                 |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                            R E S T O     P A D A N G     D A N     O L E H - O L E H                               |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                             K H A S     M I N A N G                                                |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                                                                                                    |\n";
                cout << "|                                                                                                                    |\n";
                cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 12);

    return 0;
}
