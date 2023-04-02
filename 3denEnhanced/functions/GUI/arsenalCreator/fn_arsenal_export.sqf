/*
  Author: linkion

  Date: 2023-04-01

  Description:
  exports SQF code for creating an arsenal based on selection from GUI.

  Parameter(s):
  0: STRING - Mode, can be: ace, bi

  Returns:
  -
*/
/* what selHashMap could be structured like\
 *
 * could, this is incomplete
 * 
 * ["apex", true] and all of apex is selected
 * ["apex", ["weapons", true]] all apex DLC weapons are slected
 * ["apex", ["weapons", ["handguns", true]]] only all of apex DLC hanguns are selected
 * ["apex", [["weapons", true], ["clothing", true]]] all of apex DLC weapons and clothing are selected
 * ┌───────────────────┬─────────────┬─────────────┬─────────┐
 * │       addon       │             │handguns     │   ...   │
 * ├───────────────────┤             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │assaultRifles│   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │snipers      │   ...   │
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │  weapons    ├─────────────┼─────────┤
 * │                   ├─────────────┤machineGuns  │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │subMachinGuns│   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │shotguns     │   ...   │
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │             │headgear     │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │vests        │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │  clothing   │backpacks    │   ...   │
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │uniforms     │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │facewear     │   ...   │
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │             │nightvision  │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │explosives   │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │binoculars   │   ...   │
 * │                   ├─────────────┼─────────────┼─────────┤
 * │                   │  equipment  ├─────────────┼─────────┤
 * │                   ├─────────────┤terminals    │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │optics       │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │railAcc      │   ...   │
 * │                   │             ├─────────────┼─────────┤
 * │                   │             ├─────────────┼─────────┤
 * │                   │             │muzzle       │   ...   │
 * ├───────────────────┼─────────────┴─────────────┴─────────┤
 * │                   │                                     │
 * │        ...        │                 ...                 │
 * │                   │                                     │
 * └───────────────────┴─────────────────────────────────────┘
 */
params["_mode"];
private _selHashMap = uiNamespace getVariable "ENH_arsenal_selHashMap";
_clip = "";

switch (toLower(_mode)) do {
  case "ace": {
    
  };
  case "bi": {

  };
};

copyToClipboard _clip;

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true