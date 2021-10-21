/*
  Author: R3vo

  Description:
  Used by the ENH_TexturFinder GUI. Searches the config file for useable textures.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

//Only add things which end with either .jpg or .paa
#define IS_JPG (".jpg" in (_string select [count _string - 4]))
#define IS_PAA (".paa" in (_string select [count _string - 4]))

disableSerialization;
private _display = findDisplay IDD_TEXTUREFINDER;

CTRL(IDC_TEXTUREFINDER_SEARCH) ctrlEnable false;
CTRL(IDC_TEXTUREFINDER_TEXTURELIST) ctrlEnable false;

//Focus Search CTRL + F
_display displayAddEventHandler ["keyDown",
{
  params ["_display", "_key", "_shift", "_ctrl"];
  if (_key isEqualTo 33 && _ctrl && !_shift) then
  {
    ctrlSetFocus (_display displayCtrl IDC_TEXTUREFINDER_SEARCH);
  }
}];

//Update preview
_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["treeMouseMove",
{
  _this call ENH_fnc_textureFinder_updatePreview;
}];

_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["treeMouseHold",
{
  _this call ENH_fnc_textureFinder_updatePreview;
}];

//Copy path
_display displayCtrl IDC_TEXTUREFINDER_TEXTURELIST ctrlAddEventHandler ["keyDown",
{
  _this call ENH_fnc_textureFinder_copyPath;
}];

//Update progress text
[] spawn ENH_fnc_textureFinder_progressText;

//Exit if search is running or search was already done and data was stored in uiNamespace
if (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound", []] isNotEqualTo []) exitWith {[] spawn ENH_fnc_textureFinder_fillList};
if (!isNil "ENH_TextureFinder_SearchRunning") exitWith {};

ENH_TextureFinder_SearchRunning = true;
ENH_TextureFinder_TexturesFound = [];
ENH_TextureFinder_ClassesFound = 0;
ENH_TextureFinder_ClassesSearched = 0;

//Scan configFile for all classes
private _fnc_searchConfig =
{
  params [["_depth", 1], ["_config", configFile]];

  if (_depth == 0) exitWith {[]};
  _depth = _depth - 1;
  private _array = [];

  ("true" configClasses _config) apply
  {
    _array pushBack _x;
    _array append ([_depth, _x] call _fnc_searchConfig);
    ENH_TextureFinder_ClassesFound = ENH_TextureFinder_ClassesFound + 1;
  };
  _array
};

//Check configProperties of every class for textures
private _fnc_addPath =
{
  params ["_string"];
  if (IS_PAA || IS_JPG) then
  {
    if (_string find "\" != 0) then {_string = "\" + _string};
    if !(fileExists _string) then {continue};
    ENH_TextureFinder_TexturesFound pushBackUnique toLowerANSI _string;
  };
};

private _fnc_searchArray =
{
  if (_x isEqualType "") exitWith {_x call _fnc_addPath};
  if (_x isEqualType []) exitWith {_x apply _fnc_searchArray};
};

([15] call _fnc_searchConfig) apply
{
  ENH_TextureFinder_ClassesSearched = ENH_TextureFinder_ClassesSearched + 1;

  configProperties [_x, "isText _x || isArray _x", false] apply
  {
    if (isText _x) then {getText _x call _fnc_addPath} else
    {
      getArray _x apply _fnc_searchArray;
    };
  };
};

uiNamespace setVariable ["ENH_TextureFinder_TexturesFound", ENH_TextureFinder_TexturesFound];
uiNamespace setVariable ["ENH_TextureFinder_ClassesFound", ENH_TextureFinder_ClassesFound];
uiNamespace setVariable ["ENH_TextureFinder_ClassesSearched", ENH_TextureFinder_ClassesSearched];

ENH_TextureFinder_SearchRunning = nil;
ENH_TextureFinder_TexturesFound = nil;
ENH_TextureFinder_ClassesFound = nil;
ENH_TextureFinder_ClassesSearched = nil;

[] call ENH_fnc_textureFinder_fillList;