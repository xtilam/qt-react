import React from "react"

export class Button extends React.Component<ButtonProps>{
	ref = React.createRef<any>()
	componentDidMount(): void {
		console.log(this.ref.current)
	}
	getMapEvt(){
		// return {
		// 	onClick
		// }
	}
	render() {
		// const p: any = { ...this.props }
		// p.ref = this.ref
		// delete p.onClick
		return React.createElement('qtbutton', { ref: this.ref })
	}
}


type ButtonProps = {
	onClick?: ()=>void
	children?: string
}