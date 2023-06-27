#pragma once
#include <vector>
#include <string>

#include "Entrada.h"
#include "Voluntario.h"

class PerfilPsicologico {
public:
	PerfilPsicologico(Voluntario* aVoluntario, std::vector<Entrada*>* aEntradas, bool aActivo);
	Voluntario* getVoluntario() { return mVoluntario; };
	std::vector<Entrada*>* getEntradas() { return mEntradas; };
	std::string getUltimaModificacion() { return mUltimaModificacion; };
	std::string setUltimaModificacion( std::string nuevaModificacion) { mUltimaModificacion = nuevaModificacion; };
	bool getActivo() { return mActivo; };
	void setActivo(bool newState) { mActivo = newState; };

	void ActualizarUltimaModificacion();

private:
	Voluntario* mVoluntario;
	std::vector<Entrada*>* mEntradas;
	std::string mUltimaModificacion;
	bool mActivo;
};