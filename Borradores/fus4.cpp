#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <windows.h>

// PROTOTIPO
void gotoxy(int x, int y);

int main()
{
    // DOS VARIABLES PARA LA POSICION AL ENVIAR LA FUNCION
    int x = 0, y = 0;

    // Generación de la matriz aleatoria de 5x5
    int matrix[5][5];
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    // Establecer las coordenadas iniciales del asterisco
    x = 0;
    y = 4;

    int movements = 0;
    bool generateNewMatrix = false;
    bool hideMatrix = false;

    // ESPERAMOS A QUE LA TECLA SEA PRESIONADA
    while (true)
    {
        // AGREGAMOS UN INTERVALO O UNA PAUSA PARA QUE EL BUCLE NO CORRA RAPIDO
        Sleep(100);

        // IZQUIERDA
        if (GetAsyncKeyState(0x25) && x > 0)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // MODIFICAMOS LA POSICION
            x--;

            movements++;
            generateNewMatrix = true;
        }

        // DERECHA
        if (GetAsyncKeyState(0x27) && x < 4)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // MODIFICAMOS LA POSICION
            x++;

            movements++;
            generateNewMatrix = true;
        }

        // ARRIBA
        if (GetAsyncKeyState(0x26) && y > 0)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // MODIFICAMOS LA POSICION
            y--;

            movements++;
            generateNewMatrix = true;
        }

        // ABAJO
        if (GetAsyncKeyState(0x28) && y < 4)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // MODIFICAMOS LA POSICION
            y++;

            movements++;
            generateNewMatrix = true;
        }

        if (movements >= 2 && generateNewMatrix)
        {
            if (movements % 2 == 1)
            {
                // Borrar la impresión de los valores de la matriz
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        gotoxy(j, i);
                        printf("? ");
                    }
                }
                hideMatrix = true;
            }
            else
            {
                if (hideMatrix)
                {
                    // Mostrar los nuevos valores de la matriz en las coordenadas iniciales
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            gotoxy(j, i);
                            printf("%d ", matrix[i][j]);
                        }
                    }
                    hideMatrix = false;
                }

                // Generar nuevos elementos aleatorios para la matriz
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        matrix[i][j] = rand() % 10;
                    }
                }
            }

            generateNewMatrix = false;
        }

        // MANDAMOS LA NUEVA POSICION
        gotoxy(x, y);
        printf("*");
    }

    return 0;
}

void gotoxy(int x, int y)
{
    // CONTROLADOR PARA NUESTRA CONSOLA
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

    // ESTRUCTURA PARA LAS CORDENADAS
    COORD pos;
    pos.X = x;
    pos.Y = y;

    // SETEAMOS LA POSICION EN NUESTRA CONSOLA
    SetConsoleCursorPosition(consola, pos);
}

