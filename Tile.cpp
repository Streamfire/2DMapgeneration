#include "Tile.hpp"



void CTile::Set(int Type, int max, int Val)
{
	ID = Type;
	maxValue = max;
	Value = Val;

	
}

void CTile::Update()
{
	
	Value += static_cast<int>(g_pTimer->GetElapsed()*10.0f);
	if (Value > maxValue)
		Value = maxValue;
}

void CTile::Display()
{
	std::cout << Value << ';' << maxValue << std::endl;
}