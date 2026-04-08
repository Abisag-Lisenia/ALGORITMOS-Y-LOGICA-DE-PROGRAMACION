#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    float n1, n2, n3, prom, asist;
    int proy, plagio;
    string estado, obsD, obsR = "Rendimiento estandar";

    cout << "Notas (N1 N2 N3): "; cin >> n1 >> n2 >> n3;
    cout << "Asistencia (%): "; cin >> asist;
    cout << "Proyecto (1:Si, 0:No): "; cin >> proy;
    cout << "Plagio (1:Si, 0:No): "; cin >> plagio;

    prom = (n1 + n2 + n3) / 3.0;

    if (plagio == 1) {
        estado = "REPROBADO AUTOMATICAMENTE";
        obsD = "SANCION: PLAGIO DETECTADO";
    } else {
        obsD = "Sin faltas disciplinarias";
        if (asist < 70) {
            estado = "REPROBADO";
            obsR = "Inasistencia menor al 70%";
        } else {
            if (prom >= 9 && asist >= 95 && proy == 1) {
                estado = "APROBADO CON FELICITACION";
            } else if (prom >= 7 && proy == 1) {
                estado = "APROBADO";
            } else if (prom >= 5) {
                estado = "VA A RECUPERACION";
                if (proy == 0) obsR = "Proyecto no entregado";
            } else {
                estado = "REPROBADO";
                obsR = "Promedio insuficiente";
            }
        }
    }


    int bajas = 0;
    if (n1 < 4) bajas++;
    if (n2 < 4) bajas++;
    if (n3 < 4) bajas++;

    if ((n1 == 10 || n2 == 10 || n3 == 10) && bajas >= 2) {
        obsR = "RENDIMIENTO IRREGULAR (Nota 10 con dos notas < 4)";
    }

    cout << fixed << setprecision(2);
    cout << "\n======= REPORTE ACADEMICO =======" << endl;
    cout << "PROMEDIO: " << prom << endl;
    cout << "ESTADO  : " << estado << endl;
    cout << "DISCIPLINA: " << obsD << endl;
    cout << "OBSERVACION: " << obsR << endl;

    return 0;
}
