const path = require("path");
const { argv } = require("process");
const config = require("./config");

const mode = argv.findIndex((v) => v === "--mode=production") !== -1
	? {
		mode: 'production',
		watch: false
	}
	: {
		mode: 'development',
		watch: true
	};

module.exports = {
	...mode,
	entry: {
		main: "./ui-src/main"
	},
	// target: ["web", "es5"],
	output: {
		path: path.dirname(config.targetJS),
		filename: '[name].bundle.js',
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
	externals: {
		'react': 'React'
	}
};


