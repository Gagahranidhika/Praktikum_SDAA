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
void sortingMenu(Kontak* &head);


void push(Kontak* &head);
void pop(Kontak* &head);
void enqueue(Kontak* &head);
void dequeue(Kontak* &head);

Kontak* getTail(Kontak* head);
Kontak* partition(Kontak* head, Kontak* end, Kontak** newHead, Kontak** newEnd);
Kontak* quickSortRecur(Kontak* head, Kontak* end);
void quickSort(Kontak** headRef);

Kontak* split(Kontak* head);
Kontak* mergeDescending(Kontak* first, Kontak* second);
Kontak* mergeSortDescending(Kontak* head);

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
        cout << "5. Push  \n";
        cout << "6. Pop \n";
        cout << "7. Enqueue \n";
        cout << "8. Dequeue \n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        cin.ignore();  

        switch (pilihan) {
            case 1:
                tambahKontak(head);
                break;
            case 2:
                sortingMenu(head);
                break;
            case 3:
                perbaruiKontak(head);
                break;
            case 4:
                hapusKontak(head);
                break;
            case 5:
                push(head);
                break;
            case 6:
                pop(head);
                break;
            case 7:
                enqueue(head);
                break;
            case 8:
                dequeue(head);
                break;
            case 9:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 9);

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


void push(Kontak* &head) {
    Kontak* kontakBaru = new Kontak;
    cout << "Masukkan nomor telepon untuk Stack: ";
    getline(cin, kontakBaru->phone);
    kontakBaru->name = masukkanData("Masukkan nama: ");
    kontakBaru->instagram = masukkanData("Masukkan Instagram (opsional): ");
    kontakBaru->facebook = masukkanData("Masukkan Facebook (opsional): ");
    kontakBaru->twitter = masukkanData("Masukkan Twitter (opsional): ");
    kontakBaru->next = head;
    head = kontakBaru;
    cout << "\n=== Kontak berhasil ditambahkan ke ===\n";
}


void pop(Kontak* &head) {
    if (head == nullptr) {
        cout << "\n=== Stack kosong ===\n";
        return;
    }
    Kontak* temp = head;
    head = head->next;
    delete temp;
    cout << "\n=== Kontak berhasil dihapus dari ===\n";
}


void enqueue(Kontak* &head) {
    Kontak* kontakBaru = new Kontak;
    cout << "Masukkan nomor telepon untuk Queue: ";
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
    cout << "\n=== Kontak berhasil ditambahkan ke ===\n";
}


void dequeue(Kontak* &head) {
    if (head == nullptr) {
        cout << "\n=== Queue kosong ===\n";
        return;
    }
    Kontak* temp = head;
    head = head->next;
    delete temp;
    cout << "\n=== Kontak berhasil dihapus dari ===\n";
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


Kontak* cariKontak(Kontak* head, int indeks) {
    Kontak* temp = head;
    for (int i = 1; i < indeks && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}


string masukkanData(const string &teks) {
    string input;
    cout << teks;
    getline(cin, input);
    return input;
}


void sortingMenu(Kontak* &head) {
    int pilihan;
    cout << "\nPilih metode sorting:\n";
    cout << "1. Quick Sort Ascending\n";
    cout << "2. Merge Sort Descending\n";
    cout << "Pilih opsi: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            quickSort(&head);
            tampilkanKontak(head);
            break;
        case 2:
            head = mergeSortDescending(head);
            tampilkanKontak(head);
            break;
        default:
            cout << "\nOpsi tidak valid.\n";
            break;
    }
}


Kontak* getTail(Kontak* head) {
    while (head && head->next)
        head = head->next;
    return head;
}


Kontak* partition(Kontak* head, Kontak* end, Kontak** newHead, Kontak** newEnd) {
    Kontak* pivot = end;
    Kontak *prev = nullptr, *curr = head, *tail = pivot;

    while (curr != pivot) {
        if (curr->name < pivot->name) {
            if ((*newHead) == nullptr) (*newHead) = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) prev->next = curr->next;
            Kontak* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}


Kontak* quickSortRecur(Kontak* head, Kontak* end) {
    if (!head || head == end) return head;

    Kontak *newHead = nullptr, *newEnd = nullptr;

    Kontak* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Kontak* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}


void quickSort(Kontak** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}



Kontak* split(Kontak* head) {
    Kontak* fast = head;
    Kontak* slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Kontak* secondHalf = slow->next;
    slow->next = nullptr;
    return secondHalf;
}


Kontak* mergeDescending(Kontak* first, Kontak* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->name > second->name) {
        first->next = mergeDescending(first->next, second);
        return first;
    } else {
        second->next = mergeDescending(first, second->next);
        return second;
    }
}


Kontak* mergeSortDescending(Kontak* head) {
    if (!head || !head->next) return head;

    Kontak* second = split(head);

    
    head = mergeSortDescending(head);
    second = mergeSortDescending(second);

    
    return mergeDescending(head, second);
}
