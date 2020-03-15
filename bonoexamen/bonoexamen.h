

#ifndef BONOEXAMEN_BONOEXAMEN_H
#define BONOEXAMEN_BONOEXAMEN_H
typedef struct cursos{
    char nombre[30],codigo[30];
    float creditos;
    int nivel;
}CURSOS;

typedef struct universidad{
    char nombre[30],direccion[30],telefono[30];
    int cont;
}UNIVERSIDAD;


typedef struct profesor{
    char nombre[30];
    CURSOS asig;
    UNIVERSIDAD uni;
}PROFESOR;

typedef struct estudiante{
    int id;
    char nombre[30];
    UNIVERSIDAD uni;
    char usuario [20];
    float indice;

}ESTUDIANTE;

typedef struct resena{
    char descripcion[100];
    float puntaje;
    ESTUDIANTE est;
    PROFESOR prof;
}RESENA;

PROFESOR leer_info_un_prof();
float desviacion(float var);
float varianza(int pos, float prom,RESENA a[],PROFESOR prof);
void leer_info_varios_profs(int n, PROFESOR *arr);
void leer_informacion();
ESTUDIANTE buscar_est_dio_mejor_rating(int cant_r, RESENA resenas[cant_r], int cant_e, ESTUDIANTE estudiantes[cant_e]);
float calc_desv_std_rating_prof(PROFESOR prof, int cant_resenas, RESENA resenas[cant_resenas]);
float calc_prom_ind_est_dieron_puntuacion_buena(int n, RESENA resenas[n]);
UNIVERSIDAD buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(int cant_u, UNIVERSIDAD unis[cant_u], int cant_r, RESENA resenas[cant_r]);


#endif //BONOEXAMEN_BONOEXAMEN_H
