#include "includes\mysql\mysql.inc"
global MysqlConnection = 0

public def OnScriptLoaded()
	MysqlConnection = connectmysql("127.0.0.1", "root", "scp", "")
	if MysqlConnection == 0 then
		print("Failed to connect to MySQL. The server will shut down in 30 seconds.")
		delay(30000)
		CloseApp()
	else
        print("Successfully connected to MySQL ["+MysqlConnection+"]")
        
        local query = sqlquery(mysqlconnection, "CREATE TABLE IF NOT EXISTS `accounts` (`name` text NOT NULL,`steamid` int(11) NOT NULL,`lastip` text NOT NULL,UNIQUE KEY `steamid` (`steamid`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;")
		FreeSQLQuery(query)
	end
end


public def OnPlayerConnect(playerid)
	local Query = SQLQuery(mysqlconnection, "SELECT * FROM `accounts` WHERE `steamid` = '"+GetPlayerSteamID(playerid)+"'")
	if Query > 0 then
		local row = SQLFetchRow(Query)
        
		if SQLRowCount(Query) > 0 then
            print("Connected registered account")
            
            SQLQuery(mysqlconnection, "UPDATE `accounts` SET `lastip` = '"+GetPlayerIP(playerid)+"' WHERE `steamid` = '"+GetPlayerSteamID(playerid)+"'")
		else
            local Query2 = SQLQuery(mysqlconnection, "INSERT INTO `accounts` (`name`, `steamid`, `lastip`) VALUES ('"+GetPlayerNickname(playerid)+"', '"+GetPlayerSteamID(playerid)+"', '"+GetPlayerIP(playerid)+"')")
            if Query2 Then
                print("Successfully registered "+GetPlayerSteamID(playerid))
                FreeSQLQuery(Query2)
            end
		end
        
		FreeSQLRow(Row)
		FreeSQLQuery(Query)
	else
        print("Fail to send query ["+Query+"]")
    end
    return 1
end




// Mysql

def connectmysql(host, user, database, password)
	return OpenSQLStream(host, 3306, user, password, database, 1)
end