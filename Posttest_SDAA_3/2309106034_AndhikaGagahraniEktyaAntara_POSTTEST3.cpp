#include <iostream>
using namespace std;

struct Kontak {
    string name;
    string phone;
    string instagram;
    string facebook;
    string twitter;
    Kontak* next;  
};


void tambahKontak(Kontak* &head);

void tampilkanKontak(Kontak* head);

void perbaruiKontak(Kontak* head);

void hapusKontak(Kontak* &head);

void bersihkanMemori(Kontak* &head);

string masukkanData(const string &teks);

Kontak* cariKontak(Kontak* head, int indeks);

int hitungKontak(Kontak* head);

int main() {
    Kontak* head = nullptr;  
    int pilihan;

    do {
        cout << "\n==============================\n";
        cout << "=== Manajemen Nomor Kontak ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Update Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        cin.ignore();  

        switch (pilihan) {
            case 1:
                tambahKontak(head);
                break;
            case 2:
                tampilkanKontak(head);
                break;
            case 3:
                perbaruiKontak(head);
                break;
            case 4:
                hapusKontak(head);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    bersihkanMemori(head);  
    return 0;
}

void tambahKontak(Kontak* &head) {
    Kontak* kontakBaru = new Kontak;  
    cout << "Masukkan nomor telepon: ";
    getline(cin, kontakBaru->phone);
    kontakBaru->name = masukkanData("Masukkan nama: ");
    kontakBaru->instagram = masukkanData("Masukkan Instagram (opsional): ");
    kontakBaru->facebook = masukkanData("Masukkan Facebook (opsional): ");
    kontakBaru->twitter = masukkanData("Masukkan Twitter (opsional): ");
    kontakBaru->next = nullptr;

    
    if (head == nullptr) {
        head = kontakBaru;
    } else {
        
        Kontak* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = kontakBaru;
    }

    cout << "\n=== Kontak berhasil ditambahkan ===\n";
}

void tampilkanKontak(Kontak* head) {
    if (head == nullptr) {
        cout << "\n=== Tidak ada kontak yang tersedia ===\n";
        return;
    }

    Kontak* temp = head;
    int nomor = 1;
    cout << "\nDaftar Kontak:\n";
    while (temp != nullptr) {
        cout << nomor << ". Nama: " << temp->name
             << ", Telepon: " << temp->phone
             << ", Instagram: " << (temp->instagram.empty() ? "N/A" : temp->instagram)
             << ", Facebook: " << (temp->facebook.empty() ? "N/A" : temp->facebook)
             << ", Twitter: " << (temp->twitter.empty() ? "N/A" : temp->twitter) << endl;
        temp = temp->next;
        nomor++;
    }
}

void perbaruiKontak(Kontak* head) {
    int indeks;
    cout << "Masukkan nomor kontak: ";
    cin >> indeks;
    cin.ignore();  

    Kontak* kontakDiperbarui = cariKontak(head, indeks);
    if (kontakDiperbarui != nullptr) {
        cout << "Nomor: " << kontakDiperbarui->phone << "\n";
        kontakDiperbarui->name = masukkanData("Masukkan nama baru: ");
        kontakDiperbarui->instagram = masukkanData("Masukkan Instagram baru (opsional): ");
        kontakDiperbarui->facebook = masukkanData("Masukkan Facebook baru (opsional): ");
        kontakDiperbarui->twitter = masukkanData("Masukkan Twitter baru (opsional): ");
        cout << "\n=== Kontak berhasil diupdate ===\n";
    } else {
        cout << "\n=== Kontak tidak ditemukan ===\n";
    }
}

void hapusKontak(Kontak* &head) {
    int indeks;
    cout << "Masukkan nomor kontak: ";
    cin >> indeks;
    cin.ignore();  

    if (head == nullptr) {
        cout << "\n=== Tidak ada kontak yang tersedia ===\n";
        return;
    }

    
    if (indeks == 1) {
        Kontak* temp = head;
        head = head->next;
        delete temp;
        cout << "\n=== Kontak berhasil dihapus ===\n";
        return;
    }

    
    Kontak* prev = head;
    Kontak* curr = head->next;
    for (int i = 2; i < indeks && curr != nullptr; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr) {
        prev->next = curr->next;
        delete curr;
        cout << "\n=== Kontak berhasil dihapus ===\n";
    } else {
        cout << "\n=== Kontak tidak ditemukan ===\n";
    }
}

void bersihkanMemori(Kontak* &head) {
    Kontak* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

string masukkanData(const string &teks) {
    string input;
    cout << teks;
    getline(cin, input);
    return input;
}

Kontak* cariKontak(Kontak* head, int indeks) {
    Kontak* temp = head;
    for (int i = 1; i < indeks && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

int hitungKontak(Kontak* head) {
    int count = 0;
    Kontak* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
