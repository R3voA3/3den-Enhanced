//Include in description.ext 
//See https://community.bistudio.com/wiki/Arma_3_Mission_Parameters for the full documentation. 
class Params 
{ 
	#define COUNTDOWN_MIN 600
	#define COUNTDOWN_MAX 3600
	#define COUNTDOWN_DEFAULT -1
	#include "\a3\functions_f\Params\paramCountdown.hpp"

	#define DAYTIMEHOUR_DEFAULT 19
	#include "\a3\functions_f\Params\paramDaytimeHour.hpp"

	//#define DAYTIMEPERIOD_DEFAULT 12
	//#include "\a3\functions_f\Params\paramDaytimePeriod.hpp"

	#define DEBUGCONSOLE_DEFAULT 1
	#include "\a3\functions_f\Params\paramDebugConsole.hpp"

	#define GUERFRIENDLY_DEFAULT -1
	#include "\a3\functions_f\Params\paramGuerFriendly.hpp"

	#define TICKETS_MIN 100
	#define TICKETS_MAX 1100
	#define TICKETS_DEFAULT -1
	#include "\a3\functions_f\Params\paramRespawnTickets.hpp"

	#define WEATHER_DEFAULT 40
	#include "\a3\functions_f\Params\paramWeather.hpp"

	#define TIMEACCELERATION_DEFAULT 10
	#include "\a3\Functions_F_MP_Mark\Params\paramTimeAcceleration.hpp"

	#define VIEW_DISTANCE_MIN 1500
	#define VIEW_DISTANCE_MAX 4000
	#define VIEW_DISTANCE_DEFAULT 2000
	#include "\a3\Functions_F_Heli\Params\paramViewDistance.hpp"

	#include "\a3\Functions_F\Params\paramRevive.hpp"
};