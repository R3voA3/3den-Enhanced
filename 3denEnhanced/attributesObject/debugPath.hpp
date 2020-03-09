class ENH_debugPath
{
	displayName = $STR_ENH_DEBUGPATH_DISPLAYNAME;
	tooltip = $STR_ENH_DEBUGPATH_TOOLTIP;
	property = "ENH_debugPath";
	control = "Checkbox";
	expression =
	"if (!is3DEN && {_value}) then\
	{\
		[_this] spawn\
		{\
			systemChat format [localize 'STR_ENH_DEBUGPATH_MESSAGE',str _this];\
			params ['_unit'];\
			private _arrow = objNull;\
			private _arrowColour = format ['#(rgb,8,8,3)color(%1,%2,%3,1)',random(1),random(1),random(1)];\
			while {true} do\
			{\
				if ((_unit distance _arrow) > 20)  then\
				{\
					_arrow = createVehicle ['Sign_Arrow_Direction_Blue_F',position _unit,[],0,'CAN_COLLIDE'];\
					_arrow setObjectTexture [0,_arrowColour];\
					_arrow setDir getDir _unit;\
					_markerName = format ['debugPath_%1_%2',str _unit,str random 100000];\
					_marker = createMarker [_markerName,_unit];\
					_marker setMarkerDir getDir _unit;\
					_marker setMarkerType 'mil_arrow2';\
				};\
				sleep 0.2;\
			};\
		};\
	}";
	condition = "objectBrain + objectVehicle";
	defaultValue = "false";
};