#include <iostream>

using namespace std;

int main() {

    int b20 = 10, b10 = 10, b5 = 10, b1 = 10;
    float efectivoCajero = (b20*20) + (b10*10) + (b5*5) + (b1*1);
    float saldoUsuario = 1000.0;

    int pedido, montoAux;
    int e20=0, e10=0, e5=0, e1=0;

    cout << "--- CAJERO AUTOMATICO ---" << endl;
    cout << "Saldo en cuenta: $" << saldoUsuario << endl;
    cout << "Monto a retirar: "; cin >> pedido;

    if (pedido <= 0 || pedido > saldoUsuario || pedido > efectivoCajero) {
        cout << "Operacion rechazada: Fondos insuficientes o monto invalido." << endl;
    } else {
        montoAux = pedido;


        e20 = montoAux / 20;
        if (e20 > b20) e20 = b20;
        montoAux -= (e20 * 20);

        e10 = montoAux / 10;
        if (e10 > b10) e10 = b10;
        montoAux -= (e10 * 10);

        e5 = montoAux / 5;
        if (e5 > b5) e5 = b5;
        montoAux -= (e5 * 5);

        e1 = montoAux / 1;
        if (e1 > b1) e1 = b1;
        montoAux -= (e1 * 1);


        if (montoAux == 0) {
            saldoUsuario -= pedido;
            efectivoCajero -= pedido;
            cout << "\n--- COMPROBANTE DE RETIRO ---" << endl;
            cout << "Billetes de $20: " << e20 << endl;
            cout << "Billetes de $10: " << e10 << endl;
            cout << "Billetes de $5 : " << e5 << endl;
            cout << "Billetes de $1 : " << e1 << endl;
            cout << "-----------------------------" << endl;
            cout << "Nuevo Saldo Cuenta : $" << saldoUsuario << endl;
            cout << "Efectivo en Cajero : $" << efectivoCajero << endl;
        } else {
            cout << "Error: No hay billetes suficientes para el monto exacto." << endl;
        }
    }

    return 0;
}
