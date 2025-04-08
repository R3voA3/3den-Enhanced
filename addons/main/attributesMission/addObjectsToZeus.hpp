// Type name check in expression is for backwards compatibility
class ENH_AddObjectsToZeus
{
    displayName = "$STR_ENH_MAIN_EDITABLEOBJZEUS_DISPLAYNAME";
    property = "ENH_AddObjectsToZeus";
    control = "Combo";
    expression =
    "\
        if (_value isEqualType true) then {_value = 2};\
        if (!is3DEN && isServer && _value > 0) then\
        {\
            _value spawn
            {
                params ['_value'];
                waitUntil {sleep 1; allCurators isNotEqualTo []};
                if (_value == 1 || _value == 2) then\
                {\
                    allCurators apply {_x addCuratorEditableObjects [allMissionObjects '', true]};\
                };\
                if (_value == 2) then\
                {\
                    addMissionEventHandler ['EntityCreated',\
                    {\
                        params ['_entity'];\
                        allCurators apply {_x addCuratorEditableObjects [[_entity], true]};\
                    }];\
                };\
            };\
        }";
    defaultValue = 0;
    typeName = "NUMBER";

    class Values
    {
        class Disabled
        {
            name = "$STR_DISABLED";
            value = 0;
        };
        class EditorPlacedOnly
        {
            name = "$STR_ENH_MAIN_EDITABLEOBJZEUS_EDITORPLACEONLY_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_EDITABLEOBJZEUS_EDITORPLACEONLY_TOOLTIP";
            value = 1;
        };
        class All
        {
            name = "$STR_ENH_MAIN_EDITABLEOBJZEUS_ALL_DISPLAYNAME";
            tooltip = "$STR_ENH_MAIN_EDITABLEOBJZEUS_ALL_TOOLTIP";
            value = 2;
        };
    };
};
