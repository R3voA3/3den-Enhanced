#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-10-20

    Description:
    Used by the CfgSentences Browser GUI. Handles favorites such as filling the list, adding or removing favorites.

    Parameter(s):
    0: STRING - Mode, can be empty for deleting or adding (automatically handles) or "fill" to fill the favorites list

    Returns:
    -
*/

private _display = uiNamespace getVariable ["ENH_CFGS_Display", displayNull];

params [["_mode", ""]];

if (_mode == "fill") then // Fill list
{
    private _tvFavorites = CTRL(IDC_SENTENCESBROWSER_FAVORITES);
    tvClear _tvFavorites;
    {
        _x params ["_text", "_configStr"];
        private _index = _tvFavorites tvAdd [[], _text];
        _tvFavorites tvSetData [[_index], _configStr];
    } forEach ENH_CFGS_Favorites;
}
else
{
    private _tv = uiNamespace getVariable ["ENH_CFGS_ActiveList", controlNull];
    private _selectedPath = tvCurSel _tv;
    private _text = _tv tvText _selectedPath;
    private _configStr = _tv tvData _selectedPath;
    if (_configStr == "") exitWith {false};

    if (ctrlClassName _tv == "List") then // Add to favorites
    {
        private _tvFavorites = (ctrlParent _tv displayCtrl IDC_SENTENCESBROWSER_FAVORITES);
        if ((ENH_CFGS_Favorites find [_text, _configStr]) > -1) exitWith {false};

        ENH_CFGS_Favorites = ENH_CFGS_Favorites + [[_text, _configStr]];
        "fill" call ENH_fnc_CFGS_handleFavorites;
        [_display] spawn
        {
            private _ctrlHighlight = [((_this select 0) displayCtrl IDC_SENTENCESBROWSER_PAGES), 5] call BIS_fnc_highlightControl;
            sleep 2;
            ctrlDelete _ctrlHighlight;
        };
    }
    else
    {
        _tv tvDelete _selectedPath; // Remove from favorits
        ENH_CFGS_Favorites = ENH_CFGS_Favorites - [[_text, _configStr]];
        ["ENH_ActionPerformed"] call BIS_fnc_3DENNotification;
    };
};
