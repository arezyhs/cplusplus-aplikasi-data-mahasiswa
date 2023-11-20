#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

/*
    Created by Akbar Setiyawan
    arezyh.s
*/

struct mahasiswa {
    string namaLengkap;
    string nim;
    string fakultas;
    string programStudi;
    string kotaAsal;
    string noTelp;
};

bool isNumber(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// main code here!
int main() {
    const int jumlahDataMahasiswa = 100;

    // app title
    cout << "#       DATA MAHASISWA       #" << endl;
    cout << "==============================" << endl;

    mahasiswa dataMahasiswa[jumlahDataMahasiswa];
    char lanjut;
    int i = 0;

    do {
        system("cls");
        cout << "Input data mahasiswa ke-" << i + 1 << ":" << endl;

        cout << "1. Nama lengkap    : ";
        getline(cin, dataMahasiswa[i].namaLengkap);
        
        // NIM validation
        do {
            cout << "2. NIM             : ";
            getline(cin, dataMahasiswa[i].nim);
            if (!isNumber(dataMahasiswa[i].nim)) {
                cout << "NIM harus berupa angka. Silakan masukkan kembali." << endl;
            }
        } while (!isNumber(dataMahasiswa[i].nim));

        cout << "3. Fakultas        : ";
        getline(cin, dataMahasiswa[i].fakultas);
        cout << "4. Program Studi   : ";
        getline(cin, dataMahasiswa[i].programStudi);
        cout << "5. Kota Asal       : ";
        getline(cin, dataMahasiswa[i].kotaAsal);
        
        // Nomor Telepon (noTelp) validation
        do {
            cout << "6. Nomor Telepon   : ";
            getline(cin, dataMahasiswa[i].noTelp);
            if (!isNumber(dataMahasiswa[i].noTelp)) {
                cout << "Nomor Telepon harus berupa angka. Silakan masukkan kembali." << endl;
            }
        } while (!isNumber(dataMahasiswa[i].noTelp));

        cout << "Lanjut memasukkan data mahasiswa (Y/N): ";
        cin >> lanjut;
        cin.ignore();

        i++;
    } while ((lanjut == 'Y' || lanjut == 'y') && i < jumlahDataMahasiswa);

    ofstream file("DATA_MAHASISWA.txt");
    if (file.is_open()) {
        file << "***** DATA MAHASISWA *****" << endl;
        for (int j = 0; j < i; ++j) {
            file << "Data Mahasiswa ke-" << j + 1 << ":" << endl;
            file << "1. Nama Lengkap   : " << dataMahasiswa[j].namaLengkap << endl;
            file << "2. NIM            : " << dataMahasiswa[j].nim << endl;
            file << "3. Fakultas       : " << dataMahasiswa[j].fakultas << endl;
            file << "4. Program Studi  : " << dataMahasiswa[j].programStudi << endl;
            file << "5. Kota Asal      : " << dataMahasiswa[j].kotaAsal << endl;
            file << "6. Nomor Telepon  : " << dataMahasiswa[j].noTelp << endl;
            file << endl;
        }
        file.close();
        system("cls");
        cout << "Berhasil disimpan ke dalam file DATA_MAHASISWA.txt" << endl;
    } else {
        cout << "Gagal membuka file untuk penulisan." << endl;
    }
    return 0;
}
