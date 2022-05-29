#PLAYERSCRIPT

global Menuscale = float(float(getmonitorheight())/1024.0)
global GameFont = 0
global txt = 0

public def OnDisconnect()
	freefont(GameFont)
end

public def OnLaunchGame()
   GameFont = loadfont("Tahoma", 100*menuscale, 1,0,0)
end

public def OnUpdate()
	setfont(GameFont)
    text (100.0*menuscale, 100.0*menuscale, txt, 0,0)
    if MouseHit2() Then 
        SetGameMessage("Why you click second mouse?", 3)
        LockMouse(1)
        ShowPointer()
    end
    
    if DrawUIButton(500, 500, 200, 30, "BUTTON", False, True) Then
        txt = not txt
        LockMouse(0)
        HidePointer()
    end
end

public def OnSpawn()

end