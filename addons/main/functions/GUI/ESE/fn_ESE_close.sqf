#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-06-28

    Description:
    Prevents the equipment storage editor from being accidentally closed and shows a warning.

    Parameter(s):
    -

    Returns:
    -
*/

#define DISPLAY_ESE (uiNamespace getVariable "ENH_Display_ESE")

private _currentValue = true call ENH_fnc_ESE_applyAttribute;
private _setValue = (ENH_ESE_target get3DENAttribute "ammoBox") # 0;

// Check if saved attribute value is equal to the content of the inventory list
if (_currentValue isNotEqualTo _setValue) then
{
    [
        localize "STR_ENH_MAIN_ESE_EXIT_TEXT",
        localize "STR_CFG_MARKERS_WARNING",
        [
            nil,
            {
                0 spawn
                {
                    waitUntil {!isNull DISPLAY_ESE};
                    DISPLAY_ESE closeDisplay 1
                }
            }
        ],
        nil,
        "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\save_ca.paa",
        DISPLAY_ESE
    ] call BIS_fnc_3DENShowMessage;
}
else
{
    DISPLAY_ESE closeDisplay 1;
};
