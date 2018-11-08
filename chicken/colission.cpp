#include "colission.h"


// primary collision-processing functions
typedef void(*HitFunctionPtr)(GameObject&, GameObject&);
typedef std::map<std::pair<std::string, std::string>, HitFunctionPtr> HitMap;
namespace {
	void bulletInChiken(GameObject& bullet, GameObject& chicken)
	{
		Bullets& bulletRef = static_cast<Bullets&>(bullet);
		Chickens& chickenRef = static_cast<Chickens&>(chicken);
		chickenRef.decreaseLife();
		chickenRef.playPakPak();//play hit sound
		//bulet is now not available will be erased
		bulletRef.setUnAvailable();
	}
	void BulletInBoss(GameObject& bullet, GameObject& boss)
	{
		Bullets& bulletRef = static_cast<Bullets&>(bullet);
		Boss& bossRef = static_cast<Boss&>(boss);
		bossRef.decreaseLife();
		bossRef.playPakPak();//play hit sound
		//bulet is now not available will be erased
		bulletRef.setUnAvailable();

	}
	void bossInShip(GameObject& boss, GameObject& ship)
	{
		Boss& bossref = static_cast<Boss&>(boss);
		SpaceShip& shipRef = static_cast<SpaceShip&>(ship);

		bossref.decreaseLife();
		bossref.playPakPak();//play hit sound
		shipRef.decreaseLive();
		shipRef.resetShipWeapon();//reset ship
	}
	void eggInShip(GameObject& egg, GameObject& ship) {

		Eggs& eggRef = static_cast<Eggs&>(egg);
		//no need to continue if the egg is broken
		if (eggRef.getBroken())
			return;
		SpaceShip& shipRef = static_cast<SpaceShip&>(ship);

		eggRef.setUnAvailable();//set egg to be deleted
		shipRef.decreaseLive();
		shipRef.resetShipWeapon();
		//set game over after ship death
		/*if (shipRef.getLives() == 0) {
			shipRef.setGameOver(true);
		}*/
	}
	void upgradeInShip(GameObject& upgrade, GameObject& ship) {

		Upgrade& upgradeRef = static_cast<Upgrade&>(upgrade);
		SpaceShip& shipRef = static_cast<SpaceShip&>(ship);
		upgradeRef.setUnAvailable();
		shipRef.speedFire();
	}
	void giftInShip(GameObject& gift, GameObject& ship) {

		Gift& giftRef = static_cast<Gift&>(gift);
		SpaceShip& shipRef = static_cast<SpaceShip&>(ship);
		giftRef.setUnAvailable();//set gift to be deleted
		shipRef.setLevelUpFire();//make fire stronger
	}
	void chickenInShip(GameObject& chicken, GameObject& ship) {

		Chickens& chickenRef = static_cast<Chickens&>(chicken);
		SpaceShip& shipRef = static_cast<SpaceShip&>(ship);

		chickenRef.decreaseLife();
		chickenRef.playPakPak();//play hit sound
		chickenRef.setUnAvailable();//mkae chiken unavailible
		shipRef.decreaseLive();
		shipRef.resetShipWeapon();
	}

	std::unique_ptr<HitMap> initializeCollisionMap() {
		auto phm = std::make_unique<HitMap>();

		(*phm)[std::make_pair(typeid(Bullets).name(), typeid(Chickens).name())] = &bulletInChiken;
		(*phm)[std::make_pair(typeid(Bullets).name(), typeid(Boss).name())] = &BulletInBoss;
		(*phm)[std::make_pair(typeid(Eggs).name(), typeid(SpaceShip).name())] = &eggInShip;
		(*phm)[std::make_pair(typeid(Upgrade).name(), typeid(SpaceShip).name())] = &upgradeInShip;
		(*phm)[std::make_pair(typeid(Gift).name(), typeid(SpaceShip).name())] = &giftInShip;
		(*phm)[std::make_pair(typeid(Chickens).name(), typeid(SpaceShip).name())] = &chickenInShip;
		(*phm)[std::make_pair(typeid(Boss).name(), typeid(SpaceShip).name())] = &bossInShip;

		return phm;
	}

	HitFunctionPtr lookup(const std::string& class1,
		const std::string& class2) {
		static std::unique_ptr<HitMap>
			collisionMap(initializeCollisionMap());

		auto mapEntry =
			collisionMap->find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap->end())
			return nullptr;
		return (*mapEntry).second;
	}
} // end namespace



colission::colission()
{
}


colission::~colission()
{
}

void colission::processCollision(GameObject& object1, GameObject& object2)
{
	HitFunctionPtr phf = lookup(typeid(object1).name(),
		typeid(object2).name());
	if (phf)
		phf(object1, object2);
}