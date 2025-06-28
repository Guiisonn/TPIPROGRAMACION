#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

void mostrarMenu();
void menuReportes();

//   LOTE       MARCAS     -------------------

void CargarLoteMarcas (int VcodMarca[10],string VnomMarca[10]);

void CargarCodMarca(int i,int VcodMarca[10]);


// LOTE      PRODUCTOS -----------

void CargarNomMarca (int i,string VnomMarca[10]);

void CargarLoteProd (int VcodProd[20],
                 string VnomProd[20],
                 float VpreVta[20],
                 float VpreCmp[20],
                 int Vstock[20],
                 int VcodMarcaComp[20],int VcodMarca[10]);

void VerifComp(int i,int VcodMarcaComp[20],int VcodMarca[10]);

//   LOTE     FORMAS    PAGO --------------

void CargarLoteFPago (string VcodFP[5],string VnombFP[5],int Vporcen[5]);

int ValidarCFP(string codFP,string VcodFP[5]);

void RevalidarFP (int indfp,bool&BE,bool&BM,bool&BT,bool&BTC,bool&BC);


//  LOTE     PROCESO   --------------------------------


void Proceso (int VcodProd[20],string VnombFP[5],int VacuRec [20],int VcantVnd[20],int Vindice[20],int Vstock[20],float VpreVta[20],int Vporcen[5] );


int indiceProducto(int codProd,int VcodProd[20]);
int indiceFormaPago(string formPag,string VnombFP[5]);
int calcularTotal (int inpr,int infp,int cantVnd,float VpreVta[20],int Vporcen[5]);
void ordenPuntoA(int VcantVnd[20],int Vindice[20]);

void reporteRecaudacionProducto();

void reportePorcentajeFormasPago();

void reporteVentasPorMarcaYForma();

void reporteProductosSinVenta();

void reporteTop10Clientes();



















#endif // FUNCIONES_H_INCLUDED

