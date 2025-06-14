#include <iostream>
using namespace std;

//struktur
class RestoPadang {
public:
	//deklarasi atribut array, isi elemen array 20
    string menu[20] = {
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
        
};
    int harga[20] = {
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
        
};
	//di inisialusasi ke 0
	//untuk menyimpan jumlah pesanan
    int pesanan[20] = {0};
	
	//function dalam class ada void...
    void tampilkanMenu() {
        cout << "\n=== Daftar Menu Resto Padang ===\n";
        for (int i = 0; i < 20; i++) {
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
            if (pilihan >= 1 && pilihan <= 20) {
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
        for (int i = 0; i < 20; i++) {
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

        if (total >= 200000) {
            diskon = total * 10 / 100;
        }

        totalBayar = total + packing + ongkir - diskon;
        
        int jumlahItem = 0;
    	for (int i = 0; i < 20; i++) {
        	jumlahItem += pesanan[i];
    	}
    	int estimasiWaktu = jumlahItem * 5;
		
		string metodeBayar;
		if (bayarSekarang) {
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
	                break;
	            case 3:
	                metodeBayar = "QRIS";
	                break;
	            default:
	                metodeBayar = "Pilihan tidak valid";
	        }
		}
		
        cout << "\n===== STRUK PEMBELIAN =====\n";
        for (int i = 0; i < 20; i++) {
            if (pesanan[i] > 0) {
                cout << menu[i] << " x" << pesanan[i]
                     << " = Rp" << harga[i] * pesanan[i] << endl;
            }
        }
        cout << "-------------------------------\n";
        cout << "Subtotal\t: Rp" << total << endl;
        cout << "Diskon\t\t: Rp" << diskon << endl;

        if (bayarSekarang) {
            cout << "Packing\t\t: Rp" << packing << endl;
            cout << "Ongkir + packing: Rp" << ongkir << endl;
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

        cout << "===============================\n";
    }

    void lihatPesanan() {
        cout << "\n=== Daftar Pesanan Anda ===\n";
        bool ada = false;
        for (int i = 0; i < 20; i++) {
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
        for (int i = 0; i < 20; i++) {
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
        if (hapus >= 1 && hapus <= 20 && pesanan[hapus - 1] > 0) {
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
		
		cout << "\n=== CLAIM BIRTHDAY TREAT ===\n";
		cout << "Tanggal saat ini : " << tgl << " - " << bln;
		cout << "\nMasukan tanggal lahir anda\t: ";
		cin >> tgll;
		cout << "Masukan bulan lahir anda\t: ";
		cin >> blnn;
		
		if(tgll == tgl && blnn == bln){
			cout << "----- HAPPY BIRTHDAY -----\n";
			cout << "Selamat Gratis 1 Ayam Pop\n";
			cout << "---------------------------\n";
			
		}else{
			cout << "Claim birthday treat harus sesuai dengan tanggal dan bulan saat ini!!!";
		}
	}
};

int main() {
    RestoPadang resto;
    int pilihan;

    do {
        cout << "\n==== RESTORAN PADANG ====\n";
        cout << "1. Lihat Menu\n";
        cout << "2. Pilih Menu\n";
        cout << "3. Lihat Pesanan\n";
        cout << "4. Hapus Pesanan\n";
        cout << "5. Selesai dan Bayar\n";
        cout << "6. Claim Birthday Treat\n";
        cout << "7. Keluar\n";
        cout << "Pilihan : ";
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
                resto.prosesPesanan(true); 
                break;
            case 6:
            	resto.birthday();
            	break;
            case 7:
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
	
    } while (pilihan != 7);

    return 0;
}
