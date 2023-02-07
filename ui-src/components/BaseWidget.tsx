import React from "react"
import { CSSProperties } from "react"

class BaseWidget<P = {}, T = WidgetProp & P> extends React.Component<T>{
	['constructor']: typeof BaseWidget
	static tagName = ""
	static propertyInvalid: any = {
		children: true,
	}
	static requireProperty = {} as any
	static events = {} as any
	static mapConvert = {} as any
	static defaultValues = {} as any

	ref = React.createRef<any>()
	historySetEvt = {} as any

	componentDidMount(): void {
		const props: any = this.props
		this.setProps(props)
		if (props.hasOwnProperty('show')) {
			this.ref.current.show = props.show
		} else {
			this.ref.current.show = true
		}
	}
	componentDidUpdate(prevProps: Readonly<T>): void {
		this.setProps(this.props, prevProps)
	}
	setProps(newProps: any, oldProps = ({} as any)) {
		const el = this.ref.current
		const { requireProperty, propertyInvalid, events, mapConvert, defaultValues } = (this.constructor as typeof BaseWidget)
		const newHistorySetEvt = {}
		// set require properties
		for (const property in requireProperty) {
			let newVal
			if (newProps.hasOwnProperty(property)) {
				newVal = newProps[property] || defaultValues[property]
			} else {
				newVal = requireProperty[property]
			}
			if (el[property] === newVal) continue
			el[property] = newVal
		}
		// convert props
		for (const key in mapConvert) {
			const val = newProps[key] || defaultValues[key]
			const elProperty = mapConvert[key]
			if (el[elProperty] === val) continue
			el[elProperty] = val
		}
		// set properties
		for (const property in newProps) {
			const val = newProps[property]
			if (propertyInvalid[property]) {
				if (propertyInvalid[property] === 4) {
					const connect = events[property](el)
					if (typeof connect !== 'function') continue
					if (this.historySetEvt[property]) {
						const oldFunc = oldProps[property]
						if (typeof val === 'function') {
							if (oldFunc !== val) {
								connect.disconnect(oldFunc)
								connect.connect(val)
							}
							newHistorySetEvt[property] = true
						} else {
							connect.disconnect(oldFunc)
						}
					} else {
						if (typeof val !== 'function') continue
						connect.connect(val)
						newHistorySetEvt[property] = true
					}
				}
				continue
			}
			if (el[property] === val) continue
			el[property] = val
		}

		this.historySetEvt = newHistorySetEvt
	}
	withChildRender() {
		return React.createElement(this.constructor.tagName, { ref: this.ref, children: (this.props as any).children })
	}
	render() {
		return React.createElement(this.constructor.tagName, { ref: this.ref })
	}
}

export function makeWidgetComponent<T = {}>(info: ParamWidgetComponent<T>) {
	const classWidget = class extends BaseWidget<T>{ }
	classWidget.tagName = info.tagName
	classWidget.propertyInvalid = { ...classWidget.propertyInvalid }

	if (info.convert) classWidget.mapConvert = { ...classWidget.mapConvert, ...info.convert }
	if (info.events) classWidget.events = info.events
	if (info.hasChildren) classWidget.prototype.render = classWidget.prototype.withChildRender
	if (info.defaultValue) classWidget.defaultValues = info.defaultValue
	if (info.require) {
		classWidget.requireProperty = { ...classWidget.requireProperty }
		for (const key of info.require) {
			classWidget.requireProperty[key] = classWidget.defaultValues[key]
			classWidget.propertyInvalid[key] = true
		}
	}

	for (const property in classWidget.mapConvert) {
		classWidget.propertyInvalid[property] = true
	}
	for (const property in classWidget.events) {
		classWidget.propertyInvalid[property] = 4
	}
	return classWidget
}

type WidgetProp = {
	x?: number
	y?: number
	width?: number
	height?: number
	title?: string
	show?: boolean
	disabled?: boolean
	className?: string
	style?: CSSProperties
	verPolicy?: QSizePolicy.Policy
	horPolicy?: QSizePolicy.Policy
	gridColspan?: number
	gridRowspan?: number
}
type ParamWidgetComponent<P, T = WidgetProp & P, KEYS = keyof T> = {
	tagName: string
	require?: KEYS[]
	convert?: { [n in keyof T]: string }
	hasChildren?: boolean
	defaultValue?: { [n in keyof T]: any }
	events?: { [n in keyof T]: (_thisParam: any) => any }
}