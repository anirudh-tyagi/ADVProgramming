const fs = require('fs');

const content = `Name: Anirudh
Course: AP
School: SCDS
University: SaiU`;

fs.writeFile('./2.txt', content, (err) => {
    if (err) {
        console.error('Error creating the file:', err);
    } else {
        console.log('File 2.txt created successfully with the specified content.');
    }
});