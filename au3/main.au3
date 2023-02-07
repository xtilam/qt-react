#include "lib/qt.au3"
;~ #include "login.au3"

main()

Func main()
	Local $obj = $qt.obj().name("9999")
	Local $path = "/build/"

	If Not @Compiled Then 
		$qt.setRCPath(@ScriptDir & "/../ui")
		$path = "/dev/"
	EndIf

	$qt.addStyle($path & "main.css")
	$qt.addJS($path & 'core.js')
	$qt.addJS($path & 'modules.js')
	$qt.addJS($path & 'main.js')
	$qt.exec()
EndFunc   ;==>main

Func onReload()

EndFunc   ;==>onReload

Func click($time = 1000)
	Local $win = WinGetHandle('Active 3')
	Local $winActive = WinGetHandle("[ACTIVE]")
	Local $oldMousePos = MouseGetPos()
	Local $winpos = WinGetPos($win)
	Local $xCenter = ($winpos[0] + $winpos[2] / 2)
	Local $yCenter = ($winpos[1] + $winpos[3] / 2)
	MouseMove($xCenter, $yCenter, 0)
	MouseDown('left')
	Sleep($time)
	MouseUp('left')
	MouseMove($oldMousePos[0], $oldMousePos[1], 0)
	WinActivate($winActive)
EndFunc   ;==>click

Func writeFile($name, $content)
	Local $path = @ScriptDir & '\data\' & $name
	Local $fileHandle = FileOpen($path, 10)
	ConsoleWrite($content)
	FileWrite($path, $content)
EndFunc   ;==>writeFile
