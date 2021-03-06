#ifndef CelestialAlignment_CPP
#define CelestialAlignment_CPP


#include <typeinfo>
class Magic;
#include "..\Magic.h"
class Character;
#include "..\Character.h"
class Hero;
#include "..\Hero.h"
class Dragon;
#include "..\Dragon.h"

class CelestialAlignment : public Magic {

	public:
		CelestialAlignment() {
		}
		~CelestialAlignment() {
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
				//printf("cel: %d\n", magic);
				p2 -> AskAnswer(user, magic);
			} else {
				float dam = 10.0;
				dam = p1 -> CalDam(dam, 3);
				receiver -> GetHurt(user, dam, 3);
			}
			return true;
		}
		void Effect(bool cho = true) {
			Character *user = user_;
			Character *receiver = receiver_;
			Hero *p1 = dynamic_cast<Hero*>(user);
			Hero *p2 = dynamic_cast<Hero*>(receiver);
			float dam = 10.0;
			dam = p1 -> CalDam(dam, 3);
			p2 -> GetHurt(user, dam, 3);
		}
		string Display() {
			return "CelestialAlignment";//�������
		}

};



#endif
