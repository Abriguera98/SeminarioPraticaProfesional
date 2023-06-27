#include "PerfilPsicologico.h"

PerfilPsicologico::PerfilPsicologico(Voluntario* aVoluntario, std::vector<Entrada*>* aEntradas, bool aActivo)
	:mVoluntario(aVoluntario), mEntradas(aEntradas), mActivo(aActivo)
{
	mUltimaModificacion = (*mEntradas)[0]->getDate();
}
