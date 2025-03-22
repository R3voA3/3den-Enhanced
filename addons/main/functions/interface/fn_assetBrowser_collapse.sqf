#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-20

    Description:
    Called onTerrainNew. Collapes all tree views of the asset browser

    Parameter(s):
    -

    Returns:
    -
*/

if (profileNamespace getVariable ["ENH_EditorPreferences_Interface_CollapseAssetBrowser", false]) then
{
    disableSerialization;

    private _fnc_collapse =
    {
        private _path = _this;
        if (count _path > 0) then
        {
            _ctrlTree tvCollapse _path;
        };
        for "_i" from 0 to (_ctrlTree tvCount _path) do
        {
            (_path + [_i]) call _fnc_collapse;
        };
    };

    {
        private _ctrlTree = findDisplay IDD_DISPLAY3DEN displayCtrl _x;
        [] call _fnc_collapse;
    } forEach [IDC_DISPLAY3DEN_CREATE_ALL];
};
