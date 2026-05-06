// Inclusión de librerias
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

// Macro para establecer dimension maxima de las matrices, ejercicio 1.
#define DIMENSION_MAX 2
// Macro para establecer dimension maxima de los strings, ejercicio 2.
#define MAX_STR 20

/**
 * Utilízada para ejecutar el ejercicio 1.
 */
void ejercicio1();
/**
 * Utilízada para ejecutar el ejercicio 2.
 */
void ejercicio2();
/**
 * Utilízada para ejecutar el ejercicio 3.
 */
void ejercicio3();
/**
 * Utilízada para ejecutar el ejercicio 4.
 */
void ejercicio4();
/**
 * Menú de la Aplicación.
 */
int menu();
/**
 * Menú del ejercicio 3.
 */
int menu_ordenamiento();
/**
 * Menú del ejercicio 4.
 */
int menu_conversiones();
/**
 * Función para obtener las matrices por consola.
 * @param matriz
 */
void obtener_matriz(int matriz[2][2]);
/**
 * Utilízada para imprimir matrices.
 * @param matriz
 */
void imprimir_matriz(int matriz[2][2]);
/**
 * Utilízada para realizar la suma de dos matrices.
 * @param matriz1, matriz2
 */
void sumar_matrices(int matriz1[2][2], int matriz2[2][2]);
/**
 * Utilízada para transponer 2 matrices dadas.
 * @param matriz1, matriz2
 */
void matriz_transpuesta(int matriz1[2][2], int matriz2[2][2]);
/**
 * Utilízada para transponer una matriz dada.
 * @param matriz, matriz_resultante
 */
void transponer_matriz(int matriz[2][2],int matriz_resultante[2][2]);
/**
 * Utilízada para cargar palabras en el ejercicio 3.
 * @param palabra
 */
void cargar_palabra(char palabra[5]);
/**
 * Utilízada para ordenar palabras en el ejercicio 3.
 * @param palabras
 */
void ordenar_palabras(char palabras[5][MAX_STR], char opcion[5]);
/**
 * Utilízada para imprimir las palabras ordenadas en el ejercicio 3.
 * @param palabras
 */
void imprimir_palabras(char palabras[5][MAX_STR]);

/**
 * Structs utilizadas para el ejercicio 2.
 */
typedef struct puesto {
    char nombre[MAX_STR];
    char estudios[MAX_STR];
    int sueldo;
} TPuesto;

typedef struct empleado {
    int codigo_empleado;
    char nombre[MAX_STR];
    char apellidos[MAX_STR];
    TPuesto puesto;
} TEmpleado;

/**
 * Utilízada para la carga de empleado del ejercicio 2.
 * @param empleado
 */
void cargar_empleado(TEmpleado *empleado);
/**
 * Utilízada para la carga de puesto del ejercicio 2.
 * @param puesto
 */
void cargar_puesto(TPuesto *puesto);

int menu() {
    int opcion;
    printf("Menú: \n" \
              "1 - Ejecutar ejercicio 1 \n" \
              "2 - Ejecutar ejercicio 2 \n" \
              "3 - Ejecutar ejercicio 3 \n" \
              "4 - Ejecutar ejercicio 4 \n" \
              "0 - Salir \n" \
              "Ingrese una opción:"); \
    scanf("%i", &opcion);
    return opcion;
}

// Funciones del ejercicio 1
void ejercicio1() {
    int matriz1[DIMENSION_MAX][DIMENSION_MAX];
    int matriz2[DIMENSION_MAX][DIMENSION_MAX];
    printf("Ingresé los valores de la primera matriz 2x2:");
    obtener_matriz(matriz1);
    printf("Ingresé los valores de la segunda matriz 2x2:");
    obtener_matriz(matriz2);
    sumar_matrices(matriz1, matriz2);
    matriz_transpuesta(matriz1, matriz2);
}

