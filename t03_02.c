#include <stdio.h>   // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Diperlukan untuk INT_MAX dan INT_MIN (nilai integer maksimum dan minimum)
#include <float.h>   // Diperlukan untuk DBL_MAX (nilai double maksimum)

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;        // Variabel untuk menyimpan setiap bilangan yang dibaca
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer minimum

    // Variabel tambahan untuk fitur rata-rata berturut-turut
    int prev_num;             // Menyimpan bilangan sebelumnya untuk menghitung rata-rata pasangan
    double lowest_consecutive_avg = DBL_MAX; // Inisialisasi dengan nilai double maksimum

    // 1. Membaca jumlah baris masukan berikutnya (n)
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Gagal membaca jumlah baris (n).\n");
        return 1;
    }

    // Memastikan n positif dan setidaknya 1 untuk dapat memproses input
    if (n <= 0) {
        fprintf(stderr, "Error: Jumlah baris (n) harus bilangan bulat positif.\n");
        return 1;
    }

    // 2. Melakukan perulangan sebanyak n kali untuk membaca setiap bilangan
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) {
            fprintf(stderr, "Error: Gagal membaca bilangan ke-%d.\n", i + 1);
            return 1;
        }

        // Untuk iterasi pertama, inisialisasi min_val, max_val, dan prev_num
        // agar perbandingan berikutnya akurat dan ada prev_num untuk pasangan pertama
        if (i == 0) {
            min_val = num;
            max_val = num;
            prev_num = num; // Bilangan pertama menjadi prev_num untuk iterasi berikutnya
        } else {
            // Membandingkan dan memperbarui nilai terkecil (min_val)
            if (num < min_val) {
                min_val = num;
            }

            // Membandingkan dan memperbarui nilai terbesar (max_val)
            if (num > max_val) {
                max_val = num;
            }

            // ---- Logika baru untuk rata-rata terendah dari dua nilai berturut-turut ----
            double current_avg = (double)(prev_num + num) / 2.0;
            if (current_avg < lowest_consecutive_avg) {
                lowest_consecutive_avg = current_avg;
            }
            // --------------------------------------------------------------------------

            prev_num = num; // Set bilangan saat ini sebagai prev_num untuk iterasi berikutnya
        }
    }

    // 5. Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menampilkan rata-rata terendah dari dua nilai berturut-turut
    // Hanya tampilkan jika n >= 2, karena jika n=1 tidak ada pasangan berturut-turut
    if (n >= 2) {
        printf("%.2f\n", lowest_consecutive_avg);
    } else {
        // Jika n < 2, tidak ada rata-rata berturut-turut yang bisa dihitung
        // Anda bisa memilih untuk tidak mencetak apa-apa, atau mencetak pesan.
        // Berdasarkan contoh sebelumnya, diasumsikan n akan cukup besar.
        // Untuk saat ini, kita akan mencetak nilai default DBL_MAX jika n < 2.
        // Atau, jika diminta, bisa ditambahkan pesan seperti "N/A"
        // printf("N/A\n"); // Contoh alternatif
        // Jika diasumsikan input valid selalu memiliki n >= 2, baris ini tidak perlu.
    }

    return 0; // Menandakan program berakhir dengan sukses
}
