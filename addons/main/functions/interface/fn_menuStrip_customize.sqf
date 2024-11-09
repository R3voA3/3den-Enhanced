#include "\x\enh\addons\main\script_component.hpp"

// This is where the checkbox of the first level starts
#define TV_X_START 6.5 * GRID_W

// That's the amount we need to move to the right with each level that we go deeper
#define INDENT_SIZE_X 4.2 * GRID_W

// With of the checkbox icon
#define CHECKBOX_WIDTH 3 * GRID_W

#define SELECT_TEXTURE [TEXTURE_CHECKED, TEXTURE_UNCHECKED, TEXTURE_PARTIALLY_CHECKED] select _state

disableSerialization;

params ["_display"];

private _level = 0;
private _path = [];
private _pathTemp = [];
private _menuStripItems = configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items";
private _ctrlTV = CTRL(IDC_CUSTOMIZE_MENU_STRIP_TREE);

private _fnc_addChildren =
{
    params ["_config", "_path"];
    private _children = getArray (_config >> "items");

    private _countChildren = count _children;

    {
        if (_x != "Separator") then
        {
            // Check if item is a root item
            if (_x in getArray (_menuStripItems >> "items")) then
            {
                _path = [];
                _level = 0;
            };

            private _indexItem = _ctrlTV tvAdd [_path, getText (_menuStripItems >> _x >> "text")];

            _pathTemp = _path + [_indexItem];

            private _state = ENH_MenuStrip_Customization_HashMap getOrDefault [_x, 0];

            _ctrlTV tvSetPicture [_pathTemp, SELECT_TEXTURE];
            _ctrlTV tvSetData [_pathTemp, _x];
            _ctrlTV tvSetTooltip [_pathTemp, _x];

            if (getArray (_menuStripItems >> _x >> "items") isNotEqualTo []) then
            {
                _path pushBack _indexItem;
                _level = _level + 1;
                [_menuStripItems >> _x, _path] call _fnc_addChildren;
            }
            else
            {
                // Go one level back on the last child with no children
                if (_forEachIndex == _countChildren - 1) then
                {
                    _path deleteAt [-1];
                    _level = 0
                };
            };
        };
    } forEach _children;
};

ENH_MenuStrip_Customization_HashMap = profileNamespace getVariable ["ENH_MenuStrip_Customization_HashMap", createHashMap];

[
    configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items",
    _path
] call _fnc_addChildren;

_display displayAddEventHandler ["Unload",
{
    profileNamespace setVariable ["ENH_MenuStrip_Customization_HashMap", ENH_MenuStrip_Customization_HashMap];
    saveProfileNamespace;
    ENH_MenuStrip_Customization_HashMap = nil;
}];

_ctrlTV setVariable ["fnc_toggleChildren",
{
    params ["_ctrlTV", "_parentPath", "_state"];

    private _childrenCount = _ctrlTV tvCount _parentPath;

    for "_i" from 0 to _childrenCount - 1 do
    {
        _ctrlTV tvSetValue [_parentPath + [_i], _state];

        ENH_MenuStrip_Customization_HashMap set [_ctrlTV tvData _parentPath + [_i], _state];

        _ctrlTV tvSetPicture [_parentPath + [_i], SELECT_TEXTURE];

        [_ctrlTV, _parentPath + [_i], _state] call (_ctrlTV getVariable ["fnc_toggleChildren", {}]);
    };
}];

_ctrlTV setVariable
[
    "ColorHighlight",
    [
        profileNamespace getVariable ["GUI_BCG_RGB_R", 0.77],
        profileNamespace getVariable ["GUI_BCG_RGB_G", 0.51],
        profileNamespace getVariable ["GUI_BCG_RGB_B", 0.08],
        1
    ]
];

// Update selection when mouse is moving
_ctrlTV ctrlAddEventHandler ["TreeMouseMove",
{
    params ["_ctrlTV", "_path"];

    _ctrlTV tvSetCurSel _path;
}];

// Save cursor position
_ctrlTV ctrlAddEventHandler ["MouseMoving",
{
    params ["_ctrlTV", "_xPos"];

    _ctrlTV setVariable ["CursorPosX", _xPos];
}];

_ctrlTV ctrlAddEventHandler ["MouseButtonDown",
{
    params ["_ctrlTV"];

    private _path = tvCurSel _ctrlTV;
    private _cursorPosX = _ctrlTV getVariable ["CursorPosX", 0];

    private _indentCount = count _path - 1;

    private _ctrlTreeWidth = ctrlPosition _ctrlTV select 2;

    private _checkboxStart = _indentCount * INDENT_SIZE_X + TV_X_START;
    private _inCheckboxArea = _cursorPosX >= _checkboxStart && {_cursorPosX <= (_checkboxStart + CHECKBOX_WIDTH )};

    if _inCheckboxArea then
    {
        // Get state of parent
        // 0 = Visible
        // 1 = Hidden
        // 2 = Children partially visible/hidden

        // Switch state
        private _state = [1, 0] select (_ctrlTV tvValue _path); //TODO: Fix that
        _ctrlTV tvSetValue [_path, _state];

        // Store value for later use
        ENH_MenuStrip_Customization_HashMap set [_ctrlTV tvData _path, _state];

        _ctrlTV tvSetPicture [_path, SELECT_TEXTURE];

        [_ctrlTV, _path, _state] call (_ctrlTV getVariable ["fnc_toggleChildren", {}]);
    };
}];

// Handle search button
CTRL(IDC_CUSTOMIZE_MENU_STRIP_SEARCH) ctrlAddEventHandler ["EditChanged",
{
    params ["_ctrlEdit", "_newText"];

    private _image = [TEXTURE_SEARCH_END, TEXTURE_SEARCH_START] select (_newText == "");

    ctrlParent _ctrlEdit displayCtrl IDC_CUSTOMIZE_MENU_STRIP_BUTTON_SEARCH ctrlSetText _image;
}];

// Handle search button
CTRL(IDC_CUSTOMIZE_MENU_STRIP_BUTTON_SEARCH) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    //Change search button icon and clear edit control to reset tree view filter
    ctrlParent _ctrlButton displayCtrl IDC_CUSTOMIZE_MENU_STRIP_SEARCH ctrlSetText "";
    _ctrlButton ctrlSetText TEXTURE_SEARCH_START;
}];

// Collapse
CTRL(IDC_CUSTOMIZE_MENU_STRIP_BUTTON_COLLAPSE_ALL) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    tvCollapseAll (ctrlParent _ctrlButton displayCtrl IDC_CUSTOMIZE_MENU_STRIP_TREE);
}];

// Expand
CTRL(IDC_CUSTOMIZE_MENU_STRIP_BUTTON_EXPAND_ALL) ctrlAddEventHandler ["ButtonClick",
{
    params ["_ctrlButton"];

    tvExpandAll (ctrlParent _ctrlButton displayCtrl IDC_CUSTOMIZE_MENU_STRIP_TREE);
}];

// Add 3rd checkbox status

/*
When an item status changes, get the parent with path [x]. Save this path and loop through all children and grand children .... and find the first two that don't have the
save status. That means 3rd state should be applied to path [x]*/