void obtener_matriz(int matriz[DIMENSION_MAX][DIMENSION_MAX]) {
    for (int i = 0; i< DIMENSION_MAX; ++i) {
        for (int j = 0; j < DIMENSION_MAX; ++j) {
            // Usamos & para obtener la dirección de memoria de cada celda
            scanf("%i", &matriz[i][j]);
        }
    }
    imprimir_matriz(matriz);
}

void imprimir_matriz(int matriz[DIMENSION_MAX][DIMENSION_MAX]) {
    for (int i = 0; i < DIMENSION_MAX; ++i) {
        printf("|");
        for (int j = 0; j < DIMENSION_MAX; ++j) {
            // Agregamos %i para mostrar el valor y un espacio para separar números
            printf(" %i ", matriz[i][j]);
        }
        printf("|\n"); // Salto de línea al terminar cada fila
    }
}

void sumar_matrices(int matriz1[DIMENSION_MAX][DIMENSION_MAX], int matriz2[DIMENSION_MAX][DIMENSION_MAX]) {
    int matriz_resultante[DIMENSION_MAX][DIMENSION_MAX];
    for (int i = 0; i < DIMENSION_MAX; ++i) {
        for (int j = 0; j < DIMENSION_MAX; ++j) {
            matriz_resultante[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("\nResultado de la suma de A y B:\n");
    imprimir_matriz(matriz_resultante);
}

void matriz_transpuesta(int matriz1[DIMENSION_MAX][DIMENSION_MAX], int matriz2[DIMENSION_MAX][DIMENSION_MAX]) {
    int matriz_resultante1[DIMENSION_MAX][DIMENSION_MAX];
    int matriz_resultante2[DIMENSION_MAX][DIMENSION_MAX];
    // Transponer Matriz 1
    transponer_matriz(matriz1, matriz_resultante1);
    printf("\nTranspuesta de A:\n");
    imprimir_matriz(matriz_resultante1);
    // Transponer Matriz 2
    transponer_matriz(matriz2, matriz_resultante2);
    printf("\nTranspuesta de B:\n");
    imprimir_matriz(matriz_resultante2);
}

void transponer_matriz(int matriz[DIMENSION_MAX][DIMENSION_MAX],int matriz_resultante[DIMENSION_MAX][DIMENSION_MAX]) {
    for (int i = 0; i < DIMENSION_MAX; ++i) {
        for (int j = 0; j < DIMENSION_MAX; ++j) {
            matriz_resultante[j][i] = matriz[i][j];
        }
    }
}

// Funciones del ejercicio 2
void ejercicio2() {
    // Instancio los structs creados.
    TPuesto puesto;
    TEmpleado empleado;
    cargar_empleado(&empleado);
    cargar_puesto(&puesto);
    empleado.puesto = puesto;
    printf("\nLos datos del empleado son: \n");
    printf("Nombre: %s Apellidos: %s Código de empleado: %i \n", empleado.nombre, empleado.apellidos, empleado.codigo_empleado);
    printf("Nombre: %s Estudios: %s Sueldo: %i \n", empleado.puesto.nombre, empleado.puesto.estudios, empleado.puesto.sueldo);
}

void cargar_empleado(TEmpleado *empleado) {
    char nombre[MAX_STR];
    char apellido[MAX_STR];
    printf("Ingresé los datos del empleado:\n");
    printf("Ingresé el Nombre:");
    scanf("%s", nombre);
    printf("Ingresé los Apellidos:");
    scanf("%s", apellido);
    printf("Ingresé el Código del Empleado:");
    scanf("%i", &empleado->codigo_empleado);
    //Mostramos la información del empleado.
    strcpy(empleado->nombre, nombre);
    strcpy(empleado->apellidos, apellido);
}

void cargar_puesto(TPuesto *puesto) {
    char nombre[MAX_STR];
    char estudios[MAX_STR];
    printf("Ingresé los datos del puesto:\n");
    printf("Ingresé el Nombre del puesto:");
    scanf("%s", nombre);
    printf("Ingresé el Estudio:");
    scanf("%s", estudios);
    printf("Ingresé el Sueldo:");
    scanf("%i", &puesto->sueldo);
    //Mostramos la información del empleado.
    strcpy(puesto->nombre, nombre);
    strcpy(puesto->estudios, estudios);
}

// Funciones del ejercicio 3
void ejercicio3() {
    char palabras[5][MAX_STR];
    for (int i = 0; i < 5; i++) {
        cargar_palabra(palabras[i]);
        if (!isalpha(palabras[i][0])) {
            printf("Error, se debe ingresar una palabra. \n");
            i=i-1;
        }
    }
    int OPCION;
    do {
        OPCION = menu_ordenamiento();
        switch (OPCION) {
            case 0: {
                printf("Hasta luego! \n");
                break;;
            }
            case 1: {
               ordenar_palabras(palabras, "DESC");
               printf("\nLa lista de palabras ordenada en orden decreciente es: \n");
               imprimir_palabras(palabras);
               break;
            }
            case 2: {
               ordenar_palabras(palabras, "ASC");
               printf("\nLa lista de palabras ordenada en orden creciente es: \n");
               imprimir_palabras(palabras);
               break;
            }
             default: {
               printf("Opción no valida, intente de nuevo.\n");
               break;;
            }
        }
    } while (OPCION != 0);
}

int menu_ordenamiento() {
    int opcion;
    printf("Opciones de ordenamiento: \n" \
              "1 - Descendente \n" \
              "2 - Ascendente \n" \
              "0 - Salir \n" \
              "Ingrese una opción:"); \
    scanf("%i", &opcion);
    return opcion;
}

void cargar_palabra(char *palabra) {
    printf("Ingresé una palabra:");
    scanf("%s", palabra);
}

void ordenar_palabras(char palabras[5][MAX_STR], char opcion[5]) {
    char temporal[MAX_STR];
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (strcmp(opcion,"ASC") == 0) {
                 if (strcmp(palabras[j], palabras[j + 1]) > 0) {
                     strcpy(temporal, palabras[j]);
                     strcpy(palabras[j], palabras[j + 1]);
                     strcpy(palabras[j + 1], temporal);
              }
            }
             if (strcmp(opcion,"DESC") == 0) {
                if (strcmp(palabras[j], palabras[j + 1]) < 0) {
                    strcpy(temporal, palabras[j]);
                    strcpy(palabras[j], palabras[j + 1]);
                    strcpy(palabras[j + 1], temporal);
                }
            }
        }
    }
}

void imprimir_palabras(char palabras[5][MAX_STR]) {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", palabras[i]);
    }
}

// Funciones del ejercicio 4
void ejercicio4() {
    int OPCION;
    do {
        OPCION = menu_conversiones();
        switch (OPCION) {
            case 0: {
                printf("Hasta luego! \n");
                break;;
            }
            case 1: {
                break;
            }
            case 2: {

                break;
            }
            default: {
                printf("Opción no valida, intente de nuevo.\n");
                break;;
            }
        }
    } while (OPCION != 0);
}

int menu_conversiones() {
    int opcion;
    printf("Opciones de conversión: \n" \
              "1 - Convertir cartesianas a polares \n" \
              "2 - Convertir polares a cartesianas \n" \
              "0 - Salir \n" \
              "Ingrese una opción:"); \
    scanf("%i", &opcion);
    return opcion;
}



// Función Main
int main(void) {
    // Seteamos en la consola UTF8 para poder mostrar mensajes con tilde
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    printf("Bienvenido! \n");
    while (true) {
        int OPCION = menu(); // Declaramos la variable que guardara la opción ingresada
        switch (OPCION) {
            // Opción por defecto en caso que el usuario ingrese una opción no valida
            case 0:
                printf("Hasta Luego!");
                return 0;
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            default:
                printf("Opción no valida, intente de nuevo.\n");
                break;
        }
    }
}