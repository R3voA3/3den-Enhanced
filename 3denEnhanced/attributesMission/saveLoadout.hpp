class ENH_SaveLoadout
{
   displayName = $STR_ENH_SAVELOADOUT_DISPLAYNAME;
   tooltip = $STR_ENH_SAVELOADOUT_TOOLTIP;
   property = "ENH_saveLoadout";
   control = "Checkbox";
   expression =
   "\
      if (!is3DEN && {hasInterface && {_value && {isMultiplayer}}}) then\
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