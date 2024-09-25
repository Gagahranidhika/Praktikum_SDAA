#include <iostream>
using namespace std;

struct Kontak {
    string name;
    string phone;
    string instagram;
    string facebook;
    string twitter;
};

void addKontak(Kontak **isikontak, int &count);
void showKontak(Kontak *isikontak, int count);
void updateKontak(Kontak *isikontak, int count);
void deleteKontak(Kontak **isikontak, int &count);
void bersihkanMemory(Kontak **isikontak, int count);
string Input(const string &isi);
int carIndex(int count);

int main() {
    Kontak *isikontak = nullptr;
    int count = 0;
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "=== Manajemen Nomor Kontak ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Update Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                addKontak(&isikontak, count);
                break;
            case 2:
                showKontak(isikontak, count);
                break;
            case 3:
                updateKontak(isikontak, count);
                break;
            case 4:
                deleteKontak(&isikontak, count);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

    bersihkanMemory(&isikontak, count);
    return 0;
}

void addKontak(Kontak **isikontak, int &count) {
    Kontak *newisikontak = new Kontak[count + 1];
    for (int i = 0; i < count; i++) {
        newisikontak[i] = (*isikontak)[i];
    }

    cout << "Masukkan nomor telepon: ";
    getline(cin, newisikontak[count].phone);
    newisikontak[count].name = Input("Masukkan nama: ");

    newisikontak[count].instagram = Input("Masukkan Instagram (opsional): ");
    newisikontak[count].facebook = Input("Masukkan Facebook (opsional): ");
    newisikontak[count].twitter = Input("Masukkan Twitter (opsional): ");

    delete[] *isikontak;
    *isikontak = newisikontak; 
    count++;
    cout << "\n=== Kontak berhasil ditambahkan ===\n";
}

void showKontak(Kontak *isikontak, int count) {
    if (count == 0) {
        cout << "\n=== Tidak ada kontak yang tersedia ===\n";
        return;
    }

    cout << "\nDaftar Kontak:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". Nama: " << isikontak[i].name 
             << ", Telepon: " << isikontak[i].phone
             << ", Instagram: " << (isikontak[i].instagram.empty() ? "N/A" : isikontak[i].instagram)
             << ", Facebook: " << (isikontak[i].facebook.empty() ? "N/A" : isikontak[i].facebook)
             << ", Twitter: " << (isikontak[i].twitter.empty() ? "N/A" : isikontak[i].twitter) << endl;
    }
}

void updateKontak(Kontak *isikontak, int count) {
    int index = carIndex(count);
    if (index == -1) return;
    cout<<"Nomor: "<<isikontak[index - 1].phone<<"\n";
    isikontak[index - 1].name = Input("Masukkan nama baru: ");
    isikontak[index - 1].instagram = Input("Masukkan Instagram baru (opsional): ");
    isikontak[index - 1].facebook = Input("Masukkan Facebook baru (opsional): ");
    isikontak[index - 1].twitter = Input("Masukkan Twitter baru (opsional): ");
    cout << "\n=== Kontak berhasil diupdate ===\n";
}

void deleteKontak(Kontak **isikontak, int &count) {
    int index = carIndex(count);
    if (index == -1) return;

    Kontak *newisikontak = new Kontak[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index - 1) {
            newisikontak[j++] = (*isikontak)[i];
        }
    }

    delete[] *isikontak;
    *isikontak = newisikontak;
    count--;
    cout << "\n=== Kontak berhasil dihapus ===\n";
}

void bersihkanMemory(Kontak **isikontak, int count) {
    delete[] *isikontak; 
    *isikontak = nullptr; 
}

string Input(const string &isi) {
    string input;
    cout << isi;
    getline(cin, input); 
    return input;
}

int carIndex(int count) {
    int index;
    cout << "Masukkan nomor kontak: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "\n=== Kontak tidak ditemukan ===\n";
        return -1; 
    }
    return index;
}
