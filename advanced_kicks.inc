/*
	* Library: Samp Advanced Kick (advanced_kicks.inc)
	* Author: Mergevos
	* Date: 27. July 2020.
	* Copyright: (C) 2020
	* Credits: 
		IllidanS4 - PawnPlus
*/


#if defined ___@ADVANCED_KICK_INC
	#endinput
#endif

#define ___@ADVANCED_KICK_INC

#include < a_samp >

#include < PawnPlus >

#if !defined KICK_ON_PING_TIME
	#define KICK_ON_PING_TIME 10
#endif 

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
    wait_ms(GetPlayerPing(playerid) + KICK_ON_PING_TIME);
	Kick(playerid);
    return 1;
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
		wait_ms(time);
		CallLocalFunction("OnPlayerKicked", "iisii", playerid, kickerid, reason, time, KICK_SUCCESS);
		KickEx(playerid, reason, true);
	}
	else {
		return Kick(playerid);
	}
	return KICK_SUCCESS;
}


// --
// ALS
// --

#if defined _ALS_Kick 
  #undef Kick
#else 
#define _ALS_Kick
#endif 
#define Kick AK_Kick 