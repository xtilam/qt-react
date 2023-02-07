const path = require("path");
const { argv } = require("process");
const config = require("./config");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

const isProduction = argv.findIndex((v) => v === "--mode=production") !== -1

const mode = isProduction
	? {
		mode: 'production',
		watch: false,
		devtool: false,
	}
	: {
		mode: 'development',
		watch: true,
		devtool: 'inline-source-map',
	};

module.exports = {
	...mode,
	entry: {
		main: "./ui-src/main"
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
			},
			{
				test: /\.(css|s[ac]ss)$/,
				use: [MiniCssExtractPlugin.loader, 'css-loader', 'sass-loader']
			},
		],
	},
	externals: {
		'react': 'React'
	},
	plugins: [new MiniCssExtractPlugin({
		filename: `${isProduction ? 'build' : 'dev'}/[name].css`,
		chunkFilename: "[id].css",
	})]
};


