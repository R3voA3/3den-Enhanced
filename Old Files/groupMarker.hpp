class Enh_GroupMarker: Title
{
	attributeLoad=
	"\
	private _ctrl =_this controlsGroupCtrl 100;\
	private _filter = [];\
	{\
		if (getNumber (_x >> 'scope') > 0) then\
		{\
			if (_forEachIndex == 0) then\
			{\
				_ctrl lbAdd 'No Change';\
				_ctrl lbSetData [_forEachIndex,''];\
				if (_value isEqualTo _class) then {_ctrl lbSetCurSel _forEachIndex};\
			}\
			else\
			{\
				private _name = getText (_x >> 'name');\
				if !(_name in Enh_GroupMarker_Filter) then\
				{\
					Enh_GroupMarker_Filter pushBackUnique _name;\
					private _class = configName _x;\
					private _icon = getText (_x >> 'icon');\
					private _i = _ctrl lbAdd _name;\
					_ctrl lbSetData [_i,_class];\
					_ctrl lbSetPicture [_i,_icon];\
					_ctrl lbSetPictureColor [_i,[1,1,1,1]];\
					if (_value isEqualTo _class) then {_ctrl lbSetCurSel _i};\
				};\
			};\
		};\
	} forEach configProperties [configFile >> 'CfgMarkers','true']";

	attributeSave = "(_this controlsGroupCtrl 100) lbData lbCurSel (_this controlsGroupCtrl 100)";
	h = ATTRIBUTE_CONTENT_W * GRID_W / 3;
	class Controls: Controls
	{
		class Text: Title {};
		class Value: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;//Height is incorrect
		};
	};
};
