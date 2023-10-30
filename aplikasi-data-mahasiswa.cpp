#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// function here!
// validate only digits for nim
bool is_nim_valid(const string &nim) {
    for (char c : nim) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// validae only digits for phone number
bool is_phone_valid(const string &no_telp) {
    for (char c : no_telp) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// main code here!
int main() {
    // variabel here!
    string nama_lengkap, nim, fakultas, program_studi, kota_asal, no_telp;

    // app title
    cout << "#       DATA MAHASISWA       #" << endl;
    cout << "==============================" << endl;

    while (true) {
        // request input from user.
        cout << "Masukkan data berikut: " << endl;
        cout << "1. Nama Lengkap   : ";
        getline(cin, nama_lengkap);

        // input user nim
        while (true) {
            cout << "2. NIM            : ";
            getline(cin, nim);
            if (is_nim_valid(nim)) {
                break;
            } else {
                cout << "NIM yang dimasukkan tidak valid. Pastikan NIM hanya berisi angka." << endl;
            }
        }

        cout << "3. Fakultas       : ";
        getline(cin, fakultas);
        cout << "4. Program Studi  : ";
        getline(cin, program_studi);
        cout << "5. Kota Asal      : ";
        getline(cin, kota_asal);

        while (true) {
            cout << "6. No Telp        : ";
            getline(cin, no_telp);
            if (is_phone_valid(no_telp)) {
                break;
            } else {
                cout << "Nomor Telepon yang dimasukkan tidak valid. Pastikan nomor telepon hanya berisi angka." << endl;
            }
        }

        // show their inputted data
        cout << " " << endl;
        cout << "Data berhasil dimasukkan! " << endl;
        cout << "Berikut data yang telah anda masukkan: " << endl;
        cout << "Data Mahasiswa: " << endl;
        cout << "1. Nama           : " << nama_lengkap << endl;
        cout << "2. NIM            : " << nim << endl;
        cout << "3. Fakultas       : " << fakultas << endl;
        cout << "4. Program Studi  : " << program_studi << endl;
        cout << "5. Kota Asal      : " << kota_asal << endl;
        cout << "6. Nomor Telepon  : " << no_telp << endl;

        cout << "Apakah Anda ingin mengupdate data (Y/N)? " << endl;
        string konfirmasi;
        cin >> konfirmasi;

        if (konfirmasi == "N" || konfirmasi == "n") {
            break;
        }
    }

    return 0;
}
