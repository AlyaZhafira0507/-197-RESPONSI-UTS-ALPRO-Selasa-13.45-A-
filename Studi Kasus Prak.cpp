#include<iostream>
using namespace std;

int main() {
    int HargaAymG = 17000;
    int HargaAymB = 21000;
    float diskon = 0.10;
    int maxdiskn = 45000;
    int jumlahGoreng, jumlahBakar;
    int totalGoreng, totalBakar, total;
    float totalSetelahDiskon;

    cout<<"=== KEDAI MAKAN AYAM ==="<<endl;
    cout<<"Jumlah ayam goreng (Rp17.000) : ";
    cin>>jumlahGoreng;
    cout<<"Jumlah ayam bakar (Rp21.000) : ";
    cin>>jumlahBakar;

    totalGoreng = jumlahGoreng * HargaAymG;
    totalBakar = jumlahBakar * HargaAymB;
    total = totalGoreng + totalBakar;
    
	cout<<endl;
    cout<<"=== NOTA PEMBAYARAN ===" << endl;
    cout<<"Ayam Goreng x"<<jumlahGoreng<<" = Rp"<<totalGoreng<<endl;
    cout<<"Ayam Bakar x"<<jumlahBakar<<" = Rp"<<totalBakar<<endl;
    cout<<"Total Sebelum Diskon = Rp"<<total<<endl;

    if (total > maxdiskn) {
        float potongan = total * diskon;
        totalSetelahDiskon = total - potongan;
        cout<<"Diskon 10% (Rp"<<potongan<<") = Rp"<<totalSetelahDiskon<<endl;
    } else {
        cout<<"Total Pembayaran            = Rp"<<total<<endl;
    }
	cout<<"TERIMA KASIH"<<endl;
}
