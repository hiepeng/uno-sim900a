const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");

const port = new SerialPort({
  path: "COM9",
  baudRate: 115200,
});

port.on('open', function () {
  port.write('AT')
  setTimeout(() => {
    port.write('AT+CSCS="GSM"');
    setTimeout(() => {
      port.write('AT+CIMI');
      setTimeout(() => {
        port.write('AT+CNMI=2,2,0,0,0');
        setTimeout(() => {
          port.write('AT+CMGF=1');
        }, 2000)
      }, 2000)
    }, 2000)
  }, 2000)
});

port.on('data', function (data) {
  console.log('Received: ', data.toString());
});

// const parser = new ReadlineParser({ delimiter: "\r\n" })
// port.pipe(parser);

// port.on('readable', function () {
//   const value = port.read()
//   console.log(convertAsciiToString(value.toString()))
// })

// function convertAsciiToString(hexString) {
//   var hexArray = hexString.match(/.{1,4}/g); // Chia chuỗi thành các cặp số hex
//     var asciiString = '';
//     for (var i = 0; i < hexArray.length; i++) {
//         asciiString += String.fromCharCode(parseInt(hexArray[i], 16)); // Chuyển đổi từ mã hex sang ký tự ASCII
//     }
//     return asciiString;
// }