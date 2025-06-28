#include "Funciones.h"
#include <random>
#include <ctime>

//Menu Principal
void mostrarMenu()
{
    cout << "========== GESTION DE COMERCIO ==================="<<endl;
    cout << "##                                              ##                        "<<endl;
    cout << "##   [1] Cargar lote de marcas                  ##    ######## #######   ##    Intregantes:            "<<endl;
    cout << "##   [2] Cargar lote de productos               ##       ||    ||     #  ##    [] Alan Menendez         "<<endl;
    cout << "##   [3] Cargar lote de formas de pago          ##       ||    ||     #  ||    [] Nicolas Maidana         "<<endl;
    cout << "##   [4] Cargar lote de ventas                  ##       ||    ||#####   ||    [] Roman Burgos        "<<endl;
    cout << "##   [5] Mostrar reportes                       ##       ||    ||        ||    [] Uziel Re         "<<endl;
    cout << "##   [0] Salir                                  ##       ||    ||        ||                      "<<endl;
    cout << "##                                              ##       ||    ||        ||                       "<<endl;
    cout<<"===================================================                                                  "<<endl;
    cout<<endl;

}
//SUBMENU
void menuReportes()
{


    int opcion;


    do
    {

        cout << "========== SUBMENU DE REPORTES ======================="<<endl;
        cout << "##                                                 ## "<<endl;
        cout << "##   [1] Recaudacion por producto                  ## "<<endl;
        cout << "##   [2] Porcentaje de ventas por forma de pago    ## "<<endl;
        cout << "##   [3] Ventas por marca y forma de pago          ##  "<<endl;
        cout << "##   [4] Productos sin ventas                      ##   "<<endl;
        cout << "##   [5] Top 10 clientes y Sorteo de cupones       ##       "<<endl;
        cout << "##   [0] Salir                                     ##           "<<endl;
        cout << "##                                                 ##           "<<endl;
        cout<<"=======================================================             "<<endl;
        cout<<endl;


    }
    while (opcion != 0);


}





//  L   O  T  E        D  E        M   A  R  C  A  S----------------------------------





void CargarLoteMarcas (int VcodMarca[10],string VnomMarca[10])
{
    for (int i = 0; i < 10; i++)
    {
        CargarCodMarca(i,VcodMarca);
        CargarNomMarca(i,VnomMarca);
    }
}

void CargarCodMarca(int i,int VcodMarca[10])
{
    int cod;
    bool BC=false;
    while (!BC)
    {
        cout<<"Ingrese el codigo de marca: "<<endl;
        cin>>cod;
        VcodMarca[i]=cod;
        if (VcodMarca[i]>=1&&VcodMarca[i]<=10)
        {
            BC=true;
        }
        else
        {
            cout<<"Numero no valido."<<endl;
        }
    }
}

void CargarNomMarca (int i,string VnomMarca[10])
{
    string nom;
    bool BN=false;
    while (!BN)
    {
        cout<<"Ingrese el nombre de la marca: "<<endl;
        cin.ignore();
        getline(cin, nom);
        VnomMarca[i]=nom;
        if(VnomMarca[i]=="")
        {
            cout<<"Nombre no ingresado."<<endl<<endl;
        }
        else
        {
            BN=true;
        }
    }
}


//   L  O  T  E       D  E       P  R  O  D  U  C  T  O  S--------------------------------



void CargarLoteProd(int VcodProd[20],
                    string VnomProd[20],
                    float VpreVta[20],
                    float VpreCmp[20],
                    int Vstock[20],
                    int VcodMarcaComp[20],int VcodMarca[10])
{

    for (int i=0; i<20; i++)
    {
        cout<<"Ingrese el codigo del producto:"<<endl;
        cin>>VcodProd[i];
        cout<<"Ingrese el nombre del producto:"<<endl;
        cin>>VnomProd[i];
        cout<<"Ingrese el precio de venta del producto:"<<endl;
        cin>>VpreVta[i];
        cout<<"Ingrese el precio de compra del producto:"<<endl;
        cin>>VpreCmp[i];
        cout<<"Ingrese el stock:"<<endl;
        cin>>Vstock[i];
        VerifComp(i,VcodMarcaComp,VcodMarca);
    }
}

