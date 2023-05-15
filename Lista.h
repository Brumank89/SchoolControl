#include <iostream>
#include "Nodo.h"
using namespace std;

class Lista {
	private:
		Nodo  *inicio;
	public:

		void Inicializar() {
			inicio = NULL;
		}

		bool EsVacia() {
			if(inicio == NULL) {
				return true;
			} else {
				return false;
			}
		}

		void Registrar(string nombre, string apellidoP, string apellidoM, string matricula, float calificacion) { // Punto 1
			Nodo *nuevo, *aux;
			nuevo = nuevo->Crear(nombre, apellidoP, apellidoM, matricula, calificacion);
			if(EsVacia()) {
				nuevo->apuntador = NULL;
				inicio = nuevo;
				nuevo = NULL;
			} else {
				aux = inicio;
				while(aux->ObtieneApuntador() != NULL) {
					aux = aux->ObtieneApuntador();
				}
				nuevo->apuntador = NULL;
				aux->Conectar(nuevo);
				aux = NULL;
				nuevo = NULL;
			}
		}

		void ActualizarEstudiante(string matricula) { 
			Nodo *aux = inicio;
			if(EsVacia()) {
				cout<<"La lista esta vacia"<<endl;
			} else {
				while(aux != NULL) {
					if(aux->ObtenerMatricula() == matricula) {
						int opc;
						string nomAux, apAux, amAux, matriculaAux;
						do {
							system("cls");
							cout<<"Seleccione el dato a modificar: "<<endl;
							cout<<"1.- Nombre"<<endl;
							cout<<"2.- Apellido Paterno "<<endl;
							cout<<"3.- Apellido Materno "<<endl;
							cout<<"4.- Matricula"<<endl;
							cout<<"5.- Salir"<<endl;
							cin>>opc;

							switch(opc) {
								case 1:
									cout<<"Escriba el nuevo nombre: "<<endl;
									cin>>nomAux;
									aux->setNombre(nomAux);
									break;
								case 2:
									cout<<"Escriba el nuevo apellido paterno: "<<endl;
									cin>>apAux;
									aux -> setApellidoP(apAux);
									break;
								case 3:
									cout<<"Escriba el nuvo apellido materno: "<<endl;
									cin>>amAux;
									aux -> setApellidoM(amAux);
									break;
								case 4:
									cout<<"Escriba la nueva matricula: "<<endl;
									cin>>matriculaAux;
									aux -> setMatricula(matriculaAux);
									break;
								case 5:
									return;
									break;
							}
						} while(opc != 5);
					} else {
						cout<<"No se encontro la matricula"<<endl;
					}
				}
			}
		}


		void ActualizarCalificacion(string matricula) { 
			Nodo *aux = inicio;
			if(EsVacia()) {
				cout<<"La lista esta vacia"<<endl;
			} else {
				while(aux != NULL) {
					if(aux->ObtenerMatricula() == matricula) {
						float CalfAux;
						cout<<"Escriba la nueva calificacion del estudiante: "<<endl;
						cin>>CalfAux;
						aux->setCalificacion(CalfAux);
					} else {
						aux=aux->ObtieneApuntador();
					}
				}
			}

		}

		void BuscarEstudiante (string matricula) { 
		
			Nodo *aux = inicio;
			Nodo *aux2 = inicio->ObtieneApuntador();
			if(inicio ->ObtenerMatricula() == matricula) {
				aux->ObtenerDatos();
			} else {
				while(aux2) {
					if(aux2->ObtenerMatricula() == matricula) {
						aux2->ObtenerDatos();
					}
					aux = aux->ObtieneApuntador();
					aux2 = aux2->ObtieneApuntador();
				}
			}

		}

		void Eliminar(string matricula) { 
			Nodo *aux = inicio;
			if(EsVacia()) {
				cout<<"La lista esta vacia"<<endl;
			} else {
				while(aux != NULL) {
					if(aux->ObtenerMatricula() == matricula) {
						Nodo  *borrar;
						bool flag = false;
						borrar = inicio;
						while(borrar->ObtieneApuntador() != NULL && borrar->ObtenerMatricula() != matricula) {
							aux=borrar;
							borrar = borrar->ObtieneApuntador();
							flag = true;
						}

						if (flag==false) {
							inicio = inicio->ObtieneApuntador();
							delete borrar;
						} else {
							aux->Conectar(borrar->ObtieneApuntador());
							delete borrar;
						}
					} else {
						aux=aux->ObtieneApuntador();
					}
				}
			}
		}

		void MostrarEstudiantes() { 
			Nodo *aux = inicio;
			while(aux != NULL) {
				cout<<aux->ObtenerMatricula()<<" "<<aux->ObtenerApellidoP()<<" "<<aux->ObtenerApellidoM()<<" "<<aux->ObtenerNombre()<<endl;
				aux = aux->ObtieneApuntador();
			}
		}

		void MostrarCalificacion() { 
			Nodo *aux = inicio;
			while(aux != NULL) {
				cout<<aux->ObtenerMatricula()<<" "<<aux->ObtenerApellidoP()<<" "<<aux->ObtenerApellidoM()<<" "<<aux->ObtenerNombre()<<" "<<aux->ObtenerCalificacion()<<endl;
				aux = aux->ObtieneApuntador();
			}
		}

		void ReporteFinal() { 
			if(EsVacia()) {
				cout<<"Lista vacia"<<endl;
			} else {
				Nodo *aux = inicio;
				float prom = 0;
				int contRegular = 0, contRiesgo = 0, contReprobados = 0;
				while(aux != NULL) {
					contRegular++;
					prom = prom + aux->ObtenerCalificacion();
					if(aux->ObtenerCalificacion() <= 7 && aux->ObtenerCalificacion() >= 6) {
						contRiesgo++;
					}
					if(aux->ObtenerCalificacion()<6) {
						contReprobados++;
					}
					aux = aux->ObtieneApuntador();
				}
				cout<<"El promedio general es de: "<<(prom/contRegular)<<endl;
				cout<<"El total de alumno es de: "<<contRegular<<endl;
				cout<<"Alumnos en situacion de reprobar: "<<contReprobados<<endl;
				cout<<"Alumnos reprobados: "<<contReprobados<<endl;
			}
		}

		int BuscaMatricula(string matricula) { 
			Nodo *aux = inicio;
			if(EsVacia()) {
				cout<<"La lista esta vacia"<<endl;
			} else {
				while(aux != NULL) {
					if(aux->ObtenerMatricula() == matricula) {
						return 1;
					} else {
						aux=aux->ObtieneApuntador();
					}
				}
			}
		}

};


