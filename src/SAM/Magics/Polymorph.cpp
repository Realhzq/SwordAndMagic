#ifndef Polymorph_CPP
#define Polymorph_CPP


#include <typeinfo>
class Magic;
#include "..\Magic.h"
class Character;
#include "..\Character.h"
class Hero;
#include "..\Hero.h"
class Dragon;
#include "..\Dragon.h"

class Polymorph : public Magic {

	public:
		Polymorph() {
		}
		~Polymorph() {
		}
		bool CanUse(Character *user, int turn = 3) {
			if (turn == 3)
				return true;
			return false;
		}
		bool Passive() {
			return false;
		}
		bool Use(Character *user, Character *receiver, Magic *magic) {
			user_ = user;
			receiver_ = receiver;
			Hero *p1 = dynamic_cast<Hero*>(user);
			if (receiver -> GetType() == 1) {
				Hero *p2 = dynamic_cast<Hero*>(receiver);
				p2 -> SetHit(magic);
				p2 -> SetHitFrom(user);
				p2 -> AskAnswer(user, magic);
			} else
				receiver -> GetHeal(user, p1 -> CalHeal(3.0, 3), 3);
			return true;
		}
		void Effect(bool cho = true) {
			Character *user = user_;
			Character *receiver = receiver_;
			Hero *p1 = dynamic_cast<Hero*>(user);
			Hero *p2 = dynamic_cast<Hero*>(receiver);
			p2 -> ClearAllStates();
			p2 -> AddState(skiptotalturn, user);
			p2 -> GetHeal(user, p1 -> CalHeal(3.0, 3), 3);
		}
		string Display() {
			return "Polymorph";//������
		}

};



#endif