void VerifComp(int i,int VcodMarcaComp[20],int VcodMarca[10])
{
    bool BCM=false;
    while(!BCM)
    {
        cout<<"Ingrese Codigo Marca:"<<endl;
        cin>>VcodMarcaComp[i];
        BCM=false;

        for(int y=0; y<10; y++)
        {
            if (VcodMarcaComp[i]==VcodMarca[y])
            {
                BCM=true;
                break;
            }
        }
        if (!BCM)
        {
            cout<<"no existe"<<endl;
        }
    }
}


//    L  O  T  E     F  O  R  M  A  S     P  A  G  O-----------------------------------------


void CargarLoteFPago(string VcodFP[5],string VnombFP[5],int Vporcen[5])
{
    int indfp;
    string codFP;
    bool BE=false,BM =false,BT=false,BTC=false,BC=false;

    for (int i=0; i<10; i++)
    {
        cout<<"Ingrese Codigo de forma de pago(BE/BM/BTC/BC): "<<endl;
        cin>>codFP;

        indfp= ValidarCFP(codFP,VcodFP);

        RevalidarFP(indfp,BE,BM,BT,BTC,BC);
    }
}

int ValidarCFP(string codFP,string VcodFP[5])
{
    for  (int i=0; i<5; i++)

    {
        if(codFP==VcodFP[i])

            return i;
    }
}

void RevalidarFP (int indfp,bool&BE,bool&BM,bool&BT,bool&BTC,bool&BC)

{
    switch (indfp)
    {
    case 0:
        BE=true;
        break;
    case 1:
        BM=true;
        break;
    case 2:
        BT=true;
        break;
    case 3:
        BTC=true;
        break;
    case 4:
        BC=true;
        break;

    default:
        cout << "Opción inválida";

    }

}


//    L  O  T  E          D  E        P  R  O  C  E  S  O     ----------------------



void  Proceso (int VcodProd[20],string VnombFP[5],int VacuRec [20],int VcantVnd[20],int Vindice[20],int Vstock[20],float VpreVta[20],int Vporcen[5] )
{


    int nroComp;
    int codProd;
    string formPag;
    int cantVnd;
    int codCli;
    int diaVta;

    int inpr;
    int infp;
    int total;

    cout<<"Ingrese Numero de compra: "<<endl;
    cin>>nroComp;
    cout<<"Ingrese Codigo de Producto: "<<endl;
    cin>>codProd;
    cout<<"Ingrese Forma de pago: "<<endl;
    cin>>formPag;
    cout<<"Ingrese Cantidad vendida: "<<endl;
    cin>>cantVnd;
    cout<<"Ingrese codigo de cliente: "<<endl;
    cin>>codCli;
    cout<<"Ingrese dia de la venta: "<<endl;
    cin>>diaVta;

    while(diaVta!=0)
    {


        inpr=indiceProducto(codProd,VcodProd);

        infp=indiceFormaPago (formPag,VnombFP);

        total=calcularTotal (inpr,infp,cantVnd,VpreVta,Vporcen);

        VcantVnd[inpr]+=cantVnd;
        VacuRec[inpr]+=total;
        Vstock[inpr] -= cantVnd;




















        cout<<"Ingrese Numero de compra: "<<endl;
        cin>>nroComp;
        cout<<"Ingrese Codigo de Producto: "<<endl;
        cin>>codProd;
        cout<<"Ingrese Forma de pago: "<<endl;
        cin>>formPag;
        cout<<"Ingrese Cantidad vendida: "<<endl;
        cin>>cantVnd;
        cout<<"Ingrese codigo de cliente: "<<endl;
        cin>>codCli;
        cout<<"Ingrese dia de la venta: "<<endl;
        cin>>diaVta;



    }




}





