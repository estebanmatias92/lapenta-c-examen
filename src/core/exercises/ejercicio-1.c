#include <stdio.h>
#include <string.h> // For strcmp()
#include <stdlib.h> // For system()
#include "../../../include/core/exercises/ejercicios.h"

// Define new data type.
struct Position {
	char name[30];
	double base_salary;
	int overtime_hours;
	float overtime_wage;
	float bonus;
	float discount;
	double total_salary;
};

// Create an alias for "struct Position" type
typedef struct Position Position;

// Headers
float get_overtime_wage(int seniority);
float get_bonus(int seniority);
double get_discount(Position position, int seniority);
double get_total_salary(Position position);
void show_salary_table_options(Position *positions, size_t size);

/*
	Get the extra hour wage corresponding to the years of work.
*/
float get_overtime_wage(int seniority)
{
	if (seniority < 1)
		return 750;
	else if (seniority >= 1 && seniority < 5)
		return 900;
	else if (seniority >= 5 && seniority < 10)
		return 1200;
	else if (seniority >= 10 && seniority < 20)
		return 1450;
	else 
		return 1500;
}

/*
	Get the bonus corresponding to the years of work.
*/
float get_bonus(int seniority)
{
	if (seniority < 1)
		return 2500;
	else if (seniority >= 1 && seniority < 5)
		return 3200;
	else if (seniority >= 5 && seniority < 10)
		return 3700;
	else if (seniority >= 10 && seniority < 20)
		return 4200;
	else 
		return 5350;
}

/*
	Obtain the percentage associated with the years of work.
*/
double get_discount(Position position, int seniority)
{
	// Temporary holder
	float discount_percentage = 0;

	if (seniority < 1)
		discount_percentage = 0.02; // %2 discount
	else if (seniority >= 1 && seniority < 5)
		discount_percentage = 0.05 ;
	else if (seniority >= 5 && seniority < 10)
		discount_percentage = 0.09;
	else if (seniority >= 10 && seniority < 20)
		discount_percentage = 0.12;
	else 
		discount_percentage = 0.15;

	return position.base_salary * discount_percentage;
}

/*
	Equation to obtain the final wage.
*/
double get_total_salary(Position position)
{
	return (position.base_salary - position.discount) + (position.overtime_wage * position.overtime_hours) + position.bonus;

}

/*
	Display the menu with every position available.
*/
void show_salary_table_options(Position *positions, size_t size)
{
	system("clear");

	for (size_t i = 0; i < size; i++)
	{		
		printf("\n(%i) %s", i + 1, positions[i].name);
	}

	printf("\n\n(0) Exit\n\n");
}



void ejercicio_1() 
{    
	// Exercise premise
	printf("Una empresa presenta la nomina de sueldos de sus empleados de la siguiente manera\n");
	printf("para cada uno de los distintos puestos que se detallan a continuacion: \n");
	printf("1-Cargo jerarquico\n");
	printf("2-Administrativo\n");
	printf("3-Maestranza\n");
	printf("Los sueldos basicos son de $170000, $80000, $55000 pesos, respectivamente.\n");
	printf("Ademas, el valor de la hora extra de c/u se abona segun el siguiente cuadro.\n");
	printf("Consisdere que cada empleado trabaja 5 horas extras al mes.");
	printf("\n\n\n");

	
	//printf("-------------------------------------------------------------------------------------\n");
	printf("=====================================================================================\n");
	printf("Franja de antiguedad (años)\n");
	printf("========== |==========================================================================\n");
	printf("< 1 año \t| 1 >= && < 5 \t| 5 >= && < 10 \t| 10 >= && < 20\t| >= 20\n");
	printf("-------------------------------------------------------------------------------------\n");
	//printf("-------------------------------------------------------------------------------------\n");
	printf("Valor de hora extra\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("$750 \t| $900 \t| $1200 \t| $1450 \t| $1500\n");
	printf("=====================================================================================\n");
	//printf("-------------------------------------------------------------------------------------\n");
	printf("Bonificaciones\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("$2500 \t| $3200 \t| $3700 \t| $4200 \t| $5350\n");
	printf("=====================================================================================\n");
	//printf("-------------------------------------------------------------------------------------\n");
	printf("Descuentos\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("%2 \t| %5 \t| %9 \t| %12 \t| %15\n");
	printf("=====================================================================================\n");
	//printf("-------------------------------------------------------------------------------------\n");
	
	char *left_align_format = "| %-15s | %-4d |\n";

	printf("+-----------------+------+\n"
		   "| Column name     | ID   |\n"
		   "+-----------------+------+\n");
	for (int i = 0; i < 5; i++) 
	{
		char parsed_data[30];
		sprintf(parsed_data, "some data %d", i);
		printf(left_align_format, parsed_data, i * i);
	}
	printf("+-----------------+------+\n");

	// Constant
	int overtime_hours = 5;
	
	// Cargos
	Position cargo_jerarquico = {
		.name = "Cargo Jerarquico", 
		.base_salary = 170000, 
		.overtime_hours = overtime_hours
	};
	Position administrativo = {"Administrativo", 80000, overtime_hours};
	Position maestranza = {"Maestranza", 55000, overtime_hours};

	// Lista de cargos
	Position position_list[] = {cargo_jerarquico, administrativo, maestranza};

	// Cargo
	int position_code;
	// Antigüedad
	int seniority;


	// Main part of the program
	do
	{
		// Prepare to show positions list (counting them)
		size_t list_size = sizeof(position_list) / sizeof(position_list[0]);
		// Displaying the menu with all the positions
		show_salary_table_options(position_list, list_size);
		

		// Starting the game
		printf("Introduzca el codigo del cargo: ");
		fflush(stdin);
		scanf(" %d", &position_code);

		if (position_code <= 0)
			break;

		printf("Introduzca los años de antigüedad: ");
		fflush(stdin);
		scanf(" %d", &seniority);

		if (position_code > 3 || seniority < 0)	
			break;


		// Copying the position selected
		Position position = position_list[position_code - 1];
		
		// Populate the attributes left
		position.overtime_wage = get_overtime_wage(seniority);
		position.bonus = get_bonus(seniority);
		position.discount = get_discount(position, seniority);
		position.total_salary = get_total_salary(position);


		// Showhing the category or position data
		printf("\n"
			   "Categoria:        %s\n"
			   "Sueldo Base:      $%.2f\n"
			   "Horas Extra:      %d\n"
			   "Valor Hora Extra: $%.2f\n"
			   "Bonificación:     $%.2f\n"
			   "Descuento:        $%.2f\n"
			   "Sueldo Total:     $%.2f\n"
			   "\n", 
			   position.name,
			   position.base_salary,
			   position.overtime_hours,
			   position.overtime_wage,
			   position.bonus,
			   position.discount,
			   position.total_salary			   
		);
	}
	// While the user keep entering the correct choices, the loop continues
	while (position_code <= 3 && position_code > 0);

	system("clear");

}