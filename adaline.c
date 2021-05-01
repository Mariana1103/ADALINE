#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 3

// D ES EL VALOR QUE SE DESEA
// Y ES EL VALOR CALCULADO
// 1
// 0.783 
float predict(int x[], float w[])
{
	// Y = SUMATORIA DE Xi + Wi
	// [X1, X2, X3] -> [W1, W2, W3]
	// [0, 0, 1] -> [0.85, 2.0, 0.2]
	// Y = (X1*W1) + (X2*W2) + (X3*W3) .... + (Xn * Wn)
	// X = VALORES DE LOS BINARIOS (X1, X2, X3)
	// W = VALORES DE LOS PESOS (W1, W2, W3)
	float result = 0;
	for (int i = 0; i <= COLS - 1; i++)
	{
        // PRIMERA ITERACION
		// Y = (X1*W1)
		// SEGUNDA ITERACION
		// Y = (X1*W1) + (X2*W2)
		// TERCERA ITERACION
		// Y = (X1*W1) + (X2*W2) + (X3*W3)
		result += x[i] * w[i];
	}
    // FLOAT Y = (X1*W1) + (X2*W2) + (X3*W3) .... + (Xn * Wn)
	return result;
}


// X_row = [0, 0, 1]
// INCREMENTO EN iWj = delta * ERROR * Xi
// w = [1, 0.5, 3]
// W = W + iWj
// APUNTADOR = DIRECCION DE MEMORIA
// float variable;
// void scanf("%f", &variable);
void fit(float delta, float error, int x_row[], float (*w)[])
{
	printf("VALOR -> %d %d %d\n", x_row[0], x_row[1], x_row[2]);
	for (int i = 0; i <= COLS - 1; i++)
	{
		(*w)[i] = (*w)[i] + (delta * error * x_row[i]);
	}
}

void read_binary(int (*direction)[3]){
	for(int x = 0; x < 3; x++){
		int value;
		printf("INGRESE EL DIGITO [%d]:", x);
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
		printf("ESCRIBA EL VALOR ESPERADO:\n");
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
	float w[COLS] = {3.12, 2.00, 1.86};
	bool error_passed = false;
	char exit='Y';

	int X_Train[ROWS][COLS] = {
		{0,0,1},
		{0,1,0},
		{0,1,1},
		{1,0,0},
		{1,0,1},
		{1,1,0},
		{1,1,1},
	};
	int y_Train[ROWS] = {1,2,3,4,5,6,7};

	int X_Test[COLS];

	printf("INGRESE EL VALOR DE DELTA:\n");
	scanf("%f", &delta);
	printf("INGRESE EL ERROR DESEADO:\n");
	scanf("%f", &error_level);


	while(!error_passed) {
		printf("----------- ITERACIÓN %d ------------\n", fors);
		/*for(int i = 0; i <= ROWS-1; i++){
			read_binary(&X_Train[i]);
			read_result(i, &y_Train[i]);
		}*/
		for(int i = 0; i <= ROWS-1; i++) {
			printf("%d %d %d -> %d\n", X_Train[i][0], X_Train[i][1], X_Train[i][2], y_Train[i]);
		}
		for (int i = 0; i <= ROWS-1; i++)
		{
			printf("++++++++++++++ TEST %d ++++++++++++++\n", i);
			float y = predict(X_Train[i], w);
			float error = (float)y_Train[i] - y;
			printf("VALOR ESPERADO: %d\n", y_Train[i]);
			printf("VALOR OBTENIDO: %f\n", y);
			printf("ERROR: %f\n", error);
			if (error != error_level)
			{
				fit(delta, error, X_Train[i], &w);
				error_passed = false;
			} else {
				error_passed = true;
			}
			printf("*** PESOS ***\n");
			printf("W1: %f\n", w[0]);
			printf("W2: %f\n", w[1]);
			printf("W3: %f\n", w[2]);
			printf("+++++++++++++++++++++++++++++++++++++\n");

		}

		printf("--------------------------------\n");

		fors++;
	}

	if(error_passed==true){
		printf("------------- EJERCICIOS ------------\n");
		while(exit == 'y' || exit=='Y')
		{
			read_binary(&X_Test);
			printf("EL RESULTADO ES DE: %f\n", predict(X_Test, w));
			printf("DESEA CONTINUAR? PRESIONE Y/y \n");
			scanf(" %c", &exit);
		}
	}
}