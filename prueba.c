#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
float alfa;
int patron[7][4];
float error_us;
float error_cal;
float w[3]={0.84, 0.39, 0.78};
float y=0.0;

printf("ESTE PROGRAMA REALIZA LA FUNCION DE ADALINE\n");
printf("Ingrese el error deseado: \n");
scanf("%f", &error_us);

printf("Ingrese el valor de alfa: ");
scanf("%f", &alfa);
printf("Ingrese los primeros tres digitos binarios y el cuarto del valor decimal correspondiente\n");
for (int m=1; m<=1; m++)
{
	for (int i=0;i<=7; i++)
	{
		for (int j=0; j<4; j++) 
		{
			printf("Patron [%d] digito [%d]: ", (i+1),(j+1));
			scanf("%d", &patron[i][j]);
		}
         printf("\n");
	}
}


	for (int i=0;i<=0; i++)
	{
		for (int j=0; j<3; j++) 
		{
			y=y+(patron[i][j]*w[j]);
                        error_cal=1-y;
		}
         printf("\n");
	}
printf("y=%f\n",y);
printf("Error us: %f, Error cal: %f\n",error_us, error_cal);


if (error_cal!=error_us)
{
printf("Error");


}

}

