const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");

const port = new SerialPort({
  path: "COM3",
  baudRate: 9600,
});

const parser = new ReadlineParser({ delimiter: "\r\n" })
port.pipe(parser);

let i = 0;


parser.on("data", (data) => {
  i = i + 1
  console.log(i+": ",data);
});

// port.on('readable', function () {
//   const value = port.read()
//   console.log(value.toString())
// })
