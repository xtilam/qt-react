const path = require("path");
const { argv } = require("process");
const config = require("./config");

const isProduction = argv.findIndex((v) => v === "--mode=production") !== -1

const mode = isProduction
	? {
		mode: 'production',
		watch: false,
		devtool: false,
	}
	: {
		mode: 'development',
		watch: false,
		devtool: 'inline-source-map',
	};

module.exports = {
	...mode,
	entry: {
		modules: "./ui-src/modules.js",
		core: "./ui-src/core.js"
	},
	output: {
		path: path.dirname(config.targetJS),
		filename: `${isProduction ? 'build' : 'dev'}/[name].js`,
	},
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


