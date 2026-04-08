#include <iostream>
#include <string>

using namespace std;

int main() {
    float promedio, asistencia;
    int materiasPerdidas, proyectos, ingresos, nivel = 0;
    string ayuda, r_acad, r_econ, obs = "Proceso estandar";

    cout << "--- SISTEMA DE BECAS UNIVERSITARIAS ---" << endl;
    cout << "Promedio: "; cin >> promedio;
    cout << "Materias perdidas: "; cin >> materiasPerdidas;
    cout << "Porcentaje asistencia: "; cin >> asistencia;
    cout << "Participa en proyectos (1:Si, 0:No): "; cin >> proyectos;
    cout << "Ingresos bajos (1:Si, 0:No): "; cin >> ingresos;

    if (asistencia < 80 || promedio < 7) {
        ayuda = "Sin beneficio";
        r_acad = "No alcanza el minimo academico o de asistencia";
        r_econ = "N/A";
        obs = "Rechazado automaticamente";
    } else {
        // Calculo Nivel Base
        if (promedio >= 9 && asistencia >= 90 && materiasPerdidas == 0) {
            nivel = 3;
            r_acad = "Excelencia academica (Sobresaliente)";
        } else if (promedio >= 8 && asistencia >= 85) {
            nivel = 2;
            r_acad = "Buen rendimiento académico";
        } else {
            nivel = 1;
            r_acad = "Rendimiento aceptable";
        }

        // Modificador socio-proyectos
        if (proyectos == 1 && ingresos == 1) {
            r_econ = "Ingresos bajos y participacion activa";
            if (nivel == 1) {
                nivel = 2;
                obs = "Nivel subido por apoyo social y proyectos";
            } else if (nivel == 2 && materiasPerdidas == 0) {
                nivel = 3;
                obs = "Nivel subido a Completa por merito social";
            } else if (nivel == 2 && materiasPerdidas > 0) {
                obs = "No puede subir a Completa por materias perdidas";
            }
        } else {
            r_econ = "Ingresos estables o sin proyectos";
        }


        if (nivel == 1) ayuda = "Solo ayuda de materiales";
        else if (nivel == 2) ayuda = "Beca parcial";
        else if (nivel == 3) ayuda = "Beca completa";
    }

    cout << "\n========== RESULTADO ==========" << endl;
    cout << "AYUDA: " << ayuda << endl;
    cout << "RAZON ACAD: " << r_acad << endl;
    cout << "RAZON ECON: " << r_econ << endl;
    cout << "OBSERVACION: " << obs << endl;

    return 0;
}
