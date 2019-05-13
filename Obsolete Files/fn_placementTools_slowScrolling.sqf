params ["_slider","_scroll"];

_slider sliderSetPosition ((sliderPosition _slider) + 0.1 * _scroll);//Scroll very smoothly. Direction is given by _scroll (can be positiv or negativ)
_slider sliderSetSpeed [1,1];

//tooltip = "Hold the ALT key and use the scroll wheel for fine adjustment."
//onKeyDown = "params ['_slider', '_key', '_shift', '_ctrl', '_alt']; if (_alt) then {_slider sliderSetSpeed [0.01,0.01]}";
//onKeyUp = "params ['_slider', '_key', '_shift', '_ctrl', '_alt']; if (_alt) then {_slider sliderSetSpeed [1,1]}";