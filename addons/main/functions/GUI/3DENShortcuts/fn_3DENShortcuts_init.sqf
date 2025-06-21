#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

params ["_display"];

private _ctrlSearch = CTRL(IDC_SHORTCUTS_SEARCH);
private _ctrlButtonSearch = CTRL(IDC_SHORTCUTS_BUTTONSEARCH);
private _ctrlContent = CTRL(IDC_SHORTCUTS_CONTENT);
private _ctrlFilter = CTRL(IDC_SHORTCUTS_FILTER);

_ctrlFilter lnbAddRow ["", localize "STR_ENH_MAIN_TOOLS_3DENSHORTCUTS_ACTION", localize "STR_ENH_MAIN_TOOLS_3DENSHORTCUTS_SHORTCUTS"];

[_ctrlFilter, _ctrlContent, [0, 1, 2]] call BIS_fnc_initListNBoxSorting;

// Add search EH
_ctrlButtonSearch ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];
    ctrlParent _ctrlButton displayCtrl IDC_SHORTCUTS_SEARCH ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];

_ctrlSearch ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlSearch", "_newText"];
    ctrlParent _ctrlSearch displayCtrl IDC_SHORTCUTS_BUTTONSEARCH ctrlSetText TEXTURE_SEARCH_END;
    [ctrlParent _ctrlSearch displayCtrl IDC_SHORTCUTS_CONTENT, _newText] call ENH_fnc_3DENShortcuts_fillList;
}];

// Focus search so user can search right away
ctrlSetFocus _ctrlSearch;

// Cache data
if ((uiNamespace getVariable ["ENH_3DENShortcuts_Cache", []]) isEqualTo []) then
{
    private _temp = [];
    private _classes = ("true" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items")) +
                        ("true" configClasses (configFile >> "Display3DEN" >> "ContextMenu" >> "Items"));

    {
        private _sc = [getArray (_x >> "shortcuts")] call ENH_fnc_3DENShortcuts_parseShortcut;
        private _text = getText (_x >> "text");

        if (_sc isEqualTo "" || _text isEqualTo "") then {continue};

        private _picture = getText (_x >> "picture");

        _temp append [[_text, _sc, _picture]];
    } forEach _classes;
    uiNamespace setVariable ["ENH_3DENShortcuts_Cache", _temp];
};

[_ctrlContent, ""] call ENH_fnc_3DENShortcuts_fillList;
