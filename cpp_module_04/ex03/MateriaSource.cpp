#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : idx(0)
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& a)
{
	for (int i = 0; i < 4; i++)
	{
		if (a.materia[i])
			materia[i] = a.materia[i]->clone();
		else
			materia[i] = NULL;
	}
	this->idx = a.idx;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &a)
{
	if (this != &a)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia[i])
				delete materia[i];
			if (a.materia[i])
				materia[i] = a.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria*a)
{
	for(int i = 0; i < 4; i++)
	{
		if (!materia[i])
		{
			materia[i] = a;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return NULL;
}