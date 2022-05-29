// Works only since 1.2.3 version. // By Ne4to

#include "includes\multiplayer_core.inc"

const BAN_CMD = "/ban"
def BanPlayer(playerid, seconds)
    PutIniValue("inibans", getplayersteamid(playerid), "banuntil", getunixtime()+seconds)
    Kick(playerid, GetPlayerNickname(playerid)+" was banned")
    
    UpdateINIFile("inibans")
end

public def OnScriptLoaded()

    if FileType("inibans") == 0 then
        CloseFile(WriteFile("inibans"))
    end
    
    print("INI BAN by Ne4to loaded successfully!")
end

public def OnPlayerRconAuthorized(playerid)
    SendMessage(playerid, "[INI BAN] Use '/ban [id] [minutes]' to ban players")
end

public def OnIncomingConnection(nickname, IP, SteamID)
    local banend = int(GetINIValue("inibans", SteamID, "banuntil", "0"))
    if getunixtime() < banend then return "You are banned by admin."+Chr(13)+Chr(10)+"("+int((banend-getunixtime())/60)+" minutes left)"
end

public def OnPlayerChat(playerid, txt)
    if IsPlayerAdmin(playerid) then
        if instr(txt, BAN_CMD, 1) then
            local id = ""
            local minutes = ""
            id = split(txt, 3, " ")
            minutes = split(txt, 4, " ")
            if id > 0 and id < MAX_PLAYERS then 
                if IsPlayerConnected(id) then 
                    BanPlayer(int(id), int(minutes)*60)
                    return 0
                end
            end
        end
    end
end


def split(s, entry, char)
    while Instr(s,char+char, 1)
        s = Replace(s, char+char,char)
    end
    for n = 1; n < entry; n++
        p = Instr(s, char, 1)
        s = Right(s, Len s-p)
    end
    p = Instr(s, char, 1)
    If p < 1 then
        a = s
    else
        a = Left(s,p-1)
    end
    return a
end