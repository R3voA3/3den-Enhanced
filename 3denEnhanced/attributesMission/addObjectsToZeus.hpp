class ENH_AddObjectsToZeus
{
	displayName = $STR_ENH_EDITABLEOBJZEUS_DISPLAYNAME;
	tooltip = $STR_ENH_EDITABLEOBJZEUS_TOOLTIP;
	property = "ENH_dynamicGroups";
	control = "Checkbox";
	expression =
	"\
		if (!is3DEN && {isServer && {_value && {!(allCurators isEqualTo [])}}}) then\
		{\
			[] spawn\
			{\
				while {true} do\
				{\
					{\
						 _x addCuratorEditableObjects\
						 [\
						 	entities [[],['Logic'],true],\
						  	true\
						 ];\
					} count allCurators;\
					sleep 60;\
				};\
			};\
		}";
	defaultValue = "false";
};