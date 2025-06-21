#include <iostream>
#include "funciones.h"
using namespace std;

// ------------------------ Menú Principal ------------------------
void mostrarMenu() {
    cout << "\n====== GESTIÓN DE COMERCIO ======\n";
    cout << "1. Cargar lote de marcas\n";
    cout << "2. Cargar lote de productos\n";
    cout << "3. Cargar lote de formas de pago\n";
    cout << "4. Cargar lote de ventas\n";
    cout << "5. Mostrar reportes\n";
    cout << "0. Salir\n";
}

// ------------------------ Submenú de Reportes ------------------------
void menuReportes() {
    int op;
    do {
        cout << "\n--- Reportes Disponibles ---\n";
        cout << "1. Recaudación por producto\n";
        cout << "2. Porcentaje de ventas por forma de pago\n";
        cout << "3. Ventas por marca y forma de pago\n";
        cout << "4. Productos sin ventas\n";
        cout << "5. Top 10 clientes + Sorteo\n";
        cout << "0. Volver al menú principal\n";
        cout << "Ingrese una opción: ";
        cin >> op;

        switch (op) {
            case 1: reporteRecaudacionProducto(); break;
            case 2: reportePorcentajeFormasPago(); break;
            case 3: reporteVentasPorMarcaYForma(); break;
            case 4: reporteProductosSinVenta(); break;
            case 5: reporteTop10Clientes(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }

    } while (op != 0);
}

// ------------------------ Funciones de carga ------------------------
void cargarMarcas() {
    cout << "[FUNC] Carga de marcas aún no implementada.\n";
}

void cargarProductos() {
    cout << "[FUNC] Carga de productos aún no implementada.\n";
}

void cargarFormasPago() {
    cout << "[FUNC] Carga de formas de pago aún no implementada.\n";
}

void cargarVentas() {
    cout << "[FUNC] Carga de ventas aún no implementada.\n";
}

// ------------------------ Reportes ------------------------
void reporteRecaudacionProducto() {
    cout << "[REPORT] Recaudación por producto aún no implementada.\n";
}

void reportePorcentajeFormasPago() {
    cout << "[REPORT] Porcentaje por forma de pago aún no implementado.\n";
}

void reporteVentasPorMarcaYForma() {
    cout << "[REPORT] Ventas por marca y forma aún no implementado.\n";
}

void reporteProductosSinVenta() {
    cout << "[REPORT] Productos sin ventas aún no implementado.\n";
}

void reporteTop10Clientes() {
    cout << "[REPORT] Top 10 clientes aún no implementado.\n";
}
