import { CSSProperties } from "react";
import { App } from "./App";
import "./styles/style.scss"

export const defaultWindow = (window as any).defaultWindow;
export const renderApplication = (window as any).renderApplication

defaultWindow.x =0
defaultWindow.y = 0
defaultWindow.height = 500
defaultWindow.title = 'this is window'
defaultWindow.show = true
defaultWindow.layout = "row"
// defaultWindow.windowFlags = Qt.WindowFlags.Window | Qt.WindowFlags.FramelessWindowHint | Qt.WindowFlags.CustomizeWindowHint
defaultWindow.className = 'main-window'

// const widget = defaultWindow.createElement('qtwidget')
// widget.layout = 'row'
// defaultWindow.appendChild(widget)
// widget.show = true
// widget.className = 'console-view'

// const button = widget.createElement('qtbutton')
// button.text = 'this is button'
// widget.appendChild(button) 

// defaultWindow.reset()

export const application = renderApplication(defaultWindow, <App/>)

export function showSignalConnect(obj){
	for(const key in obj){
		const val = obj[key]
		if(typeof val !== 'function') continue
		if(!val.connect && typeof val.connect !== 'function') continue
		if(!val.disconnect && typeof val.disconnect !== 'function') continue
		try {
			val.connect(test)
			val.disconnect(test)
			console.log(key)
		} catch (error) {
			
		}
	}
	function test(){}
}
