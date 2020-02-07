class ENH_SaveLoadout
{
   displayName = $STR_ENH_saveLoadout_displayName;
   tooltip = $STR_ENH_saveLoadout_tooltip;
   property = "ENH_saveLoadout";
   control = "Checkbox";
   expression =
   "\
      if (!is3DEN && hasInterface && _value) then\
      {\
         [] spawn\
         {\
            waitUntil {sleep 1; !isNull player};\
            player setVariable ['ENH_savedLoadout',getUnitloadout player];\
            player addEventHandler ['Respawn',{player setUnitLoadout (player getVariable 'ENH_savedLoadout')}];\
         };\
      };\
   ";
   defaultValue = "false";
};