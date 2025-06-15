#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Deletes all empty layers (10 layers deep) and creates a history entry.

    Parameter(s):
    -

    Returns:
    -
*/

[localize "STR_ENH_MAIN_TOOLS_DELETEEMPTYLAYERS", nil, "a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa"] collect3DENHistory
{
    for "_i" from 0 to 10 do // Delete 10 layers deep, easy workaround, performance doesn't matter here
    {
        {
            if ((get3DENLayerEntities _x) isEqualTo []) then
            {
                remove3DENLayer _x;
            };
        } forEach (all3DENEntities # 6);
    };
};

["collapseEntityList"] call BIS_fnc_3DENInterface;
["ENH_actionPerformed"] call BIS_fnc_3DENNotification;
