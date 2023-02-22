const fs = require('fs')
const path = require('path')
const colors = require('colors')
const { spawnSync, spawn, execSync } = require('child_process')
const nodemon = require('nodemon')
const config = require('../config')

main()

async function main() {
    let au3Process;
    let isStartApp = false

    watcherFiles()
    spawnExec('node', [path.join(__dirname, 'watch-resouce.js')])
    watchAU3()

    function watchAU3() {
        runAu3()
        const mon = nodemon({
            exec: ` `,
            watch: path.join(config.mainAhkPath, '..'),
            ext: '.ahk',
            stdout: true,
            stdin: true
        })
        mon.on("restart", function (files) {
            runAu3()
        })
    }

    function watcherFiles() {
        for (const [source, target] of config.watchers) {
            watchOtherBuild(source, target)
        }
    }

    function runAu3() {
        if (isStartApp) return
        isStartApp = true

        setTimeout(() => {
            if (au3Process) {
                try {
                    execSync(`taskkill /f /pid ${au3Process.pid}`)
                } catch (error) { }
                console.log('=> restart au3 app\n'.green.bold)
            } else {
                console.log('=> start au3 app\n'.green.bold)
            }
            
            setTimeout(()=>{
				let currentProcess = spawnExec(path.join(config.ahkPath, 'AutoHotkey64.exe'), [
					`${config.mainAhkPath}`,
				],
					{
						env: config.au3DevEnv,
					}
				)
	
				currentProcess.on('exit', (exitCode) => {
					if (au3Process !== currentProcess) return
					console.log('=> exit au3 app\n'.red.bold)
				})
	
				au3Process = currentProcess
	
				isStartApp = false
			}, 200)
        },)
    }

    async function watchOtherBuild(source, dest, timeCopy = 3000) {

        const dirDest = path.dirname(dest)
        let oldTimeStartCopy = 0

        try {
            await copyFile()
        } catch (error) {
            console.log(`copy error[ ${error} ]: ${source} => ${dest}`)
        }

        fs.watchFile(source, { interval: 100 }, (cur, pre) => {
            console.log('file change', source)
            if (au3Process) {
                try {
                    execSync(`taskkill /f /pid ${au3Process.pid}`)
                } catch (error) { }
                console.log('=> restart au3 app\n'.green.bold)
            } else {
                console.log('=> start au3 app\n'.green.bold)
            }
            if (cur.size) return copyFile().then(runAu3).catch(err => console.log(`copy error[ ${err} ]: ${source} => ${dest}`))
        })

        async function copyFile(checkExists = true) {
            return new Promise((resolve, reject) => {
                if (checkExists) {
                    if (!fs.existsSync(source)) return resolve()
                } else if (oldTimeStartCopy) {
                    return resolve()
                }


                if (!fs.existsSync(dirDest)) fs.mkdirSync(dirDest, { recursive: true })
                if (!fs.lstatSync(dirDest).isDirectory()) {
                    fs.rmSync(dirDest)
                    fs.mkdirSync(dirDest, { recursive: true })
                }
                oldTimeStartCopy = new Date().getTime()

                const _interval = setInterval(() => {
                    if (!checkValidTime()) {
                        clearTimeout(_interval)
                        console.log('checkValidTime', checkValidTime())
                        reject('timeout error')
                    }

                    try {
                        fs.copyFileSync(source, dest)
                        clearTimeout(_interval)
                        resolve()
                    } catch (error) { }
                }, 300)

                function checkValidTime() {
                    return (new Date().getTime() - oldTimeStartCopy) < timeCopy
                }
            })
        }
    }
}

function spawnExec(...args) {
    const child = spawn.apply(undefined, [...args])
    child.stdout.on('data', (d) => {
        process.stdout.write(d.toString())
    })
    child.stderr.on('data', (d) => {
        process.stderr.write(d.toString())
    })
    return child
}