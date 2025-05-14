const fs = require('fs');

fs.rename('./2.txt', './renamed.txt', (err) => {
    if (err) {
        console.error('Error renaming the file:', err);
    } else {
        console.log('File renamed successfully to renamed.txt');
    }
});

