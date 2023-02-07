import { QButton } from "./QButton";
import { QWidget } from "./QWidget";

export function ConsoleView() {
	return <QWidget layout="row" className="console-view">
		<QButton>Console view</QButton>
		<QButton>Console view</QButton>
	</QWidget>
}