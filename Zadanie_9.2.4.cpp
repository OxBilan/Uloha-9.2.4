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
	int i;
	float e[mat->size], f[mat->size], g[mat->size];

	mat->udiag = e;
	mat->diag = f;
	mat->ldiag = g;
	
	for(i = 0; i < mat->size; i++)
	{
    	mat->udiag[i] = 0;
    	printf("%f ", mat->udiag[i]);

    	mat->diag[i] = 1;
    	printf("%f ", mat->diag[i]);
    
    	mat->ldiag[i] = 0;
    	printf("%f ", mat->ldiag[i]);
    }
}


int main()
{
	unsigned int a;
	
    TDMAT* c;
    
    printf("Zadaj rozmier matice: ");
	scanf("%d", &a);
    
    c = tdmat_create_with_type(a);
    
    c->size = a;
    
    tdmat_unit(c);

    tdmat_destroy(c);
}
