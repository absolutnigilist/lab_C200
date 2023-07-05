#pragma once

class Bochka {
	int Volume;
	double Concentration;
	double Content_of_spirt;
public:
	Bochka(int value_Volume, double value_Concentration);
	~Bochka();
	double GetSpirtConcentration() const;
	void Pereliv(Bochka& dest, int cup_capacity);
	
};
