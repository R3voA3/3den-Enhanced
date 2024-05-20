class ENH_AddObjectsToZeus
{
	displayName = "$STR_ENH_MAIN_EDITABLEOBJZEUS_DISPLAYNAME";
	tooltip = "$STR_ENH_MAIN_EDITABLEOBJZEUS_TOOLTIP";
	property = "ENH_AddObjectsToZeus";
	control = "Checkbox";
	expression =
	"\
		if (!is3DEN && isServer && _value) then\
		{\
			private _objects = allMissionObjects "";\
			allCurators apply { _x addCuratorEditableObjects [_objects, true]};\
			addMissionEventHandler ['EntityCreated',\
			{\
				params ['_entity'];\
				allCurators apply {_x addCuratorEditableObjects [[_entity], true]};\
			}];\
		}";
	defaultValue = "false";
};