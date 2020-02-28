/*
   Author: R3vo

   Date: 2020-02-28

   Description:
   Used for the Single Player Respawn (SPR) attribute (WIP).

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

if (isMultiplayer) exitWith {false};

ENH_SPR_Markers_West = allMapMarkers select {"respawn_west" in _x};
ENH_SPR_Markers_East = allMapMarkers select {"respawn_east" in _x};
ENH_SPR_Markers_Guerilla = allMapMarkers select {"respawn_guerilla" in _x};
ENH_SPR_Markers_Civilian = allMapMarkers select {"respawn_civlian" in _x};
ENH_SPR_Time = 8;
ENH_SPR_RandomPos = false;
ENH_SPR_SpawnWhereDied = false;
ENH_SPR_Tickets = 3;
ENH_SPR_CanDie = true;

#define THRESHOLD 0.9
#define FADEOUT_TIME 3
#define FADEIN_TIME 8

ENH_SPR_fnc_respawn =
{
	params ["_unit"];
	if !(ENH_SPR_SpawnWhereDied) then
	{  
		private _sideID = (_unit getVariable ["ENH_SPR_OriginalSide",west]) call BIS_fnc_sideID;
		private _markerPool = [ENH_SPR_Markers_East,ENH_SPR_Markers_West,ENH_SPR_Markers_Guerilla,ENH_SPR_Markers_Civilian] select _sideID;
		if !(_markerPool isEqualTo []) then
		{
			private _respawnmarker = if (ENH_SPR_RandomPos) then
			{
				selectRandom _markerPool;
			}
			else
			{
				([_markerPool,[],{_unit distance getMarkerPos _x},"ASCEND"] call BIS_fnc_sortBy) select 0;
			};
			_unit setPos getMarkerPos _respawnmarker;
		};
	};
	_unit setUnconscious false;
	_unit allowDamage true;
	_unit setCaptive false;
	_unit setDamage 0;
	_unit setVariable ["ENH_SPR_Unconcious",false];
};

ENH_SPR_fnc_handleRespawnTimer =
{
	params ["_unit"];
	if (isPlayer _unit) then
	{
		private _respawnTime = time + ENH_SPR_Time;
		private _ctrlRespawnTimer = (call BIS_fnc_displayMission) ctrlCreate ["RscStructuredText",-1];

		_ctrlRespawnTimer ctrlSetPosition [0.25,0,0.5,0.06];
		_ctrlRespawnTimer ctrlSetBackgroundColor [0,0,0,0.1];
		_ctrlRespawnTimer ctrlCommit 0;

		//Fade out, disable sounds and player input
		0 cutText ["","BLACK OUT",FADEOUT_TIME];
		FADEOUT_TIME fadeMusic 0;
		FADEOUT_TIME fadeRadio 0;
		FADEOUT_TIME fadeSpeech 0;
		showChat false;
		disableUserInput true;

		while {time <= _respawnTime} do
		{
			_ctrlRespawnTimer ctrlSetStructuredText parseText format ["<t size='1.25' color='#218a36' align='center'>Respawn in %1 seconds.</t>",[(_respawnTime - time),"HH:MM"] call BIS_fnc_timeToString];
			sleep 0.1;
		};
		ctrlDelete _ctrlRespawnTimer;

		//Fade in, enable sounds and player input
		0 cutText ["","BLACK IN",FADEIN_TIME];
		FADEIN_TIME fadeMusic 1;
		FADEIN_TIME fadeRadio 1;
		FADEIN_TIME fadeSpeech 1;
		showChat true;
		disableUserInput false;
		[
			["Respawned"],
			[format ["GRID:%1",mapGridPosition _unit]],
			[
				format 
				["Tickets used: %1/%2",
				_unit getVariable ["ENH_SPR_UsedTickets",0],
				ENH_SPR_Tickets]
			]
		] spawn BIS_fnc_EXP_camp_SITREP;
	}
	else
	{
		sleep ENH_SPR_Time;
	};
	_unit call ENH_SPR_fnc_respawn;
};

{
	_x setVariable ["ENH_SPR_OriginalSide",side _x];
	_x addEventHandler ["handleDamage",
	{
		params ["_unit","","_damage","","","_hitIndex"];
		if (_unit getVariable ["ENH_SPR_Unconcious",false]) exitWith {0};

		//If tickets are used, let the unit die
		if (_unit getVariable ["ENH_SPR_UsedTickets",0] >= ENH_SPR_Tickets) exitWith
		{
			_unit removeEventHandler ["handleDamage",_thisEventHandler];
		};

		//If damage received to head, neck or face is greater 1, unit can die instantly.
		if (ENH_SPR_CanDie && {_hitIndex in [0,1,2] && _damage > 1}) exitWith {1};

		//Get new damage
		private _newDamage = if (_hitIndex >= 0) then
		{
			_damage - (_unit getHitIndex _hitIndex);
		} else 
		{
			_damage - damage _unit;
		};
		
		//If damage is greater than threshold, init respawn
		if (damage _unit + _newDamage >= THRESHOLD) then
		{
			_unit setVariable ["ENH_SPR_Unconcious",true];
			_unit allowDamage false;
			_unit setCaptive true;
			_unit setUnconscious true;
			private _usedTickets = _unit getVariable ["ENH_SPR_UsedTickets",0];
			_unit setVariable ["ENH_SPR_UsedTickets",_usedTickets + 1];
			_unit spawn ENH_SPR_fnc_handleRespawnTimer;
		};
	}];
} forEach allUnits;

true