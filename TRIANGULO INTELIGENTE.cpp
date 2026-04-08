#include <iostream>
#include <string>

using namespace std;

int main() {
    float l1, l2, l3, h, ang, area;
    string tLados, tAngulos, msjConsistencia;

    cout << "Ingrese Lado 1 (Base), Lado 2 y Lado 3: ";
    cin >> l1 >> l2 >> l3;
    cout << "Ingrese la Altura (h): ";
    cin >> h;
    cout << "Ingrese el Angulo principal: ";
    cin >> ang;


    if ((l1 + l2 <= l3) || (l1 + l3 <= l2) || (l2 + l3 <= l1)) {
        cout << "\nVALIDEZ: Triangulo invalido. La suma de dos lados debe superar al tercero." << endl;
    }
    else {

        if (l1 == l2 && l2 == l3) tLados = "Equilatero";
        else if (l1 == l2 || l1 == l3 || l2 == l3) tLados = "Isosceles";
        else tLados = "Escaleno";


        if (ang < 90) tAngulos = "Acutangulo";
        else if (ang == 90) tAngulos = "Rectangulo";
        else tAngulos = "Obtusangulo";


        area = (l1 * h) / 2;


        if (h > l2 || h > l3) {
            msjConsistencia = "ADVERTENCIA: La altura ingresada es fisicamente imposible para estos lados.";
        } else {
            msjConsistencia = "GEOMETRIA: Consistente.";
        }


        cout << "\n========== ANALISIS DE TRIANGULO ==========" << endl;
        cout << "TIPO POR LADOS : " << tLados << endl;
        cout << "TIPO POR ANGULOS: " << tAngulos << endl;
        cout << "AREA CALCULADA : " << area << " unidades cuadradas." << endl;
        cout << "ESTADO         : " << msjConsistencia << endl;
        cout << "===========================================" << endl;
    }

    return 0;
}
