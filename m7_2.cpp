#include <iostream>
#include <iomanip>
using namespace std;

const int Row_A = 3, Clm_A = 4;
const int Row_D = 2, Clm_D = 3;
const int Row_E = 2, Clm_E = 4;

int A[Row_A][Clm_A];
int B[Row_A][Clm_A];
int C[Row_A][Clm_A];
int D[Row_D][Clm_D];
int E[Row_E][Clm_E];

bool mExist = false;

//Input matrix
void mCreate(){
    cout << "\nInput Matrix: \n";
    //Matrix A
    cout << "\nInput Matrix A [" << Row_A << "x" << Clm_A << "]:\n";
    for (int i=0; i < Row_A; i++)
        for (int j=0; j < Clm_A; j++){
            cout << "\nA[" << i+1 << "][" << j+1 << "]: \n";
            cin >> A[i][j];
        }
    //Matrix B
    cout << "\nInput Matrix B [" << Row_A << "x" << Clm_A << "]:\n";
    for (int i=0; i < Row_A; i++)
        for (int j=0; j < Clm_A; j++){
            cout << "\nB[" << i+1 << "][" << j+1 << "]: \n";
            cin >> B[i][j]; 
        }
    //Matrix D
    cout << "\nInput Matrix D[" << Row_D << "x" << Clm_D << "]:\n";
    for (int i=0; i < Row_D; i++)
        for (int j=0; j < Clm_D;j++){
            cout << "\nD[" << i+1 << "][" << j+1 << "]: \n";
            cin >> D[i][j];
        }
    //Matrix C & E = 0
     for (int i=0; i < Row_A; i++)
        for (int j=0; j < Clm_A; j++){
            C[i][j]=0;
        }
    for (int i=0; i < Row_E; i++)
        for (int j=0; j < Clm_E; j++){
            E[i][j]=0;
        }
    mExist = true;
}

//cetak matriks A & B
void mPrint1(int mat[][Clm_A], int row, int column, const string& nama){
    cout << "\nMatriks " << nama << "[" << row << "x" << column << "]:\n";
    for (int i=0; i < row; i++){
        cout << "[";
        for (int j=0; j < column; j++)
            cout << setw(5) << mat[i][j];
        cout << "]\n";
    }
}

void mPrint2(int row, int column,int mat[][4], const string& nama){
    cout << "\nMatriks " << nama << "[" << row << "x" << column << "]:\n";
    for (int i=0; i < row; i++){
        cout << "[";
        for (int j=0; j < column; j++) 
            cout << setw(5) << mat[i][j];
        cout << "]\n";
    }
}

void mPrint3(){
    cout << "\nMatriks D [" << Row_D << "x" << Clm_D << "]:\n";
    for (int i=0; i < Row_D; i++){
        cout << "[";
        for (int j=0; j < Clm_D; j++)
            cout << setw(5) << D[i][j];
        cout << "]\n";
    }
}

//tampilkan semua
void mShow(){
    if (!mExist) {
        cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
        return;
    }
        mPrint1(A, Row_A, Clm_A, "A");
        mPrint1(B, Row_A, Clm_A, "B");
        mPrint1(C, Row_A, Clm_A, "C (Hasil penjumlahan)");
        mPrint3();
        mPrint1(E, Row_E, Clm_E, "E (Hasil perkalian)");
}

//perkalian matriks
void mMult(){
    if (!mExist) {
        cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
        return;
    }
    if (Row_A != Clm_D){
        cout << "\nPerkalian tidak valid!";
        cout << "Baris D (" << Row_A << ") tidak sama dengan Kolom A (" << Clm_D <<")\n"; 
        return;
}

cout << "Perkalian matriks D x B";
    for (int i=0; i < Row_D; i++)
    for (int j=0; j < Clm_E; j++){
        E[i][j] = 0;
        for (int k=0; k < Clm_D; k++)
        E[i][j] += D[i][k] * B[k][j];
    }  
    cout << "\nHasil perkalian= ";
    mPrint1(E, Row_E, Clm_E, "E");
}

