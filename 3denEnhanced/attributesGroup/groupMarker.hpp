class ENH_GroupMarker
{
  displayName = "$STR_ENH_GROUPMARKER_DISPLAYNAME";
  collapsed = 1;
  class Attributes
  {
    class ENH_GroupMarker_Subcategory
    {
      description = "$STR_ENH_GROUPMARKER_DESCRIPTION";
      data = "AttributeSystemSubcategory";
      control = "ENH_SubCategoryNoHeader3_Fixed";
    };
    class ENH_GroupMarker
    {
      displayName = "$STR_ENH_GROUPMARKER_DISPLAYNAME";
      tooltip = "$STR_ENH_GROUPMARKER_DESCRIPTION";
      property = "ENH_groupMarker";
      control = "ENH_GroupMarker";
      expression = "\
      if (!is3DEN && (_value # 0 != '')) then\
      {\
        [_this, _value] spawn\
        {\
          scriptName 'ENH_Attribute_GroupMarker';\
          params ['_group', '_parameters'];\
          _parameters params ['_type', '_color', '_text', '_showGroupSize'];\
          private _leader = leader _group;\
          private _marker = createMarkerLocal\
          [\
            'ENH_GroupMarker_' + str _group,\
            _leader\
          ];\
          _marker setMarkerTypeLocal _type;\
          _marker setMarkerColorLocal _color;\
          _marker setMarkerTextLocal (_text call BIS_fnc_localize);\
          while {true} do\
          {\
            sleep 1;\
            if (units _group isEqualTo []) exitWith {deleteMarker _marker};\
            if (_group getVariable ['ENH_GroupMarker_Update', true]) then\
            {\
              _marker setMarkerPos _leader;\
              if (_showGroupSize) then\
              {\
                _marker setMarkerTextLocal (groupID _group + ' (' + str count units _group + ')');\
              };\
            };\
          };\
        };\
      };";
      defaultValue = "['', 'Default', groupID _this, true]";
    };
  };
};