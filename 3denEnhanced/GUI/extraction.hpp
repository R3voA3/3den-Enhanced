#define DIALOG_W 110
#define DIALOG_H 70

class Enh_Extraction
{
	idd = ENH_IDD_EXTRACTION;
	movingEnable = true;
	onLoad = "_this call Enh_fnc_extraction_onLoad";
	class ControlsBackground
	{
		DISABLE_BACKGROUND
		class Background: ctrlStaticBackground
		{
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + CTRL_DEFAULT_H;
			w = DIALOG_W * GRID_W;
			h = DIALOG_H * GRID_H;
		};
	};
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text = "Extraction Creator";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP;
			w = DIALOG_W * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ShowRadioChat: ctrlStatic
		{
			text = "Show Radio Chat";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 6 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ShowRadioChatValue: ctrlCheckbox
		{
			idc = 100;
			x = CENTERED_X(DIALOG_W) + 27 * GRID_W;
			y = DIALOG_TOP + 6 * GRID_H;
			w = 30 * pixelW;
			h = 30 * pixelH;
			onCheckedChanged = "_this call Enh_fnc_extraction_onCheckedChanged";
		};
		class NameCaller: ctrlStatic
		{
			text = "Callsign Caller";
			tooltip = "Name of the caller shown in radio chat.";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 12 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class NameCallerValue: ctrlEdit
		{
			idc = 200;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 12 * GRID_H;
			w = 81 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class NameTransport: ctrlStatic
		{
			text = "Callsign Transport";
			tooltip = "Name of the transport shown in radio chat.";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 18 * GRID_H;
			w = 28 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class NameTransportValue: ctrlEdit
		{
			idc = 300;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 18 * GRID_H;
			w = 81 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ConditionStart: ctrlStatic
		{
			text = "Condition Start";
			tooltip = "Condition for the extraction to start. By default the variable Enh_Extraction_Start has to be set to true. Leave empty if you want to start it by a trigger.";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 24 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ConditionStartValue: ctrlEditMulti
		{
			idc = 400;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 24 * GRID_H;
			w = 81 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class GrenadeType: ctrlStatic
		{
			text = "Grenade Type";
			tooltip = "The landing zone is marked by this grenade type."
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 30 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class GrenadeTypeValue: ctrlCombo
		{
			idc = 500;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 30 * GRID_H;
			w = 81 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Condition: ctrlStatic
		{
			text = "Condition";
			tooltip = "This condition has to become true for the vehicle to move to the end waypoint. By default all alive units in player's group have to be inside the pick up vehicle."
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 36 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class ConditionValue: ctrlEditMulti
		{
			idc = 600;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 36 * GRID_H;
			w = 81 * GRID_W;
			h = 4 * CTRL_DEFAULT_H;
		};
		class GridPosition: ctrlStatic
		{
			text = "Grid Position";
			x = CENTERED_X(DIALOG_W);
			y = DIALOG_TOP + 57 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class GridPositionValue: ctrlEdit
		{
			idc = 700;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 57 * GRID_H;
			w = 81 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VehicleClass: ctrlEdit
		{
			idc = 800;
			x = CENTERED_X(DIALOG_W) + 28 * GRID_W;
			y = DIALOG_TOP + 63 * GRID_H;
			w = 44 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Position: ctrlEdit
		{
			idc = 900;
			x = CENTERED_X(DIALOG_W) + 73 * GRID_W;
			y = DIALOG_TOP + 63 * GRID_H;
			w = 36 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class VehicleImage: ctrlStaticPictureKeepAspect
		{
			idc = 1000;
			x = CENTERED_X(DIALOG_W) + 4 * GRID_W;
			y = DIALOG_TOP + 38 * GRID_H;
			w = 20 * GRID_W;
			h = 20 * GRID_H
		};
		class Cancel: ctrlButtonCancel
		{
			x = CENTERED_X(DIALOG_W) + 86 * GRID_W;
			y = DIALOG_TOP + 69 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
		class Ok: ctrlButtonOK
		{
			idc = -1;//We don't want it to close the GUI
			action = "call Enh_fnc_extraction_setup";
			x = CENTERED_X(DIALOG_W) + 61 * GRID_W;
			y = DIALOG_TOP + 69 * GRID_H;
			w = 23 * GRID_W;
			h = CTRL_DEFAULT_H;
		};
	};
};