//penjumlahan matriks
void mAdd(){
    if (!mExist) {
        cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
        return;
        }
    cout << "Penjumlahan matriks A + B";
    for (int i=0; i < Row_A; i++)
        for (int j=0; j < Clm_A; j++){
            C[i][j]= A[i][j] + B[i][j];
        }
    cout << "\nHasil penjumlahan=\n ";
    mPrint1(C, Row_A, Clm_A, "C");
}

//diagonal matriks
void mDiag(){
    if (!mExist) {
        cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
        return;
        }
    cout << "\nndiagonal matriks A\n";
    if (Row_A != Clm_A){
        cout << "Matriks A bukan matriks persegi (" << Row_A << "x" << Clm_A << ").\n";
        cout << "Menampilkan: " << min(Row_A, Clm_A) << " diagonal.\n";
    }

    int batas= min(Row_A, Clm_A);
    cout << "Diagonal: ";
    for (int i=0; i < batas; i++){
        cout << A[i][i] << (i < batas-1 ? " " : "\n " );
    }

//posisi diagonal
    cout <<"Posisi diagonal dalam matriks: \n";
    for (int i=0; i < Row_A; i ++){
        cout << "[";
        for (int j=0; j < Clm_A; j++){
            if (i==j)
                cout << setw(5) << A[i][j] << "*";
                else 
                cout << setw(5) << A[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "nb: * adalah elemen diagonal.\n";
}
//Lower triangle
void mL (){
    if (!mExist) {
    cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
    return;
    }

    cout << "\nMatriks segitiga bawah: \n";
    cout << "Elemen indeks baris >= indeks kolom, lainnya 0\n";

    for (int i=0; i < Row_A; i++){
        cout << "[";
        for (int j=0; j < Clm_A; j++){
            if (i >= j)
            cout << setw(5) << A[i][j];
            else
            cout << setw(5) << 0;
        }
        cout << " ]\n";
    }
}

//Upper triangle
void mU (){
    if (!mExist) {
    cout << "\nMatriks belum dibuat! Silahkan buat dahulu.\n";
    return;
    }

    cout << "\nMatriks segitiga atas: \n";
    cout << "Elemen indeks baris <= indeks kolom, lainnya 0\n";

    for (int i=0; i < Row_A; i++){
        cout <<  "[";
        for (int j=0; j < Clm_A; j++){
            if (i <= j)
            cout << setw(5) << A[i][j];
            else
            cout << setw(5) << 0;
        }
        cout << " ]\n";
    }
}

//Tampilan menu
void view(){
    cout << "\n       Program Operasi Matriks        \n";
    cout << "1. Buat matriks\n";
    cout << "2. Tampilkan matriks\n";
    cout << "3. Penjumlahan matriks\n";
    cout << "4. Perkalian matriks\n";
    cout << "5. Diagonal matriks\n";
    cout << "6. Segitiga bawah matriks\n";
    cout << "7. Segitiga atas matriks\n";
    cout << "8. Keluar\n";
    cout << "Status matriks: " << (mExist ? "[Sudah dibuat]\n" : "[Belum dibuat]\n");
    cout << "Pilihan anda: ";
} 
//main
int main (){
    int pilihan;

    do {
        view();
        cin >> pilihan;

        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Peringatan, angka yang anda masukkan tidak valid. Masukkan angka 1-8.";
            continue;
        }

    switch(pilihan){
        case 1: mCreate(); break;
        case 2: mShow(); break;
        case 3: mAdd(); break;
        case 4: mMult(); break;
        case 5: mDiag(); break;
        case 6: mL(); break;
        case 7: mU(); break;
        case 8: 
            cout << "\nProgram selesai. Terima kasih!\n";
            break;
        default : 
        cout << "Peringatan, angka yang anda masukkan tidak valid. Masukkan angka 1-8.";
    }
    }while (pilihan != 8);
return 0;
}