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
    TDMAT* t = (TDMAT*)malloc(sizeof(float)*size);
    
    if(t == NULL)
    {
		free(t); //Funkcia uvolnuje pamat
		return NULL; //Funkcia vracia nulu
	}
	else
	{
    	return t; //Funkcia vracia adresu struktury TDMAT
	}
}
 
void tdmat_destroy(TDMAT *mat)
{
	if (mat != NULL)
	
	free(mat); //Funkcia uvolnuje vsetku pamat, ktora sa podiela na reprezentacii tridiagonalnej matice
	
}
 
int main(void)
{
    unsigned int size = 5;
    TDMAT* c;
    
    c = tdmat_create_with_type(size);
    printf("%d", c);
    
    tdmat_destroy(c);

}
