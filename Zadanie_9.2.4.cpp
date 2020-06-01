#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct
{
	unsigned int size;
	float *udiag;
	float *diag;
	float *ldiag;
	
} TDMAT;

TDMAT *tdmat_create_with_type(unsigned int size)
{

	TDMAT* t = (TDMAT*)malloc(sizeof(TDMAT)*size);
	
	if (t == NULL)
	{
		free(t); //Funkcia uvolnuje pamat
		return NULL; //Funkcia vracia nulu
	}
	else
	{
		printf("Adresa struktury TDMAT: %d", t); //Funkcia vypysuje adresu struktury TDMAT
		return t; //Funkcia vracia adresu struktury TDMAT
	}
}

void tdmat_destroy(TDMAT *mat)
{
	
}

int main(void)
{
	unsigned int size = 5;
	
	tdmat_create_with_type(size);
}
