!alive unit [<ARRAY>keywords, <STRING>descripton, <STRING>code]

[["alive", "units", "soldier"], "Returns true if unit is not alive", "!alive unit"]

units unit

units in vehicle

units alive

units not alive

can move vehicle+

({alive _x} count (units _group)) == 0


Perhaps predefined triggers?

(allPlayers findIf {_x distance thisTrigger < 50 || _x inArea thisTrigger}) == -1
(nearestObjects [thisTrigger, [], triggerArea thisTrigger # 0 max triggerArea thisTrigger # 1]) apply {deleteVehicle _x};