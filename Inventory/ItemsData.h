#pragma oncec

struct Weapons {
	Items::Types _weap;
	int _id;
	const std::string &_name;
	int dmgMax;
	int dmgMin;
};

struct Foods {
	Items::Types _food;
	int _id;
	int healMax;
	int healMin;
};