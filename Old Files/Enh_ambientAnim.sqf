/*
	Author: Jiri Wainar

	Description:
	Play set of ambient animations on given unit.

	Remarks:
	* Can handle several different anims and auto-switching between them.

	Parameter(s):
	0: OBJECT - unit the anim & gear changes are going to be applied to
	1: STRING - animation set id, describing what the unit's action looks like.
	   > "STAND"		- standing still, slightly turning to the sides, with rifle weapon
	   > "STAND_IA"		- standing still, slightly turning to the sides, with rifle weapon
	   > "STAND_U1-3"	- standing still, slightly turning to the sides, no weapon
	   > "WATCH1-2"		- standing and turning around, with rifle weapon
	   > "GUARD"		- standing still, like on guard with hands behing the body
	   > "LISTEN_BRIEFING"  - standing still, hands behind back, recieving briefing / commands, no rifle.
	   > "LEAN_ON_TABLE"	- standing while leaning on the table
	   > "LEAN"		- standing while leaning (on wall)
	   > "BRIEFING"		- standing, playing ambient briefing loop with occasional random moves
	   > "BRIEFING_POINT_LEFT"	- contains 1 extra pointing animation, pointing left & high
	   > "BRIEFING_POINT_RIGHT"	- contains 1 extra pointing animation, pointing right & high
	   > "BRIEFING_POINT_TABLE"	- contains 1 extra pointing animation, pointing front & low, like at table
	   > "SIT1-3"		- sitting on chair or bench, with rifle weapon
	   > "SIT_U1-3"		- sitting on chair or bench, without weapon
	   > "SIT_AT_TABLE"	- sitting @ table, hands on table
	   > "SIT_HIGH1-2" 	- sitting on taller objects like a table or wall, legs not touching the ground. Needs a rifle!
	   > "SIT_LOW"		- sitting on the ground, with weapon.
	   > "SIT_LOW_U"	- sitting on the ground, without weapon.
	   > "SIT_SAD1-2"	- sitting on a chair, looking very sad.
	   > "KNEEL"		- kneeling, with weapon.
	   > "PRONE_INJURED_U1-2" - laying wounded, back on the ground, wothout weapon
	   > "PRONE_INJURED"	- laying wounded & still, back on the ground, with or without weapon
	   > "KNEEL_TREAT"	- kneeling while treating the wounded
	   > "REPAIR_VEH_PRONE"	- repairing vehicle while laying on the ground (under the vehicle)
	   > "REPAIR_VEH_KNEEL"	- repairing vehicle while kneeling (like changing a wheel)
	   > "REPAIR_VEH_STAND"	- repairing/cleaning a vehicle while standing

	Returns:
	-
*/

//Has issues with positioning the unit correctly, some sort of auto offset

params ["_unit","_animSet"];

//surpress the unit "intelligence"
{_unit disableAI _x} forEach ["ANIM","AUTOTARGET","FSM","MOVE","TARGET"];

//Anim Parameters
(_animset call BIS_fnc_ambientAnimGetParams) params ["_anims","_azimutFix","_attachSnap","_attachOffset","_noBackpack","_noWeapon","_randomGear","_canInterpolate"];

//remove backpack for some anim sets
if (_noBackpack) then {removeBackpack _unit};

//store primary weapon
_weapon = primaryWeapon _unit;
_unit setVariable ["BIS_fnc_ambientAnim__weapon",_weapon];

//remove primary weapon for some anim sets
if (_noWeapon) then
{
	_unit removeWeapon _weapon;
}
else
{
	private _storedWeapon = _unit getVariable ["BIS_fnc_ambientAnim__weapon",""];

	if (primaryWeapon _unit == "" && _storedWeapon != "") then
	{
		_unit addWeapon _storedWeapon;
		_unit selectWeapon _storedWeapon;
	};
};

//store persistant animation data in the units namespace
_unit setVariable ["BIS_fnc_ambientAnim__anims",_anims];
_unit setVariable ["BIS_fnc_ambientAnim__interpolate",_canInterpolate];

//play next anim when previous finishes
_ehAnimDone = _unit addEventHandler
[
	"AnimDone",
	{
		params ["_unit","_anim"];
		private _pool = _unit getVariable ["BIS_fnc_ambientAnim__anims",[]];

		if (alive _unit) then
		{
			_unit call BIS_fnc_ambientAnim__playAnim;
		}
		else
		{
			_unit call BIS_fnc_ambientAnim__terminate;
		};
	}
];
//_unit setVariable ["BIS_EhAnimDone", _ehAnimDone];//???

//free unit from anim loop if it is killed
_ehKilled = _unit addEventHandler
[
	"Killed",
	{
		(_this # 0) call BIS_fnc_ambientAnim__terminate;
	}
];

//free unit from anim loop if it is killed
_ehDamaged = _unit addEventHandler
[
	"Dammaged",
	{
		(_this # 0) call BIS_fnc_ambientAnim__terminate;
	}
];
//_unit setVariable ["BIS_EhKilled", _ehKilled];//???

//_unit call BIS_fnc_ambientAnim__playAnim;
BIS_fnc_ambientAnim__playAnim =
{
	private _anims 	= _this getVariable ["BIS_fnc_ambientAnim__anims",[]];

	if (_anims isEqualTo []) exitWith {false};
//_this getVariable ["BIS_fnc_ambientAnim__interpolate",false]
	//select a random anim from the pool of available animations and play it
	if (false) then {_this playMoveNow (selectRandom _anims)} else {_this switchMove (selectRandom _anims)};
};
_unit call BIS_fnc_ambientAnim__playAnim;

//_unit call BIS_fnc_ambientAnim__terminate;
BIS_fnc_ambientAnim__terminate =
{
	//_this = _unit;
	if (isNull _this) exitWith {};
	if (alive _this) then 
	{
		_this switchMove ""; 
		_this addWeapon (_this getVariable "BIS_fnc_ambientAnim__weapon");
		_this selectWeapon (_this getVariable "BIS_fnc_ambientAnim__weapon");
		{_this enableAI _x} forEach ["ANIM", "AUTOTARGET", "FSM", "MOVE", "TARGET"];
	};

/* 	//remove the event handlers
	private _ehAnimDone = _this getVariable ["BIS_EhAnimDone",-1];
	private _ehKilled = _this getVariable ["BIS_EhKilled",-1];

	if (_ehAnimDone != -1) then
	{
		_this removeEventHandler ["AnimDone",_ehAnimDone];
		_this setVariable ["BIS_EhAnimDone",-1];
	};
	if (_ehKilled != -1) then
	{
		_this removeEventHandler ["Killed",_ehKilled];
		_this setVariable ["BIS_EhKilled",-1];
	}; */
};


PosThis = getPosATL _unit; posThis set [2,0.534]; _unit setPosATL PosThis;