#include < a_samp >
#define YSI_YES_HEAP_MALLOC
#include < m_kick >

main() {}

public OnGameModeInit() {
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    if(!strcmp(cmdtext, "/test", true)) {
        SendClientMessage(playerid, -1, "Does this work? Does this work? Kickin's cool ma nibba");
        SendClientMessage(playerid, -1, "Does this work? Does this work? Kickin's cool ma nibba");
        SendClientMessage(playerid, -1, "Does this work? Does this work? Kickin's cool ma nibba combo 3x xxxx ma beibe");
        Kick(playerid);
        return 1;
    }
    if(!strcmp(cmdtext, "/testex", true)) {
        SendClientMessage(playerid, -1, "Does this work?");
        KickEx(playerid, "test");
        return 1;
    }
    if(!strcmp(cmdtext, "/testexclb", true)) {
        SendClientMessage(playerid, -1, "Does this work? Kickin's cool ma nibba");
        KickEx(playerid, "testclbeeeeeeeeeeeeeeeeeeeeeeeee", true);
        return 1;
    }
    if(!strcmp(cmdtext, "/testadvanced", true)) {
        SendClientMessage(playerid, -1, "Does this work?");
        AdvancedKick(playerid, playerid, "Znjrizon", 6000);
        return 1;
    }
    return 0;
}

public OnPlayerKicked(playerid, kickerid, reason[], time, responselevel)
{
    if(responselevel == KICK_KICKEROFFLINE) {
        printf("Igrac: %d, nije kikovan od jer je nekonektovan kiker %d, razlog: %s, time: %d", playerid, kickerid, reason, time);
    }
    if(responselevel == KICK_TARGETOFFLINE) {
        printf("Igrac: %d, nije kikovan od jer je nekonektovan target %d, razlog: %s, time: %d", playerid, kickerid, reason, time);
    }
    if(responselevel == KICK_SUCCESS) {
        printf("Igrac: %d, kikovan od %d, razlog: %s, time: %d", playerid, kickerid, reason, time);
    }
    return 1;
}