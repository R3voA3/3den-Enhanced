class ENH_SPR
{
	collapsed = 1;
	displayName = "Single Player Respawn";
	class Attributes
	{
		class ENH_SPR
		{
			displayName = "Single Player Respawn";
			property = "ENH_SPR";
			control = "ENH_SPR";
			expression =
			"\
			if (is3DEN && {_value # 1 == 0 && isMultiplayer}) exitWith {};\
			ENH_SPR_Delay = _value param [0,20];\
			ENH_SPR_Tickets = _value param [1,0];\
			ENH_SPR_Ruleset = _value param [2,0];\
			ENH_SPR_CanDie = _value param [3,false];\
			ENH_SPR_Positions_West = allMapMarkers select {'respawn_west' in _x} apply {getMarkerPos _x};\
			ENH_SPR_Positions_East = allMapMarkers select {'respawn_east' in _x} apply {getMarkerPos _x};\
			ENH_SPR_Positions_Guerilla = allMapMarkers select {'respawn_guerilla' in _x} apply {getMarkerPos _x};\
			ENH_SPR_Positions_Civilian = allMapMarkers select {'respawn_civlian' in _x} apply {getMarkerPos _x};\
			ENH_fnc_SPR_respawn =\
			{\
				params ['_unit'];\
				if (ENH_SPR_Ruleset > 0) then\
				{\
					private _sideID = (_unit getVariable ['ENH_SPR_OriginalSide',west]) call BIS_fnc_sideID;\
					private _positions = [ENH_SPR_Positions_East,ENH_SPR_Positions_West,ENH_SPR_Positions_Guerilla,ENH_SPR_Positions_Civilian] select _sideID;\
					if !(_positions isEqualTo []) then\
					{\
						private _respawnPos = if (ENH_SPR_Ruleset == 1) then\
						{\
							selectRandom _positions;\
						}\
						else\
						{\
							([_positions,[],{_unit distance _x},'ASCEND'] call BIS_fnc_sortBy) select 0;\
						};\
						_unit setPos _respawnPos;\
					};\
				};\
				_unit setUnconscious false;\
				_unit allowDamage true;\
				_unit setCaptive false;\
				_unit setDamage 0;\
				_unit setVariable ['ENH_SPR_Unconcious',false];\
			};\
			ENH_fnc_SPR_respawnTimer =\
			{\
				params ['_unit'];\
				if (isPlayer _unit) then\
				{\
					private _respawnTime = time + ENH_SPR_Delay;\
					private _ctrlRespawnTimer = (call BIS_fnc_displayMission) ctrlCreate ['RscStructuredText',-1];\
					_ctrlRespawnTimer ctrlSetPosition [0.25,0,0.5,0.06];\
					_ctrlRespawnTimer ctrlSetBackgroundColor [0,0,0,0.1];\
					_ctrlRespawnTimer ctrlCommit 0;\
					0 cutText ['','BLACK OUT',0.3];\
					0.3 fadeMusic 0;\
					0.3 fadeRadio 0;\
					0.3 fadeSpeech 0;\
					showChat false;\
					while {time < _respawnTime} do\
					{\
						_ctrlRespawnTimer ctrlSetStructuredText parseText format ['<t size=''1.25'' color=''#218a36'' align=''center''>Respawn in %1 seconds.</t>',[(_respawnTime - time),'HH:MM'] call BIS_fnc_timeToString];\
						sleep 0.1;\
					};\
					ctrlDelete _ctrlRespawnTimer;\
					0 cutText ['','BLACK IN',8];\
					8 fadeMusic 1;\
					8 fadeRadio 1;\
					8 fadeSpeech 1;\
					showChat true;\
					[\
						['Respawned'],\
						[format ['GRID:%1',mapGridPosition _unit]],\
						[format ['Tickets used: %1/%2',_unit getVariable ['ENH_SPR_UsedTickets',0],ENH_SPR_Tickets]]\
					] spawn BIS_fnc_EXP_camp_SITREP;\
				}\
				else\
				{\
					sleep ENH_SPR_Delay;\
				};\
				_unit call ENH_fnc_SPR_respawn;\
			};\
			{\
				_x setVariable ['ENH_SPR_OriginalSide',side _x];\
				_x addEventHandler ['handleDamage',\
				{\
					params ['_unit','','_damage','','','_hitIndex'];\
					if (_unit getVariable ['ENH_SPR_Unconcious',false]) exitWith {0};\
					if (_unit getVariable ['ENH_SPR_UsedTickets',0] >= ENH_SPR_Tickets) exitWith\
					{\
						_unit removeEventHandler ['handleDamage',_thisEventHandler];\
					};\
					if (ENH_SPR_CanDie && {_hitIndex in [0,1,2] && _damage > 1}) exitWith {1};\
					private _newDamage = if (_hitIndex >= 0) then\
					{\
						_damage - (_unit getHitIndex _hitIndex);\
					}\
					else\
					{\
						_damage - damage _unit;\
					};\
					if (damage _unit + _newDamage >= 0.9) then\
					{\
						_unit setVariable ['ENH_SPR_Unconcious',true];\
						_unit allowDamage false;\
						_unit setCaptive true;\
						_unit setUnconscious true;\
						_unit setVariable ['ENH_SPR_UsedTickets',(_unit getVariable ['ENH_SPR_UsedTickets',0]) + 1];\
						_unit spawn ENH_fnc_SPR_respawnTimer;\
						0.9;\
					};\
					damage _unit + _newDamage;\
				}];\
			} forEach (allUnits select {_x getVariable 'ENH_EnableSPR' isEqualTo true})";
			defaultValue = "[20,0,0,false]";
		};
	};
};