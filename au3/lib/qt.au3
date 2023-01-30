
#include-once

Global $JS_DebugerPort = 9999
Global $Qt_DLL = 0
Global $OBJ_DLL = 0

Opt("TrayIconHide", 1)

If $Qt_DLL = 0 Then
	$OBJ_DLL = DllOpen('obj.dll')
	$Qt_DLL = DllOpen('qml.dll') 

	If $OBJ_DLL = -1 Or $Qt_DLL = -1 Then
		ConsoleWrite('Cannot load DLL' & @CRLF)
		Exit
	EndIf

	If Not $JS_DebugerPort Then $JS_DebugerPort = 1234
	Qt_setDebugPort($JS_DebugerPort)

	DllCall($Qt_DLL, 'none', 'initApplication')

	If Not @Compiled Then
		Qt_enableDebug()
	EndIf

	Local $methods = DllCall($OBJ_DLL, 'ptr', 'getAllMethods')[0]
	DllCall($Qt_DLL, 'none', 'setComMethods', 'ptr', $methods)
	Global Const $console = DllCall($Qt_DLL, 'idispatch', 'getDebugger')[0]
	Global Const $ui = DllCall($Qt_DLL, 'idispatch', 'getUI')[0]

	Local $configMethods = DllStructCreate('ptr methods[3]')
	DllStructSetData($configMethods, 'methods', DllCallbackGetPtr(DllCallbackRegister(Qt_mainHandleSignal, 'none', 'str;idispatch')), 1)		
	if IsFunc(Execute('onReload')) Then 
		DllStructSetData($configMethods, 'methods', DllCallbackGetPtr(DllCallbackRegister('onReload', 'none', '')), 2)
	EndIf
	DllCall($Qt_DLL, 'none', 'configMethods', 'ptr', DllStructGetPtr($configMethods))
EndIf

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
EndFunc

Func Qt_enableDebug()
	DllCall($Qt_DLL, 'none', 'enableDebug')
EndFunc   ;==>Qt_enableDebug

Func Qt_newObject()
	return DllCall($Qt_DLL, 'idispatch', 'newObject')[0]
EndFunc

Func Qt_newArray()
	return DllCall($Qt_DLL, 'idispatch', 'newArray')[0]
EndFunc

Func Qt_ProcessEvents()
	DllCall($Qt_DLL, 'none', 'execLoopEvent')
EndFunc

Func Qt_setRCPath($path = '')
	DllCall($Qt_DLL, 'none', 'setRCPath', 'wstr', $path)
EndFunc

Func Qt_addJS($path = '')
	DllCall($Qt_DLL, 'none', 'addJS', 'wstr', $path)
EndFunc

Func Qt_useStyle($path = '')
	DllCall($Qt_DLL, 'none', 'useStyle', 'wstr', $path)
EndFunc

Func Qt_addExtension($extension = Ptr(0))
	DllCall($Qt_DLL, 'none', 'addExtension', 'ptr', $extension)
EndFunc

Func Qt_setDebugPort($port = '9999')
	DllCall($Qt_DLL, 'none', 'setDebuggerPort', 'str', $port)
EndFunc