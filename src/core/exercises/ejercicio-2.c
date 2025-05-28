#include <stdio.h>
#include "../../../include/core/exercises/ejercicios.h"

void ejercicio_2() 
{    
    // Declarando y definiendo
    int potencia = 0;
    int resultado = 2;

    // Pidiendo la potencia
    printf("\nIngrese la potencia a la que elevar el numero 2: ");
    fflush(stdin);
    scanf(" %d", &potencia);

    // Si la potencia es correcta, procede el programa principal
    if (potencia > 0)
    {   
        // Se multiplica 2 por si mismo hasta el numero ingresado
        for (int i = 1; i <= potencia; i++)
            resultado *= 2;

        // Mostrando
        printf("El resultado es: %d", resultado);
    }
    // De lo contrario se sale con un mensaje de error
    else
    {
        printf("La potencia es incorrecta");
    }

    system("pause");
    
}