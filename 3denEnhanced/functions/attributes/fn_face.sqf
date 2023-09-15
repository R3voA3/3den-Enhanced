/*
  Author: R3vo

  Date: 3023-08-17

  Description:
  Handles the Face attribute.

  Parameter(s):
  Internal use only.

  Return Value:
  Internal use only.
*/

#define IMG_SEARCH_END "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa"
#define IMG_SEARCH_START "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa"

params
[
  ["_mode", "attributeLoad"],
  ["_ctrlGroup", controlNull],
  ["_params", ""]
];

switch _mode do
{
  case "attributeLoad":
  {
    private _value = _params;
    private _ctrlTV = _ctrlGroup controlsGroupCtrl 302;

    tvClear _ctrlTV;

    {
      private _displayName = getText (_x >> "displayName");

      if (_displayName == '' || getnumber (_x >> 'disabled') == 1) then {continue};

      private _configName = configName _x;
      private _texture = getText (_x >> "texture");
      private _dlcLogo = if (configsourcemod _x == '') then {''} else {modParams [configsourcemod _x,['logo']] param [0,'']};

      private _index = _ctrlTV tvAdd [[], _displayName];

      _ctrlTV tvSetData [[_index], _configName];
      _ctrlTV tvSetPicture [[_index], _texture];
      _ctrlTV tvSetPictureRight [[_index], _dlcLogo];
      _ctrlTV tvSetTooltip [[_index], _displayName + "\n" + _configName];

      if (_value == _configName) then
      {
        _ctrlTV tvSetCurSel [_index];
        _ctrlTV tvSetValue [[_index], 1];
      };
    } forEach configproperties [configfile >> 'cfgfaces' >> 'Man_A3','isclass _x'];

    //Sort by name first
    _ctrlTV tvSort [[], false];

    //Sort by value so next time list is opened, selected value is at the top
    _ctrlTV tvSortByValue [[], false];

    //Scroll to the top
    _ctrlTV ctrlSetScrollValues [0, 0];
  };
  case "attributeSave":
  {
    private _ctrlTV = _ctrlGroup controlsGroupCtrl 302;
    _ctrlTV tvData (tvCurSel _ctrlTV);
  };
  case "onEditChanged":
  {
    _params params [["_ctrlEdit", controlNull]];

    //Change search button icon
    private _image = [IMG_SEARCH_END, IMG_SEARCH_START] select (ctrlText _ctrlEdit == "");
    (ctrlParentControlsGroup _ctrlEdit controlsGroupCtrl 301) ctrlSetText _image;
  };
  case "onButtonClick":
  {
    _params params [["_ctrlButton", controlNull]];

    //Change search button icon and clear edit control to reset tree view filter
    ctrlParentControlsGroup _ctrlButton controlsGroupCtrl 300 ctrlSetText "";
    _ctrlButton ctrlSetText IMG_SEARCH_START;
  };
  case "onTreeSelChanged":
  {
    _params params ["_ctrlTree", "_path"];
    private _picture = _ctrlTree tvPicture _path;

    _ctrlGroup controlsGroupCtrl 303 ctrlSetText _picture;
    _ctrlGroup controlsGroupCtrl 303 ctrlShow (_picture != "");
    _ctrlGroup controlsGroupCtrl 304 ctrlShow (_picture != "");
  };
};