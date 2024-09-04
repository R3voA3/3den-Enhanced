class ENH_SaveLoadout
{
    displayName = "$STR_ENH_MAIN_SAVELOADOUT_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_SAVELOADOUT_TOOLTIP";
    property = "ENH_saveLoadout";
    control = "Checkbox";
    expression =
    "if (!isMultiplayer || !_value || is3DEN || !hasInterface) exitWith {};\
        0 spawn\
        {\
            waitUntil {sleep 1; !isNull player};\
            player setVariable ['ENH_savedLoadout', getUnitloadout player];\
            player addMPEventHandler ['MPRespawn',\
            {\
                params ['_unit'];\
                private _loadout = _unit getVariable ['ENH_savedLoadout', []];\
                if (_loadout isNotEqualTo []) then {_unit setUnitLoadout _loadout};\
            }];\
        };";
    defaultValue = "false";
};
