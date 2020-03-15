
#include "bonoexamen.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



/*PROFESOR leer_info_un_prof(){
    int b,i=0;
    PROFESOR a;
    printf("Digite el nombre del profesor\n");
    scanf("%s",&a.nombre);
    printf("Digite la cantidad de cursos impartidos por %s\n",a.nombre);
    scanf("%d",&b);
    for (int i = 0; i <b ; ++i) {
        printf("Digite el nombre de la %d asignatura impartida por %s\n",i+1,a.nombre);
        scanf("%s",&a.asig[i].nombre);
        printf("Digite el nivel de dificultad de %s\n",a.asig[i].nombre);
        scanf("%s",&a.asig[i].nivel);
        printf("Digite el codigo de %s\n",a.asig[i].nombre);
        scanf("%s",&a.asig[i].codigo);
        printf("Digite la cantidad de creditos de %s\n",a.asig[i].nombre);
        scanf("%f",&a.asig[i].creditos);
    }
    printf("Digite el nombre de la universidad donde trabaja %s\n",a.nombre);
    scanf("%s",&a.uni.nombre);
    printf("Digite la direccion de la universidad  %s\n",a.uni.nombre);
    scanf("%s",&a.uni.direccion);
    printf("Digite el numero de telefono de la universidad %s\n",a.uni.nombre);
    scanf("%s",&a.uni.telefono);

    return a;
}

void leer_info_varios_profs(int n, PROFESOR *arr){
    for (int i = 0; i<n ;i++) {
        arr[i]=leer_info_un_prof();
    }

}*/

/*RESENA  leer_informacion[] {
   int cant_r;
   printf("Digite la cantidad de resennas que se escribiran \n");
   scanf("%d",&cant_r);
    RESENA resenas[cant_r];
    for (int i = 0; i < cant_r; ++i) {
        printf("Digite la descripcion de la resena\n");
        scanf("%s", &resenas[i].descripcion);
        printf("Digite el nombre del profesor del cual escribe la resena\n");
        scanf("%s", &resenas[i].prof.nombre);
        printf("diga el nombre de la universidad donde trabaja %s \n", resenas[i].prof.nombre);
        scanf("%s", &resenas[i].prof.uni.nombre);
        printf("diga el nombre del estudiante el cual realiza la resenna \n");
        scanf("%s", &resenas[i].est.nombre);
        printf("diga el valor (0.00-5.00) que le da en su resenna al profesor %s \n", resenas[i].prof.nombre);
        scanf("%f", &resenas[i].puntaje);
    }
    return resenas[cant_r];
}*/

ESTUDIANTE buscar_est_dio_mejor_rating(int cant_r, RESENA resenas[cant_r], int cant_e, ESTUDIANTE estudiantes[cant_e]) {
    float temp;
    int div=0;
    float prom[cant_e];
    for (int i = 0; i <cant_e ; ++i) {
        prom[i]=0;
    }
    for (int j = 0; j < cant_e; ++j) {
        for (int k = 0; k < cant_r; ++k) {
            prom[j] = resenas[k].puntaje + prom[j];
            div++;
        }
        prom[j] = prom[j]/div;
    }
    for (int m = 0;  m<cant_e-1 ; ++m) {
        for (int n=1;n<cant_e; ++n) {
            if(prom[m]>prom[n]){
                temp=prom[n];
                prom[n]=prom[m];
                prom[m]=temp;
            }

        }

    }
    return estudiantes[cant_e-1];
}


float calc_desv_std_rating_prof(PROFESOR prof, int cant_resenas, RESENA resenas[cant_resenas]){
    float sum=0,prom,res;
    int cont=0;
    for (int i=0;i<cant_resenas;i++){
        if(strcmp(resenas[i].prof.nombre,prof.nombre)==0) {
            sum = resenas[i].puntaje + sum;
            cont++;
        }
    }
    prom=sum/cont;
    float var=varianza(cant_resenas,prom,resenas,prof);
    res=desviacion(var);

    return res;
}
float varianza(int pos, float prom,RESENA a[],PROFESOR prof){
    int n=0,i=0;
    float cuav,sumv=0,aux=0,desv,var;
    for(i=0;i<pos;i++){
        if(strcmp(a[i].prof.nombre,prof.nombre)==0) {
            cuav = a[i].puntaje - prom;
            sumv = cuav * cuav;
            aux = sumv + aux;
            n++;
            var = aux / n;
        }
    }
    return var;
}
float desviacion(float var){
    float desv;
    desv=sqrtf(var);
    return desv;
}

float calc_prom_ind_est_dieron_puntuacion_buena(int n, RESENA resenas[n]){
    float promind,suma=0;
    int cont=0;

    for (int i = 0; i <n ; ++i) {
        if(resenas[i].puntaje>2.5){
            suma=resenas[i].est.indice+suma;
            cont++;
        }

    }
    promind=suma/cont;
    return promind;
}

UNIVERSIDAD buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(int cant_u, UNIVERSIDAD unis[cant_u], int cant_r, RESENA resenas[cant_r]){

    UNIVERSIDAD aux;
    for (int i = 0; i <cant_u ; ++i) {
        unis[i].cont=0;
        for (int j = 0; j <cant_r ; ++j){
            if( strcmp(resenas[j].prof.uni.nombre,unis[i].nombre)==0){
                if ((resenas[j].puntaje>2.5) && (resenas[j].prof.asig.nivel==2)) {
                    unis[i].cont++;
                }
            }
        }
    }
    for (int k = 0; k <cant_u-1 ; ++k) {
        for (int g = k+1; g <cant_u ; ++g) {
            if(unis[k].cont>unis[g].cont){
                aux=unis[g];
                unis[g]=unis[k];
                unis[k]=aux;
            }
        }
    }
    return unis[cant_u-1];
}





