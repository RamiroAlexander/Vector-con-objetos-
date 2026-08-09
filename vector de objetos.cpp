#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int main() {

    vector<string> productos = { "Cuaderno", "Lapiz", "Borrador", "Regla", "Marcador" };
    vector<float> precios = { 40.50, 5.00, 3.50, 10.00, 15.00 };

    productos.push_back("Sacapuntas");
    precios.push_back(12.50);

    cout << "--- LISTADO DE PRODUCTOS ---" << endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << productos[i] << " - $" << precios[i] << endl;
    }
    cout << endl;

    int pos = 1; 

    try {
        productos.at(pos);
        precios.at(pos);

        productos.erase(productos.begin() + pos);
        precios.erase(precios.begin() + pos);

        cout << "Producto en la posicion " << pos << " eliminado." << endl << endl;
    }
    catch (out_of_range) {
        cout << "Error: La posicion no existe." << endl << endl;
    }

    cout << "--- LISTA ACTUALIZADA ---" << endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << productos[i] << " - $" << precios[i] << endl;
    }
    cout << endl;

    float suma = 0;
    for (int i = 0; i < precios.size(); i++) {
        suma += precios[i];
    }
    float promedio = suma / precios.size();
    cout << "Precio promedio: $" << promedio << endl;

    float precioMayor = precios[0];
    string productoMayor = productos[0];

    for (int i = 1; i < precios.size(); i++) {
        if (precios[i] > precioMayor) {
            precioMayor = precios[i];
            productoMayor = productos[i];
        }
    }

    cout << "Producto mas caro: " << productoMayor << " ($" << precioMayor << ")" << endl;

    return 0;
}