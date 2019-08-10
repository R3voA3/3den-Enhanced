class Enh_GroupMarker
{
	displayName = $STR_ENH_groupMarker_displayName;
	collapsed = 0;
	class Attributes
	{
		class Enh_GroupMarker
		{
			displayName = $STR_ENH_groupMarker_displayName;
			property = "Enh_groupMarker";
			control = "Enh_GroupMarker";
			expression = "\
			if (!is3DEN && !(_value isEqualTo ['','','',true])) then\
			{\
				[_this,_value] spawn\
				{\
					params ['_group','_value'];\
					_value params ['_type','_color','_text','_showGroupSize'];\
					private _leader = leader _group;\
					private _marker = createMarker\
					[\
						format ['Enh_GroupMarker_%1',str floor random 10e5],\
						_leader\
					];\
					_marker setMarkerType _type;\
					_marker setMarkerColor _color;\
					_marker setMarkerText _text;\
					while {true} do\
					{\
						sleep 1; comment 'Sleep here to make sure units joined the group already';\
						if (units _group isEqualTo []) exitWith {deleteMarker _marker};\
						if (_group getVariable ['Enh_GroupMarker_Update',true]) then\
						{\
							_marker setMarkerPos _leader;\
							if (_showGroupSize) then\
							{\
								_marker setMarkerText format ['%1 (%2)',groupId _group, count units _group];\
							};\
						};\
					};\
				};\
			};";
			defaultValue = "['',[side _this,true] call BIS_fnc_sideColor,groupID _this ,true]";
		};
	};
};