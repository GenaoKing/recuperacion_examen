#include <minunit.h>
#include <string.h>
#include "bonoexamen.h"

#define MINUNIT_EPSILON 1E-2

MU_TEST(test_case1) {
    PROFESOR prof;
    strcpy(prof.nombre,"santiago");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"santiago");
    a[0].puntaje=3.0;
    strcpy(a[1].prof.nombre,"santiago");
    a[1].puntaje=3.5;
    strcpy(a[2].prof.nombre,"Saul");
    a[2].puntaje=2.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.25, res);
}
MU_TEST(test_case2) {
    PROFESOR prof;
    strcpy(prof.nombre,"saul");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"saul");
    a[0].puntaje=4.0;
    strcpy(a[1].prof.nombre,"santiago");
    a[1].puntaje=3.5;
    strcpy(a[2].prof.nombre,"saul");
    a[2].puntaje=4.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.35, res);
}
MU_TEST(test_case3) {
    PROFESOR prof;
    strcpy(prof.nombre,"ramon");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"ramon");
    a[0].puntaje=4.5;
    strcpy(a[1].prof.nombre,"ramon");
    a[1].puntaje=4.8;
    strcpy(a[2].prof.nombre,"ramon");
    a[2].puntaje=4.9;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.17, res);
}
MU_TEST(test_case4) {
    PROFESOR prof;
    strcpy(prof.nombre,"ivan");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"ivan");
    a[0].puntaje=5.0;
    strcpy(a[1].prof.nombre,"ivan");
    a[1].puntaje=4.7;
    strcpy(a[2].prof.nombre,"ivan");
    a[2].puntaje=5.0;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.141, res);
}
MU_TEST(test_case5) {
    PROFESOR prof;
    strcpy(prof.nombre,"alejandro");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"alejandro");
    a[0].puntaje=1.0;
    strcpy(a[1].prof.nombre,"alejandro");
    a[1].puntaje=0.8;
    strcpy(a[2].prof.nombre,"alejandro");
    a[2].puntaje=0.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.125, res);
}
MU_TEST(test_case6) {
    PROFESOR prof;
    strcpy(prof.nombre,"alonso");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"alonso");
    a[0].puntaje=5.0;
    strcpy(a[1].prof.nombre,"alonso");
    a[1].puntaje=5.0;
    strcpy(a[2].prof.nombre,"alonso");
    a[2].puntaje=4.9;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.0471, res);
}
MU_TEST(test_case7) {
    PROFESOR prof;
    strcpy(prof.nombre,"pedro");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"pedro");
    a[0].puntaje=3.0;
    strcpy(a[1].prof.nombre,"santiago");
    a[1].puntaje=3.8;
    strcpy(a[2].prof.nombre,"pedro");
    a[2].puntaje=2.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.15, res);
}
MU_TEST(test_case8) {
    PROFESOR prof;
    strcpy(prof.nombre,"torres");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"fernando");
    a[0].puntaje=4.9;
    strcpy(a[1].prof.nombre,"torres");
    a[1].puntaje=2.5;
    strcpy(a[2].prof.nombre,"torres");
    a[2].puntaje=3.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.6, res);
}
MU_TEST(test_case9) {
    PROFESOR prof;
    strcpy(prof.nombre,"fernando");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"fernando");
    a[0].puntaje=4.9;
    strcpy(a[1].prof.nombre,"fernando");
    a[1].puntaje=4.5;
    strcpy(a[2].prof.nombre,"saul");
    a[2].puntaje=1.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.2, res);
}
MU_TEST(test_case10) {
    PROFESOR prof;
    strcpy(prof.nombre,"caridad");
    RESENA a[3];
    strcpy(a[0].prof.nombre,"caridad");
    a[0].puntaje=4.3;
    strcpy(a[1].prof.nombre,"caridad");
    a[1].puntaje=4.7;
    strcpy(a[2].prof.nombre,"pablo");
    a[2].puntaje=2.7;
    float res=calc_desv_std_rating_prof(prof,3,a);
    mu_assert_double_eq(0.2, res);
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