#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cargarMarcas(); break;
            case 2: cargarProductos(); break;
            case 3: cargarFormasPago(); break;
            case 4: cargarVentas(); break;
            case 5: menuReportes(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción inválida\n";
        }
    } while (opcion != 0);

    return 0;
}
