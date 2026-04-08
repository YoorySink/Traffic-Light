int ledRed[]    = {2, 5, 8, 11};
int ledYellow[]  = {3, 6, 9, 12};
int ledGreen[] = {4, 7, 10, 13};
int jumlahLampu = 4;

void semuaMerah() {      //Mengatur semua sisi simpang ke kondisi lampu merah
  for (int i = 0; i < jumlahLampu; i++) {
    digitalWrite(ledGreen[i], LOW);
    digitalWrite(ledYellow[i], LOW);
    digitalWrite(ledRed[i], HIGH);
  }
}

void kelapkelip(int i) { //Memberikan efek kedip pada lampu kuning sebagai transisi
  for (int k = 0; k < 3; k++) {
    digitalWrite(ledYellow[i], HIGH);
    delay(300);
    digitalWrite(ledYellow[i], LOW);
    delay(300);
  }
}

void setup() {  //Inisialisasi semua pin LED sebagai OUTPUT
  for (int i = 0; i < jumlahLampu; i++) {
    pinMode(ledGreen[i], OUTPUT);
    pinMode(ledYellow[i], OUTPUT);
    pinMode(ledRed[i], OUTPUT);
  }
}
void pengaktifan(int i){ //mengaktifkan skema satu sisi simpang.
  	semuaMerah();                 //lampu merah akan menyala untuk semua sisi
    digitalWrite(ledRed[i], LOW); //mematikan lampu merah di sisi sekarang
    kelapkelip(i);                //menyalakan skema lampu kuning
    digitalWrite(ledYellow[i], HIGH);
    delay(2000);      //jeda 2 detik untuk membuat lampu kuning masih menyala
    digitalWrite(ledYellow[i], LOW);
    digitalWrite(ledGreen[i], HIGH);
    delay(5000);      //jeda 5 detik untuk membuat lampu hijau masih menyala
    digitalWrite(ledGreen[i], LOW);
}
void loop() {
  semuaMerah(); // semua lampu merah akan menyala diawal sebelum sisi lain lain menyala
  delay(1000);
  for (int i = 0; i < jumlahLampu; i++) { //menjalankan urutan traffic light untuk setiap sisi simpang secara bergantian
    pengaktifan(i);                       // skema ini akan terus menerus menyala sampai simulasi dihentikan
  }
}
