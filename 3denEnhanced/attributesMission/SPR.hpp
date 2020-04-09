class ENH_SPR
{
	collapsed = 1;
	displayName = $STR_ENH_SPR;
	class Attributes
	{
		class ENH_SPR
		{
			displayName = $STR_ENH_SPR;
			property = "ENH_SPR";
			control = "ENH_SPR";
			expression =
			"if (!is3DEN && {_value # 0 > 0 && {!isMultiplayer}}) then\
			{\
				ENH_SPR_Ruleset = _value param [0,0];\
				ENH_SPR_Delay = _value param [1,20];\
				ENH_SPR_CanDie = _value param [2,false];\
				ENH_SPR_RestoreLoadout = _value param [3,false];\
				ENH_SPR_Positions_West = allMapMarkers select {'respawn_west' in _x} apply {getMarkerPos _x};\
				ENH_SPR_Positions_East = allMapMarkers select {'respawn_east' in _x} apply {getMarkerPos _x};\
				ENH_SPR_Positions_Guerilla = allMapMarkers select {'respawn_guerilla' in _x} apply {getMarkerPos _x};\
				ENH_SPR_Positions_Civilian = allMapMarkers select {'respawn_civilian' in _x} apply {getMarkerPos _x};\
				\
				{\
					_x setVariable ['ENH_SPR_OriginalSide',side _x];\
					_x setVariable ['ENH_SPR_OriginalLoadout',getUnitLoadout _x];\
					_x addEventHandler ['handleDamage',\
					{\
						params ['_unit','_selection','_damage','','','_hitIndex'];\
						if (_handleDamage < 0.1 || {!alive _unit || {lifeState _unit isEqualTo 'INCAPACITATED'}}) exitWith {0};\
						if (ENH_SPR_CanDie && {_selection == 'head' && {_damage >= 1.2}}) exitWith\
						{\
							_unit setDamage 1;\
							_unit removeEventHandler ['handleDamage',_thisEventHandler];\
						};\
						if (_unit getVariable ['ENH_SPR_Tickets',0] == 0) then\
						{\
							_unit removeEventHandler ['handleDamage',_thisEventHandler];\
						}\
						else\
						{\
							if(_selection == '' && {_damage >= 0.95}) then\
							{\
								setAccTime 1;\
								_unit allowDamage false;\
								_unit setCaptive true;\
								_unit setUnconscious true;\
								_unit setVariable ['ENH_SPR_Tickets',(_unit getVariable ['ENH_SPR_Tickets',0]) - 1];\
								if (isPlayer _unit) then {enableTeamSwitch false} else {removeSwitchableUnit _unit};\
								moveOut _unit;\
								_unit spawn ENH_fnc_SPR_respawnTimer;\
								_damage = 0;\
							}\
							else\
							{\
								_damage = _damage min 0.95;\
							};\
						};\
						_damage;\
					}];\
				} forEach (allUnits select {_x getVariable ['ENH_SPR_Tickets',0] > 0});\
				\
				ENH_fnc_SPR_respawn =\
				{\
					params ['_unit'];\
					if (isPlayer _unit) then {enableTeamSwitch true} else {addSwitchableUnit _unit};\
					if (ENH_SPR_RestoreLoadout) then {_unit setUnitLoadout (_unit getVariable 'ENH_SPR_OriginalLoadout')};\
					if (ENH_SPR_Ruleset >= 2) then\
					{\
						private _sideID = (_unit getVariable 'ENH_SPR_OriginalSide') call BIS_fnc_sideID;\
						private _positions = [ENH_SPR_Positions_East,ENH_SPR_Positions_West,ENH_SPR_Positions_Guerilla,ENH_SPR_Positions_Civilian] select _sideID;\
						if !(_positions isEqualTo []) then\
						{\
							private _respawnPos = if (ENH_SPR_Ruleset == 2) then\
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
					_unit setDamage 0;\
					_unit switchMove '';\
					_unit spawn\
					{\
						sleep 8;\
						_this setCaptive false;\
					};\
				};\
				\
				ENH_fnc_SPR_respawnTimer =\
				{\
					params ['_unit'];\
					private _respawnTime = time + ENH_SPR_Delay;\
					if (isPlayer _unit) then\
					{\
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
							[format ['GRID: %1',mapGridPosition _unit]],\
							[format ['Tickets left: %1',_unit getVariable 'ENH_SPR_Tickets']]\
						] spawn BIS_fnc_EXP_camp_SITREP;\
					}\
					else\
					{\
						if ((side player getFriend (_unit getVariable 'ENH_SPR_OriginalSide')) >= 0.6) then\
						{\
							[\
								str _unit,'onEachFrame',\
								{\
									drawIcon3D ['\a3\Modules_f\data\portraitRespawn_ca.paa',[0.13,0.54,0.21,0.8],ASLToAGL ((_this # 0) modelToWorldVisualWorld [0,0,1]),1,1,0,str round ((_this # 1) - time),2];\
								},\
								[_unit,_respawnTime]\
							] call BIS_fnc_addStackedEventHandler;\
						};\
						sleep ENH_SPR_Delay;\
					};\
					[str _unit,'onEachFrame'] call BIS_fnc_removeStackedEventHandler;\
					_unit call ENH_fnc_SPR_respawn;\
				};\
			}";
			defaultValue = "[0,20,false,false]";
		};
	};
};