#include <stdio.h>
#include <stdlib.h>
#define  ROWS 7
#define COLS 3

float predict(int x[], float w[]){
	float result=0;
	for (int i=0; i<=ROWS-1; i++){
		result +=x[i]*w[i];
	}
	return result;
}

void fit(float delta, float error, int x_row[], float(*w)[]){
printf("--------------FIT-----------------\n");
for (int i=0; i<=COLS-1; i++){
printf("CHANGE W%i->%f->%f\n",i,(*w)[i], (*w)[i]+(delta*error*x_row[i]));
(*w)[i]=(*w)[i]+(delta*error*x_row[i]);
}
printf("**************\n");
}

int main (){
float delta=0.3;
float w[COLS]={3.12,2.0,1.86};

int X_Train[ROWS*5][COLS]={
{0,0,1},
{0,1,0},
{0,1,1},
{1,0,0},
{1,0,1},
{1,1,0},
{1,1,1} 
};

int X_Test[ROWS][COLS]={

{0,1,1},
{1,0,0},
{1,1,1},
{1,1,0},
{1,0,0},
{1,0,1},
{0,0,1}
};

int y_Train[ROWS*5]={1,2,3,4,5,6,7};
int y_Test[ROWS]= {3,4,7,6,4,5,1};
for (int i=0; i<=ROWS*1-1; i++){
float p=predict(X_Train[i],w);
float error=(float) y_Train[i]-p;
if (error !=0){
fit (delta, error, X_Train[i], &w);
}
}
printf("--------------W FINAL--------------\n");
for (int i=0; i<=COLS-1; i++){
printf("->%f\n",w[i]);
}
printf("-------------PRUEBA FINAL------------\n");
for (int i=0; i<=ROWS-1; i++){
printf("-----------\n");
printf("DATO-> %i %i %i\n", X_Test[i][0], X_Test[i][1], X_Test[i][2]);
printf ("DATO ESPERADO->%i\n", y_Test[i]);
printf("RESULTADO ->%f\n", predict(X_Test[i],w));
printf("-------------\n");
}
}
