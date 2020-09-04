/*
   Author: R3vo

   Date: 2020-07-18

   Description:
   Converts a single digit number into a two digit string. Used for time display for example.

   Parameter(s):
   0: NUMBER - Number to be converted

   Returns:
   STRING: Either the number just as string, or the number as string with an added 0 in front of it.
*/

params ["_number"];

if (_number < 10) then
{
	"0" + str _number;
} else
{
	str _number;
};