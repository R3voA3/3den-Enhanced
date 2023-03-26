/*
  Author: linkion

  Description:
  Initializes or removes arsenal from selected object(s) by setting Init attribute.

  Parameter(s):
  STRING - _this - "init", "remove"

  Returns:
  BOOLEAN: true / false
*/

private _input = param [0, "", [""]];
private _object = get3DENSelected "object";

if (_object isEqualTo []) exitWith
{
  ["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification;
  false
};

switch (_input) do {
  case "init": {
    set3DENAttributes [_object, "Init", str(_object get3DENAttribute "Init") + "[\"AmmoboxInit\", [this, true]] spawn BIS_fnc_arsenal;"];
    // adds init line after exists Init
    if (isClass(configFile >> "CfgPatches" >> "ace_main")) then { // check if ACE is loaded, then add ace arsenal to init
      set3DENAttributes [_object, "Init", str(_object get3DENAttribute "Init") + "[this, true] call ace_arsenal_fnc_initBox;"]; 
      // adds ace arsenal init line after exists Init
    };
  };
  case "remove": {
    // just clear the init of the object for now... not ideal
    set3DENAttributes [_object, "Init", ""];
  };
  default: {
    
  };
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true