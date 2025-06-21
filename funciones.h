#ifndef FUNCIONES_H
#define FUNCIONES_H

// Prototipos del menú
void mostrarMenu();
void menuReportes();

// Prototipos de carga de lotes
void cargarMarcas();
void cargarProductos();
void cargarFormasPago();
void cargarVentas();

// Prototipos de reportes (a implementar después)
void reporteRecaudacionProducto();
void reportePorcentajeFormasPago();
void reporteVentasPorMarcaYForma();
void reporteProductosSinVenta();
void reporteTop10Clientes();

#endif
