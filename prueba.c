#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 3

float predict(int x[], float w[])
{
	float result = 0;
	for (int i = 0; i <= ROWS - 1; i++)
	{
		result += x[i] * w[i];
	}
	return result;
}

void fit(float delta, float error, int x_row[], float (*w)[])
{
	for (int i = 0; i <= COLS - 1; i++)
	{
		(*w)[i] = (*w)[i] + (delta * error * x_row[i]);
	}
}

void read_binary(int (*direction)[3]){
	for(int x = 0; x < 3; x++){
		int value;
		printf("INGRESE EL BINARIO: %d\n", x);
		scanf("%d", &value);
		if(value != 0 && value != 1) {
			printf("VALOR INGRESADO ES INCORRECTO %d\n", value);
			x--;
		} else {
			(*direction)[x] = value;
		}
	}
	printf("%d %d %d -> ?\n", (*direction)[0], (*direction)[1], (*direction)[2]);
}

void read_result(int index, int *direction){
	int value;
	bool save = false;
	while(!save){
		printf("ESCRIBA EL RESULTADO:\n");
		scanf("%d", &value);
		if(value >= 0 && value <= 7){
			(*direction) = value;
			save = true;
		} else {
			printf("EL VALOR ES INCORRECTO \n");
		}
	}
}

int main()
{
	int fors = 1;
	float delta;
	float error_level;
	float w[COLS] = {0.84, 0.39, 0.78};
	bool error_passed = false;
	char exit = 'Y';

	int X_Train[ROWS][COLS];
	int y_Train[ROWS];

	int X_Test[COLS];

	printf("ESCOJA EL NIVEL DE DELTA:\n");
	scanf("%f", &delta);
	printf("ESCOJA EL NIVEL DE ERROR:\n");
	scanf("%f", &error_level);


	while(!error_passed) {
		for(int i = 0; i <= ROWS; i++){
			read_binary(&X_Train[i]);
			read_result(i, &y_Train[i]);
		}
		for(int i = 0; i <= ROWS; i++) {
			printf("%d %d %d -> %d\n", X_Train[i][0], X_Train[i][1], X_Train[i][2], y_Train[i]);
		}
		printf("----------- TANDA %d ------------\n", fors);

		for (int i = 0; i <= ROWS; i++)
		{
			printf("++++++++++++++ TEST %d ++++++++++++++\n", i);
			float p = predict(X_Train[i], w);
			float error = (float)y_Train[i] - p;
			printf("VALOR ESPERADO: %d\n", y_Train[i]);
			printf("VALOR OBTENIDO: %f\n", p);
			printf("ERROR: %f\n", error);
			printf("* PESOS *\n");
			printf("W1: %f\n", w[0]);
			printf("W2: %f\n", w[1]);
			printf("W3: %f\n", w[2]);
			printf("+++++++++++++++++++++++++++++++++++++\n");
			if (error > error_level)
			{
				fit(delta, error, X_Train[i], &w);
				error_passed = false;
			} else {
				error_passed = true;
			}


		}

		printf("--------------------------------\n");

		fors++;
	}


	printf("------------- EJERCICIOS ------------\n");
	while(exit == 'Y' || exit == 'y')
	{
		read_binary(&X_Test);
		printf("EL RESULTADO ES DE: %f\n", predict(X_Test, w));
		printf("DESEA CONTINUAR? PRESIONE Y/y \n");
		scanf(" %c", &exit);
	}
}

