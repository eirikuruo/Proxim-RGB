#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Eirikur
#
# Created:     05.06.2013
# Copyright:   (c) Eirikur 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import time
import serial
from pyo import *

def main():
    pass

if __name__ == '__main__':
    main()
    arduino = serial.Serial(
        "COM7",
        9600,
        serial.EIGHTBITS,
        serial.PARITY_NONE,
        serial.STOPBITS_ONE)
    time.sleep(2)
    s = Server().boot()
    s.start()
    a = Sine(freq=100, mul=0.1).out()
    try:
        while 1:
            arduino.write('v1')
            line = arduino.readline().rstrip()
            print "V"
            print line
            ivalue2=int(float(line))

            arduino.write('r1')
            line = arduino.readline().rstrip()
            print "R"
            print line
            ivalue=int(float(line))
            arduino.write('g1')
            line = arduino.readline().rstrip()
            print "G"
            print line
            ivalue=int(float(line))
            arduino.write('b1')
            line = arduino.readline().rstrip()
            print "B"
            print line
            ivalue=int(float(line))
            #mod = Sine(freq=6, mul=50)
            s.setAmp(ivalue)
            a.freq = ivalue2
    except KeyboardInterrupt:
        pass
    arduino.close()
    s.stop()