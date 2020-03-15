#include <minunit.h>

#include "bonoexamen.h"

#define MINUNIT_EPSILON 1E-1

MU_TEST(test_case1) {
    RESENA a[5];
    a[0].puntaje=2.6,a[0].est.indice=3.0;
    a[1].puntaje=2.4,a[1].est.indice=2.4;
    a[2].puntaje=2.7,a[2].est.indice=3.4;
    a[3].puntaje=4.5,a[3].est.indice=3.5;
    a[4].puntaje=2.0,a[4].est.indice=4.0;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(3.3, res);
}
MU_TEST(test_case2) {
    RESENA a[5];
    a[0].puntaje=2.8,a[0].est.indice=4.0;
    a[1].puntaje=2.6,a[1].est.indice=1.4;
    a[2].puntaje=2.3,a[2].est.indice=2.4;
    a[3].puntaje=2.6,a[3].est.indice=3.5;
    a[4].puntaje=2.0,a[4].est.indice=2.0;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(3.0, res);
}
MU_TEST(test_case3) {
    RESENA a[5];
    a[0].puntaje=1.8,a[0].est.indice=2.0;
    a[1].puntaje=1.6,a[1].est.indice=3.4;
    a[2].puntaje=3.3,a[2].est.indice=3.4;
    a[3].puntaje=4.6,a[3].est.indice=2.5;
    a[4].puntaje=5.0,a[4].est.indice=2.5;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(2.8, res);
}
MU_TEST(test_case4) {
    RESENA a[5];
    a[0].puntaje=3.8,a[0].est.indice=2.0;
    a[1].puntaje=1.9,a[1].est.indice=3.4;
    a[2].puntaje=2.3,a[2].est.indice=2.4;
    a[3].puntaje=4.1,a[3].est.indice=1.5;
    a[4].puntaje=2.0,a[4].est.indice=1.5;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(1.8, res);
}
MU_TEST(test_case5) {
    RESENA a[5];
    a[0].puntaje=4.8,a[0].est.indice=2.9;
    a[1].puntaje=3.9,a[1].est.indice=3.1;
    a[2].puntaje=3.3,a[2].est.indice=2.8;
    a[3].puntaje=1.1,a[3].est.indice=1.9;
    a[4].puntaje=2.2,a[4].est.indice=1.9;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(2.9, res);
}
MU_TEST(test_case6) {
    RESENA a[5];
    a[0].puntaje=2.8,a[0].est.indice=1.0;
    a[1].puntaje=2.9,a[1].est.indice=1.0;
    a[2].puntaje=3.3,a[2].est.indice=1.0;
    a[3].puntaje=4.1,a[3].est.indice=1.0;
    a[4].puntaje=4.0,a[4].est.indice=1.0;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(1.0, res);
}
MU_TEST(test_case7) {
    RESENA a[5];
    a[0].puntaje=1.8,a[0].est.indice=3.0;
    a[1].puntaje=2.9,a[1].est.indice=2.4;
    a[2].puntaje=3.3,a[2].est.indice=3.4;
    a[3].puntaje=2.1,a[3].est.indice=3.5;
    a[4].puntaje=3.0,a[4].est.indice=2.5;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(2.8, res);
}
MU_TEST(test_case8) {
    RESENA a[5];
    a[0].puntaje=4.8,a[0].est.indice=1.0;
    a[1].puntaje=2.9,a[1].est.indice=2.4;
    a[2].puntaje=3.3,a[2].est.indice=3.4;
    a[3].puntaje=2.1,a[3].est.indice=2.5;
    a[4].puntaje=2.0,a[4].est.indice=3.5;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(2.3, res);
}
MU_TEST(test_case9) {
    RESENA a[5];
    a[0].puntaje=1.8,a[0].est.indice=3.0;
    a[1].puntaje=3.9,a[1].est.indice=2.4;
    a[2].puntaje=2.3,a[2].est.indice=3.4;
    a[3].puntaje=1.1,a[3].est.indice=2.5;
    a[4].puntaje=4.0,a[4].est.indice=0.5;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(1.5, res);
}
MU_TEST(test_case10) {
    RESENA a[5];
    a[0].puntaje=2.4,a[0].est.indice=2.1;
    a[1].puntaje=2.0,a[1].est.indice=3.6;
    a[2].puntaje=2.3,a[2].est.indice=2.3;
    a[3].puntaje=4.1,a[3].est.indice=4.0;
    a[4].puntaje=2.0,a[4].est.indice=1.7;
    float res=calc_prom_ind_est_dieron_puntuacion_buena(5,a);
    mu_assert_double_eq(4.0, res);
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
