/*
	Author: linkion and R3vo

	Description:
	Initialize table view for selected item

	Parameter(s):
	tvControl - table view control
  String - item class name of which to display compatible items

	Returns:
	-

	Usage:
	[_ctrlTV, "LMG_Mk200_F"] call ENH_fnc_VAM_tvItemInit;
*/

params["_ctrlTV", "_itemClass"];

tvClear _ctrlTV;

// from ace_arsenal fnc_fillRightPanel.sqf lines 76-100
// Author: Alganthe

// Retrieve compatible mags
private _compatibleItems = [];
private _compatibleMagazines = [[[], []], [[], []], [[], []]];
{
    if (_x != "") then {
        private _weaponConfig = (configFile >> "CfgWeapons" >> _x);
        private _index = _forEachIndex;

        {
            private _subIndex = _forEachIndex min 1;
            {
                ((_compatibleMagazines select _index) select _subIndex) pushBackUnique (configName (configFile >> "CfgMagazines" >> _x))
            } foreach ([getArray (_weaponConfig >> _x >> "magazines"), getArray (_weaponConfig >> "magazines")] select (_x == "this"));

            // Magazine groups
            {
                private _magazineGroups = createHashMap;

                private _cfgMagazines = configFile >> "CfgMagazines";

                {
                    private _magList = [];
                    {
                        private _magazines = (getArray _x) select {isClass (_cfgMagazines >> _x)}; //filter out non-existent magazines
                        _magazines = _magazines apply {configName (_cfgMagazines >> _x)}; //Make sure classname case is correct
                        _magList append _magazines;
                    } foreach configProperties [_x, "isArray _x", true];

                    _magazineGroups set [toLower configName _x, _magList arrayIntersect _magList];
                } foreach configProperties [(configFile >> "CfgMagazineWells"), "isClass _x", true];

                private _magArray = _magazineGroups get (toLower _x);
                {((_compatibleMagazines select _index) select _subIndex) pushBackUnique _x} forEach _magArray;
            } foreach ([getArray (_weaponConfig >> _x >> "magazineWell"), getArray (_weaponConfig >> "magazineWell")] select (_x == "this"));


        } foreach getArray (_weaponConfig >> "muzzles");
    };
} foreach [_itemClass];

private _compatibleMagsPrimaryMuzzle = [];
private _compatibleMagsSecondaryMuzzle = [];
private _compatibleItems = [_itemClass] call ENH_fnc_compatibleItems;

_compatibleMagsPrimaryMuzzle = _compatibleMagazines select 0 select 0;
_compatibleMagsSecondaryMuzzle = _compatibleMagazines select 0 select 1;

// Fill tree view with equipment
{
  (uiNamespace getVariable ["ENH_VIM_itemsHashMap", createHashMap] get toLower(_x)) params ["_displayName", "_picture", "_addonClass", "_addonIcon", "_category", "_specificType", "_descriptionShort", "_class"];

  private _indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _category;

  private _selectHashMap = uiNamespace getVariable ["ENH_VAM_selectHashMap", createHashMap];

  if (_indexCategory < 0) then
  {
    _indexCategory = (uiNamespace getVariable ["ENH_VIM_types", []]) find _specificType;
  };

  private _indexEquipment = _ctrlTV tvAdd [[_indexCategory], _displayName];

  _ctrlTV tvSetData [[_indexCategory, _indexEquipment], _class];
  _ctrlTV tvSetPicture [[_indexCategory, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa"];
  _ctrlTV tvSetValue [[_indexCategory, _indexEquipment], 0];
  _ctrlTV tvSetTooltip [[_indexCategory, _indexEquipment], _descriptionShort];

  if (toLower(_class) in (keys _selectHashMap)) then {
    _ctrlTV tvSetPicture [[_indexCategory, _indexEquipment], "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa"];
    _ctrlTV tvSetValue [[_indexCategory, _indexEquipment], 1];
  };

} foreach (_compatibleItems);

{
  private _indexEquipment = _ctrlTV tvAdd [[], _x];
} forEach (_compatibleMagsPrimaryMuzzle)

// TODO: separate via attachment type (scope, pointer, muzzle, primary ammo, secondary ammo (GLs), etc.)
// NOTE: check out switch case (line 165) in ace arsenal fn_fillRightPanel.sqf
// NOTE: GVAR(virtualItems) = [[[], [], []], [[], [], [], []], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []];
// NOTE: My brain...splooosh
// NOTE: GVAR(virtualItems) select 1 is weapon attachments
// NOTE: (GVAR(virtualItems) select 1) select 0 is scopes
// NOTE: (GVAR(virtualItems) select 1) select 1 is accessories
// NOTE: (GVAR(virtualItems) select 1) select 2 is muzzles
// NOTE: (GVAR(virtualItems) select 1) select 3 is bipods
/*

*/



// TODO: implement traverse parents, need previous TODO completed first though.
private _fnc_traverseParents =
{
	params ["_path"];

	// traversing backwards from farthest child to first parent
	// to make sure to check uncheck when all children are checked
	for "_i" from 1 to (count _path - 1) step 1 do {
		private _partialCheckedPic = "\a3\ui_f\data\gui\rsccommon\rsccheckbox\checkbox_checked_ca.paa";
		private _newPath = +_path;
		_newPath deleteRange [count _path - _i, count _path];

		_ctrlTV tvSetPicture [_newPath, _partialCheckedPic];
		_ctrlTV tvSetValue [_newPath, 2];

		// check if all children are checked
		private _tempBool = true;
		for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
		{
			private _newPath = _newPath + [_i];
			if (_ctrlTV tvValue _newPath == 0 || _ctrlTV tvValue _newPath == 2) exitWith {
				_tempBool = false;
			};
		};
		// make parent checked
		if (_tempBool) then {
			private _checkedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_texturechecked_ca.paa";

			_ctrlTV tvSetPicture [_newPath, _checkedPic];
			_ctrlTV tvSetValue [_newPath, 1];
		};

		// check if all children are unchecked
		private _tempBool = true;
		for "_i" from (_ctrlTV tvCount _newPath) to 0 step -1 do
		{
			private _newPath = _newPath + [_i];
			if (_ctrlTV tvValue _newPath == 1 || _ctrlTV tvValue _newPath == 2) exitWith {
				_tempBool = false;
			};
		};
		// make parent unchecked
		if (_tempBool) then {
			private _uncheckedPic = "\a3\3den\data\controls\ctrlcheckbox\baseline_textureunchecked_ca.paa";

			_ctrlTV tvSetPicture [_newPath, _uncheckedPic];
			_ctrlTV tvSetValue [_newPath, 0];
		};
	};
};