class ENH_MagazinesTurrets
{
	displayName = "Turrets Magazines";
  control = "ENH_MagazinesTurrets";
	property = "ENH_MagazinesTurrets";
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
  defaultValue = "_this call ENH_fnc_magazineTurrets_defaultValue";
};