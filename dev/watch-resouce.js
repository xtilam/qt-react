const fs = require('fs')
const path = require('path')
const colors = require('colors')
const nodemon = require('nodemon')

main()

async function main() {
    const qmlReloadFolder = path.join(__dirname, '../ui/_scriptReload.reload')

    watchQML()

    fs.existsSync(qmlReloadFolder) && fs.rmSync(qmlReloadFolder, { recursive: true })
    function watchQML() {
        const mon = nodemon({
            exec: ` `,
            watch: path.join(__dirname, '../ui'),
            ext: '.qml,.js,.css',
            stdout: true,
            stdin: true,
            delay: 10            
        })

        mon.on("restart", function (files) {
            if (!fs.existsSync(qmlReloadFolder)) fs.mkdirSync(qmlReloadFolder)
            console.log('resouce reload'.red) 
        })
    }

}