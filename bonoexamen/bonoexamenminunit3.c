#include <minunit.h>
#include <string.h>
#include "bonoexamen.h"

#define MINUNIT_EPSILON 1E-6

MU_TEST(test_case1) {
    RESENA b[2];
    b[0].est.id=1,b[0].puntaje=2.6;
    b[1].est.id=5,b[1].puntaje=2.8;

    ESTUDIANTE a[2];
    a[0].id=1;
    a[1].id=2;

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_double_eq(2, res.id);
}

MU_TEST(test_case2) {
    RESENA b[2];
    b[0].puntaje=2.5;
    b[1].puntaje=3.8;

    ESTUDIANTE a[2];
    a[0].id=5;
    a[1].id=7;

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_double_eq(7, res.id);
}

MU_TEST(test_case3) {
    RESENA b[2];
    b[0].puntaje=2.9;
    b[1].puntaje=3.0;

    ESTUDIANTE a[2];
    a[0].id=1;
    a[1].id=5;

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_double_eq(5, res.id);
}

MU_TEST(test_case4) {
    RESENA b[2];
    b[0].puntaje=2.4;
    b[1].puntaje=2.5;

    ESTUDIANTE a[2];
    a[0].id=3;
    a[1].id=2;

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_double_eq(2, res.id);
}
MU_TEST(test_case5) {
    RESENA b[2];
    b[0].puntaje=2.4;
    b[1].puntaje=2.5;

    ESTUDIANTE a[2];
    strcpy(a[0].nombre, "jose");
    strcpy(a[1].nombre, "santiago");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("santiago", res.nombre);
}
MU_TEST(test_case6) {
    RESENA b[2];
    b[0].puntaje=1.5;
    b[1].puntaje=3.9;

    ESTUDIANTE a[2];
    strcpy(a[0].nombre, "ramon");
    strcpy(a[1].nombre, "rochy");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("rochy", res.nombre);
}
MU_TEST(test_case7) {
    RESENA b[2];
    b[0].puntaje=5.0;
    b[1].puntaje=4.9;

    ESTUDIANTE a[2];
    strcpy(a[1].nombre, "tornado");
    strcpy(a[0].nombre, "saul");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("tornado", res.nombre);
}
MU_TEST(test_case8) {
    RESENA b[2];
    b[0].puntaje=4.2;
    b[1].puntaje=5.0;

    ESTUDIANTE a[2];
    strcpy(a[0].usuario, "itorres");
    strcpy(a[1].usuario, "sgenao");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("sgenao", res.usuario);
}
MU_TEST(test_case9) {
    RESENA b[2];
    b[0].puntaje=4.0;
    b[1].puntaje=3.9;

    ESTUDIANTE a[2];
    strcpy(a[1].usuario, "pperez");
    strcpy(a[0].usuario, "jlopez");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("pperez", res.usuario);
}
MU_TEST(test_case10) {
    RESENA b[2];
    b[0].puntaje=2.4;
    b[1].puntaje=2.5;

    ESTUDIANTE a[2];
    strcpy(a[0].nombre, "jose");
    strcpy(a[0].usuario, "jpons");
    strcpy(a[1].nombre, "santiago");
    strcpy(a[1].usuario, "la_maxima");

    ESTUDIANTE res=buscar_est_dio_mejor_rating(2,b,2,a);

    mu_assert_string_eq("santiago", res.nombre);
    mu_assert_string_eq("la_maxima", res.usuario);
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

