/*
	Author: Revo

	Description:
	Used by ENH_Credits. Called onLoad event.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

params ["_display"];

private _contributers =
[
	"dixon13",
	"dardothemaster",
	"niquenen","solentis",
	"XerXesCZ",
	"Artenis",
	"KiritoKun223",
	"11RDP-LoupVert",
	"arv187",
	"Theassassinzz",
	"Jason Bert",
	"TaktischerSpeck",
	"pokertour",
	"Kofeina101",
	"IllidanS4",
	"2RIMa-PapaBear",
	"a1044438870",
	"SynchronizedHD",
	"GhostJumper",
	"lex__1",
	"ConnorAU",
	"shukari",
	"Poslovitch",
	"zagor64bz"
];

private _ctrl = _display displayCtrl 1000;

{
	_ctrl lbAdd _x;
} forEach _contributers;

true