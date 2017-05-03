#include "Sprite.hpp"
#include "Timer.hpp"






class CTile
{
public:
	void Set(int Type, int max, int Val);

	int GetID(){ return ID; };
	int GetValue(){ return Value; };
	void Display();
	void Update();
private:
	int ID;
	int maxValue;
	int Value;
	int PlayerClaim;



};