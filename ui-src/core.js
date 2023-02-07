try {
	window.HTMLIFrameElement = function(){}
	window.setTimeout = function (callback, time = 1) {
		const timer = app.timer()
		timer.interval = time
		timer.singleShot = true
		timer.timeout.connect(this, callback);
		timer.start();
		return timer
	}

	window.setInterval = function (callback, time = 1) {
		const timer = app.timer()
		timer.interval = time
		timer.singleShot = false
		timer.timeout.connect(this, callback);
		timer.start();
		return timer
	}

	window.clearTimeout = function (timer) {
		app.deleteObject(timer)
	}
	au3.execute = function(name, ...args){
		au3.call(name, args)
	}
} catch (error) {
	console.log(error.stack)
}
