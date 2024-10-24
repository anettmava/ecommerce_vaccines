#include <iostream>
#include <string>

using namespace std;

// Cliente
class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;

public:
    Cliente(string newName, string newDireccion, string newTelefono) {
        nombre = newName;
        direccion = newDireccion;
        telefono = newTelefono;
    }

    string getNombre() {
        return nombre;
    }

    string getDireccion() {
        return direccion;
    }

    string getTelefono() {
        return telefono;
    }

    // Setters
    void setNombre(string newName) {
        nombre = newName;
    }

    void setDireccion(string newDireccion) {
        direccion = newDireccion;
    }

    void setTelefono(string newTelefono) {
        telefono = newTelefono;
    }
};

// Vacuna
class Vacuna {
private:
    string tipo;
    int costo;
    int cantidad;

public:
    Vacuna(string newTipo, int newCosto, int newCantidad) {
        tipo = newTipo;
        costo = newCosto;
        cantidad = newCantidad;
    }

    string getTipo() {
        return tipo;
    }

    int getCosto() {
        return costo;
    }

    int getCantidad() {
        return cantidad;
    }

    // Setters
    void setTipo(string newTipo) {
        tipo = newTipo;
    }

    void setCosto(int newCosto) {
        costo = newCosto;
    }

    void setCantidad(int newCantidad) {
        cantidad = newCantidad;
    }

    // Función para restar la cantidad de vacunas que se van a comprar
    void actualizarCantidad(int cantidadComprar) {
        if (cantidadComprar > 0 && cantidadComprar <= cantidad) {
            cantidad -= cantidadComprar;
            cout << "¡Gracias por tu compra! Tu pedido llegará pronto. El costo total es de: $" << cantidadComprar * costo << endl;
            cout << "Usted compró " << cantidadComprar << " vacunas de " << tipo << endl;
        } else {
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "No hay suficientes vacunas, por lo que no se realizó la compra, disculpe las molestias." << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        }
    }
};

// Inventario
class InventarioVacunas {
private:
    Vacuna vacunaInfluenza;
    Vacuna vacunaCovid;

public:
    InventarioVacunas() : vacunaInfluenza("Influenza", 40, 150), vacunaCovid("COVID", 20, 150) {
        cout << "El costo de la vacuna de COVID es $20 y el costo de la vacuna de influenza es $40." << endl;
    }

    // Func tabla de inventario
    void mostrarInventario() {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "           INVENTARIO DE VACUNAS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

        cout << "Tipo de vacuna\t\tCantidad disponible\n";
        cout << "-----------------------------------------------\n";
        cout << "COVID\t\t\t" << vacunaCovid.getCantidad() << " vacunas\n";
        cout << "Influenza\t\t" << vacunaInfluenza.getCantidad() << " vacunas\n";
        cout << "-----------------------------------------------\n";
    }

    // Menú de vacunas
    void comprarVacunas(Cliente& cliente) {
        int opcion;
        cout << "Seleccione el número correspondiente a la vacuna que desea comprar:\n1. Influenza\n2. COVID\n";
        cin >> opcion;

        int cantidadComprar;
        cout << "Ingrese la cantidad de vacunas que desea comprar: " << endl;
        cin >> cantidadComprar;

        // Switch para pasar la cantidad que el usuario quiere comprar
        switch (opcion) {
            case 1:
                if (cantidadComprar > vacunaInfluenza.getCantidad()) {
                    cout << "No hay suficientes vacunas de Influenza disponibles." << endl;
                    return; // salir si no hay en stock
                }
                vacunaInfluenza.actualizarCantidad(cantidadComprar);
                break;
            case 2:
                if (cantidadComprar > vacunaCovid.getCantidad()) {
                    cout << "No hay suficientes vacunas de COVID disponibles." << endl;
                    return; 
                }
                vacunaCovid.actualizarCantidad(cantidadComprar);
                break;
            default:
                cout << "Opción inválida, solo hay 2 tipos de vacunas, debes seleccionar 1 o 2." << endl;
                return;
        }

        // Imprimir resumen de compra con datos del cliente
        cout << "\n==============================";
        cout << "\n     RESUMEN DE LA COMPRA" << endl;
        cout << "==============================";
        cout << "\n- Cliente: " << cliente.getNombre();
        cout << "\n- Dirección: " << cliente.getDireccion();
        cout << "\n- Teléfono: " << cliente.getTelefono() << endl;

        // Imprimir detalles del pedido
        cout << "- Vacuna comprada: " << (opcion == 1 ? "Influenza" : "COVID") << endl;
        cout << "- Cantidad comprada: " << cantidadComprar << " vacunas" << endl;
        cout << "- Costo total: $" << (opcion == 1 ? vacunaInfluenza.getCosto() : vacunaCovid.getCosto()) * cantidadComprar << endl;
    }
};

int main() {
    string nombre, direccion, telefono;
    // Inputs del usuario
    cout << "*********************************";
    cout << "   ¡Bienvenido a VacunaTec!   ";
    cout << "*********************************\n";
    cout << "Por favor, proporcione los siguientes datos para realizar su pedido.\n\n";

    cout << "Ingrese su nombre: ";
    getline(cin, nombre); // getline para espacios

    cout << "Ingrese su dirección: ";
    getline(cin, direccion);

    cout << "Ingrese su teléfono: ";
    getline(cin, telefono);

    Cliente cliente(nombre, direccion, telefono); // obj

    InventarioVacunas inventario; // obj

    char continuar; // char es para solo un caracter
    // Ciclo si el usuario quiere comprar más
    do {
        inventario.mostrarInventario();
        inventario.comprarVacunas(cliente);

        cout << "¿Desea realizar otro pedido? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << "\n¡Gracias por su compra, " << cliente.getNombre() << "! Vuelva pronto\n";

    return 0;
}
