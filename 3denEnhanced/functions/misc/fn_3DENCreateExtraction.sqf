/*
   Author: R3vo

   Date: 2019-09-06

   Description:
   Creates all required entities within Eden for a helicopter extraction.

   Parameter(s):
   0: STRING - Class of the helicopter
   1: BOOLEAN - True to show smoke at LZ

   Returns:
   BOOLEAN: true
*/ 

(uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_center","_veh"];

_showSmoke = true;
_center set [2,0];//Set z to zero

collect3DENHistory
{
	private _layer = -1 add3DENLayer "Extraction";
	//private _veh = create3DENEntity ["Object",_veh,_center vectorAdd [0,-120,0]];
	private _heliPad = create3DENEntity ["Object","Land_HelipadEmpty_F",_center];
	_veh set3DENAttribute ["Position",_center vectorAdd [0,-120,0]];
	//Set up first waypoint. This WP has to be complete for the extraction to start
	private _wpStart = group _veh create3DENEntity ["Waypoint","Move",_center vectorAdd [0,-119,0]];
	_wpStart set3DENAttribute ["Behaviour","CARELESS"];

	//Set up start trigger. This trigger has to fire for the extraction to start
	private _triggerStart = create3DENEntity ["Trigger","EmptyDetector",_center vectorAdd [10,-119,0]];
	add3DENConnection ["WaypointActivation",[_triggerStart],_wpStart];
	_triggerStart set3DENAttribute ["ActivationBy","ALPHA"];
	_triggerStart set3DENAttribute ["IsServerOnly",true];
	
	private _wpTransportUnload = group _veh create3DENEntity ["Waypoint","TransportUnload",_center  vectorAdd [0,-0.5,0]];

	//Condition for the transport unload wp to become true. Acc time is set to 1 to prevent waypoint to be skipped
	_wpTransportUnload set3DENAttribute	["Condition","units group player findIf {!(_x in (vehicle this))} < 0;"]; //setAccTime 1; 

	private _wpEnd = group _veh create3DENEntity ["Waypoint","Move",_center vectorAdd [0,120,0]];
	
	{
		_x set3DENLayer _layer;
	} forEach [_veh,_wpStart,_wpTransportUnload,_wpEnd,_heliPad,_triggerStart];

	if (_showSmoke) then
	{
		private _smoke  = create3DENEntity ["Logic","ModuleSmoke_F",_center vectorAdd [0,-1,0]];
		add3DENConnection ["Sync",[_triggerStart],_smoke];
		_smoke set3DENLayer _layer;
	};
};

true