#include "steam_api.inc"

#define_ex :String = = ""
#define_ex :Float = = 0.0
#define_ex :Int = = 0

#define INFINITY 2**32
// =======================================LIMITATIONS
	// GAME
		#define MAX_OBJECTS = 65535
		#define MAX_PLAYERS = 65
		#define MAX_ROOMS = 200
		#define MAX_DOORS = 500
		#define MAX_NPCS = 255
		#define MAX_EVENTS = 90
		#define MAX_ITEMS = 1000
		
	// MISC
		#define MAX_PLUGINS = 64
		#define MAX_INCLUDES = 64
	// VARS
		#define MAX_PLAYER_VARIABLES = 256
		#define MAX_VARIABLES = 512
	// GUI
		#define MAX_DRAWS = 32
		#define MAX_TEXTS = 32
	// SCRIPT
		#define MAX_PUBLICS = INFINITY
		#define MAX_PUBLICS_TICKS = 64
		#define MAX_PUBLIC_PARAMS = 16
		
	// ANTICHEAT
		#define CHEAT_NOITEM = 1
		#define CHEAT_INCORRECT_ROLE = 2
		#define CHEAT_INCORRECT_POS = 3
		#define CHEAT_CONSOLE_USE = 4
		#define CHEAT_SPAWN_ITEM = 5
		#define CHEAT_INTERCOM = 6
		#define CHEAT_NORECOILORSPREAD = 7
// =======================================PLUGINS
	#define P_TYPE_BYTE = 1
	#define P_TYPE_SHORT = 2

	#define P_TYPE_INT = 3
	#define P_TYPE_FLOAT = 4
	#define P_TYPE_STRING = 5
// =======================================PLAYER ANIMS
	#define PLAYER_SITTING_IDLING = 5
	#define PLAYER_SITTING_WALKING_LEFT = 7
	#define PLAYER_SITTING_WALKING_RIGHT = 8
	#define PLAYER_SITTING_WALKING_BACK = 9
	#define PLAYER_SITTING_WALKING_FORWARD = 10
	#define PLAYER_IDLING = 11
	#define PLAYER_WALKING = 12
	#define PLAYER_RUNNING = 13
	#define PLAYER_CRYING = 14
// =======================================PLAYER GUNS
	#define GUN_USP = 1
	#define GUN_P90 = 2
	#define GUN_MP5SD = 3
	#define GUN_BAZOOKA = 4
	#define GUN_MINIGUN = 5
	#define GUN_MICROHID = 6
	#define GUN_DEAGLE = 7
	#define GUN_SHOTGUN = 8
	#define GUN_M4A4 = 9
	#define GUN_HANDCUFFS = 10
	#define GUN_GRENADE = 11
	#define GUN_GRENADEFLASHBANG = 12
	#define GUN_GRENADESMOKE = 13
// =======================================PLAYER TYPES
	#define TYPE_NTF = 1
	#define TYPE_GUARD = 2
	#define TYPE_CLASSD = 3
	#define TYPE_SCIENTIST = 4
	#define TYPE_173 = 5
	#define TYPE_049 = 6
	#define TYPE_CHAOS = 7
	#define TYPE_JANITOR = 8
	#define TYPE_939 = 10
	#define TYPE_106 = 11
	#define TYPE_966 = 12
	#define TYPE_ZOMBIE = 13
	#define TYPE_096 = 14
	#define TYPE_860 = 15
	#define TYPE_035 = 16
// =======================================GUI

	#define DRAW_IMAGE = 0
	#define DRAW_RECT = 1
	#define DRAW_OVAL = 2

	#define DRAW_IMAGE_STANDART_SIZE = -1