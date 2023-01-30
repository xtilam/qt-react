try {
    var name = 14;
	this.setTimeout = function(callback, time = 1){
		const timer = app.timer()
		console.log(timer)
		timer.interval = time
		timer.singleShot = true
		timer.timeout.connect(this, callback);
		timer.start();
		return timer
	}
	
	this.setInterval = function(callback, time = 1){
		const timer = app.timer()
		timer.interval = time
		timer.singleShot = false
		timer.timeout.connect(this, callback);
		timer.start();
		return timer
	}
	
	this.clearTimeout  = function(timer){
		app.deleteObject(timer)
	}
	
	var window = this
	let mainCount = 1
	let count = 0
	let interval = setInterval(()=>{
		for(let i = 0; i < 5000; i++){

		}
		if(++count < 1000) return
		clearTimeout(interval)
		count = 0
		console.log('running: ', ++mainCount)
	}, 1)
} catch (error) {
	console.log(error.stack)	
}
// console.log(QTimer)
