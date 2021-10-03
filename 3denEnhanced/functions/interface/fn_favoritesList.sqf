/*
  Author: R3vo

  Date: 2021-09-30

  Description:
  Used to initialize the favorites list.

  Parameter(s):
  0: STRING - Action to be taken

  Returns:
  -
*/

#define FAVORITES (profileNamespace getVariable ["ENH_FavoritesList", []])
#define PANEL_RIGHT (findDisplay 313 displayCtrl 1021)

disableSerialization;
params [["_mode", "onLoad"], ["_arguments", []]];

switch (_mode) do
{
  case "onLoad":
  {
    private _ctrlFavorites = (PANEL_RIGHT controlsGroupCtrl 1337) controlsGroupCtrl 1338;
    private _ctrlButton = (PANEL_RIGHT controlsGroupCtrl 1337) controlsGroupCtrl 1339;

    _ctrlFavorites ctrlAddEventHandler ["treeDblClick",
    {
      params ["_ctrlFavorites", "_selectionPath"];
      ["createEntity", [_ctrlFavorites, _selectionPath]] call ENH_fnc_favoritesList;
    }];

    _ctrlFavorites ctrlAddEventHandler ["treeMouseHold",
    {
      params ["_ctrlFavorites", "_path"];
      ["showPreview", [_ctrlFavorites, _path]] call ENH_fnc_favoritesList;
    }];

    _ctrlFavorites ctrlAddEventHandler ["treeMouseMove",
    {
      params ["_ctrlFavorites", "_path"];
      ["showPreview", [_ctrlFavorites, _path]] call ENH_fnc_favoritesList;
    }];

    _ctrlFavorites ctrlAddEventHandler ["MouseExit",
    {
        (findDisplay 313 displayCtrl 98) ctrlShow false;
    }];

    _ctrlButton ctrlAddEventHandler ["buttonClick",
    {
      private _ctrlFavorites = (PANEL_RIGHT controlsGroupCtrl 1337) controlsGroupCtrl 1338;
      private _selection = tvSelection _ctrlFavorites;
      if (_selection isEqualTo []) exitWith {};
      _selection sort false; //Sort the selection from highest to lowest to not mess with the paths
      {
        private _class = _ctrlFavorites tvData _x;
        _ctrlFavorites tvDelete _x;
        profileNamespace setVariable ["ENH_FavoritesList", FAVORITES - [_class]];
      } forEach _selection;
      saveprofileNamespace;
    }];

    if (_ctrlFavorites tvCount [] > 0) exitWith {};

    ["add", FAVORITES] call ENH_fnc_favoritesList;
  };
  case "contextMenu":
  {
    private _entitiesToAdd = flatten (get3DENSelected "Object" + get3DENSelected "Logic");
    _entitiesToAdd = _entitiesToAdd apply {typeOf _x};
    _entitiesToAdd= _entitiesToAdd arrayIntersect _entitiesToAdd;
    _entitiesToAdd = _entitiesToAdd select {!(_x in FAVORITES)};
    ["add", _entitiesToAdd] call ENH_fnc_favoritesList;
  };
  case "add":
  {
    private _ctrlFavorites = (PANEL_RIGHT controlsGroupCtrl 1337) controlsGroupCtrl 1338;
    {
      private _config = configFile >> "CfgVehicles";
      private _class = _x;

      if !(isClass (_config >> _class)) then {continue};

      private _displayName = getText (_config >> _class >> "displayName");
      private _side = getNumber (_config >> _class >> "side");
      if (_class isKindOf "Static" || _class isKindOf "Thing") then {_side = 8};
      private _color = _side call BIS_fnc_sideColor;
      if (_class isKindOf "Logic") then {_color = [1, 1, 1, 1]};
      private _icon = getText (_config >> _class >> "icon");
      ((_config >> _class) call ENH_fnc_getConfigSourceAddon) params ["", "", ["_addonIcon", ""]];

      if (!fileExists _icon) then
      {
        _icon = getText (configFile >> "CfgVehicleIcons" >> _icon);
      };

      private _index = _ctrlFavorites tvAdd [[], _displayName];
      _ctrlFavorites tvSetData [[_index], _class];
      _ctrlFavorites tvSetTooltip [[_index], _displayName + "\n" + _class];
      _ctrlFavorites tvSetPictureRight [[_index], _addonIcon];

      if (_icon isNotEqualTo "" && fileExists _icon) then
      {
        _ctrlFavorites tvSetPicture [[_index], _icon];
        _ctrlFavorites tvSetPictureColor [[_index], _color];
      }
      else
      {
        _ctrlFavorites tvSetPicture [[_index], "\a3\modules_f\data\portraitmodule_ca.paa"];
      };
      _ctrlFavorites tvSort [[]];
      if (_class in FAVORITES) then {continue};
      profileNamespace setVariable ["ENH_FavoritesList", FAVORITES + [_class]];
    } forEach _arguments;
    saveprofileNamespace;
  };
  case "createEntity":
  {
    private _ctrlFavorites = (PANEL_RIGHT controlsGroupCtrl 1337) controlsGroupCtrl 1338;
    _arguments params ["_ctrlFavorites", "_selectionPath"];
    private _class = _ctrlFavorites tvData _selectionPath;
    private _type = ["Object", "Logic"] select (_class isKindOf "Logic");
    set3DENSelected [create3DENEntity [_type, _class, screenToWorld [0.5, 0.5]]];
  };
  case "showPreview":
  {
    _arguments params ["_ctrlFavorites", "_path"];
    private _ctrlPreviewGroup = findDisplay 313 displayCtrl 98;
    private _ctrlPreview = _ctrlPreviewGroup controlsGroupCtrl 99;

    _ctrlPreviewGroup ctrlShow true;
    private _class = _ctrlFavorites tvData _path;
    private _picture = (getText (configFile >> "CfgVehicles" >> _class >> "editorPreview"));

    if (_picture isEqualTo "") exitWith {_ctrlPreviewGroup ctrlShow false};
    _ctrlPreview ctrlSetText _picture;

    getMousePosition params ["", "_mouseY"];
    _ctrlPreviewGroup ctrlSetPositionY _mouseY;
    _ctrlPreviewGroup ctrlCommit 0;
  };
};