# Tugas Besar 2 IF3130 - Distance Vector Simulation

##### Anggota Tim:
  - Faiz Ghifari Haznitrama - 13515010
  - Dery Rahman Ahaddienata - 13515097
  - Irfan Ariq - 13515112

## Petunjuk Penggunaan Program
Program distance vector simulation yang kami buat menggunakan bahasa C++. Untuk source code terdapat dalam folder `src`, data pengujian dalam folder `data`. Untuk menjalankan program, cukup hal berikut pada terminal pada direktori file ini. Kami mensimulasikan sebuah node 

```sh
$ makefile
```
Kemudian pertama-tama silahkan masukkan jumlah node dan edges. Lalu masukkan node-node yang terhubung sebanyak edges yang telah diinputkan. Setelah itu masukkan sebuah angka S yang didefinisikan sebagai banyak simulasi penyaluran informasi yang akan dilakukan pada kumpulan nodes yang telah tersedia. Terakhir silahkan masukkan node asal dan node tujuan yang mensimulasikan pengiriman informasi node to node sebanyak S yang telah diinputkan sebelumnya. Setelah itu program akan melakukan pengolahan terhadap input-input yang telah diterima dan akan menampilkan hasil akhir routing table berdasarkan simulasi yang telah dilakukan.

### Bagaimana anda mensimulasikan sebuah node dalam program anda?
Node dalam program yang kami buat disimulasikan dengan sebuah array 1 dimensi dengan panjang 2, yang merepresentasikan nextHop dan nodeDestination. Kemudian untuk merepresentasikan kumpulan nodes dan edges beserta keterhubungannya, kami membuat sebuah array 3 dimensi sebesar 1001 x 1001 x 2 untuk menampung kemungkinan nodes dan edges dalam jumlah yang cukup besar. Sebetulnya jika node direpresentasikan sebagai objek, maka sebenarnya yang terbentuk adalah matrix of node, dimana setiap node menyimpan informasi mengenai hubungannya dengan nodes lain berupa nextHop dan nodeDestination yang telah disebutkan sebelumnya. Array 3 dimensi direpresentasikan dengan variabel `Mt`, jumlah nodes direpresentasikan dengan `N`, dan jumlah edges direpresentasikan dengan variabel `M`.

### Bagaimana proses pengiriman pesan antar node terjadi?
Proses pengiriman pesan antar node beserta update pada routing table setiap node diimplementasikan pada fungsi solve. Jadi pada proses pengiriman informasi antar node, node yang mengirimkan informasi ke node lainnya juga memberikan informasi-informasi routing table yang dimilikinya ke node yang dituju. Sebagai contoh, `node 2` memiliki hubungan ke `node 1` dengan `distance = 1`. Ketika `node 2` mengirim informasi ke `node 3`, dalam hal ini `node 2` dan `node 3` bersebelahan `distance = 1` maka `node 3` juga mendapatkan informasi seluruh nodes yang juga terhubung dengan `node 2`, dalam kasus ini adalah `node 1` dengan `distance = 1`. Sebelumnya, `node 3` tidak memiliki informasi ke `node 1`. Setelah mendapatkan informasi dari `node 2`, `node 3` mengetahui bahwa ia bisa memberikan informasi ke `node 1` melalui `node 2`, dalam hal ini adalah `nextHop` ke `node 1` dari `node 3`, dengan `distance = 2` yang didapatkan dari `distance node3-node1 = distance node3-node2 + distance node2-node1`. Begitupun seterusnya ketika ada proses pengiriman pesan antar node.

## Pembagian Tugas
  - Faiz Ghifari Haznitrama : Fungsionalitas main
  - Dery Rahman Ahaddienata : Fungsionalitas solve
  - Irfan Ariq : Struktur data nodes dan Fungsionalitas output

## Jawaban Pertanyaan
##### 1. Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang lebih baik untuk digunakan?
Letak perbedaan antara routing protocol distance-vector dan link state adalah bagaimana kedua protocol tersebut mengupdate nilai dari routing tabelnya. Pada distance vector, update routing tabel dilakukan dengan pertukaran routing tabel node tetangganya dan updating routing tabel hanya mengatakan hal-hal tentang router. Tidak seperti distance vector, pada link state protocol updating tabel mengatakan hal yang lebih dari router seperti memberikan data tentang topologi jaringan dan router akan melakukan komputasi dari data yang diberikan. 
Baik link state protocol atau distance vector protocol pasti memiliki kelebihan dan kekurangan. Untuk jaringan berskala kecil distance routing lebih baik karena tidak memerlukan power CPU yang besar. Namun untuk jaringan berskala besar link state protocol lebih baik. 

##### 2. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau  link state? Kenapa?
Saat ini lebih banyak link state dibandingkan dengan distance vector. Kenapa? Karena untuk jaringan dalam skala besar, link state lebih cocok digunakan karena memiliki informasi yang jauh lebih lengkap tentang keseluruhan topologi jaringan. Sehingga setiap router dapat menentukan jalur terdekat ke router lain dari informasi tersebut. Meskipun pada penggunaan link state akan ada overhead, tetapi hal itu masih lebih wajar dibandingkan dengan distance vector dimana router memiliki keterbatasan informasi dan perbedaan kecepatan transmit di setiap jalur.