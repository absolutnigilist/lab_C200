#include "myBochka.h"

Bochka::Bochka(int value_Volume, double value_Concentration) {
	Volume=value_Volume;
	Concentration=value_Concentration;
	Content_of_spirt = Volume*Concentration*10;
};

Bochka::~Bochka() {};

void Bochka::Pereliv(Bochka& dest, int cup_capacity) {
	Volume += cup_capacity;
	dest.Volume -= cup_capacity;
	Content_of_spirt += (cup_capacity * dest.Concentration*10);
	dest.Content_of_spirt -= (cup_capacity * dest.Concentration * 10);
	Concentration = (Content_of_spirt / (Volume*10));
	dest.Concentration = (dest.Content_of_spirt / (dest.Volume * 10));
};
double Bochka::GetSpirtConcentration()const {
	return Concentration;
}; 

