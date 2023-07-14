#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Club {
    string name;
    int menang, kalah, seri;
    int goal, poin;
};

Club klub[16];

void init_club() {
    klub[0].name = "Manchester United";
    klub[1].name = "Manchester City";
    klub[2].name = "Liverpool";
    klub[3].name = "Chealsea";
    klub[4].name = "Tottenham";
    klub[5].name = "Newcastle";
    klub[6].name = "Southampton";
    klub[7].name = "Wolves Wanderers";
    klub[8].name = "Leeds United";
    klub[9].name = "Fulham";
    klub[10].name = "Brigthon";
    klub[11].name = "Brentford";
    klub[12].name = "Aston Villa";
    klub[13].name = "Leicester";
    klub[14].name = "Everton";
    klub[15].name = "Westham";

    for (int i = 0; i < 16; i++) {
        klub[i].menang = klub[i].kalah = klub[i].seri = 0;
        klub[i].goal = klub[i].poin = 0;
    }
}

void daftar_klub() {
    cout << "+==========================================+" << endl;
    cout << "| Daftar Nama Klub Liga Inggris 2023        |" << endl;
    cout << "+==========================================+" << endl;
    for (int i = 0; i < 16; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(27) << left << klub[i].name << " |" << endl;
    }
    cout << "+==========================================+" << endl;
}

void sorting() {
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = i + 1; j < 16; j++) {
            if (klub[i].poin < klub[j].poin) {
                Club temp = klub[i];
                klub[i] = klub[j];
                klub[j] = temp;
            }
        }
    }
}

void display_detail(int idx) {
    cout << "Nama klub: " << klub[idx].name << endl;
    cout << "Menang: " << klub[idx].menang << endl;
    cout << "Kalah: " << klub[idx].kalah << endl;
    cout << "Seri: " << klub[idx].seri << endl;
    cout << "Goal: " << klub[idx].goal << endl;
    cout << "Poin: " << klub[idx].poin << endl;
}

void search() {
    string name;
    int i, flag = 0;

    cout << "Masukkan nama klub yang ingin dicari: ";
    cin.ignore();
    getline(cin, name);

    for (i = 0; i < 16; i++) {
        if (klub[i].name == name || klub[i].name.find(name) != string::npos) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << "Klub " << klub[i].name << " berada di posisi " << i + 1 << " pada klasemen liga." << endl;
        display_detail(i);
    } else {
        cout << "Klub tidak ditemukan pada klasemen liga." << endl;
    }
}

void show_klasemen() {
    int i;
    cout << "========================================================" << endl;
    cout << "| No. | Nama Klub               | M | K | S | G | P |" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (i = 0; i < 16; i++) {
        printf("|%4d | %-23s | %d | %d | %d | %d | %d |\n",
               i + 1, klub[i].name.c_str(), klub[i].menang, klub[i].kalah, klub[i].seri, klub[i].goal, klub[i].poin);
    }
    cout << "========================================================" << endl;
}

void entry_pertandingan() {
    string home_name, away_name;
    int skor_home, skor_away;
    cout << "Masukkan klub tuan rumah: ";
    cin >> ws;
    getline(cin, home_name);
    cout << "Masukkan skor tuan rumah: ";
    cin >> skor_home;
    cin.ignore();
    cout << "Masukkan klub tamu: ";
    cin >> ws;
    getline(cin, away_name);
    cout << "Masukkan skor tamu: ";
    cin >> skor_away;
    cin.ignore();

    int idx_home = -1, idx_away = -1;
    for (int i = 0; i < 16; i++) {
        if (klub[i].name == home_name) {
            idx_home = i;
        } else if (klub[i].name == away_name) {
            idx_away = i;
        }
        if (idx_home >= 0 && idx_away >= 0)
            break;
    }

    klub[idx_home].goal += skor_home;
    klub[idx_away].goal += skor_away;

    if (skor_home > skor_away) {
        klub[idx_home].menang++;
        klub[idx_away].kalah++;
        klub[idx_home].poin += 3;
    } else if (skor_home < skor_away) {
        klub[idx_away].menang++;
        klub[idx_home].kalah++;
        klub[idx_away].poin += 3;
    } else {
        klub[idx_home].seri++;
        klub[idx_home].poin++;
        klub[idx_away].seri++;
        klub[idx_away].poin++;
    }

    cout << "\nPertandingan berhasil dimasukkan!" << endl;
    cin.get();
}

int main() {
    char jawab;
    int kategori;

    init_club();

    do {
        system("clear");
        cout << "\n" << endl;
        cout << "\t         TUGAS KELOMPOK MATKUL STRUKTUR DATA" << endl;
        cout << "\t         1222624 - Fan Fan Firgiawan" << endl;
        cout << "\t         1222638 - Angga Trisetyo Yanuar" << endl;
        cout << "\t         1222631 - Asiyono Sidik" << endl;
        cout << "\n" << endl;
        cout << "==============================================================" << endl;
        cout << "\t         Program klasemen liga sepak bola" << endl;
        cout << "==============================================================" << endl;
        cout << "\t\t           Pilih menu" << endl;
        cout << "==============================================================" << endl;
        cout << "\t\t||[1] = Daftar klub        ||" << endl;
        cout << "\t\t||[2] = Entry Pertandingan ||" << endl;
        cout << "\t\t||[3] = Klasemen           ||" << endl;
        cout << "\t\t||[4] = Pencarian Klub     ||" << endl;
        cout << "\t\t||[5] = Keluar             ||" << endl;
        cout << "==============================================================" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> kategori;
        cout << endl;

        switch (kategori) {
            case 1:
                system("clear");
                daftar_klub();
                cin.get();
                break;

            case 2:
                system("clear");
                entry_pertandingan();
                break;

            case 3:
                system("clear");
                cout << "=============================================================================" << endl;
                cout << "|---------------------------------Klasemen Liga -----------------------------|" << endl;
                cout << "=============================================================================" << endl;
                sorting();
                show_klasemen();
                break;

            case 4:
                system("clear");
                search();
                cin.get();
                break;

            case 5:
                goto akhir;
                break;

            default:
                cout << "Yang anda masukan tidak sesuai" << endl;
                break;
        }

        cout << "\n" << "Kembali Ke Menu Awal? (Y/N) ";
        cin >> jawab;
        cout << endl;
    } while (jawab == 'Y' || jawab == 'y');

    akhir:
    cout << "Terimakasih telah menggunakan program ini!" << endl;

    return 0;
}
