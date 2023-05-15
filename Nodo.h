#include <iostream>
using namespace std;
#ifndef NODO_H
#define NODO_H

class Nodo{
	private:
		float calificacion = 0;
		string nombre;
		string matricula;
		string apellidoP;
		string apellidoM;
	public:
	Nodo *apuntador;	
		
	Nodo *Crear(string _nombre, string _apellidoP, string _apellidoM, string _matricula, float _calificacion){  //Atribuos que se guardan en el nodo
		Nodo *nuevo = new Nodo();
		nuevo -> nombre = _nombre;
		nuevo -> apellidoP = _apellidoP;
		nuevo -> apellidoM = _apellidoM;
		nuevo -> matricula = _matricula;
		nuevo -> calificacion = _calificacion;
		return nuevo;
	}	
	
	Nodo *ObtieneApuntador(){
		return apuntador;
	}
	
	string ObtenerNombre(){
		return nombre;
	}
	
	void setNombre(string _nombre){
		nombre = _nombre;
	}
	
	string ObtenerMatricula(){
		return matricula;
	}
	
	void setMatricula(string _matricula){
		matricula = _matricula;
	}
	
	string ObtenerApellidoP(){
		return apellidoP;
	}
	
	void setApellidoP(string _apellidoP){
		apellidoP = _apellidoP;
	}
	
	string ObtenerApellidoM(){
		return apellidoM;
	}
	
	void setApellidoM(string _apellidoM){
		apellidoM = _apellidoM;
	}
	
	
	void Conectar(Nodo *siguiente){
		apuntador = siguiente;
	}
	
	float ObtenerCalificacion(){
		return calificacion;
	}
	
	void setCalificacion(float _calificacion){
		calificacion = _calificacion; 
	}
	
	void ObtenerDatos(){ //Buscar estudiante (Paso 5)
		cout<<nombre<<" "<<apellidoP<<" "<<apellidoM<<endl;
		cout<<"Calificacion: "<<calificacion<<endl;
		if(calificacion <=7 && calificacion <= 6){
			cout<<"Atencion: estudiante con situacion probable de reprobacion "<<endl;
		}
			
		if(calificacion < 6){
			cout<<"Atencion: estudiante en repite"<<endl;
		}
		cout<<endl;
	}
	
};

#endif
