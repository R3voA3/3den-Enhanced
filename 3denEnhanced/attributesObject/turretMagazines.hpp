class ENH_TurretMagazines
{
	displayName = "Turret Magazines";
  tooltip = "Shows all available magazines from all turrets. Use the slider to set a custom magazine count.";
  control = "ENH_TurretMagazines";
	property = "ENH_TurretMagazines";
	expression = "if (!is3DEN && {isServer}) then\
  {\
    {\
      _x params ['_magClass','_turretPath','_count'];\
      _this removeMagazinesTurret [_magClass,_turretPath];\
      for '_i' from 0 to _count do\
      {\
        _this addMagazineTurret [_magClass,_turretPath];\
      };\
    } forEach parseSimpleArray _value;\
  };";
	condition = "objectVehicle";
  defaultValue = "_this call ENH_fnc_turretMagazines_defaultValue";
};