class Enh_Airdrop
{
	collapsed = 1;
	displayName = $STR_ENH_attributeCategory_airdrop;
	class Attributes
	{
		class Enh_Airdrop_Classes
		{
			displayName = $STR_ENH_airdrop_classes_displayName;
			tooltip = "Classes of the soldiers which should be dropped in format:\nclassname_1 classname_2 classname_n.\nUnit are stored in Enh_Airdrop_Units. This variable is available on host and server machine.";
			property = "Enh_Airdrop_Classes";
			control = "EditArray";
			expression =
			"\
				if (!is3DEN && !(_value isEqualTo []) && isServer) then\
				{\
					_value spawn\
					{\
						private _condition = compile (missionNamespace getVariable ['Enh_Airdrop_Condition',false]);\
						waitUntil {sleep 1; call _condition};\
						private _center = missionNamespace getVariable ['Enh_Airdrop_Center',[0,0,0]];\
						_center set [2,(_center # 2) + random 50 - random 50];\
						private _side = call compile (missionNamespace getVariable ['Enh_Airdrop_Side','west']);\
						private _r = missionNamespace getVariable ['Enh_Airdrop_Radius',200];\
						private _group = createGroup _side;\
						playSound3D ['A3\Data_F_Warlords\sfx\flyby.wss',objNull,false,_center vectorAdd [0,0,100],2.5];\
						Enh_Airdrop_Units = [];\
						{\
							private _unit = _group createUnit [_x,_center,[],0,'FORM'];\
							private _para = createVehicle ['Steerable_Parachute_F',_center,[],_r,'FLY'];\
							Enh_Airdrop_Units pushBack _unit;\
							_unit moveInDriver _para;\
						} forEach _this;\
					};\
				}";
			defaultValue = "[]";
		};
		class Enh_Airdrop_Condition
		{
			displayName = $STR_ENH_airdrop_condition_displayName;
			tooltip = $STR_ENH_airdrop_classes_tooltip;
			property = "Enh_Airdrop_Condition";
			control = "EditCodeMulti3";
			expression = "if (isServer) then {missionNamespace setVariable ['%s',_value]}";
			defaultValue = "false";
			typeName = "STRING";
		};
		class Enh_Airdrop_Center
		{
			displayName = $STR_ENH_airdrop_center_displayName;
			tooltip = $STR_ENH_airdrop_center_tooltip;
			property = "Enh_Airdrop_Center";
			control = "EditXYZ";
			expression = "if (isServer) then {missionNamespace setVariable ['%s',_value]}";
			defaultValue = "[0,0,0]";
		};
		class Enh_Airdrop_Radius
		{
			displayName = $STR_ENH_airdrop_radius_displayName;
			tooltip = $STR_ENH_airdrop_radius_tooltip;
			property = "Enh_Airdrop_Radius";
			control = "DynSimDist";
			expression = "if (isServer) then {missionNamespace setVariable ['%s',_value]}";
			defaultValue = "200";
			typeName = "NUMBER";
		};
		class Enh_Airdrop_Side
		{
			displayName= $STR_ENH_airdrop_side_displayName;
			tooltip = $STR_ENH_airdrop_side_tooltip;
			property = "Enh_Airdrop_Side";
			control = "Edit";
			expression = "if (isServer) then {missionNamespace setVariable ['%s',_value]}";
			defaultValue = "West";
			typeName = "STRING";
		};
	};
};