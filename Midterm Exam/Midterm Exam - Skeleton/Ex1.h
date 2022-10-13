/* ----------------------------------------------------------------------- */
/*                         INSERT YOUR NAME HERE                           */
/* ----------------------------------------------------------------------- */


#ifndef EX1_H
#define EX1_H

#include <stdlib.h>
// Uncomment to test the exercise
#define TEST_EX1

//Implement abstract Soldier base class here

class Soldier {
private:
	const char* name;
protected:
	int healthPoints;
	int damage;
	int position;

public:
	Soldier(){}
	Soldier(const char* name0, int hp0, int damage0, int range, int position0) : name(name0) {
		healthPoints = hp0;
		position = position0;
		damage = damage0;
	}

	const char* getName() const {
		return name;
	}
	int getHealthPoints() const {
		return healthPoints;
	}
	int getPosition() const {
		return position;
	}
	virtual void recieveDamage(int damage) {
		int hold = damage - healthPoints;
		if (hold < 0) {
			healthPoints = 0;
		}
		else {
			healthPoints = hold;
		}
	}
	void move(int distance) {
		int poshold = distance + position;
		position = poshold;
	}
	virtual void upgrade() = 0;
	virtual void attack(Soldier* other) {}
	virtual ~Soldier() {}
};


//Implement derived Archer class here

class Archer : public Soldier{
private:
	int range;

public:
	Archer(int posit0) : Soldier("Archer",10,3,3,posit0) {}

	void upgrade() override {
		this->range++;
		this->damage++;
	}
	void attack(Soldier* &other) {
		if (abs(this->position - other->getPosition()) <= this->range) {
			other->recieveDamage(this->damage);
		}
	}
	~Archer() {}
	};

//Implement derived Tank class here
class Tank : public Soldier{
private:
	int defense;

public:
	Tank(){}
	Tank(int position0) : Soldier ("Tank",15,6,3,position0) {}

	void upgrade() override {
		this->defense++;
	}
	void attack(Soldier* &other) {
		if (other->getName() == "Archer") {
			other->recieveDamage(this->damage);
		}
	}
	void recieveDamage(int damage) override {
		int hold2 = damage - this->defense;
		int final = hold2 - this->healthPoints;
		if (this->getHealthPoints() < 0) {
			this->healthPoints = 0;
		}
		else {
			this->healthPoints = final;
		}
	}
	~Tank(){}
};



#endif
