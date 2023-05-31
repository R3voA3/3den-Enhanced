params["_ctrlTV", "_typeIndex", "_displayName", "_class", "_descriptionShort", "_addonIcon", "_selectHashMap"];\

// add new item entry to TV
private _indexEquipment = _ctrlTV tvAdd [[_typeIndex], _displayName];

// set picture right to addons icon
_ctrlTV tvSetPictureRight [[_typeIndex, _indexEquipment], _addonIcon];

// set data to item's class
_ctrlTV tvSetData [[_typeIndex, _indexEquipment], _class];


// check if item is already selected
if (toLower(_x) in _selectHashMap) then {
  [_ctrlTV, 1, [_typeIndex, _indexEquipment]] call ENH_fnc_VAM_switchNodeState;
} else {
  [_ctrlTV, 0, [_typeIndex, _indexEquipment]] call ENH_fnc_VAM_switchNodeState;
};

// set on-hover tooltip to short description
_descriptionShort = _descriptionShort+"";
_ctrlTV tvSetTooltip [[_typeIndex, _indexEquipment], _descriptionShort];