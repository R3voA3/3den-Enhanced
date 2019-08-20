class Enh_AmbientAnimations
{
	displayName = $STR_ENH_ambientAnimations_displayName;
	control = "Enh_AmbientAnimations";
	property = "Enh_AmbientAnimations";
	expression =
	"\
		if !(_value # 0 isEqualTo '') then\
		{\
			_value params ['_animSet','_anims','_canExit','_attach'];\
			\
			_this setVariable ['Enh_ambientAnimations_anims',_anims];\
			_this disableAI 'all';\
			if (_attach && !is3DEN) then\
			{\
				private _logic = group _this createUnit ['Logic',getPosATL _this,[],0,'NONE'];\
				_this setVariable ['Enh_ambientAnimations_logic',_logic];\
				[_this,_logic] call BIS_fnc_attachToRelative;\
			};\
			\
			Enh_fnc_ambientAnimations_play =\
			{\
				params ['_unit'];\
				private _anim = selectRandom (_unit getVariable ['Enh_ambientAnimations_anims',[]]);\
				[_unit,_anim] remoteExec ['switchMove',0];\
			};\
			\
			Enh_fnc_ambientAnimations_exit =\
			{\
				params ['_unit'];\
				if (_unit getVariable ['Enh_ambientAnimations_exit',false]) exitWith {false};\
				_unit setVariable ['Enh_ambientAnimations_exit',true];\
				detach _unit;\
				deleteVehicle (_unit getVariable ['Enh_ambientAnimations_logic',objNull]);\
				[_unit,''] remoteExec ['switchMove',0];\
				\
				_unit enableAI 'all';\
				\
				_unit removeEventHandler ['Killed',_unit getVariable ['Enh_EHKilled',-1]];\
				_unit removeEventHandler ['Dammaged',_unit getVariable ['Enh_EHDammaged',-1]];\
				_unit removeEventHandler ['AnimDone',_unit getVariable ['Enh_EHAnimDone',-1]];\
			};\
			\
			_EHAnimDone = _this addEventHandler\
			[\
				'AnimDone',\
				{\
					params ['_unit'];\
					if (alive _unit) then\
					{\
						_unit call Enh_fnc_ambientAnimations_play;\
					}\
					else\
					{\
						_unit call Enh_fnc_ambientAnimations_exit;\
					};\
				}\
			];\
			_this setVariable ['Enh_EHAnimDone',_EHAnimDone];\
			\
			if (_canExit) then\
			{\
				private _EHKilled = _this addEventHandler\
				[\
					'Killed',\
					{\
						(_this select 0) call Enh_fnc_ambientAnimations_exit;\
					}\
				];\
				_this setVariable ['Enh_EHKilled',_EHKilled];\
				private _EHDammaged = _this addEventHandler\
				[\
					'Dammaged',\
					{\
						(_this select 0) call Enh_fnc_ambientAnimations_exit;\
					}\
				];\
				_this setVariable ['Enh_EHDammaged',_EHDammaged];\
				_this spawn\
				{\
					params ['_unit'];\
					waitUntil\
					{\
						sleep 1; !isNull (_unit findNearestEnemy _unit) || (_unit getVariable ['Enh_ambientAnimations_exit',false])\
					};\
					_unit call Enh_fnc_ambientAnimations_exit;\
				};\
			};\
			_this call Enh_fnc_ambientAnimations_play;\
		};";
	condition = "objectBrain";
	defaultValue = "['',false,false]";
};