/*
  Author: R3vo

  Date: 2019-09-06

  Description:
  Creates all required entities within Eden for a extraction. Values are taken from ENH_Extraction GUI.

  Parameter(s):
  -

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

private _display = findDisplay IDD_EXTRACTION;
(uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") params ["_center","_veh"];

_center set [2,0];//Set z to zero

//Get values from GUI
private _conditionStart = ctrlText CTRL(IDC_EXTRACTION_CONDITIONSTART);
private _ctrlGrenadeType = CTRL(IDC_EXTRACTION_GRENADE);
private _grenadeType = _ctrlGrenadeType lbData lbCurSel _ctrlGrenadeType;

collect3DENHistory
{
  _veh set3DENAttribute ["Position",_center vectorAdd [0,-120,0]];
  private _layer = -1 add3DENLayer localize "STR_ENH_EXTRACTION_LAYER";

  //Set up first waypoint. This WP has to be completed for the extraction to start
  private _wpStart = group _veh create3DENEntity ["Waypoint","Move",_center vectorAdd [0,-119,0]];
  _wpStart set3DENAttribute ["Behaviour","CARELESS"];

  if (_veh isKindOf "Helicopter") then
  {
    private _heliPad = create3DENEntity ["Object","Land_HelipadEmpty_F",_center];
    _heliPad set3DENLayer _layer;
  };

  if !(_grenadeType isEqualTo "") then
  {
    private _triggerSmoke = create3DENEntity ["Trigger","EmptyDetector",_center vectorAdd [2,-119,0]];
    _triggerSmoke set3DENAttribute ["Condition","ENH_Extraction_Start"];
    _triggerSmoke set3DENAttribute ["IsServerOnly",true];
    _triggerSmoke set3DENAttribute ["Text",localize "STR_ENH_EXTRACTION_TRIGGERSMOKETEXT"];
    _triggerSmoke set3DENAttribute ["OnActivation",
      format
      [
        "0 = createvehicle ['%1',%2,[],0,'none'];",
        _grenadeType,
        _center
      ]
    ];
    _triggerSmoke set3DENAttribute
    [
      "Condition",
      format
      [
        "%1",
        _conditionStart
      ]
    ];
    _triggerSmoke set3DENLayer _layer;
  };

  private _triggerStart = create3DENEntity ["Trigger","EmptyDetector",_center vectorAdd [4,-119,0]];
  _triggerStart set3DENAttribute
  [
    "Condition",
    format
    [
      "%1",
      _conditionStart
    ]
  ];
  _triggerStart set3DENAttribute ["IsServerOnly",true];
  _triggerStart set3DENAttribute ["Text",localize "STR_ENH_EXTRACTION_TRIGGERSTARTEXTRACTIONTEXT"];

  add3DENConnection ["WaypointActivation",[_triggerStart],_wpStart];

  //Set up radio chat trigger
  if (cbChecked CTRL(IDC_EXTRACTION_SHOWRADIOCHAT)) then
  {
    private _nameRequester = ctrlText CTRL(IDC_EXTRACTION_NAMEREQUESTER);
    private _nameTransport = ctrlText CTRL(IDC_EXTRACTION_NAMETRANSPORT);
    private _callExtractionMsg = format [localize "STR_ENH_EXTRACTION_CALLEXTRACTIONMSG",_nameRequester,_nameTransport,ctrlText CTRL(IDC_EXTRACTION_GRID)];
    private _extractionConfirmedMsg = format [localize "STR_ENH_EXTRACTION_EXTRACTIONCONFIRMEDMSG",_nameRequester,_nameTransport];
    _triggerStart set3DENAttribute
    [
      "OnActivation",
      format
      [
        "[['%1','%3'],['%2','%4',8]] remoteExec ['BIS_fnc_EXP_camp_playSubtitles',0];",
        _nameRequester,
        _nameTransport,
        _callExtractionMsg,
        _extractionConfirmedMsg
      ]
    ];
  };

  //Setup unload waypoint
  private _wpTransportUnload = group _veh create3DENEntity ["Waypoint","TransportUnload",_center  vectorAdd [0,-0.5,0]];

  //Condition for the transport unload wp to become true.
  _wpTransportUnload set3DENAttribute	["Condition",format ["%1",ctrlText CTRL(IDC_EXTRACTION_CONDITION)]];

  private _markerLZ = create3DENEntity ["Marker","hd_pickup",_center vectorAdd [1,0,0]];
  _markerLZ set3DENAttribute ["baseColor","colorBLUFOR"];
  _markerLZ set3DENAttribute ["text","LZ"];//No need to localize

  private _wpEnd = group _veh create3DENEntity ["Waypoint","Move",_center vectorAdd [0,120,0]];
  //Put everything into one layer
  {
    _x set3DENLayer _layer;
  } forEach [_veh,_wpStart,_wpTransportUnload,_wpEnd,_triggerStart,_triggerSmoke,_markerLZ];
};

_display closeDisplay 0;

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;