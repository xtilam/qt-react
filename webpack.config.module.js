const path = require("path");
const { argv } = require("process");
const config = require("./config");

const isProduction = argv.findIndex((v) => v === "--mode=production") !== -1

const mode = isProduction
	? {
		mode: 'production',
		watch: false
	}
	: {
		mode: 'development',
		watch: false
	};

module.exports = {
	...mode,
	entry: {
		main: "./ui-src/modules.js"
	},
	output: {
		path: path.dirname(config.targetJS),
		filename: `module${isProduction ? '' : '.dev'}.bundle.js`,
	},
	devtool: false,
	resolve: {
		extensions: [".js", ".ts", ".tsx", ".jsx"],
	},
	module: {
		rules: [
			{
				test: /\.(ts|tsx|js|jsx)$/,
				use: ["babel-loader"],
			}
		],
	},
};


