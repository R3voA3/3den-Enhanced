class ENH_AddObjectsToZeus
{
  displayName = "$STR_ENH_MAIN_EDITABLEOBJZEUS_DISPLAYNAME";
  tooltip = "$STR_ENH_MAIN_EDITABLEOBJZEUS_TOOLTIP";
  property = "ENH_AddObjectsToZeus";
  control = "Checkbox";
  expression =
  "\
    if (!is3DEN && isServer && _value && !(allCurators isEqualTo [])) then\
    {\
      0 spawn\
      {\
        scriptName 'ENH_Attribute_AddObjectsToZeus';\
        while {true} do\
        {\
          {\
          _x addCuratorEditableObjects\
            [\
              entities [[], ['Logic'], true],\
              true\
            ];\
          } count allCurators;\
          sleep 60;\
        };\
      };\
    }";
  defaultValue = "false";
};