#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int hojas, tipoColor, rol, horario, anillado;
    float pBase, subtotal, descuento = 0, recargo = 0, costoAnillado = 0, total;

    cout << "--- COPIADORA UNIVERSITARIA ---" << endl;
    cout << "Hojas: "; cin >> hojas;
    cout << "Tipo (1:Color, 0:B/N): "; cin >> tipoColor;
    cout << "Rol (1:Docente, 0:Estudiante): "; cin >> rol;
    cout << "Horario (1:Nocturno, 0:Normal): "; cin >> horario;
    cout << "Anillado (1:Si, 0:No): "; cin >> anillado;


    if (hojas <= 20) pBase = 0.10;
    else if (hojas <= 100) pBase = 0.08;
    else pBase = 0.05;

    if (tipoColor == 1) pBase += 0.15;

    subtotal = pBase * hojas;


    float tasaDesc = 0;
    if (rol == 1) tasaDesc = 0.05;
    else if (rol == 0 && hojas > 50) tasaDesc = 0.08;

    descuento = subtotal * tasaDesc;


    if (horario == 1) recargo = subtotal * 0.10;


    if (anillado == 1) {
        costoAnillado = 1.50;
        if (hojas > 100) costoAnillado *= 0.50;
    }

    total = (subtotal - descuento) + recargo + costoAnillado;

    cout << fixed << setprecision(2);
    cout << "\n======= FACTURA =======" << endl;
    cout << "Subtotal Impresion: $" << subtotal << endl;
    cout << "Descuento aplicado: $" << descuento << endl;
    cout << "Recargo Nocturno  : $" << recargo << endl;
    cout << "Costo Anillado    : $" << costoAnillado << endl;
    cout << "-----------------------" << endl;
    cout << "TOTAL A PAGAR     : $" << total << endl;

    return 0;
}
