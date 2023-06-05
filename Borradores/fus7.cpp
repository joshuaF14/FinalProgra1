#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
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

    int prevX1 = x;
    int prevY1 = y;
    int prevX2 = x;
    int prevY2 = y;
    int movements = 0;
    bool generateNewMatrix = false;
    bool hideMatrix = false;
    bool allowMovement = true;

    // ESPERAMOS A QUE LA TECLA SEA PRESIONADA
    while (true)
    {
        // AGREGAMOS UN INTERVALO O UNA PAUSA PARA QUE EL BUCLE NO CORRA RAPIDO
        Sleep(100);

        // IZQUIERDA
        if (GetAsyncKeyState(VK_LEFT) && x > 0 && allowMovement)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // GUARDAMOS LA POSICION ACTUAL
            prevX2 = prevX1;
            prevY2 = prevY1;
            prevX1 = x;
            prevY1 = y;

            // MODIFICAMOS LA POSICION
            x--;

            movements++;
            generateNewMatrix = true;
        }

        // DERECHA
        if (GetAsyncKeyState(VK_RIGHT) && x < 4 && allowMovement)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // GUARDAMOS LA POSICION ACTUAL
            prevX2 = prevX1;
            prevY2 = prevY1;
            prevX1 = x;
            prevY1 = y;

            // MODIFICAMOS LA POSICION
            x++;

            movements++;
            generateNewMatrix = true;
        }

        // ARRIBA
        if (GetAsyncKeyState(VK_UP) && y > 0 && allowMovement)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // GUARDAMOS LA POSICION ACTUAL
            prevX2 = prevX1;
            prevY2 = prevY1;
            prevX1 = x;
            prevY1 = y;

            // MODIFICAMOS LA POSICION
            y--;

            movements++;
            generateNewMatrix = true;
        }

        // ABAJO
        if (GetAsyncKeyState(VK_DOWN) && y < 4 && allowMovement)
        {
            // REGRESAMOS AL ANTERIOR ASTERISCO
            gotoxy(x, y);
            printf(" ");

            // GUARDAMOS LA POSICION ACTUAL
            prevX2 = prevX1;
            prevY2 = prevY1;
            prevX1 = x;
            prevY1 = y;

            // MODIFICAMOS LA POSICION
            y++;

            movements++;
            generateNewMatrix = true;
        }

        if (movements >= 1 && generateNewMatrix)
        {
            if (movements % 2 == 1)
            {
                if (!hideMatrix)
                {
                    // Ocultar la matriz
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
            }
            else
            {
                if (hideMatrix)
                {
                    // Mostrar la matriz
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

                // Detener el movimiento del asterisco y solicitar respuesta
                allowMovement = false;
                printf("\n¿Cuánto es 2 + 2? ");

                int answer;
                std::cin >> answer;

                if (answer == 4)
                {
                    // Respuesta correcta, reiniciar el número de movimientos y permitir el movimiento del asterisco nuevamente
                    allowMovement = true;
                    movements = 0;
                }
                else
                {
                    // Respuesta incorrecta, devolver al asterisco a la posición anterior a los dos movimientos previos
                    x = prevX2;
                    y = prevY2;
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

