#include "PerfilPsicologico.h"

PerfilPsicologico::PerfilPsicologico(Voluntario* aVoluntario, std::vector<Entrada*>* aEntradas, bool aActivo)
	:mVoluntario(aVoluntario), mEntradas(aEntradas), mActivo(aActivo)
{
	ActualizarUltimaModificacion();
}

void PerfilPsicologico::ActualizarUltimaModificacion()
{
	if (mEntradas->size() > 0)
	{
		mUltimaModificacion = (*mEntradas)[0]->getDate();
		for (int i = 1; i < mEntradas->size(); ++i)
		{
			if ((*mEntradas)[i]->getDate() > mUltimaModificacion)
			{
				mUltimaModificacion = (*mEntradas)[i]->getDate();
			}
		}
	}
	else
	{
		mUltimaModificacion = "No se registran entradas";
	}
}
