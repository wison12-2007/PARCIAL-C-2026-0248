#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 100

int main() {
    int N, M, L, U;
    int matriz[MAXN][MAXM];
    int i, j;

    // Lectura de dimensiones y parámetros
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }
    if (N <= 0 || M <= 0 || N > MAXN || M > MAXM) {
        printf("ERROR\n");
        return 0;
    }

    // Lectura de la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    // Variables para resultados
    int eventosFila[MAXN] = {0};
    int impactoFila[MAXN] = {0};
    int rachaFila[MAXN] = {0};
    int inicioFila[MAXN] = {0};
    int eventosCol[MAXM] = {0};

    // Procesar cada fila
    for (i = 0; i < N; i++) {
        int sumaFila = 0;
        for (j = 0; j < M; j++) sumaFila += matriz[i][j];
        double promedio = (double)sumaFila / M;

        int rachaActual = 0, inicioActual = 0;
        int mejorRacha = 0, mejorInicio = 0;

        for (j = 0; j < M; j++) {
            int x = matriz[i][j];
            // Regla: M*x - SF >= M*L && x >= U
            if (M * x - sumaFila >= M * L && x >= U) {
                int impacto = M * x - sumaFila + 1;
                eventosFila[i]++;
                impactoFila[i] += impacto;
                eventosCol[j]++;

                // Racha
                if (rachaActual == 0) inicioActual = j + 1; // índice humano
                rachaActual++;
                if (rachaActual > mejorRacha) {
                    mejorRacha = rachaActual;
                    mejorInicio = inicioActual;
                }
            } else {
                rachaActual = 0;
            }
        }
        rachaFila[i] = mejorRacha;
        inicioFila[i] = mejorInicio;
    }

    // Selección de fila prioritaria
    int filaPrioridad = 0;
    for (i = 1; i < N; i++) {
        if (rachaFila[i] > rachaFila[filaPrioridad] ||
            (rachaFila[i] == rachaFila[filaPrioridad] && impactoFila[i] > impactoFila[filaPrioridad]) ||
            (rachaFila[i] == rachaFila[filaPrioridad] && impactoFila[i] == impactoFila[filaPrioridad] && eventosFila[i] > eventosFila[filaPrioridad]) ||
            (rachaFila[i] == rachaFila[filaPrioridad] && impactoFila[i] == impactoFila[filaPrioridad] && eventosFila[i] == eventosFila[filaPrioridad] && i < filaPrioridad)) {
            filaPrioridad = i;
        }
    }

    // Selección de columna destacada
    int colDestacada = 0;
    for (j = 1; j < M; j++) {
        if (eventosCol[j] > eventosCol[colDestacada] ||
            (eventosCol[j] == eventosCol[colDestacada] && j < colDestacada)) {
            colDestacada = j;
        }
    }

    // Salida
    for (i = 0; i < N; i++) {
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
               i + 1, eventosFila[i], impactoFila[i], rachaFila[i], inicioFila[i]);
    }
    printf("COLUMNAS");
    for (j = 0; j < M; j++) {
        printf(" %d", eventosCol[j]);
    }
    printf("\nPRIORIDAD %d\n", filaPrioridad + 1);
    printf("COLUMNA %d\n", colDestacada + 1);

    return 0;
}
