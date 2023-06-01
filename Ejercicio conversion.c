#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
void bin_a_dec(char *dir_bin, char *dir_dec) { // Funcion para hacer la conversion de binario a decimal
    char *t;
    int VD;// se declara la variable del Valor decimal
    int ind = 0; // Contador

    t = strtok(dir_bin, " ");
    while (t != NULL) {
        VD = strtol(t, NULL, 2);
        sprintf(dir_dec + ind, "%d.", VD);
        ind += strlen(dir_dec + ind);
        t = strtok(NULL, " ");
    }

    dir_dec[strlen(dir_dec) - 1] = '\0';
}

void bin_a_hex(char *dir_bin, char *dir_hexa) {// Funcion para hacer la conversion de binario a hexadecimal
    char *t;
    int VD;// se declara la variable del Valor decimal
    int ind = 0; // Contador

    t = strtok(dir_bin, " ");
    while (t != NULL) {
        VD = strtol(t, NULL, 2);
        sprintf(dir_hexa + ind, "%02X:", VD);
        ind += strlen(dir_hexa + ind);
        t = strtok(NULL, " ");
    }

    dir_hexa[strlen(dir_hexa) - 1] = '\0';
}

unsigned long long factor(int n) { // funcion para multiplicar el dato empezando desde 1 hasta llegar a n 
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

unsigned long long cal_per(int n, int r) { // funcion para calcular la permutacion
    return factor(n) / factor(n - r);
}

unsigned long long cal_com(int n, int r) {// funcion para calcular la combinacion
    return factor(n) / (factor(r) * factor(n - r));
}

int main() {
    int opcion;
    char dir_bin[128];
    char con_dir[40];
    int n, r;
    unsigned long long result;

    printf("Seleccione la opcion que desee:\n");
    printf("1. Convertir una direccion IPv4 a decimal\n");
    printf("2. Convertir una direccion IPv6 a hexadecimal\n");
    printf("3. Realizar un calculo de permutacion\n");
    printf("4. Realizar un calculo de combinacion\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    getchar();  // Clear newline character from buffer

    if (opcion == 1 || opcion == 2) {
        printf("Ingrese la direccion en formato binario: ");
        fgets(dir_bin, sizeof(dir_bin), stdin);

        if (opcion == 1) {
            bin_a_dec(dir_bin, con_dir);
            printf("Direccion IPv4 en formato decimal: %s\n", con_dir);
        } else if (opcion == 2) {
            bin_a_hex(dir_bin, con_dir);
            printf("Direccion IPv6 en formato hexadecimal: %s\n", con_dir);
        }
    } else if (opcion == 3 || opcion == 4) {
        printf("Ingrese el valor de n: ");
        scanf("%d", &n);
        printf("Ingrese el valor de r: ");
        scanf("%d", &r);

        if (opcion == 3) {
            result = cal_per(n, r);
           printf("Permutaciones: %I64u\n", result);
        } else if (opcion == 4) {
            result = cal_com(n, r);
            printf("Combinaciones: %I64u\n", result);
        }
    } else {    
        printf("Opcion invalida. Saliendo del programa.\n");
    }

    return 0;
}