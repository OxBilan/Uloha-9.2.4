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
    TDMAT* t = (TDMAT*)malloc(sizeof(float)*size*size);
    
    if(t == NULL)
    {
		free(t);
		return NULL;
	}
	else
	{
    	return t;
	}
}
 
void tdmat_destroy(TDMAT *mat)
{	
	free(mat);
}

void tdmat_unit(TDMAT *mat)
{
	int i, j, k;
	
	for(i = 0; i < mat->size-1; i++)
	{
    	mat->udiag[i] = 0;
	}
	
	for(j = 0; j < mat->size; j++)
	{
    	mat->diag[j] = 1;
	}
	
	for(k = 0; k < mat->size-1; k++)
	{
    	mat->ldiag[k] = 0;
	}
}

void tdmat_random(TDMAT *mat)
{
	int i, j, k;
	
	for(i = 0; i < mat->size-1; i++)
	{
    	mat->udiag[i] = (rand()/(float)(RAND_MAX)) * 2 - 1;
	}
	
	for(j = 0; j < mat->size; j++)
	{
    	mat->diag[j] = (rand()/(float)(RAND_MAX)) * 2 - 1;
	}
	
	for(k = 0; k < mat->size-1; k++)
	{
    	mat->ldiag[k] = (rand()/(float)(RAND_MAX)) * 2 - 1;
	}
}

void tdmat_print(TDMAT *mat)
{
	int i, j, k, l, m, n;
	
	tdmat_unit(mat);
    
	for(i = 0; i < mat->size-1; i++)
	{
    	printf("%f ", mat->udiag[i]);
	}
	printf("\n");
	
    for(j = 0; j < mat->size; j++)
	{
    	printf("%f ", mat->diag[j]);
	}
	printf("\n");
	
    for(k = 0; k < mat->size-1; k++)
	{
    	printf("%f ", mat->ldiag[k]);
    }
    printf("\n\n");
    
    tdmat_random(mat);
    
    for(l = 0; l < mat->size-1; l++)
	{
    	printf("%f ", mat->udiag[l]);
	}
	printf("\n");
	
	for(m = 0; m < mat->size; m++)
	{
    	printf("%f ", mat->diag[m]);
    }
    printf("\n");
    
	for(n = 0; n < mat->size-1; n++)
	{
    	printf("%f ", mat->ldiag[n]);
    }
}

int main()
{
	unsigned int a;
	
    TDMAT* c;
    
    printf("Zadaj velkost matice: ");
	scanf("%d", &a);
    
    c = tdmat_create_with_type(a);
    
    c->size = a;
    
    float e[c->size-1], f[c->size], g[c->size-1];

	c->udiag = e;
	c->diag = f;
	c->ldiag = g;
    
    tdmat_print(c);
    
    tdmat_destroy(c);
}
