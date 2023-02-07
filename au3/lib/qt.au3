
#include-once

Global $JS_DebugerPort = '4444,4445'
Global $Qt_DLL = 0
Global $OBJ_DLL = 0

Qt_Init()

Func Qt_mainHandleSignal($func, $p)
	Local $lastIndex = $p.length - 1
	Local $start = ''
	$strExecute = $func & '('

	For $i = 0 To $lastIndex Step +1
		$strExecute &= $start & '$p.get(' & $i & ')'
		$start = ', '
	Next
	$strExecute &= ')'

	Execute($strExecute)
EndFunc   ;==>Qt_mainHandleSignal

Func Qt_GetAu3Methods()
	Static Local $configMethods = DllStructCreate('ptr methods[3]')
	DllStructSetData($configMethods, 'methods', DllCallbackGetPtr(DllCallbackRegister(Qt_mainHandleSignal, 'none', 'str;idispatch')), 1)
	DllStructSetData($configMethods, 'methods', _
			DllCallbackGetPtr(DllCallbackRegister(IsFunc(Execute('mainLoop')) ? 'mainLoop' : 'Qt_MainLoop', 'none', '')), 2)
	If IsFunc(Execute('onReload')) Then _
			DllStructSetData($configMethods, 'methods', DllCallbackGetPtr(DllCallbackRegister('onReload', 'none', '')), 3)
	Return DllStructGetPtr($configMethods)
EndFunc   ;==>Qt_GetAu3Methods

Func Qt_Init()
	If (IsDeclared('qt')) Then Return

	If $Qt_DLL = 0 Then
		$OBJ_DLL = DllOpen('obj.dll')
		$Qt_DLL = DllOpen('qml.dll')

		If $OBJ_DLL = -1 Or $Qt_DLL = -1 Then
			ConsoleWrite('Cannot load DLL' & @CRLF)
			Exit
		EndIf

	EndIf

	If Not $JS_DebugerPort Then $JS_DebugerPort = 4444
	Global Const $qt = DllCall($Qt_DLL, 'idispatch', 'getQtObject', _
			'ptr', Qt_GetAu3Methods(), _
			'ptr', DllCall($OBJ_DLL, 'ptr', 'getAllMethods')[0], _
			'BOOL', Not @Compiled, 'wstr', $JS_DebugerPort)[0]
	Global Const $console = $qt.getDebugger()
	Global Const $ui = $qt.getUI()
EndFunc   ;==>Qt_Init

Func Qt_MainLoop()

EndFunc   ;==>Qt_MainLoop
