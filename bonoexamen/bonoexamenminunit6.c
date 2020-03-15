#include <minunit.h>
#include <string.h>
#include "bonoexamen.h"

#define MINUNIT_EPSILON 1E-6

MU_TEST(test_case1) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"pucmm");
    strcpy(u[1].nombre,"uasd");
    strcpy(u[2].nombre,"utesa");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"pucmm");
    r[1].puntaje=2.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"pucmm");
    r[2].puntaje=4.5,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"pucmm");
    r[3].puntaje=3.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"pucmm");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=1,strcpy(r[4].prof.uni.nombre,"uasd");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=1,strcpy(r[5].prof.uni.nombre,"utesa");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("pucmm", res.nombre);
}
MU_TEST(test_case2) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"pucmm");
    strcpy(u[1].nombre,"uasd");
    strcpy(u[2].nombre,"utesa");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"uasd");
    r[1].puntaje=2.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"uasd");
    r[2].puntaje=4.5,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"uasd");
    r[3].puntaje=3.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"pucmm");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=1,strcpy(r[4].prof.uni.nombre,"utesa");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=1,strcpy(r[5].prof.uni.nombre,"utesa");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("uasd", res.nombre);
}
MU_TEST(test_case3) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"pucmm");
    strcpy(u[1].nombre,"uasd");
    strcpy(u[2].nombre,"utesa");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=0,strcpy(r[0].prof.uni.nombre,"uasd");
    r[1].puntaje=2.8,r[1].prof.asig.nivel=1,strcpy(r[1].prof.uni.nombre,"uasd");
    r[2].puntaje=4.5,r[2].prof.asig.nivel=1,strcpy(r[2].prof.uni.nombre,"uasd");
    r[3].puntaje=3.6,r[3].prof.asig.nivel=1,strcpy(r[3].prof.uni.nombre,"pucmm");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=1,strcpy(r[4].prof.uni.nombre,"utesa");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"utesa");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("utesa", res.nombre);
}
MU_TEST(test_case4) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"oym");
    strcpy(u[1].nombre,"isa");
    strcpy(u[2].nombre,"unev");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"unev");
    r[1].puntaje=2.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"unev");
    r[2].puntaje=4.5,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"unev");
    r[3].puntaje=3.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"isa");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=1,strcpy(r[4].prof.uni.nombre,"oym");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=1,strcpy(r[5].prof.uni.nombre,"oym");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("unev", res.nombre);
}
MU_TEST(test_case5) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"oym");
    strcpy(u[1].nombre,"isa");
    strcpy(u[2].nombre,"unev");

    RESENA r[6];
    r[0].puntaje=4.6,r[0].prof.asig.nivel=1,strcpy(r[0].prof.uni.nombre,"unev");
    r[1].puntaje=3.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"unev");
    r[2].puntaje=4.5,r[2].prof.asig.nivel=1,strcpy(r[2].prof.uni.nombre,"isa");
    r[3].puntaje=4.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"isa");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=2,strcpy(r[4].prof.uni.nombre,"oym");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"oym");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("oym", res.nombre);
}
MU_TEST(test_case6) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"oym");
    strcpy(u[1].nombre,"isa");
    strcpy(u[2].nombre,"unev");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"unev");
    r[1].puntaje=1.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"unev");
    r[2].puntaje=2.6,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"isa");
    r[3].puntaje=2.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"isa");
    r[4].puntaje=2.6,r[4].prof.asig.nivel=2,strcpy(r[4].prof.uni.nombre,"oym");
    r[5].puntaje=2.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"oym");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("isa", res.nombre);
}
MU_TEST(test_case7) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"unibe");
    strcpy(u[1].nombre,"pucmm");
    strcpy(u[2].nombre,"unphu");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"unphu");
    r[1].puntaje=2.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"pucmm");
    r[2].puntaje=2.6,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"pucmm");
    r[3].puntaje=1.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"unibe");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=2,strcpy(r[4].prof.uni.nombre,"pucmm");
    r[5].puntaje=2.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"unibe");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("pucmm", res.nombre);
}
MU_TEST(test_case8) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"unibe");
    strcpy(u[1].nombre,"pucmm");
    strcpy(u[2].nombre,"unphu");

    RESENA r[6];
    r[0].puntaje=2.6,r[0].prof.asig.nivel=0,strcpy(r[0].prof.uni.nombre,"unphu");
    r[1].puntaje=3.8,r[1].prof.asig.nivel=1,strcpy(r[1].prof.uni.nombre,"pucmm");
    r[2].puntaje=2.6,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"pucmm");
    r[3].puntaje=4.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"unibe");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=0,strcpy(r[4].prof.uni.nombre,"pucmm");
    r[5].puntaje=3.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"unibe");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("unibe", res.nombre);
}
MU_TEST(test_case9) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"unibe");
    strcpy(u[1].nombre,"pucmm");
    strcpy(u[2].nombre,"unphu");

    RESENA r[6];
    r[0].puntaje=1.6,r[0].prof.asig.nivel=2,strcpy(r[0].prof.uni.nombre,"unphu");
    r[1].puntaje=3.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"pucmm");
    r[2].puntaje=2.6,r[2].prof.asig.nivel=2,strcpy(r[2].prof.uni.nombre,"pucmm");
    r[3].puntaje=4.6,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"unibe");
    r[4].puntaje=4.6,r[4].prof.asig.nivel=2,strcpy(r[4].prof.uni.nombre,"pucmm");
    r[5].puntaje=2.2,r[5].prof.asig.nivel=2,strcpy(r[5].prof.uni.nombre,"unibe");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("pucmm", res.nombre);
}
MU_TEST(test_case10) {
    UNIVERSIDAD u[3];
    strcpy(u[0].nombre,"unibe");
    strcpy(u[1].nombre,"pucmm");
    strcpy(u[2].nombre,"unphu");

    RESENA r[6];
    r[0].puntaje=4.6,r[0].prof.asig.nivel=1,strcpy(r[0].prof.uni.nombre,"unphu");
    r[1].puntaje=3.8,r[1].prof.asig.nivel=2,strcpy(r[1].prof.uni.nombre,"pucmm");
    r[2].puntaje=4.3,r[2].prof.asig.nivel=0,strcpy(r[2].prof.uni.nombre,"pucmm");
    r[3].puntaje=4.7,r[3].prof.asig.nivel=2,strcpy(r[3].prof.uni.nombre,"unibe");
    r[4].puntaje=4.9,r[4].prof.asig.nivel=2,strcpy(r[4].prof.uni.nombre,"pucmm");
    r[5].puntaje=4.2,r[5].prof.asig.nivel=0,strcpy(r[5].prof.uni.nombre,"unibe");

    UNIVERSIDAD res=buscar_uni_con_mas_profesores_con_puntuacion_buena_y_curs_dificiles(3,u,6,r);
    mu_assert_string_eq("pucmm", res.nombre);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_case1);
    MU_RUN_TEST(test_case2);
    MU_RUN_TEST(test_case3);
    MU_RUN_TEST(test_case4);
    MU_RUN_TEST(test_case5);
    MU_RUN_TEST(test_case6);
    MU_RUN_TEST(test_case7);
    MU_RUN_TEST(test_case8);
    MU_RUN_TEST(test_case9);
    MU_RUN_TEST(test_case10);

}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}