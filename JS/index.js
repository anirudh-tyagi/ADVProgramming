const fs = require('fs');
fs.writeFile('./1.txt', 'SaiU', () => {
    console.log('File created');
})
fs.appendFile('./1.txt', '\n Chennai', () => {
    console.log('File appended');
}
)
