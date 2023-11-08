#pragma once

class Ressources
{
private:
	int nbBois;
	int nbFer;

public:
	void generateIron(float deltaTime);

	int getFer() { return nbFer; };
	void setFer(int fer) { nbFer = fer; };

	int getBois() { return nbBois; };
	void setBois(int bois) { nbBois = bois; };
};