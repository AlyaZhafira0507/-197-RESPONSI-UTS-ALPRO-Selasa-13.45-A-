#include <iostream>
#include <cstdlib>
using namespace std;

//struktur
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

	//di inisialusasi ke 0
	//untuk menyimpan jumlah pesanan
    int pesanan[100] = {0};
    bool klaimBirthday = false;
    int biayaParkir = 0;
    string jenisKendaraan = "-";

	
	//function dalam class ada void...
    void tampilkanMenu() {
        cout << "\n=== Daftar Menu Resto Padang ===\n";
        for (int i = 0; i < 100; i++) {
            cout << i + 1 << ". " << menu[i] << " - Rp" << harga[i] << endl;
        }
        cout << "==================================\n";
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
        int total = 0;
        for (int i = 0; i < 100; i++) {
            total += harga[i] * pesanan[i];
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

        if (total >= 200000) {
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
            cout << "\nPilih metode pembayaran:\n";
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
        }

        cout << "\n===== STRUK PEMBELIAN =====\n";
        for (int i = 0; i < 100; i++) {
            if (pesanan[i] > 0) {
                cout << menu[i] << " x" << pesanan[i] << " = Rp" << harga[i] * pesanan[i] << endl;
            }
        }
        cout << "-------------------------------\n";
        cout << "Ongkir + packing: " << ongkir + packing << endl;
        cout << "Packing\t\t: Rp" << packing << endl;
        cout << "Subtotal\t: Rp" << total << endl;
        cout << "Diskon\t\t: Rp" << diskon << endl;
        
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
	    cout << "\n=== BERIKAN RATING ===\n";
	    cout << "Berapa bintang yang ingin Anda berikan? (1–5): ";
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
	

	void birthday(){
		int tgl = 14;
		int bln = 6;
		int tgll;
		int blnn;
		string nm;
		
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
		    cout << "***********************************************" << endl;
		    cout << "*                                             *" << endl;
		    cout << "*                HAPPY BIRTHDAY               *" << endl;
		    cout << "*                                             *" << endl;
		    cout << "*                " << nm << "                 *" << endl;
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
	    cout << "\n===== RESERVASI MEJA =====\n";
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
		
	    cout << "\n=== RESERVASI BERHASIL ===\n";
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

};

int main() {
    RestoPadang resto;
    int pilihan;

    do {
         cout << "\n   =============================\n";
        cout << "\n ======== RESTORAN PADANG ========\n";
        cout << "\n===================================\n";
        cout << " |1. Lihat Menu\t\t\t |\n";
        cout << " |2. Pilih Menu\t\t\t |\n";
        cout << " |3. Lihat Pesanan\t\t |\n";
        cout << " |4. Hapus Pesanan\t\t |\n";
        cout << " |5. Reservasi Meja\t\t |\n";
        cout << " |6. Selesai dan Bayar\t\t |\n";
        cout << " |7. Claim Birthday Treat\t |\n";
        cout << " |8. Keluar\t\t\t |\n";
        cout << " |Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                resto.tampilkanMenu();
                break;
            case 2:
                resto.pilihMenu();
                break;
            case 3:
                resto.lihatPesanan();
                break;
            case 4:
                resto.hapusPesanan();
                break;
            case 5:
				resto.reservasi();
            	break;
            case 6:
                resto.prosesPesanan(true); 
                break;
            case 7:
            	resto.birthday();
            	break;
            case 8:
                if (resto.hitungTotal() > 0) {
                    cout << "\nSebelum keluar, berikut struk pesanan Anda:\n";
                    resto.prosesPesanan(false);
                    char rtg;
                    cout << "Apakah ingin memberi rating? (y/n) : ";
                    cin >> rtg;
                    if (rtg == 'y' || rtg == 'Y'){
                    	resto.rating();
					}
                } else {
                    cout << "Tidak ada pesanan yang perlu dibayar.\n";
                }
                cout << "Terima kasih telah berkunjung!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
	
    } while (pilihan != 8);

    return 0;
}
