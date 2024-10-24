#include <iostream>
#include <cmath>  
using namespace std;

struct Kontak {
    string name;
    int phone;  
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

void searchingMenu(Kontak* head);
int fibonacciSearch(const Kontak* head, int x);
int jumpSearch(const Kontak* head, int x);
int boyerMooreSearch( Kontak* head, const string& pattern);

int main() {
    Kontak* head = nullptr;
    int pilihan;

    do {
        cout << "\n==============================\n";
        cout << "=== Manajemen Nomor Kontak ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Update Kontak\n";
        cout << "5. Hapus Kontak\n";
        cout << "6. Push\n";
        cout << "7. Pop\n";
        cout << "8. Enqueue\n";
        cout << "9. Dequeue\n";
        cout << "10. Keluar\n";
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
                searchingMenu(head);
                break;
            case 4:
                perbaruiKontak(head);
                break;
            case 5:
                hapusKontak(head);
                break;
            case 6:
                push(head);
                break;
            case 7:
                pop(head);
                break;
            case 8:
                enqueue(head);
                break;
            case 9:
                dequeue(head);
                break;
            case 10:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 10);

    bersihkanMemori(head);
    return 0;
}


void tambahKontak(Kontak* &head) {
    Kontak* kontakBaru = new Kontak;
    cout << "Masukkan nomor telepon: ";
    cin >> kontakBaru->phone;  
    cin.ignore();
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
    cin >> kontakBaru->phone;
    cin.ignore();
    kontakBaru->name = masukkanData("Masukkan nama: ");
    kontakBaru->instagram = masukkanData("Masukkan Instagram (opsional): ");
    kontakBaru->facebook = masukkanData("Masukkan Facebook (opsional): ");
    kontakBaru->twitter = masukkanData("Masukkan Twitter (opsional): ");
    kontakBaru->next = head;
    head = kontakBaru;
    cout << "\n=== Kontak berhasil ditambahkan ke Stack ===\n";
}


void pop(Kontak* &head) {
    if (head == nullptr) {
        cout << "\n=== Stack kosong ===\n";
        return;
    }
    Kontak* temp = head;
    head = head->next;
    delete temp;
    cout << "\n=== Kontak berhasil dihapus dari Stack ===\n";
}


void enqueue(Kontak* &head) {
    Kontak* kontakBaru = new Kontak;
    cout << "Masukkan nomor telepon untuk Queue: ";
    cin >> kontakBaru->phone;
    cin.ignore();
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
    cout << "\n=== Kontak berhasil ditambahkan ke Queue ===\n";
}


void dequeue(Kontak* &head) {
    if (head == nullptr) {
        cout << "\n=== Queue kosong ===\n";
        return;
    }
    Kontak* temp = head;
    head = head->next;
    delete temp;
    cout << "\n=== Kontak berhasil dihapus dari Queue ===\n";
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
        cout << "Nomor Telepon: " << kontakDiperbarui->phone << "\n";
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


Kontak* cariKontak(Kontak* head, int indeks) {
    int nomor = 1;
    Kontak* temp = head;
    while (temp != nullptr && nomor < indeks) {
        temp = temp->next;
        nomor++;
    }
    return temp;
}


int hitungKontak(Kontak* head) {
    int jumlah = 0;
    Kontak* temp = head;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}


string masukkanData(const string &teks) {
    string data;
    cout << teks;
    getline(cin, data);
    return data;
}


void bersihkanMemori(Kontak* &head) {
    while (head != nullptr) {
        Kontak* temp = head;
        head = head->next;
        delete temp;
    }
}


void sortingMenu(Kontak* &head) {
    int pilihan;
    cout << "\nPilih metode pengurutan:\n";
    cout << "1. Quick Sort berdasarkan nomor telepon\n";
    cout << "2. Merge Sort descending berdasarkan nomor telepon\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1:
            quickSort(&head);
            break;
        case 2:
            head = mergeSortDescending(head);
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            return;
    }

    tampilkanKontak(head);
}


Kontak* getTail(Kontak* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

Kontak* partition(Kontak* head, Kontak* end, Kontak** newHead, Kontak** newEnd) {
    Kontak* pivot = end;
    Kontak *prev = nullptr, *curr = head, *tail = pivot;

    while (curr != pivot) {
        if (curr->phone < pivot->phone) {
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
    Kontak* fast = head->next;
    Kontak* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Kontak* temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Kontak* mergeDescending(Kontak* first, Kontak* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->phone > second->phone) {
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

void searchingMenu(Kontak* head) {
    int metode;
    cout << "\nPilih metode searching:\n";
    cout << "1. Fibonacci Search (Ascending)\n";
    cout << "2. Jump Search (Descending)\n";
    cout << "3. Boyer-Moore Search (Nama)\n";
    cout << "Pilihan: ";
    cin >> metode;
    cin.ignore();  

    switch (metode) {
        case 1: {
            
            int telepon;
            tampilkanKontak(head);
            cout << "\n==========================================\n";
            cout << "Masukkan nomor telepon yang dicari: ";
            cin >> telepon;
            int hasil = fibonacciSearch(head, telepon);
            if (hasil != -1) {
                cout << "Ditemukan pada indeks: " << hasil << endl;
            } else {
                cout << "Tidak ditemukan.\n";
            }
            break;
        }
        case 2: {
            tampilkanKontak(head);
            int telepon;
            cout << "\n==========================================\n";
            cout << "Masukkan nomor telepon yang dicari: ";
            cin >> telepon;
            int hasil = jumpSearch(head, telepon);
            if (hasil != -1) {
                cout << "Ditemukan pada indeks: " << hasil << endl;
            } else {
                cout << "Tidak ditemukan.\n";
            }
            break;
        }
        case 3: {
            tampilkanKontak(head);
            string nama;
            cout << "\n==========================================\n";
            cout << "Masukkan nama yang dicari: ";
            getline(cin, nama);
            int hasil = boyerMooreSearch(head, nama);
            if (hasil != -1) {
                cout << "Ditemukan pada indeks: " << hasil << endl;
            } else {
                cout << "Tidak ditemukan.\n";
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid. Kembali ke menu utama.\n";
    }
}

int fibonacciSearch(const Kontak* head, int x) {
    int n = hitungKontak((Kontak*)head);
    const Kontak* temp = head;
    
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM2 + fibM1;
    
    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        const Kontak* current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }

        if (current->phone < x) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (current->phone > x) {
            fibM = fibM2;
            fibM1 -= fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i + 1;
        }
    }

    
    const Kontak* current = head;
    for (int i = 0; i <= offset; i++) {
        current = current->next;
    }
    if (fibM1 && current->phone == x) {
        return offset + 2;
    }

    return -1;  
}

int jumpSearch(const Kontak* head, int x) {
    int n = hitungKontak((Kontak*)head);  
    if (n == 0) return -1; 
    int step = sqrt(n);
    const Kontak *prev = head;
    const Kontak *current = head;
    int prevIndex = 0;
    int currentIndex = 0;

    while (current != NULL && current->phone > x) {
        prev = current;
        prevIndex = currentIndex;

        for (int i = 0; i < step && current != NULL; ++i) {
            current = current->next;
            currentIndex++;
        }
    }

    while (prev != NULL && prev->phone > x) {
        prev = prev->next;
        prevIndex++;
    }

    if (prev != NULL && prev->phone == x) {
        return prevIndex + 1;
    }

    return -1; 
}

int boyerMooreSearch(Kontak* head, const string& pattern) {
    int m = pattern.size();
    int badChar[256];

    
    for (int i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        badChar[(int)pattern[i]] = i;
    }

    Kontak* current = head;
    int index = 1;

    
    while (current != nullptr) {
        string text = current->name;
        int n = text.size();
        int s = 0;

        
        while (s <= (n - m)) {
            int j = m - 1;
            while (j >= 0 && pattern[j] == text[s + j]) {
                j--;
            }
            if (j < 0) {
                return index;
            } else {
                s += max(1, j - badChar[(int)text[s + j]]);
            }
        }

        current = current->next;
        index++;
    }

    return -1;  
}
