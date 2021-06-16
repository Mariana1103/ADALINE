#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h> //

float y_resultado(int patrones[], float pesos[])
{

	float resultado = 0;
	for (int i = 0; i <= 2; i++)
	{

		resultado += patrones[i] * pesos[i];
	}
	return resultado;
}

float ajuste(float alfa, float error_calculado, int patron, float peso) {
    printf("pesos[j] = pesos[j] + (alfa * error_calculado[i] * patrones[i][j])\n");
    printf("%f = %f + (%f * %f * %d);\n", peso, peso, alfa, error_calculado, patron);
    return peso + (alfa * error_calculado * patron);
}

// SOLO LEE 1 DIGITO
int leer_binario(int x){
	int valor, resultado;
	bool valido;

	valido = false;

	while(!valido) {
		printf("INGRESE EL DIGITO [%d]\n", x);
		scanf("%d", &valor);
		if(valor != 0 && valor != 1) {
			printf("VALOR INGRESADO ES INCORRECTO %d\n", valor);
		} else {
			resultado = valor;
			valido = true;
		}
	}

	return resultado;
}

int leer_resultado(){
	int valor;
	bool valido;

	valido = false;
	while(!valido){
		printf("ESCRIBA EL VALOR ESPERADO:\n");
		scanf("%d", &valor);
		if(valor >= 0 && valor <= 7){
			return valor;
		} else {
			printf("EL VALOR ES INCORRECTO \n");
		}
	}
}

int main() {
    srand (time(NULL));
    int i, j;
    float alfa, error_usuario, y = 0.0;
    float error_cuadratico_medio = 0.0;
    bool validacion = false;
    alfa = 0.3;
    error_usuario = 0.0;
    float error_calculado[7];
    int patrones[7][3] = {
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };
    int resultados[7] = {1,2,3,4,5,6,7};
    float pesos[3] = /{(random() % 10 + 1), (random() % 10 + 1), (random() % 10 + 1)};/
    {3.6101157340344, 1.9851622818544, 1.4231924323284};


    printf("INGRESE EL VALOR DE DELTA:\n");
	scanf("%f", &alfa);
	printf("INGRESE EL ERROR DESEADO:\n");
	scanf("%f", &error_usuario);
    
   
