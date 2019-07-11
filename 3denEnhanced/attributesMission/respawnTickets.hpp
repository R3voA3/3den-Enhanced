class Enh_TicketsBLUFOR
{
   displayName = $STR_ENH_respawnTickets_BLUFOR_displayName;
   tooltip = "";
   property = "Enh_respawnTickets_west";
   control = "Edit";
   expression = "if (!is3DEN && isMultiplayer && isServer) then {[west,_value] call BIS_fnc_respawnTickets}";
   defaultValue = "0";
   typeName = "NUMBER";
};
class Enh_TicketsOPFOR: Enh_TicketsBLUFOR
{
   displayName = $STR_ENH_respawnTickets_OPFOR_displayName;
   property = "Enh_respawnTickets_east";
   expression = "if (!is3DEN && isMultiplayer && isServer) then {[east,_value] call BIS_fnc_respawnTickets}";
};
class Enh_TicketsINDFOR: Enh_TicketsBLUFOR
{
   displayName = $STR_ENH_respawnTickets_INDFOR_displayName;
   property = "Enh_respawnTickets_independent";
   expression = "if (!is3DEN && isMultiplayer && isServer) then {[independent,_value] call BIS_fnc_respawnTickets}";
};
class Enh_TicketsCIV: Enh_TicketsBLUFOR
{
   displayName = $STR_ENH_respawnTickets_CIV_displayName;
   property = "Enh_respawnTickets_civilian";
   expression = "if (!is3DEN && isMultiplayer && isServer) then {[civilian,_value] call BIS_fnc_respawnTickets}";
};

