class Enh_MoveIntoToDo
{
	displayName = $STR_ENH_moveIntoToDo_displayName;
	tooltip = $STR_ENH_moveIntoToDo_tooltip;
	property = "Enh_MoveIntoToDo";
	control = "Checkbox";
	expression =
	"\
	if (_value && is3DEN) then\
	{\
		private _allLayers = all3DENEntities # 6;\
		if (_allLayers isEqualTo []) then\
		{\
			Enh_toDoList = -1 add3DENLayer localize 'STR_ENH_toDoList';\
		}\
		else\
		{\
			{\
				private _layerName = (_x get3DENAttribute 'Name') # 0;\
				if (_layerName == (localize 'STR_ENH_toDoList')) exitWith {Enh_toDoList = _x};\
			} forEach _allLayers;\
		};\
		_this set3DENLayer Enh_toDoList;\
		Enh_toDoList = nil;\
	}";
	defaultValue = "false";
};