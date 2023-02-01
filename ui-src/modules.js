import React from "react";
import ReactDOMClient from "react-dom/client";

window.React = React
window.ReactDOMClient = ReactDOMClient

window.renderApplication = function(window, element){
	const root = ReactDOMClient.createRoot(window)
	root.render(element)
	return root
}