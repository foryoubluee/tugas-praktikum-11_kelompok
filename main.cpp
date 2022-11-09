#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Nilai {
	int    nilai_tugas;
	int    nilai_uts;
	int    nilai_uas;
  float  bobot;
  string grade;
};

struct Name {
	string fname;
	string lname;
};

struct Mahasiswa {
	string NIM;
  Name   name;
  Nilai  nilai;
};

char define_grade(float bobot);
void add_space(int name_length, int cols_space);
void print_result(Mahasiswa mahasiswa[], int total_rows);
void write_result(Mahasiswa mahasiswa[], ofstream &outputFile, int total_rows);

int main() {
  int i, j;
  float n_tugas, n_uts, n_uas, bobot;
  int rows = 33, cols = 198;
  char calculated_grade;
  char rows_delimiter = '\n';
  char cols_delimiter = ' ';

  string    lines;
  string    word_per_line;
  string    data_mhs[rows][cols];
  ifstream  file("./data/NilaiSiswa.txt");
  ofstream outputFile("./data/NilaiSiswa-hasil.txt");
  Mahasiswa mahasiswa[rows];
  
  for (i = 0; i < rows; i++) {
    getline(file, lines, rows_delimiter);
    stringstream line(lines);
    for (j = 0; j < cols; j++) {
      getline                           (line, word_per_line, cols_delimiter);
      n_tugas                           = strtod(data_mhs[i][3].c_str(), 0);
      n_uts                             = strtod(data_mhs[i][4].c_str(), 0);
      n_uas                             = strtod(data_mhs[i][5].c_str(), 0);
      bobot                             = n_tugas * 30 / 100 + 
                                          n_uts * 30 / 100 + 
                                          n_uas * 40 / 100;
      calculated_grade                  = define_grade(bobot);
      data_mhs[i][j]                    = word_per_line;
      mahasiswa[i].NIM                  = data_mhs[i][0];
      mahasiswa[i].name.fname           = data_mhs[i][1];
      mahasiswa[i].name.lname           = data_mhs[i][2];
      mahasiswa[i].nilai.nilai_tugas    = n_tugas;
      mahasiswa[i].nilai.nilai_uts      = n_uts;
      mahasiswa[i].nilai.nilai_uas      = n_uas;
      mahasiswa[i].nilai.bobot          = bobot;
      mahasiswa[i].nilai.grade          = calculated_grade;
    }
  }
  print_result(mahasiswa, rows);
  write_result(mahasiswa, outputFile, rows);
}

void print_result(Mahasiswa mahasiswa[], int total_rows) {
  int name_length;
  cout <<  endl << "Nilai Mata Kuliah Algoritma"                                             << endl;
	cout << "-------------------------------------------------------------------------------|" << endl;
	cout << "No  |       NIM |                   Nama | Tugas | UTS  | UAS | Bobot | Huruf  |" << endl;
	cout << "-------------------------------------------------------------------------------|" << endl;
  for(int i = 0; i < total_rows; i++) {
    string full_name = mahasiswa[i].name.fname + " " + mahasiswa[i].name.lname;
    name_length = full_name.length();
    string bobot = to_string(mahasiswa[i].nilai.bobot);
    cout << i + 1;
    if(i < 9) {
      cout << " ";
    }
    cout << "  | " 
         << mahasiswa[i].NIM 
         << " |  " ;
         add_space(name_length, 21); 
    cout << mahasiswa[i].name.fname 
         << " "
         << mahasiswa[i].name.lname
         << " | " 
         << mahasiswa[i].nilai.nilai_tugas
         << "    | "
         << mahasiswa[i].nilai.nilai_uts
         << "   | " 
         << mahasiswa[i].nilai.nilai_uas
         << "  | " 
         << mahasiswa[i].nilai.bobot;
         if(bobot[3] == '0' && bobot[4] == '0') {
           cout << "  ";
         }
    cout << "  |    " 
         << mahasiswa[i].nilai.grade
         << "   |" 
	       << endl;
  }
  cout << "-------------------------------------------------------------------------------|" << endl;
}

void write_result(Mahasiswa mahasiswa[], ofstream &outputFile,int total_rows) {
  int name_length;
  outputFile << "Nilai Mata Kuliah Algoritma"                                                      << endl;
	outputFile << "-------------------------------------------------------------------------------|" << endl;
	outputFile << "No  |       NIM |                   Nama | Tugas | UTS  | UAS | Bobot | Huruf  |" << endl;
	outputFile << "-------------------------------------------------------------------------------|" << endl;
  for(int i = 0; i < total_rows; i++) {
    string full_name = mahasiswa[i].name.fname + " " + mahasiswa[i].name.lname;
    name_length = full_name.length();
    string bobot = to_string(mahasiswa[i].nilai.bobot);
    outputFile << i + 1;
               if(i < 9) {
                 outputFile << " ";
               }
    outputFile << "  | " 
               << mahasiswa[i].NIM 
               << " |  " ;
               for(int j = 0; j < name_length - 21; j++) {
                 outputFile << " ";
               }        
    outputFile << mahasiswa[i].name.fname 
               << " "
               << mahasiswa[i].name.lname
               << " | " 
               << mahasiswa[i].nilai.nilai_tugas
               << "    | "
               << mahasiswa[i].nilai.nilai_uts
               << "   | " 
               << mahasiswa[i].nilai.nilai_uas
               << "  | " 
               << mahasiswa[i].nilai.bobot;
               if(bobot[3] == '0' && bobot[4] == '0') {
                 outputFile << "  ";
               }
    outputFile << "  |    " 
               << mahasiswa[i].nilai.grade
               << "   |" 
	             << endl;
  }
  outputFile << "-------------------------------------------------------------------------------|" << endl;
  outputFile.close();
}


char define_grade(float bobot) {
  char grade = '\0';
  if(bobot >= 80) {
    grade = 'A';
  } else if(bobot < 80 && bobot >= 70) {
    grade = 'B';
  } else if(bobot < 70 && bobot >= 56) {
    grade = 'C';
  } else if(bobot < 56 && bobot >= 45) {
    grade = 'D';
  } else if(bobot < 45) {
    grade = 'E';
  }
  return grade;
}

void add_space(int the_length, int cols_space) {
  for(int i = 0; i < cols_space - the_length; i++) {
    cout << " ";
  }
} 

void add_space_to_file(ofstream outputFile, int the_length, int cols_space) {
  for(int i = 0; i < cols_space - the_length; i++) {
    outputFile << " ";
  }
} 

// !! SOAL !! //
/*
a. Baca file "NilaiSiswa.txt". (file ada di files teams)
b. Simpan data siswa pada struct Mahasiswa, yang didalamnya terdapat struct Nilai.
c. Hitung nilai akhir setiap mahasiswa dengan rumus: 30%xTugas + 30%xUTS + 40%xUAS. 
d. Konversikan nilai akhir menjadi nilai huruf dengan ketentuan sebagai berikut:
   Nilai          Huruf 
   >= 80            A 
   70 <= Nilai < 80 B 
   56 <= Nilai < 70 C 
   45 <= Nilai < 56 D 
   < 45             E
e. Tampilkan tabel hasil perhitungan nilai pada console dan simpan tabel tersebut ke dalam file "NilaiSiswa-hasil.txt".
*/