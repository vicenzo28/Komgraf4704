#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan matriks
void tampilkanMatriks(const vector<vector<int>>& matriks) {
    for (const vector<int>& baris : matriks) {
        for (int elemen : baris) {
            cout << elemen << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk operasi penambahan matriks
vector<vector<int>> tambahMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2) {
    int baris = matriks1.size();
    int kolom = matriks1[0].size();
    vector<vector<int>> hasil(baris, vector<int>(kolom, 0));

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }

    return hasil;
}

// Fungsi untuk operasi pengurangan matriks
vector<vector<int>> kurangMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2) {
    int baris = matriks1.size();
    int kolom = matriks1[0].size();
    vector<vector<int>> hasil(baris, vector<int>(kolom, 0));

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }

    return hasil;
}

// Fungsi untuk operasi perkalian matriks
vector<vector<int>> kaliMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2) {
    int baris1 = matriks1.size();
    int kolom1 = matriks1[0].size();
    int kolom2 = matriks2[0].size();
    vector<vector<int>> hasil(baris1, vector<int>(kolom2, 0));

    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom2; j++) {
            for (int k = 0; k < kolom1; k++) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }

    return hasil;
}

// Fungsi untuk operasi perkalian skalar
vector<vector<int>> kaliSkalar(const vector<vector<int>>& matriks, int skalar) {
    int baris = matriks.size();
    int kolom = matriks[0].size();
    vector<vector<int>> hasil(baris, vector<int>(kolom, 0));

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks[i][j] * skalar;
        }
    }

    return hasil;
}

int main() {
    // Contoh matriks
    vector<vector<int>> matriksA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matriksB = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int skalar = 2;

    cout << "Matriks A:" << endl;
    tampilkanMatriks(matriksA);

    cout << "Matriks B:" << endl;
    tampilkanMatriks(matriksB);

    cout << "Hasil Penambahan Matriks A dan B:" << endl;
    tampilkanMatriks(tambahMatriks(matriksA, matriksB));

    cout << "Hasil Pengurangan Matriks A dan B:" << endl;
    tampilkanMatriks(kurangMatriks(matriksA, matriksB));

    cout << "Hasil Perkalian Matriks A dan B:" << endl;
    tampilkanMatriks(kaliMatriks(matriksA, matriksB));

    cout << "Hasil Perkalian Skalar Matriks A dengan " << skalar << ":" << endl;
    tampilkanMatriks(kaliSkalar(matriksA, skalar));

    return 0;
}
