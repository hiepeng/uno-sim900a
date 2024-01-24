const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");

const port = new SerialPort({
  path: "COM3",
  baudRate: 9600,
});

const parser = new ReadlineParser({ delimiter: "\r\n" })
port.pipe(parser);

// parser.on("data", (data) => {
//   console.log("----", data, "----");
// });

port.on('readable', function () {
  const value = port.read()
  console.log(value.toString())
})
