/* class ENH_SaveLoadout
{
  displayName = "$STR_ENH_SAVELOADOUT_DISPLAYNAME";
  tooltip = "$STR_ENH_SAVELOADOUT_TOOLTIP";
  property = "ENH_saveLoadout";
  control = "Checkbox";
  expression =
  "\
    if (!is3DEN && hasInterface && _value && isMultiplayer) then\
    {\
      [] spawn\
      {\
        scriptName 'ENH_Attribute_SaveLoadout';\
        waitUntil {sleep 1; !isNull player};\
        player setVariable ['ENH_savedLoadout', getUnitloadout player];\
        player addEventHandler ['Respawn',{player setUnitLoadout (player getVariable 'ENH_savedLoadout')}];\
      };\
    };\
  ";
  defaultValue = "false";
}; */

class ENH_SaveLoadout
{
  displayName = "$STR_ENH_SAVELOADOUT_DISPLAYNAME";
  tooltip = "$STR_ENH_SAVELOADOUT_TOOLTIP";
  property = "ENH_saveLoadout";
  control = "Checkbox";
  expression =
  "if (!isMultiplayer || !_value || is3DEN) exitWith {};\
    if (hasInterface) then\
    {\
      [] spawn\
      {\
        waitUntil {sleep 1; !isNull player};\
        diag_log format ['ENH_saveLoadout: Player (%1) was detected at %2.', player, time];\
        player setVariable ['ENH_savedLoadout', getUnitloadout player];\
        player addMPEventHandler ['MPRespawn',\
        {\
          params ['_unit', '_corpse'];\
          private _loadout = _unit getVariable ['ENH_savedLoadout', []];\
          if (_loadout isNotEqualTo []) then\
          {\
            _unit setUnitLoadout _loadout;\
            diag_log format ['ENH_saveLoadout: Loadout of player (%1) was set to %2 at %3', _unit, _loadout, time];\
          };\
        }];\
      };\
    };";
  defaultValue = "false";
};