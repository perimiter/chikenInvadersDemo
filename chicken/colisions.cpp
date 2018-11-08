//#include "GameObject.h"
//#include "Chickens.h"
//#include "Bullets.h"
//#include "Boss.h"
//
//
//namespace {
//
//
//
//			// primary collision-processing functions
//	// see below for a description of these types/functions
//	typedef void(*HitFunctionPtr)(GameObject&, GameObject&);
//	typedef std::map<std::pair<std::string, std::string>,HitFunctionPtr> HitMap;
//	
//	std::pair<std::string, std::string> makeStringPair(const char *s1,
//		const char *s2) {
//		return std::pair<std::string, std::string>(s1, s2);
//	}
//	
//	HitMap * initializeCollisionMap() {
//		HitMap *phm = new HitMap;
//		(*phm)[makeStringPair(typeid(Bullets).name(), typeid(Chickens).name())] = &bulletInChiken;
//		(*phm)[makeStringPair(typeid(Bullets).name(), typeid(Boss).name())] = &bulletInBoss;
//			return phm;
//	}
//
//	HitFunctionPtr lookup(const std::string& class1,
//		const std::string& class2) {
//		static std::auto_ptr<HitMap>
//			collisionMap(initializeCollisionMap());
//		// see below for a description of make_pair
//		HitMap::iterator mapEntry =
//			collisionMap->find(make_pair(class1, class2));
//		if (mapEntry == collisionMap->end()) return 0;
//		return (*mapEntry).second;
//	}
//} // end namespace
//
//void bulletInChiken(GameObject&, GameObject&);
//void bulletInBoss(GameObject& , GameObject& );
//
//void bulletInChiken(GameObject& bullet, GameObject& chicken)
//{
//	Bullets& bulletref = static_cast<Bullets&>(bullet);
//	Chickens& chickenref = static_cast<Chickens&>(chicken);
//	chickenref.playPakPak();
//	chickenref.decreaseLife();
//	bulletref.setUnAvailable();
//}
//
//void bulletInBoss(GameObject& bullet, GameObject& boss)
//{
//
//}
//
//class bal
//{
//	void doStuff(GameObject&,GameObject&);
//};
//
//void bal::doStuff(GameObject&dd, GameObject&de)
//{
//	auto phf= lookup()
//
//}
