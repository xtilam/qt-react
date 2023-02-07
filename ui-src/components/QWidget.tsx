import { makeWidgetComponent } from "./BaseWidget"

export const QWidget = makeWidgetComponent<QWidgetProps>({
	tagName: 'qtwidget',
	hasChildren: true,
	require: ['layout'],
	defaultValue: {
		layout: ''
	}
})

type QWidgetProps = {
	children?: any
	layout?: '' | 'row' | 'column'
}
