class Enh_AmbientAnimDescription
{
	control = "SubCategoryDesc2";
	data = "AttributeSystemSubcategory";
	displayName = $STR_ENH_ambAnimations_headline;
	description = $STR_ENH_ambAnimations_description;
	condition = "objectBrain";
};
class Enh_ambientAnimParams
{
	control = "Enh_AmbientAnimation";
	property = "Enh_ambientAnimParams";
	expression =
	"\
	if (is3DEN) then {_this call BIS_fnc_ambientAnim__terminate};\
	[_this,_value] spawn\
	{\
		sleep 0.1;\
		params ['_unit','_value'];\
		if ((_value # 0 != '') && !isMultiplayer) then\
		{\
			[_unit,_value # 0,_value # 1,objNull,false,false] call BIS_fnc_ambientAnim;\
			waitUntil {sleep 0.1; ((behaviour _unit) == 'COMBAT') || (damage _unit > 0.6)};\
			_unit call BIS_fnc_ambientAnim__terminate;\
		};\
	}";
	condition = "objectBrain";
	defaultValue = ["",""];
};