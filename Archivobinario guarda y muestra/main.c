#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    int cantidad;
} ePendrive;
int main()
{
    FILE *binario;
    ePendrive pendrive[2];
    ePendrive* pendriveptr;
    pendriveptr=&pendrive[0];
    if((binario=fopen("binario.bin","rb"))==NULL)
    {
        if((binario=fopen("binario.bin","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        else
        {
            for(int i=0; i<2; i++)
            {
                printf("\nIngrese cantidad: \n");
                scanf("%d",&(pendriveptr+i)->cantidad);
                printf("\nIngrese codigo: \n");
                scanf("%d",&(pendriveptr+i)->codigo);
            }
            printf("Archivo creado con exito!\n");
            system("pause");
            system("cls");
            fwrite(pendriveptr,sizeof(ePendrive),2,binario);
        }
        fclose(binario);
    }
    else
    {
        fread(pendriveptr,sizeof(ePendrive),2,binario);
        fclose(binario);
        system("pause");
        system("cls");
        printf("Archivo abierto con exito! Contiene esto: \n");
        for(int i=0; i<2; i++)
        {
            printf("cantidad: %d---codigo: %d\n",(pendriveptr+i)->cantidad,(pendriveptr+i)->codigo);
        }

    }
    return 0;
}
