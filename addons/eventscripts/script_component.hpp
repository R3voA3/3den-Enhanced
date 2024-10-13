#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\enh\addons\main\script_component.hpp"

#define TRIPLES_NO_SCORE(var1,var2,var3) var1####var2####var3
#define EVENT_SCRIPT(var1) var1 = QUOTE(if (fileExists QUOTE(QUOTE(TRIPLES_NO_SCORE(.enh_eventScripts\,var1,.sqf)))) then {call compileScript [QUOTE(QUOTE(TRIPLES_NO_SCORE(.enh_eventScripts\,var1,.sqf)))]})
