import { App } from "./App";

export const defaultWindow = (window as any).defaultWindow;
export const renderApplication = (window as any).renderApplication

defaultWindow.x = 0
defaultWindow.y = 0
defaultWindow.width = 300
defaultWindow.height = 300
defaultWindow.title = 'this is window '
defaultWindow.show = true
defaultWindow.addEventListener('click', function(){})
console.log('defaultWindow.addEventListener', defaultWindow.addEventListener)

try {
	// let data = ''
	// for(const key in Qt.MouseButton){
	// 	if(!isNaN(Number(key))) continue
	// 	data = data.concat(`${key}=${Number(Qt.MouseButton[key])},`)
	// }
	// console.log(data)
	renderApplication(defaultWindow, <App/>)
} catch (error) {
	console.log(error.stack)
}
