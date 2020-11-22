/*
  Author: Revo

  Description:
  Used by the ENH_TexturFinder GUI. Searches the config file for useable textures.

  Parameter(s):
  -

  Returns:
  -
*/

//Only add things which end with eighter jpg or paa
#define IS_JPG (".jpg" in (_string select [count _string - 4]))
#define IS_PAA (".paa" in (_string select [count _string - 4]))

//Update progress text
[] spawn ENH_fnc_textureFinder_progressText;

//Exit if search is running or search was already done and data was stored in uiNamespace
if (uiNamespace getVariable ["ENH_TextureFinder_TexturesFound",[]] isNotEqualTo []) exitWith {[] spawn ENH_fnc_textureFinder_fillList};
if (!isNil "ENH_TextureFinder_SearchRunning") exitWith {};

ENH_TextureFinder_SearchRunning = true;
ENH_TextureFinder_TexturesFound = [];
ENH_TextureFinder_ClassesFound = 0;
ENH_TextureFinder_ClassesSearched = 0;

//Scan configFile for all classes
private _fnc_searchConfig =
{
   params [["_depth", 1],["_class",configFile]];

   if (_depth == 0) exitWith {[]};
   _depth = _depth - 1;
   private _array = [];

   {
      _array pushBack _x;
      ENH_TextureFinder_ClassesFound = ENH_TextureFinder_ClassesFound + 1;
      _array append ([_depth, _x] call _fnc_searchConfig);
   } forEach ("true" configClasses _class);

  _array
};

//Check configProperties of every class for textures
private _addPath =
{
  params ["_string"];
  if (IS_PAA || IS_JPG) then
  {
    if (_string find "\" != 0) then {_string = "\" + _string};
    ENH_TextureFinder_TexturesFound pushBackUnique toLower _string;
  };
};

private _searchArray =
{
  if (_x isEqualType "") then {_x call _addPath} else
  {
    if (_x isEqualType []) then
    {
      _searchArray forEach _x;
    };
  };
};

{
  ENH_TextureFinder_ClassesSearched = ENH_TextureFinder_ClassesSearched + 1;
  {
    if (isText _x) then {getText _x call _addPath} else {
      _searchArray forEach getArray _x;
    };
  } forEach configProperties [_x, "isText _x || isArray _x",false];
} forEach ([13] call _fnc_searchConfig);

uiNamespace setVariable ["ENH_TextureFinder_TexturesFound",ENH_TextureFinder_TexturesFound];
uiNamespace setVariable ["ENH_TextureFinder_ClassesFound",ENH_TextureFinder_ClassesFound];
uiNamespace setVariable ["ENH_TextureFinder_ClassesSearched",ENH_TextureFinder_ClassesSearched];

ENH_TextureFinder_SearchRunning = nil;
ENH_TextureFinder_TexturesFound = nil;
ENH_TextureFinder_ClassesFound = nil;
ENH_TextureFinder_ClassesSearched = nil;

[] spawn ENH_fnc_textureFinder_fillList;