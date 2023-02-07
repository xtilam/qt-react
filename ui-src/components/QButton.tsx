import { makeWidgetComponent } from "./BaseWidget"

export const QButton = makeWidgetComponent<QButtonProps>({
	tagName: 'qtbutton',
	convert: {
		children: 'text'
	},
	events: {
		onClick: (el) => el.widget.clicked
	},
	defaultValue: {
		children: ''
	}
})
type QButtonProps = {
	onClick?: () => void
	children?: string
}