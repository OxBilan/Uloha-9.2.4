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
    TDMAT* t = (TDMAT*)malloc(sizeof(TDMAT));

    if(t == NULL)
    {
    	return NULL;
		free(t);
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
	int i;
	
	for(i = 0; i < mat->size; i++)
	{
		if(i == mat->size)
		{
			continue;
		}
		else
    	{
    		mat->udiag[i] = 0;
    		mat->ldiag[i] = 0;
    	}
    	
    	mat->diag[i] = 1;
	}
}

void tdmat_random(TDMAT *mat)
{
	int i;
	
	for(i = 0; i < mat->size; i++)
	{
		if(i == mat->size)
		{
			continue;
		}
		else
    	{
			mat->udiag[i] = (rand()/(float)(RAND_MAX)) * 2 - 1;
    		mat->ldiag[i] = (rand()/(float)(RAND_MAX)) * 2 - 1;
    	}
    	
    	mat->diag[i] = (rand()/(float)(RAND_MAX)) * 2 - 1;
	}
}

void tdmat_print(TDMAT *mat)
{
	int i, j, k;
    
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
}

float tdmat_trace(TDMAT *mat)
{	
	int i;
	float m = 0;
    
	for(i = 0; i < mat->size; i++)
	{
		m += mat->diag[i];
    }
	
    return m;
}

int main()
{
	srand(time(NULL));
	
	unsigned int a;
	float h;
	
    TDMAT* c;
    
    printf("Zadaj velkost matice: ");
	scanf("%d", &a);
    
    c = tdmat_create_with_type(a);
    
    c->size = a;
    
    float d[c->size-1], e[c->size], f[c->size-1];

	c->udiag = d;
	c->diag = e;
	c->ldiag = f;
    
    tdmat_unit(c);
    tdmat_print(c);
    
    tdmat_random(c);
    tdmat_print(c);
    
    h = tdmat_trace(c);
    printf("Stopa matice: %f", h);
    
    tdmat_destroy(c);
}
