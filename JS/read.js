const fs = require('fs');

fs.readFile('./2.txt', 'utf8', (err, data) => {
    if (err) {
        console.error('Error reading the file:', err);
    } else {
        console.log('File content:');
        console.log(data);
    }
});