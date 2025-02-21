#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase que representa una tarea
class Tarea {
public:
    string descripcion;
    bool completada;

    Tarea(string descripcion) {
        this->descripcion = descripcion;
        this->completada = false;
    }

    void mostrarTarea() {
        cout << "Tarea: " << descripcion << " | Estado: " << (completada ? "Completada" : "Pendiente") << endl;
    }

    void completar() {
        completada = true;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n---- Gestor de Tareas ----" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Mostrar tareas" << endl;
    cout << "3. Eliminar tarea" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opción: ";
}

int main() {
    vector<Tarea> tareas;  // Vector que almacenará las tareas
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();  // Limpiar el buffer del input
        
        switch (opcion) {
            case 1: {
                // Agregar tarea
                string descripcion;
                cout << "Ingresa la descripción de la tarea: ";
                getline(cin, descripcion);  // Obtener la descripción con espacios
                tareas.push_back(Tarea(descripcion));
                cout << "Tarea agregada con éxito!" << endl;
                break;
            }
            case 2: {
                // Mostrar tareas
                if (tareas.empty()) {
                    cout << "No hay tareas para mostrar." << endl;
                } else {
                    cout << "\nLista de tareas:\n";
                    for (int i = 0; i < tareas.size(); ++i) {
                        cout << i + 1 << ". ";
                        tareas[i].mostrarTarea();
                    }
                }
                break;
            }
            case 3: {
                // Eliminar tarea
                int index;
                cout << "Ingresa el número de la tarea que deseas eliminar: ";
                cin >> index;
                
                // Validar que el índice sea válido
                if (index > 0 && index <= tareas.size()) {
                    tareas.erase(tareas.begin() + index - 1);
                    cout << "Tarea eliminada con éxito." << endl;
                } else {
                    cout << "Índice no válido." << endl;
                }
                break;
            }
            case 4: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
                cout << "Opción no válida, por favor intenta nuevamente." << endl;
        }
    } while (opcion != 4);  // Continuar hasta que el usuario elija salir

    return 0;
}