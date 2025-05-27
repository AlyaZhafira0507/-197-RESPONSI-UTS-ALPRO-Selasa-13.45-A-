#include<iostream>
#include<sstream>
using namespace std;

int main(){
	string usr;
	int pas;
	string kap, lok, fas, matkul, dos, wkt, ruang;
	char ganti;
	string usrMhs;
	int pasMhs;
	int tmpl;
	stringstream tampil;
	char ulang;
	
	cout<<endl;
	
	cout<<"===== LOGIN ADMIN SISTEM INFORMASI RUANGAN =====\n";
	cout<<"Username (admin) : ";
	cin>>usr;
	cout<<"Password (1994): ";
	cin>>pas;
	cout<<endl;
	do{
			cout<<"Informasi Ruang Kelas\n";
			cout<<"Kapasitas : ";
			cin>>kap;
			cout<<"Lokasi : ";
			cin>>lok;
			cout<<"Fasilitas : ";
			cin>>fas;
		
			cout<<endl;
		
			cout<<"Jadwal Matakuliah\n";
			cout<<"Mata kuliah : ";
			cin>>matkul;
			cout<<"Dosen : ";
			cin>>dos;
			cout<<"Waktu : ";
			cin>>wkt;
			cout<<"Kebutuhan Ruangan : ";
			cin>>ruang;
		
		cout<<endl;
		
		cout<<"Ingin Mengganti Data (y/n) : ";
		cin>>ganti;
		cout<<endl;
		
	}while(ganti == 'y' || ganti == 'Y');{
		cout<<"-----INFORMASI RUANG KELAS-----\n";
		cout<<"Kapasitas Ruangan : "<<kap<<endl;
		cout<<"Lokasi Ruangan : "<<lok<<endl;
		cout<<"Fasilitas Ruangan : "<<fas<<endl;
		
		cout<<endl;
		
		cout<<"-----JADWAL MATA KULIAH-----\n";
		cout<<"Mata Kuliah : "<<matkul<<endl;
		cout<<"Nama Dosen : "<<dos<<endl;
		cout<<"Waktu Mengajar : "<<wkt<<endl;
		cout<<"Kebutuhan Ruangan : "<<ruang<<endl;
		
	}

	cout<<endl;
	cout<<endl;
	
	cout<<"===== LOGIN MAHASISWA ====="<<endl;
	cout<<"Username (mhs): ";
	cin>>usrMhs;
	cout<<"Password (1994): ";
	cin>>pasMhs;
	cout<<endl;
	
	do{
		cout<<"SISTEM INFORMASI MANAJEMEN RUANGAN"<<endl;
		cout<<"1. Informasi Ruang Kelas \n";
		cout<<"2. Jadwak Matakuliah \n";
		cout<<"Pilih yang ingin di tampilkan : ";
		cin>>tmpl;
		
		switch(tmpl){
			case 1:
				tampil<<endl;
				tampil<<"------INFORMASI RUANG KELAS------\n";
				tampil<<"Kapasitas Ruangan : "<<kap<<endl;
				tampil<<"Lokasi Ruangan : "<<lok<<endl;
				tampil<<"Fasilitas Ruangan : "<<fas<<endl;
				tampil<<"----------------------------------\n";
				tampil<<endl;
				break;
			case 2:
				tampil<<endl;
				tampil<<"-------JADWAL MATA KULIAH-------\n";
				tampil<<"Mata Kuliah : "<<matkul<<endl;
				tampil<<"Nama Dosen : "<<dos<<endl;
				tampil<<"Waktu Mengajar : "<<wkt<<endl;
				tampil<<"Kebutuhan Ruangan : "<<ruang<<endl;
				tampil<<"----------------------------------\n";
				tampil<<endl;
				break;
			default:
				cout<<"Pilihan tidak valid !!!"<<endl;
		}
		cout<<endl;
		
		cout<<tampil.str();
		cout<<"Ingin tampilkan lagi? (y/n) : ";
		cin>>ulang;
		cout<<endl;
	}while(ulang == 'y' || ulang == 'Y');{
		cout<<tampil.str();
	}
}
