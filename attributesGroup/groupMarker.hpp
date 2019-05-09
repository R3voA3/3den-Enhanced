class Enh_GroupMarker
{
	displayName = "Group Marker";
	tooltip = "Shows the groups position on the map.The position is updated every second. If the group becomes empty, the marker gets deleted.\n\nThe update process can be paused by setting the variable 'Enh_GroupMarker_Update' in the groups namespace to false.\n\nValue has to be a marker class name from CfgMarkers.";
	property = "Enh_groupMarker";
	control = "Edit";
	expression = "\
	if (!is3DEN && _value != '') then\
	{\
		[_this,_value] spawn\
		{\
			params ['_group','_value'];\
			private _leader = leader _group;\
			private _marker = createMarker\
			[\
				format ['Enh_GroupMarker_%1',str floor random 10e5],\
				_leader\
			];\
			_marker setMarkerType _value;\
			_marker setMarkerText groupId _group;\
			_marker setMarkerColor ([side _group,true] call BIS_fnc_sideColor);\
			while {true} do\
			{\
				sleep 1; comment 'Sleep here to make sure units joined the group already';\
				if (units _group isEqualTo []) exitWith {deleteMarker _marker};\
				if (_group getVariable ['Enh_GroupMarker_Update',true]) then\
				{\
					_marker setMarkerPos position leader _group;\
					_marker setMarkerText format ['%1 (%2)',groupId _group, count units _group];\
				};\
			};\
		};\
	};";
	defaultValue = "''";
	typeName = "STRING";
};