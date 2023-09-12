const readline = require('readline');

function caesarCipherEncrypt(message, key) {
  let encryptedMessage = '';
  for (let i = 0; i < message.length; i++) {
    const char = message[i];
    if (char.match(/[a-z]/i)) {
      const code = message.charCodeAt(i);
      let shift = key % 26;
      if (char.match(/[a-z]/)) {
        if (code + shift > 122) {
          encryptedMessage += String.fromCharCode(code + shift - 26);
        } else {
          encryptedMessage += String.fromCharCode(code + shift);
        }
      } else if (char.match(/[A-Z]/)) {
        if (code + shift > 90) {
          encryptedMessage += String.fromCharCode(code + shift - 26);
        } else {
          encryptedMessage += String.fromCharCode(code + shift);
        }
      }
    } else {
      encryptedMessage += char;
    }
  }
  return encryptedMessage;
}

function caesarCipherDecrypt(encryptedMessage, key) {
  return caesarCipherEncrypt(encryptedMessage, -key);
}

function main() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question("Enter your message: ", (userMessage) => {
    rl.question("Enter the shift key (an integer): ", (data) => {
      data = parseInt(data);

      if (isNaN(data)) {
        console.log("Invalid shift key. Please enter a valid integer.");
        rl.close();
        return;
      }

      const encryptedMessage = caesarCipherEncrypt(userMessage, data);
      const decryptedMessage = caesarCipherDecrypt(encryptedMessage, data);

      console.log(`
        Original Message: ${userMessage}
        Encrypted Message: ${encryptedMessage}
        Decrypted Message: ${decryptedMessage}
      `);

      rl.close();
    });
  });
}

main();
