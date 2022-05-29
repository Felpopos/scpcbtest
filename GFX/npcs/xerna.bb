Graphics3D 640, 480, 0, 2
SeedRnd MilliSecs()
mesh = LoadAnimMesh("classd.b3d")
SetAnimTime(mesh, 310)
RotateEntity Mesh, 0, Rnd(-180, 180), 0

Local bone = FindChild(mesh, "Bip01_L_UpperArm")

;DebugLog EntityPitch(bone, True)+" "+EntityYaw(bone, True)+" "+EntityRoll(bone, True)

RotateEntity(bone, -13.3971, EntityYaw(mesh)+58.1681, 135.2683, True)

bone = FindChild(mesh, "Bip01_R_UpperArm")
;DebugLog EntityPitch(bone, True)+" "+EntityYaw(bone, True)+" "+EntityRoll(bone, True)

RotateEntity(bone, -13.3971, EntityYaw(mesh)-50.1686, 48.732, True)

Local camera = CreateCamera()
PositionEntity Camera, -0, 80,50
PointEntity Camera, Mesh
api_ShowWindow(SystemProperty("AppHWND"), 1)
While True
	Cls
	RenderWorld()
	Flip
Wend