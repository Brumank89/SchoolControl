#include <iostream>
#include "Lista.h"
using namespace std;
Lista lst;

int main() {
	string nombre, apellidoP, apellidoM, matricula, matriculaA;
	float calificacion;
	int opc;
	lst.Inicializar();
	do {
		cout<<"Ingrese la opcion que desea: "<<endl;
		cout <<" 1.- Registrar estudiante" <<endl;
		cout <<" 2.- Actualizar estudiante" <<endl;
		cout <<" 3.- Actualizar calificacion" <<endl;
		cout <<" 4.- Buscar estudiante" <<endl;
		cout <<" 5.- Eliminar estudiante" <<endl;
		cout <<" 6.- Mostrar listado de estudiantes" <<endl;
		cout <<" 7.- Mostrar calificaciones" <<endl;
		cout <<" 8.- Mostrar reporte final" <<endl;
		cout <<" 9.- Salir" <<endl;
		cin>>opc;

		switch(opc) {

			case 1:	
				cout<<"Selecciono 'Registrar dato' "<<endl;
				cout<<"Ingrese los datos a guardar: "<<endl;
				cout<<"Ingrese el nombre: ";
				cin>>nombre;
				cout<<"Apellido paterno: ";
				cin>>apellidoP;
				cout<<"Apellido materno: ";
				cin>>apellidoM;
				cout<<"Matricula: ";
				cin>>matricula;
				cout<<"Calificacion: ";
				cin>>calificacion;
				lst.Registrar(nombre, apellidoP, apellidoM, matricula, calificacion);
				cout<<"Los datos han sido guardados "<<endl;
				cout<<endl;
				break;

			case 2:
				cout<<"Selecciono 'Actualizar estudiante' "<<endl;
				cout<<"Ingrese la matricula del estudiante: "<<endl;
				cin>>matriculaA;
				lst.ActualizarEstudiante(matriculaA);
				system("pause");
				break;

			case 3:
				cout<<"Selecciono 'Actualizar calificacion' "<<endl;
				cout<<"Ingrese la matricula del estudiante: "<<endl;
				cin>>matriculaA;
				lst.ActualizarCalificacion(matriculaA);
				system("pause");
				break;
			case 4:
				cout<<"Selecciono 'Buscar estudiante' "<<endl;
				cout<<"Ingrese la matricula del estudiante: "<<endl;
				cin>>matriculaA;
				lst.BuscarEstudiante(matriculaA);
				system("pause");
				break;
			case 5:
				
				cout<<"Selecciono 'Eliminar' "<<endl;
				cout<<"Ingrese la matricula del estudiante: "<<endl;
				cin>>matriculaA;
				lst.Eliminar(matricula);
				cout<<"Alumno eliminado "<<endl;
				system("pause");
				cout<<endl;
				break;
			
			case 6:
				cout<<"Selecciono 'Mostrar listado de estudiantes' "<<endl;
				lst.MostrarEstudiantes();
				system("pause");
				break;
			case 7:
				cout<<"Selecciono 'Mostrar calificaciones' "<<endl;
				lst.MostrarCalificacion();
				system("pause");
				break;
			case 8:
				cout<<"Selecciono 'Mostrar reporte final' "<<endl;
				lst.ReporteFinal();
				system("pause");;
				break;
		}
		system("cls");
	} while(opc != 9);

	return 0;
}
