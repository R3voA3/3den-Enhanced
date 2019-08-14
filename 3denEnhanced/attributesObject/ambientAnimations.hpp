class Enh_AmbientAnimations
{
	displayName = $STR_ENH_ambientAnimations_displayName;
	control = "Enh_AmbientAnimations";
	property = "Enh_AmbientAnimations";
	expression =
	"\
		_value params ['_animSet','_canExit','_disableCollision','_attach'];\
		\
		_this disableAI 'all';\
		if (_disableCollision && !is3DEN) then\
		{\
			private _object = (nearestObjects [_this,[],2,true] - [_this] select 0);\
		};\
		if (_attach && !is3DEN) then\
		{\
			private _logic = group _this createUnit ['Logic',getPosATL _this,[],0,'NONE'];\
			_this setVariable ['Enh_ambientAnimations_logic',_logic];\
			[_this,_logic] call BIS_fnc_attachToRelative;\
		};\
		(_animSet call BIS_ambientAnimationsGetParams) params ['_anims'];\
		_this setVariable ['Enh_ambientAnimations_anims',_anims];\
		\
		Enh_fnc_ambientAnimations_play =\
		{\
			params ['_this'];\
			private _anim = selectRandom (_this getVariable ['Enh_ambientAnimations_anims',[]]);\
			[_this,_anim] remoteExec ['switchMove',0];\
		};\
		\
		Enh_fnc_ambientAnimations_exit =\
		{\
			params ['_this'];\
			if (_this getVariable ['Enh_ambientAnim_exit',false]) exitWith {false};\
			_this setVariable ['Enh_ambientAnim_exit',true];\
			detach _this;\
			deleteVehicle (_this getVariable ['Enh_ambientAnimations_logic',objNull]);\
			[_this,''] remoteExec ['switchMove',0];\
			\
			_this enableAI 'all';\
			\
			_this removeEventHandler ['Killed',_this getVariable ['Enh_EHKilled',-1]];\
			_this removeEventHandler ['Dammaged',_this getVariable ['Enh_EHDammaged',-1]];\
			_this removeEventHandler ['AnimDone',_this getVariable ['Enh_EHAnimDone',-1]];\
		};\
		if (_canExit) then\
		{\
			_EHAnimDone = _this addEventHandler\
			[\
				'AnimDone',\
				{\
					params ['_this'];\
					if (alive _this) then\
					{\
						_this call Enh_ambientAnimations_play;\
					}\
					else\
					{\
						_this call Enh_ambientAnimations_exit;\
					};\
				}\
			];\
			_this setVariable ['Enh_EHAnimDone',_EHAnimDone];\
			\
			private _EHKilled = _this addEventHandler\
			[\
				'Killed',\
				{\
					(_this select 0) call Enh_ambientAnimations_exit;\
				}\
			];\
			_this setVariable ['Enh_EHKilled',_EHKilled];\
			private _EHDammaged = _this addEventHandler\
			[\
				'Dammaged',\
				{\
					(_this select 0) call Enh_ambientAnimations_exit;\
				}\
			];\
			_this setVariable ['Enh_EHDammaged',_EHDammaged];\
			[_this] spawn\
			{\
				params ['_this'];\
				waitUntil\
				{\
					sleep 1; !isNull (_this findNearestEnemy _this) || (_this getVariable ['Enh_ambientAnim_exit',false])\
				};\
				_this call Enh_ambientAnimations_exit;\
			};\
		};\
		_this call Enh_fnc_ambientAnimations_play";
	condition = "objectBrain";
	defaultValue = "['',true,false,false]";
};