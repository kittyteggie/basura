#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

	int opcion = 0;

	printf("-OPCIONES-\n");
	printf("1. Sumas, restas, multiplicacion y division\n");
	printf("2. Radio, area y volumen\n");
	printf("3. Interes compuesto\n");
	printf("4. Kilos y libras\n");
	printf("5. Temperatura (Celcius y Fahrenheit)\n");
	printf("Elije una opción: ");
	scanf("%d", &opcion);

	switch(opcion){
		case 1:
			char operador = '\0';
			double num1 = 0.0;
			double num2 = 0.0;
			double resultado = 0.0;
			bool error = 0;
			char *errorlog = "";

			printf("Coloca el primer numero: ");
			scanf("%lf", &num1);

			printf("Coloca el operador (+ - * /): ");
			scanf(" %c", &operador);

			printf("Coloca el segundo numero: ");
			scanf("%lf", &num2);

			switch(operador){
				case '+':
					resultado = num1 + num2;
					break;
				case '-':
					resultado = num1 - num2;
					break;
				case '*':
					resultado = num1 * num2;
					break;
				case '/':
					if(num2 == 0){
						error = 1;
						errorlog = "No puedes dividir entre cero\n";
					}
					else{
						resultado = num1 / num2;
					}
					break;
				default:
					error = 1;
					errorlog = "Operador invalido\n";
			}

			if(error){
				printf("ERROR: %s", errorlog);
			}
			else{
				printf("Resultado: %.3lf\n", resultado);
			}
			break;
		case 2:
			double radio = 0.0;
			double area = 0.0;
			double superficieDelArea = 0.0;
			double volumen = 0.0;
			const double PI = 3.141592653589793;

			printf("Coloca el radio: ");
			scanf("%lf", &radio);

			area = PI * pow(radio, 2);
			superficieDelArea = 4 * PI * pow(radio, 2);
			volumen = (4.0 / 3.0) * PI * pow(radio, 3);
			
			printf("--- RESULTADO ---\n");
			printf("Area: %lf\n", area);
			printf("Superficie del Area: %lf\n", superficieDelArea);
			printf("Volumen: %lf\n", volumen);
			break;
		case 3:
			double principal = 0.0;
			double tasaDeInteres = 0.0;
			int años = 0;
			int vecesCompuesto = 0;
			double total = 0;

			printf("Coloca el principal (P): ");
			scanf("%lf", &principal);

			printf("Coloca la tasa de interés %% (r): ");
			scanf("%lf", &tasaDeInteres);
			tasaDeInteres = tasaDeInteres / 100;

			printf("Coloca el numero de años (t): ");
			scanf("%d", &años);

			printf("Coloca la cantidad de veces compuesto por año (n): ");
			scanf("%d", &vecesCompuesto);

			total = principal * pow(1 + tasaDeInteres / vecesCompuesto, vecesCompuesto * años);

			printf("Despues de %d años, el total seria de $%.3lf\n", años, total);
			break;
		case 4:
			int opcion2 = 0;
			float libras = 0.0f;
			float kilogramos = 0.0f;

			printf("1. Kilogramos a Libras\n");
			printf("2. Libras a Kilogramos\n");
			printf("Escoge una opción (1/2): ");
			scanf("%d", &opcion2);

			if(opcion2 == 1){
				printf("Coloca el peso en kilogramos: ");
				scanf("%f", &kilogramos);
				libras = kilogramos * 2.20462;

				printf("%.2f kilogramos es igual a %.2f libras\n", kilogramos, libras);
			}
			else if(opcion2 == 2){
				printf("Coloca el peso en libras: ");
				printf("%f", libras);
				kilogramos = libras / 2.20462;

				printf("%.2f libras es igual a %.2f kilogramos\n", libras, kilogramos);
			}
			else{
				printf("ERROR: Opción invalida, coloque 1 o 2 en el input\n");
			}
			break;
		case 5:
			char opcion3 = '\0';
			float fahrenheit = 0.0f;
			float celcius = 0.0f;

			printf("C. Celcius a Fahrenheit\n");
			printf("F. Fahrenheit a Celcius\n");

			printf("Coloque una opción (C/F): ");
			scanf(" %c", &opcion3);

			if(opcion3 == 'C'){
				printf("Coloque la temperatura en Celcius: ");
				scanf("%f", &celcius);
				fahrenheit = (celcius * 9 / 5) + 32;
				printf("%.2f grados celcius es igual a %.2f grados Fahrenheit\n", celcius, fahrenheit);
			}else if(opcion3 == 'F'){
				printf("Coloque la temperatura en Fahrenheit: ");
				scanf("%f", &fahrenheit);
				celcius = (fahrenheit - 32) * 5 / 9;
				printf("%.2f grados Fahrenheit es igual a %.2f grados celcius\n", fahrenheit, celcius);
			}else{
				printf("ERROR: Opción invalida, por favor coloque C o F en el input\n");
			}
			break;
	}

	return 0;
}
