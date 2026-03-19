class ENH_SaveLoadout
{
    displayName = "$STR_ENH_MAIN_SAVELOADOUT_DISPLAYNAME";
    tooltip = "$STR_ENH_MAIN_SAVELOADOUT_TOOLTIP";
    property = "ENH_saveLoadout";
    control = "Combo";
    expression =
    "_value = [0, 1, 2, 3] select _value;\
    if (!isMultiplayer || _value == 0 || is3DEN || !hasInterface) exitWith {};\
    _value spawn\
    {\
        params ['_value'];\
        waitUntil {sleep 1; !isNull player};\
        switch _value do\
        {\
            case 1:\
            {\
                player setVariable ['ENH_SavedLoadout', getUnitloadout player];\
                player addEventHandler ['Respawn',\
                {\
                    private _loadout = player getVariable ['ENH_SavedLoadout', []];\
                    if (_loadout isNotEqualTo []) then {player setUnitLoadout _loadout};\
                }];\
            };\
            case 2:\
            {\
                player addEventHandler ['Killed',  {player setVariable ['ENH_SavedLoadout', getUnitLoadout player]}];\
                player addEventHandler ['Respawn',\
                {\
                    private _loadout = player getVariable ['ENH_SavedLoadout', []];\
                    if (_loadout isNotEqualTo []) then {player setUnitLoadout _loadout};\
                }];\
            };\
            case 3:\
            {
                player setVariable ['ENH_SavedLoadout', getUnitloadout player];\
                player addEventHandler ['Respawn',\
                {\
                    private _loadout = player getVariable ['ENH_SavedLoadout', []];\
                    if (_loadout isNotEqualTo []) then {player setUnitLoadout _loadout};\
                }];\
                \
                [missionNamespace, 'arsenalClosed', {player setVariable ['ENH_SavedLoadout', getUnitloadout player]}] call BIS_fnc_addScriptedEventHandler;\
            };
            default {};\
        };\
    };";
    defaultValue = 0;
    typeName = "NUMBER";
    class Values
    {
        class Disabled
        {
            name = "$STR_A3_DISABLED";
            value = 0;
        };
        class OriginalLoadout
        {
            name = "$STR_ENH_MAIN_SAVELOADOUT_ORIGINAL_LOADOUT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SAVELOADOUT_ORIGINAL_LOADOUT_TOOLTIP";
            value = 1;
        };
        class DeathLoadout
        {
            name = "$STR_ENH_MAIN_SAVELOADOUT_DEATH_LOADOUT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SAVELOADOUT_DEATH_LOADOUT_TOOLTIP";
            value = 2;
        };
        class ArsenalLoadout
        {
            name = "$STR_ENH_MAIN_SAVELOADOUT_ARSENAL_LOADOUT_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_SAVELOADOUT_ARSENAL_LOADOUT_TOOLTIP";
            value = 3;
        };
    };
};
