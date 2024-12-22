#include <stdio.h>
#include <locale.h>
#include <string.h>

// local libraries
#include "area.h"
#include "conversor_mps_kmh.h"

int main()
{
  setlocale(LC_ALL, "Portuguese_Brazil");

  // Variables
  int op = 10;
  double area;
  char saida[3];
  char entrada[3];

  // Menu central da aplica��o
  do
  {
    printf("\n=================================================================================================================\n");
    printf("=================================Bem vindo ao Sistema de convers�o de unidades=====================================\n");
    printf("--------------------------------------------------- Embarca_kit ---------------------------------------------------\n");
    printf("Escolha a convers�o desejada:");
    printf("1. �rea (mil�metros quadrados, cent�metros quadrados, metros quadrados, hect�metros quadrados e quil�metro quadrados)");
    printf("2. Volume (metros c�bicos, litros, gal�es)");
    printf("3. Comprimento (metro, cent�metro, mil�metro) ");
    printf("4. Massa (quilograma, grama, tonelada)");
    printf("5. Temperatura (Celsius, Fahrenheit, Kelvin)");
    printf("6. Velocidade (km/h, m/s, mph)");
    printf("7. Energia (Watts, quilowatts, cavalos-vapor)");
    printf("8. tempo (segundos, minutos, horas)");
    printf("\n=================================================================================================================\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("Qual a unidade da �rea de entrada (mm, cm, m, ha, km)? ");
      scanf("%s", entrada);
      printf("Qual a unidade da �rea de sa�da (mm, cm, m, ha, km)? ");
      scanf("%s", saida);
      printf("Informe o tamanho da �rea a ser convertida: ");
      scanf("%lf", &area);
      printf("\n");
      if ((strcmp(entrada, saida) == 0) || (area <= 0))
      {
        printf("As unidade de entrada e sa�da para convers�o s�o iguais ou a �rea informada � menor que 0!\n");
        printf("Desculpe, mas a execu��o ser� finalizada!\n");
        op = 0;
      }
      else if (strcmp(saida, "mm") == 0)
      {
        convert_to_millimeter(area, entrada);
      }
      else if (strcmp(saida, "cm") == 0)
      {
        convert_to_centimeter(area, entrada);
      }
      else if (strcmp(saida, "m") == 0)
      {
        convert_to_meters(area, entrada);
      }
      else if (strcmp(saida, "ha") == 0)
      {
        convert_to_hectare(area, entrada);
      }
      else if (strcmp(saida, "km") == 0)
      {
        convert_to_kilometers(area, entrada);
      }
      break;

    default:
      printf("Op��o inv�lida, digite:");
      printf("0. Para sair");
      printf("10. Para retornar ao menu principal");
      break;
    }

  } while (op != 0);

  /*float mps, kmh;

  printf("Digite a velocidade em metros por segundo (m/s): ");

  // Valida a entrada do usuário
  if (scanf("%f", &mps) != 1)
  {
    printf("Entrada inv�lida! Por favor, insira um n�mero.\n");
    return 1;
  }

  kmh = metros_por_segundo_para_quilometros_por_hora(mps);

  printf("%.2f metros por segundo equivalem a %.2f quil�metros por hora.\n", mps, kmh);*/
  system("pause");
  return 1;
}
