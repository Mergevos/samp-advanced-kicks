/*
	* Library: Samp Advanced Kick (advanced_kicks.inc)
	* Author: Mergevos
	* Date: 27. July 2020.
	* Copyright: (C) 2020
*/


#if defined ___@ADVANCED_KICK_INC
	#endinput
#endif

#define ___@ADVANCED_KICK_INC

#include < a_samp >

// --
// <summary>Forwards callback OnPlayerKicked</summary>
// --
forward OnPlayerKicked(playerid, kickerid, string: reason[], time, responselevel);

enum {
	KICK_SUCCESS = 1,
	KICK_KICKEROFFLINE,
	KICK_TARGETOFFLINE
}

// --
// <summary> Defers the timer used to kick a players</summary>
// --
stock AK_Kick(const playerid)
{
    SetTimerEx("AK_CallKick", 70, false, "i", playerid);
    return 1;
}

// --
// <summary> Kicks the particular player after the timer's finished</summary>
// --
forward AK_CallKick(const playerid);
public AK_CallKick(const playerid)
{
    return Kick(playerid);
}

// --
// <summary> Kicks the particular player with params</summary> 
// --
stock KickEx(const playerid, const reason[], bool:usecallback=false)
{
	SendClientMessage(playerid, -1, reason);
	AK_Kick(playerid);
	if(usecallback) {
		CallLocalFunction("OnPlayerKicked", "iisii", playerid, -1, reason, 0, KICK_SUCCESS);
	}
}

// --
// <summary> Advanced player kick, delayed with player status checking with custom reason and reaction</summary>
// --

stock AdvancedKick(const playerid, const kickerid, const reason[], const time)
{
	if(!IsPlayerConnected(playerid)) {
		return CallLocalFunction("OnPlayerKicked", "iisii", playerid, kickerid, reason, time, KICK_TARGETOFFLINE);
	}
	else if(!IsPlayerConnected(kickerid)) {
		return CallLocalFunction("OnPlayerKicked", "iisii", playerid, kickerid, reason, time, KICK_KICKEROFFLINE);
	}
	if(time != 0) {
		SetTimerEx("before_OnPlayerKicked", time, false, "iisii", playerid, kickerid, reason, time, KICK_SUCCESS);
	}
	else {
		return Kick(playerid);
	}
	return KICK_SUCCESS;
}

// --
// <params>Handles before kicking event</params>
// --
forward before_OnPlayerKicked(const playerid, const kickerid, reason[], const time, const responselevel);
public before_OnPlayerKicked(const playerid, const kickerid, reason[], const time, const responselevel) 
{
	new tmpstrrsn[144];
	format(tmpstrrsn, sizeof(tmpstrrsn), "%s", reason);
	SendClientMessage(playerid, -1, reason);
	CallLocalFunction("OnPlayerKicked", "iisii", playerid, kickerid, tmpstrrsn, time, responselevel);
	KickEx(playerid, tmpstrrsn, false);
	strdel(tmpstrrsn, 0, strlen(tmpstrrsn));	
}

#if defined _ALS_Kick 
  #undef Kick
#else 
#define _ALS_Kick
#endif 
#define Kick AK_Kick 
