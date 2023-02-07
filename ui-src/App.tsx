import { useState } from "react"
import { QButton } from "./components/QButton"
import { QWidget } from "./components/QWidget"
import { defaultWindow } from "./main"

export let changeTitle = function (title) {
	defaultWindow.title = title
}
const unit = 70
export function App() {
	const [count, setCount] = useState(8)
	function onClick() {
		setCount(count + 1)
	}
	return <>
		<QWidget layout="row">
			{true && <QButton>{`value: ${count} => ${count * unit}`}</QButton>}
			<QButton onClick={() => {
				setCount(count + 1)
			}}>increase</QButton>
			<QButton onClick={() => {
				setCount(count - 1)
			}}>decrease</QButton>
			<QButton onClick={() => {
				au3.execute('click', count * unit)
			}}>dump</QButton>
			{count % 2 && <QButton>ucc</QButton>}
			<QButton>dc</QButton>
			<QWidget />
		</QWidget>
	</>
}

try {

} catch (error) {
	console.log('error')
}