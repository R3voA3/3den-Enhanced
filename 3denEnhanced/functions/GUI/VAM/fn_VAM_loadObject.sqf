/*
    Author: linkion and R3vo

    Description:
    Apply the Virtual Arsenal Manager selection to an 3DEN object.

    Parameter(s):
    0: Object - 3DEN Object to apply attribute(s) to
    1: true - whether to apply ace arsenal attribute

    Returns:
    _selectHashMap

    Usage:
    _selectHashMap = [_display, _object] call ENH_fnc_VAM_loadObject;
*/

params ["_display", "_object"];

private _fnc_getAceArsenalAttr =
{
  params ["_object"];

  private _returnSelectHashMap = createHashMap;
  if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
    private _aceAttribute = _object get3DENAttribute "ace_arsenal_attribute";
    {
      private _itemClass = toLower(_x);
      private _itemValues = (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) get _itemClass;
      _returnSelectHashMap insert [[_itemClass, _itemValues]];
    } forEach (_aceAttribute select 0 select 0);
  };

  _returnSelectHashMap
};

private _fnc_getBIArsenalAttr = {
  params ["_object"];

  private _returnSelectHashMap = createHashMap;
  private _biAttribute = [_object] call BIS_fnc_getVirtualWeaponCargo;
  {
    private _itemClass = toLower(_x);
    private _itemValues = (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) get _itemClass;
    _returnSelectHashMap insert [[_itemClass, _itemValues]];
  } forEach _biAttribute;

  _returnSelectHashMap
};

if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
  private _aceHashMap = [_object] call _fnc_getAceArsenalAttr;
  private _biHashMap = [_object] call _fnc_getBIArsenalAttr;
  private _buttonOK = format ["Ace (%1)", count (keys (_aceHashMap))];
  private _buttonCancel = format ["BI (%1)", count (keys (_biHashMap))];

  uiNamespace setVariable ["ENH_VAM_loadAceHashMap", _aceHashMap];
  uiNamespace setVariable ["ENH_VAM_loadBIHashMap", _biHashMap];

  private _messageCtrl = [
    "Detected that ace is loaded, choose which arsenal to edit",
    "Which to Load?",
    [
      _buttonOK,
      {
        uiNamespace setVariable ["ENH_VAM_selectHashMap", (uiNamespace getVariable ["ENH_VAM_loadAceHashMap", createHashMap])];
        [uiNamespace getVariable "ENH_VAM_selectHashMap"] call ENH_fnc_VAM_loadSelectHashMap;
      }
    ],
    [
      _buttonCancel,
      {
        uiNamespace setVariable ["ENH_VAM_selectHashMap", (uiNamespace getVariable ["ENH_VAM_loadBIHashMap", createHashMap])];
        [uiNamespace getVariable "ENH_VAM_selectHashMap"] call ENH_fnc_VAM_loadSelectHashMap;
      }
    ],
    "\A3\ui_f\data\map\markers\handdrawn\warning_CA.paa",
    _display
  ] call BIS_fnc_3DENShowMessage;

} else {
  uiNamespace setVariable ["ENH_VAM_selectHashMap", ([_object] call _fnc_getBIArsenalAttr)];
  [(findDisplay "RscDisplayEmpty") displayCtrl 10, uiNamespace getVariable "ENH_VAM_selectHashMap"] call ENH_fnc_VAM_loadSelectHashMap;
};