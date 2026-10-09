# Parcial de algoritmos en C

- Estudiante: WILSON MANUEL PEREZ CELESTE 
- Matrícula: 20260248
- Reto asignado: Reto 15 - Comedor: demanda superior al promedio propio

## Descripción
El programa analiza matrices de consumo/raciones en comedores ($N \times M$)[cite: 11]. Evalúa cada posición $(i, j)$ para determinar si constituye un evento según la regla particular del Reto 15: demanda al menos $L$ unidades por encima del promedio de su fila ($M \cdot x - SF \ge M \cdot L$) y con asistencia mayor o igual que el límite superior ($x \ge U$)[cite: 11].

Para cada entidad/fila calcula la cantidad de eventos, la suma acumulada de impactos ($M \cdot x - SF + 1$), la mayor racha de eventos consecutivos y el índice de inicio de la primera racha máxima[cite: 11]. Construye un vector consolidado de eventos por columna y determina la fila prioritaria y la columna destacada aplicando los criterios de desempate indicados[cite: 11].

## Compilación y ejecución
- Sistema operativo: Windows 11 (VS Code / CMD / Git Bash)
- Compilador: GCC (MinGW / C11)

Comandos utilizados:
```cmd
gcc -std=c11 -Wall -Wextra 20260248.c -o a.exe
a.exe < pruebas\caso_01.in