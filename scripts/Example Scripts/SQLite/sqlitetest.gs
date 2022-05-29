#include "includes\sqlite\sqlite.inc"
global SQliteConnection = 0

public def OnScriptLoaded()
    local isfileexists = FileType("ServerDatabase.dat")
	SQliteConnection = OpenDatabase("ServerDatabase.dat", DBOpenModeCreate, True, True)
	if SQliteConnection == 0 then
		print("Failed to connect to SQLITE. The server will shut down in 30 seconds.")
		delay(30000)
		CloseApp()
	else
        print("Successfully connected to SQLITE ["+SQliteConnection+"]")
        
        if not isfileexists then ExecuteSQL("CREATE TABLE accounts (name text, steamid integer, lastip text)", 0, True)
	end
end


public def OnPlayerConnect(playerid)
	local Query = PrepareSQL("SELECT * FROM accounts WHERE steamid = '"+GetPlayerSteamID(playerid)+"'", SQliteConnection, True, True)
	if Query > 0 then
		if GetNextDataRow(Query, False, True) then
            print("Connected registered account")
            
            ExecuteSQL("UPDATE accounts SET lastip = '"+GetPlayerIP(playerid)+"' WHERE steamid = '"+GetPlayerSteamID(playerid)+"'", SQliteConnection, 0, True)
		else
            local success = ExecuteSQL("INSERT INTO accounts (name, steamid, lastip) VALUES ('"+GetPlayerNickname(playerid)+"', '"+GetPlayerSteamID(playerid)+"', '"+GetPlayerIP(playerid)+"')", SQliteConnection, 0, True)
            if success then print("Successfully registered "+GetPlayerSteamID(playerid))
		end
        
        FinaliseSQL(Query, True)
	else
        print("Fail to send query ["+Query+"]")
    end
    return 1
end