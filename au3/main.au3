#include "lib/qt.au3"
#include "login.au3"

main()

Func main()
	If Not @Compiled Then Qt_setRCPath(@ScriptDir & "/../ui")
	Qt_addJS('main.bundle.js') 
	Qt_ProcessEvents()

	While True

		Qt_ProcessEvents()
	WEnd
EndFunc   ;==>main

Func onReload()
;~ $console.Log('on reload called')
;~ $ui.showData( _
;~ 	Qt_newObject() _
;~ 		.set('name', 'cuong toi') _
;~ 		.set('test', 'cuong 12') _
;~ 		.set('data', Qt_newArray() _
;~ 			.push(1,2,3) _
;~ 		) _
;~ )
EndFunc   ;==>onReload

Func writeFile($name, $content)
	Local $path = @ScriptDir & '\data\' & $name
	Local $fileHandle = FileOpen($path, 10)
	ConsoleWrite($content)
	FileWrite($path, $content)
EndFunc
