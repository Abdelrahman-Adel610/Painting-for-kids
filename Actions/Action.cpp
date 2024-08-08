#include "Action.h"

bool Action::getExcutionState()
{
	return IsExcuted;
}

void Action::Redo()
{
}

void Action::Undo()
{
}
bool Action::getRecorded() const
{
	return IsRecorded;
}

void Action::setRecorded(bool b)
{
	IsRecorded = b;
}
