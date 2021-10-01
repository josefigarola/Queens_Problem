// N QUEENS PROBLEM USING BACKTRACKING
// Autor: José Miguel Figarola Prado
// Este programa resuelve el problema de las reinas
// Un tablero de NxN con N reinas
// Las reinas se colocan en i,j posición del tablero
// No se pueden colocar si hay una en la misma fila, columna o diagonal

#include <iostream>
using namespace std;

const int N = 12; // Tamaño del tablero

// Funcion para imprimir la matriz del tablero
void printBoard(string board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

// Checar si las casillas son seguras para colocar reina
// En la fila y en la columna
// Checar las diagonales
// True = Se puede colocar la reina
// False = No se puede colocar la reina
bool isSafe(string board[N][N], int row, int col){
    // Checar misma columna
    for (int i = 0; i < col; i++) {
        if (board[row][i] == "Q") { // Si hay una Q (reina)
            return false; // No es seguro
        }
    }
    // Checar diagonal superior del lado izq
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (board[i][j] == "Q") { // Si hay una Q (reina)
            return false; // No es seguro
        }
    }
    // Checar diagonal inferior del lado derecha
    for (int i = row, j = col; i >= 0 && j < N; j++, i--) {
        if (board[i][j] == "Q") { // Si hay una Q (reina)
            return false; // No es seguro
        }
    }
    return true;
}

// Funcion recursiva qur ayuda a resolver
bool solveUtil(string board[N][N], int col){

    // Mejor de los casos
    if(col >= N){ //Si todas las reinas fueron colocadas
        cout << "Tablero completado" << endl;
        return true; // Se colocaron las reinas
    }

    for(int i = 0; i < N; i++){ // Checar cada fila de la columna
        if(isSafe(board,i,col)){
            board[i][col] = "Q"; // Colocar reina en el tablero
            // Recursividad en la columna siguiente
            if(solveUtil(board,col+1)){ // Colocar las reinas faltantes en las siguientes col
                return true; // Se colocaron laa reinas
            }else{ // Si no se puede colocar la siguiente reina
                board[i][col] = "0"; // Se quita la reina
            }
        }
    }

    return false; // No se puede colocar en ninguna fila de la columna
}

// Utilizar solveUtil (recursiva)
// True = tiene solucion y se imprime
// False = no tiene solucion
bool solve(string board[N][N]){

    if(!solveUtil(board,0)){ // Si no tiene solucion el tablero o hay un error
        cout << "No hay solución" << endl; // Algo salio mal
        return false;
    }
    printBoard(board); // El tablero si tiene solucion y se imprime
    return true;
}

// Funcion para crear el tablero con 0s
void createBoard(string board[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = "0"; // Rellenar el tablero de 0s
        }
    }
}

int main() {

    cout << "Problema de las Reinas" << endl;
    string board[N][N]; // Crear la matriz
    createBoard(board);

    cout << "Tablero incompleto" << endl;
    printBoard(board); // Imprimir el tablero con 0s

    solve(board); // Resolver el problema

    return 0;
}