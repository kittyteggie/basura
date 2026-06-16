#include <iostream>
#include <cmath>

int main(){
  int opcion = 0;

  std::cout << "-OPCIONES-" << '\n';
  std::cout << "1. Sumas, restas, multiplicacion y division" << '\n';
  std::cout << "2. Radio, area y volumen" << '\n';
  std::cout << "3. Interes compuesto" << '\n';
  std::cout << "4. Kilos y libras" << '\n';
  std::cout << "5. Temperatura (Celcius y Fahrenheit)" << '\n';
  std::cout << "Elije una opcion: ";
  std::cin >> opcion;

  switch(opcion){
    case 1: {
      char operador = '\0';
      double num1 = 0.0;
      double num2 = 0.0;
      double resultado = 0.0;

      std::cout << "Coloca el primer numero: ";
      std::cin >> num1;
      std::cout << "Coloca el operador (+ - * /): ";
      std::cin >> operador;
      std::cout << "Coloca el segundo numero: ";
      std::cin >> num2;

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
            std::cout << "ERROR: No puedes dividir entre cero" << '\n';
            return 1;
          }
          else{
            resultado = num1 / num2;
          }
          break;
        default:
          std::cout << "ERROR: Operador invalido" << '\n';
          return 1;
      }

      std::cout << "Resultado: " << resultado;
      break;
    }
    case 2: {
      double radio = 0.0;
      double area = 0.0;
      double superficieDelArea = 0.0;
      double volumen = 0.0;
      constexpr double PI = 3.141592653589793;

      std::cout << "Coloca el radio: ";
      std::cin >> radio;

      area = PI * pow(radio, 2);
      superficieDelArea = 4 * PI * pow(radio, 2);
      volumen = (4.0 / 3.0) * PI * pow(radio, 3);

      std::cout << "--- RESULTADO ---" << '\n';
      std::cout << "Area: " << area << '\n';
      std::cout << "Superficie del Area: " << superficieDelArea << '\n';
      std::cout << "Volumen: " << volumen << '\n';
      break;
    }
    case 3: {
      double principal = 0.0;
      double tasaDeInteres = 0.0;
      int años = 0;
      int vecesCompuesto = 0;
      double total = 0;

      std::cout << "Coloca el principal (P): ";
      std::cin >> principal;
      std::cout << "Coloca la tasa de interés % (r): ";
      std::cin >> tasaDeInteres;
      tasaDeInteres = tasaDeInteres / 100;
      std::cout << "Coloca el numero de años (t): ";
      std::cin >> años;
      std::cout << "Coloca la cantidad de veces compuesto por año: ";
      std::cin >> vecesCompuesto;

      total = principal * pow(1 + tasaDeInteres / vecesCompuesto, vecesCompuesto * años);

      std::cout << "Despues de " << años << " el total seria de $" << total << '\n';
      break;
    }
    case 4: {
      int opcion2 = 0;
      float libras = 0.0f;
      float kilogramos = 0.0f;

      std::cout << "1. Kilogramos a Libras" << '\n';
      std::cout << "2. Libras a Kilogramos" << '\n';
      std::cout << "Escoge una opcion (1 o 2): ";
      std::cin >> opcion2;

      if(opcion2 == 1){
        std::cout << "Coloca el peso en kilogramos: ";
        std::cin >> kilogramos;
        libras = kilogramos * 2.20462f;

        std::cout << kilogramos << " es igual a " << libras << " libras" << '\n';
      }
      else if(opcion2 == 2){
        std::cout << "Coloca el peso en libras: ";
        std::cin >> libras;
        kilogramos = libras / 2.20462f;

        std::cout << libras << " es igual a " << kilogramos << " kilogramos" << '\n';
      }
      else{
        std::cout << "ERROR: Opción invalida, coloque 1 o 2 en el input" << '\n';
        return 1;
      }
      break;
    }
    case 5: {
      char opcion3 = '\0';
      float fahrenheit = 0.0f;
      float celcius = 0.0f;

      std::cout << "C. Celcius a Fahrenheit" << '\n';
      std::cout << "F. Fahrenheit a Celcius" << '\n';

      std::cout << "Coloque una opcion (C o F): ";
      std::cin >> opcion3;

      if(opcion3 == 'C'){
        std::cout << "Coloque la temperatura en Celcius: ";
        std::cin >> celcius;
        fahrenheit = (celcius * 9 / 5) + 32;
        std::cout << celcius << " grados celcius es igual a " << fahrenheit << " grados Fahrenheit" << '\n';
      }
      else if(opcion3 == 'F'){
        std::cout << "Coloque la temperatura en Fahrenheit: ";
        std::cin >> fahrenheit;
        celcius = (fahrenheit - 32) * 5 / 9;
        std::cout << fahrenheit << " grados Fahrenheit es igual a " << celcius << " grados celcius" << '\n';
      }
      else{
        std::cout << "ERROR: Opción invalida, por favor coloque C o F en el input" << '\n';
      }
      break;
    }
    default:
      std::cout << "ERROR: Opcion invalida" << '\n';
      return 1;
  }

  return 0;
}
