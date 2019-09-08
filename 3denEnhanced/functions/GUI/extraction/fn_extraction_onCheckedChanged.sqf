#define GET_CTRL(IDC) (_display displayCtrl IDC)

params ["_ctrlCheckbox", "_checked"];

private _display = ctrlParent _ctrlCheckbox;
private _enable = [false,true] select _checked;

GET_CTRL(200) ctrlEnable _enable;
GET_CTRL(300) ctrlEnable _enable;