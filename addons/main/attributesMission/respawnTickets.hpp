class ENH_TicketsBLUFOR
{
    displayName = "$STR_ENH_MAIN_RESPAWNTICKETS_BLUFOR_DISPLAYNAME";
    tooltip = "";
    property = "ENH_respawnTickets_west";
    control = "Edit";
    expression = "if (!is3DEN && isMultiplayer && isServer) then {[west, _value] call BIS_fnc_respawnTickets}";
    defaultValue = 0;
    typeName = "NUMBER";
};
class ENH_TicketsOPFOR: ENH_TicketsBLUFOR
{
    displayName = "$STR_ENH_MAIN_RESPAWNTICKETS_OPFOR_DISPLAYNAME";
    property = "ENH_respawnTickets_east";
    expression = "if (!is3DEN && isMultiplayer && isServer) then {[east, _value] call BIS_fnc_respawnTickets}";
};
class ENH_TicketsIndependent: ENH_TicketsBLUFOR
{
    displayName = "$STR_ENH_MAIN_RESPAWNTICKETS_INDEPENDENT_DISPLAYNAME";
    property = "ENH_respawnTickets_independent";
    expression = "if (!is3DEN && isMultiplayer && isServer) then {[independent, _value] call BIS_fnc_respawnTickets}";
};
class ENH_TicketsCivilian: ENH_TicketsBLUFOR
{
    displayName = "$STR_ENH_MAIN_RESPAWNTICKETS_CIVILIAN_DISPLAYNAME";
    property = "ENH_respawnTickets_civilian";
    expression = "if (!is3DEN && isMultiplayer && isServer) then {[civilian, _value] call BIS_fnc_respawnTickets}";
};
