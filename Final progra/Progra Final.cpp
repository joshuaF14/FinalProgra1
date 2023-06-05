#include <iostream>
#include <vector>
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

    int filas = 7;
    int columnas = 7;

   // Crear la matriz con bordes en cada casilla
    int matriz[7][7];

    // Generar valores aleatorios del 1 al 9 para el interior de la matriz
    srand(time(NULL));
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            matriz[i][j] = (rand() % 9) + 1;
        }
    }

    // Rellenar los bordes con el valor deseado
    for (int i = 0; i < filas; i++) {
        matriz[i][0] = 0; // Borde izquierdo
        matriz[i][columnas - 1] = 0; // Borde derecho
    }
    for (int j = 0; j < columnas; j++) {
        matriz[0][j] = 0; // Borde superior
        matriz[filas - 1][j] = 0; // Borde inferior
    }


    // Establecer las coordenadas iniciales del asterisco
    x = 1;
    y = 5;

    int prevX1 = x;
    int prevY1 = y;
    int prevX2 = x;
    int prevY2 = y;
    int movements = 0;
    int tmovements = 0;
    bool NewMatriz = false;
    bool hideMatrix = false;
    bool allowMovement = true;

    // Página inicial
 	system("color 8F");
    std::cout << "Bienvenido al juego de laberinto de operaciones." << std::endl;
    std::cout << "¿Deseas jugar? (S/N): ";
    char elec;
    std::cin >> elec;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // Cambia el color de texto a rojo
    system("cls");
    if (elec != 'S' && elec != 's') {
        std::cout << "¡Gracias por ejecutar el código! ¡Hasta luego!" << std::endl;
        return 0;
    }
	std::cout << "Estas son las instrucciones: \n" << std::endl;
	std::cout << "1. El objetivo del juego consiste en llegar a la meta, decir la ultima columna" << std::endl;
	std::cout << "2. Puedes mover es asterisco en cualquier sentido con las flechas del teclado" << std::endl;
	std::cout << "3. A cada dos movimientos el asterisco se dentendra y deberas dar el resultado de la siguiente operacion" << std::endl;
	std::cout << "4. Suma los números en amarillo y multiplicalos por el número en rojo" << std::endl;
	std::cout << "5. Suma los números en verde y multiplicalos por el número en celeste" << std::endl;
	std::cout << "6. Resta la primera suma con la segunda suma e ingresa el valor en el espacio indicado" << std::endl;
	std::cout << "7. Si alguno de los numeros de color no aparece, asume que su valor es cero" << std::endl;
	std::cout << "8. Si tu respuesta es correcta, entonces podrás seguir avanzando" << std::endl;
	std::cout << "9. Si tu respuesta no es correcta, entonces retrocedes a tu posición anterior" << std::endl;
	std::cout << "10. Solamente tienes 8 intentos para llegar a la meta" << std::endl;
    std::cout << "\n Listo?  Deseas continuar? (S/N): ";
    system("color 8F");
    SetConsoleTextAttribute(hConsole, 7);
    char elec1;
    std::cin >> elec1;
    system("cls");
     
    if (elec1 != 'S' && elec1 != 's') {
    	SetConsoleTextAttribute(hConsole, 12); // Cambia el color de texto a rojo
        std::cout << "¡Gracias por tu visita! ¡Hasta luego!" << std::endl;
        return 0;
    }else{
    	
    	std::cout << "             ¡Mucha Suerte!" << std::endl;
    	std::cout << "             Recuerda borrar tu respuesta anterior antes de ingresar una nueva" << std::endl;
	}

    // ESPERAMOS A QUE LA TECLA SEA PRESIONADA
    while (true)
    {
        // AGREGAMOS UN INTERVALO O UNA PAUSA PARA QUE EL BUCLE NO CORRA RAPIDO
        Sleep(100);

        // IZQUIERDA
        if (GetAsyncKeyState(VK_LEFT) && x > 1 && allowMovement)
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
            NewMatriz = true;
        }

        // DERECHA
        if (GetAsyncKeyState(VK_RIGHT) && x < 5 && allowMovement)
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
            NewMatriz = true;
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
            NewMatriz = true;
        }

        // ABAJO
        if (GetAsyncKeyState(VK_DOWN) && y < 5 && allowMovement)
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
            NewMatriz = true;
        }
        if(tmovements==17){
            printf("\n\n\n\nHaz realizado 8 intentos. Reinicia el juego ");
            return 0;
        }
        
        if (movements >= 1 && NewMatriz)
        {
            if (movements % 2 == 1)
            {
                if (!hideMatrix)
                {
                    // Ocultar la matriz
                    for (int i = 0; i < 7; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                        	
                            gotoxy(j, i);
                            if (j == 0 || j == columnas - 1) {
                printf("| ");
            }
			else if (matriz[i][j] == 0) {
                printf("-- ");
            } else {
                            printf("? ");
                        }
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
                    for (int i = 0; i < 7; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            gotoxy(j, i);
            if (j == 0 || j == columnas - 1) {
                printf("| ");
            }
			else if (matriz[i][j] == 0) {
                printf("-- ");
            } 
                     
                            else if (i == y - 1 && (j == x - 1 || j == x || j == x + 1)) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  // Color amarillo
                                printf("%d ", matriz[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y + 1 && (j == x - 1 || j == x || j == x + 1)) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  // Color amarillo
                                printf("%d ", matriz[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y && j == x + 1) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // Color rojo
                                printf("%d ", matriz[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else if (i == y && j == x - 1) {
                                // Imprimir en color diferente
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);  // Color rojo
                                printf("%d ", matriz[i][j]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // Restaurar color original
                            }
                            else {
                            	 
                                printf("%d ", matriz[i][j]);
                            }
                        }
                    }
                    hideMatrix = false;
                }

                // Calcular la operación especificada
                int answer=0;
                if ((x == 1)&&(y==1))
                {
                   answer = 0;
                }
                else if (x == 1)
                {
                    // La posición del asterisco está en la primera columna de la matriz
                    answer = (matriz[y - 1][x] + matriz[y - 1][x + 1]) * matriz[y][x + 1];
                }
                 else if (x == 5)
                {
                	system("color 8F");
                    // La posición del asterisco está en la ultima columna de la matriz
                    printf("\n\n\n\n\n ¡FELICIDADES HAZ LLEGADO A LA META! Reinicia el juego para volver a jugar. ");
                    return 0;
                }
				
                else if (y == 5)
                {
                    // La posición del asterisco está en la última fila de la matriz
                    answer = (matriz[y - 1][x - 1] + matriz[y - 1][x] + matriz[y - 1][x + 1]) * matriz[y][x + 1];
                }
                else if (y == 1)
                {
                    // La posición del asterisco está en la primera fila de la matriz
                    answer = (matriz[y + 1][x - 1] + matriz[y + 1][x] + matriz[y + 1][x + 1]) * matriz[y][x - 1];
                }
                else
                {
                    // La posición del asterisco no está en la primera columna de la matriz
                    int sum1 = (matriz[y - 1][x - 1] + matriz[y - 1][x] + matriz[y - 1][x + 1]) * matriz[y][x + 1];
                    int sum2 = (matriz[y + 1][x - 1] + matriz[y + 1][x] + matriz[y + 1][x + 1]) * matriz[y][x - 1];
                    answer = sum1 - sum2;
                }

                // Generar nuevos elementos aleatorios para la matriz
                 srand(time(NULL));
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            matriz[i][j] = (rand() % 9) + 1;
        }
    }

    // Rellenar los bordes con el valor deseado
    for (int i = 0; i < filas; i++) {
        matriz[i][0] = 0; // Borde izquierdo
        matriz[i][columnas - 1] = 0; // Borde derecho
    }
    for (int j = 0; j < columnas; j++) {
        matriz[0][j] = 0; // Borde superior
        matriz[filas - 1][j] = 0; // Borde inferior
    }

                // Detener el movimiento del asterisco y solicitar respuesta
                allowMovement = false;
                printf("\n\n\n¿Cual es el resultado de la operacion? ");

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

            NewMatriz = false;
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


