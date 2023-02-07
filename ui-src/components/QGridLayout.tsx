import { makeWidgetComponent } from "./BaseWidget";

export const GridLayout = makeWidgetComponent<GridLayoutProps>({
	tagName: 'gridlayout'
})

export const GridRow = makeWidgetComponent<GridRow>({
	tagName: 'gridlayoutrow'
})

const row = <GridRow>
	<div></div>
</GridRow>

type GridLayoutProps = {

}

type GridRow = {
	children: JSX.Element[] | JSX.Element
}