//  F  U  N  C  I  O  N  E  S      D  E    P  R  O  C  E  S O     EN      W   H   I   L   E   --------






int indiceProducto(int codProd,int VcodProd[20])
{
    for (int i=0; i<20; i++)
    {

        if(codProd==VcodProd[i])
        {
            return i;
        }
    }
}


int indiceFormaPago(string formPag,string VnombFP[5])
{
    for (int i=0; i<20; i++)
    {
        if(formPag==VnombFP[i])
        {

            return i;
        }
    }

}

int calcularTotal (int inpr,int infp,int cantVnd,float VpreVta[20],int Vporcen[5])
{

    return VpreVta[inpr]*cantVnd*(1+Vporcen[infp]);

}


// P     R     O   C  E   S  O   S            F  U  E  R  A       D  E     W  H  I  L E



void ordenPuntoA(int VcantVnd[20],int Vindice[20])
{

    int aux;
    for (int x=0; x<20; x++)
    {

        Vindice[x]=x;

    }



    for (int i=0; i<20; i++)
    {
        for (int y=0; y<20; y++)
        {

            if (VcantVnd[y] <VcantVnd[y+1] )

                aux=VcantVnd[y+1];
            VcantVnd[y+1]=VcantVnd[y];
            VcantVnd[y]=aux;
            aux=Vindice[y+1];
            Vindice[y+1]=Vindice[y];
            Vindice[y]=aux;

        }


    }
}










//  L  O  T  E      D  E       R  E  P   O  R  T  E  S

//punto 3
void reporteVentasPorMarcaYFormaPago() {
    int matriz[TOTAL_MARCAS][TOTAL_FORMAS] = {};

    for (int i = 0; i < totalVentas; i++) {
        int idxForma = obtenerIndiceFormaPago(ventas[i].formaPago);
        for (int j = 0; j < TOTAL_PRODUCTOS; j++) {
            if (ventas[i].codigoProducto == productos[j].codigo) {
                int marca = productos[j].codigoMarca - 1;
                if (marca >= 0 && marca < TOTAL_MARCAS && idxForma != -1) {
                    matriz[marca][idxForma] += ventas[i].cantidad;
                }
                break;
            }
        }
    }

    string formas[] = {"EF", "MP", "TR", "TC", "CT"};
    cout << "\nVentas por marca y forma de pago:\n";
    for (int i = 0; i < TOTAL_MARCAS; i++) {
        cout << "Marca " << (i + 1) << ": ";
        for (int j = 0; j < TOTAL_FORMAS; j++) {
            cout << formas[j] << "=" << matriz[i][j] << " ";
        }
        cout << endl;
    }
}









//punto 5

struct ClienteInfo {
    int codigoCliente;
    int compras;
};

bool comparar(ClienteInfo a, ClienteInfo b) {
    return a.compras > b.compras;
}

void reporteTop10Clientes() {
    int comprasPorCliente = {};
    for (int i = 0; i < totalVentas; i++) {
        comprasPorCliente[ventas[i].codigoCliente - 1]++;
    }

    ClienteInfo clientes[TOTAL_CLIENTES];
    for (int i = 0; i < TOTAL_CLIENTES; i++) {
        clientes[i].codigoCliente = i + 1;
        clientes[i].compras = comprasPorCliente[i];
    }
    sort(clientes, clientes + TOTAL_CLIENTES, comparar);

    cout << "\nTop 10 clientes con mas compras:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Cliente " << clientes[i].codigoCliente << " - Compras: " << clientes[i].compras << endl;
    }

    srand(time(NULL));
    vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(indices.begin(), indices.end());

    cout << " Ganadores del cupón:"endl;
    for (int i = 0; i < 3; i++) {
        int idx = indices[i];
        cout << "Cliente " << clientes[idx].codigoCliente << " - Compras: " << clientes[idx].compras << endl;
    }
}











}



