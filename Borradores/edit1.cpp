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
    int tmovements = 0;
    bool generateNewMatrix = false;
    bool hideMatrix = false;
    bool allowMovement = true;

    // Página inicial
 	system("color 8F");
    std::cout << "Bienvenido al juego de laberinto de operaciones." << std::endl;
    std::cout << "¿Deseas jugar? (S/N): ";
    char choice;
    std::cin >> choice;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // Cambia el color de texto a rojo
    system("cls");
    if (choice != 'S' && choice != 's') {
        std::cout << "¡Gracias por tu visita! ¡Hasta luego!" << std::endl;
        return 0;
    }
	std::cout << "Estas son las instrucciones" << std::endl;
    std::cout << "¿Listo? ¿Deseas continuar? (S/N): ";
    system("color 8F");
    SetConsoleTextAttribute(hConsole, 7);
    char choice1;
    std::cin >> choice1;
    system("cls");
    if (choice != 'S' && choice1 != 's') {
        std::cout << "¡Gracias por tu visita! ¡Hasta luego!" << std::endl;
        return 0;
    }

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
            tmovements++;
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
            tmovements++;
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
            tmovements++;
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
            tmovements++;
            generateNewMatrix = true;
        }
        if(tmovements==17){
            printf("\n\n\n\nHaz realizado 8 intentos. Reinicia el juego ");
            return 0;
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
                            if (i == y - 1 && (j == x - 1 || j == x || j == x + 1)) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  // Color amarillo
                                printf("%d ", matrix[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y + 1 && (j == x - 1 || j == x || j == x + 1)) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  // Color amarillo
                                printf("%d ", matrix[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y && j == x + 1) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
                                printf("%d ", matrix[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y && j == x - 1) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);  // Color rojo
                                printf("%d ", matrix[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else {
                                printf("%d ", matrix[i][j]);
                            }
                        }
                    }
                    hideMatrix = false;
                }

                // Calcular la operación especificada
                int answer=0;
                if ((x == 0)&&(y==0))
                {
                   answer = 0;
                }
                else if (x == 0)
                {
                    // La posición del asterisco está en la primera columna de la matriz
                    answer = (matrix[y - 1][x] + matrix[y - 1][x + 1]) * matrix[y][x + 1];
                }
                 else if (x == 4)
                {
                    // La posición del asterisco está en la primera columna de la matriz
                    printf("\n\n\n\n ¡FELICIDADES HAZ LLEGADO A LA META! Reinicia el juego ");
                    return 0;
                }
				
                else if (y == 4)
                {
                    // La posición del asterisco está en la última fila de la matriz
                    answer = (matrix[y - 1][x - 1] + matrix[y - 1][x] + matrix[y - 1][x + 1]) * matrix[y][x + 1];
                }
                else if (y == 0)
                {
                    // La posición del asterisco está en la primera fila de la matriz
                    answer = (matrix[y + 1][x - 1] + matrix[y + 1][x] + matrix[y + 1][x + 1]) * matrix[y][x - 1];
                }
                else
                {
                    // La posición del asterisco no está en la primera columna de la matriz
                    int sum1 = (matrix[y - 1][x - 1] + matrix[y - 1][x] + matrix[y - 1][x + 1]) * matrix[y][x + 1];
                    int sum2 = (matrix[y + 1][x - 1] + matrix[y + 1][x] + matrix[y + 1][x + 1]) * matrix[y][x - 1];
                    answer = sum1 - sum2;
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
                printf("\n¿Cual es el resultado de la operacion? ");

                int userAnswer=0;
                std::cin >> userAnswer;

                if (userAnswer == answer)
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
                    allowMovement = true;  // Permitir el movimiento nuevamente
                    movements = 0;  // Reiniciar el número de movimientos
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

    // REGRESAMOS LA CORDENADA
    SetConsoleCursorPosition(consola, pos);
}

