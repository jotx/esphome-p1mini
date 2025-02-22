# P1 Passthrough
It is possible to attach another P1 reading device in case you need to connect a car charger (or a second p1-mini...) etc.

> [!WARNING]
> Currently, the RTS signal of the secondary device is ignored. If you are using the secondary port *and* this is a problem, let me know and I will try to fix it!

### Parts
- Female connector for the RJ12 cable.
- White (or blue) LED
- Resistor 1 - 3 kΩ

![Secondary port pins](../images/secondary_pins.png)

> [!NOTE]  
> Since the RTS signal is currenty ignored, only the TX and GND pins need to be connected. TX -> TX and GND -> Data GND.

The LED will, in addition to providing visual indication that updates are beeing requested on the port, ensure that the voltage on D0 will not get high enough to damage the D1 mini. The LED needs to have a high enough voltage drop for it to work and some colors may not work.

The value of the resistor is not very critical. I have tested with 3 kΩ and anything down to 1 kΩ should be fine.

A p1mini wired up with a secondary port (unpowered) on an experimental board:

![Secondary port](../images/secondary_experimental.png)

### Power to the secondary port

Power to the secondary port needs to be supplied from a secondary source (such as an USB charger). Unless the secondary device is already powered (like a car charger etc) in which case it may not be necessary to supply any power at all to the secondary port.

### Configuration changes
The feature needs to be enabled in the configuration file (yaml). Change `secondary_p1` from `false` to `true`.
```
  secondary_p1: true
```

### Limitations

The RTS signal of the secondaty port is ignored and all data is passed along as soon as it is received, regardless if the secondary device is ready to receive or not.
