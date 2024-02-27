#include <iostream>
using namespace std;

// Fungsi untuk mengompresi array karakter
int compress(char chars[], int length) {
    int index = 0; // Inisialisasi indeks untuk array yang telah dikompresi
    int count = 1; // Inisialisasi hitungan karakter berurutan

    // Iterasi melalui array karakter
    for (int i = 0; i < length - 1; i++) {
        if (chars[i] == chars[i + 1]) {
            // Jika karakter saat ini sama dengan karakter berikutnya, tambahkan hitungan
            count++;
        } else {
            // Jika tidak, simpan karakter saat ini dalam array yang telah dikompresi
            chars[index] = chars[i];
            index++;

            // Jika ada lebih dari satu karakter berurutan, tambahkan hitungannya
            if (count > 1) {
                string countString = to_string(count);
                for (char c : countString) {
                    chars[index] = c;
                    index++;
                }
            }

            // Atur ulang hitungan untuk karakter berikutnya
            count = 1;
        }
    }

    // Tambahkan karakter terakhir dan hitungannya
    chars[index] = chars[length - 1];
    index++;
    if (count > 1) {
        string countString = to_string(count);
        for (char c : countString) {
            chars[index] = c;
            index++;
        }
    }

    return index; // Kembalikan panjang array yang telah dikompresi
}

int main() {
    char chars[] = {'s', 's', 'h', 'h', 'a', 'a', 'n', 'n', 'n', 'd', 'd','d','y','y','y','y'}; // Input Chars
    int length = sizeof(chars) / sizeof(chars[0]);
    int compressedLength;

    cout << "Sebelum dikompresi: " << length << ", "; // Output yang sebelum di kompresi.
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << "\"" << chars[i] << "\"";
        if (i < length - 1) {
            cout << ",";
        }
    }
    cout <<"]" << endl;

    compressedLength = compress(chars, length); // chars yang di kompresi.

    cout << "Setelah dikompresi: " << compressedLength << ", "; // Output yang setelah di kompresi.
    cout << "[";
    for (int i = 0; i < compressedLength; i++) {
        cout << "\"" << chars[i] << "\"";
        if (i < compressedLength - 1) {
            cout << ",";
        }
    }
    cout <<"]" << endl;

    return 0;
}