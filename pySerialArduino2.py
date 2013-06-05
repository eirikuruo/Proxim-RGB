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
    mod = Sine(freq=10, mul=50)
    a = Sine(freq=100, mul=0.1).out()
    V1value=0
    R1value=0
    G1value=0
    B1value=0
    try:
        while 1:
            V1value=0
            R1value=0
            G1value=0
            B1value=0
            for x in range(0,1):
                #
                arduino.write('v1')
                line = arduino.readline().rstrip()
                V1value+=float(line)
                #
                arduino.write('r1')
                line = arduino.readline().rstrip()
                R1value+=float(line)
                #
                arduino.write('g1')
                line = arduino.readline().rstrip()
                G1value+=float(line)
                #
                arduino.write('b1')
                line = arduino.readline().rstrip()
                B1value+=float(line)
                #
            #
            V1val=int(V1value/2)
            R1val=int(R1value/2)
            G1val=int(G1value/2)
            B1val=int(B1value/2)
            #
            #
            y = 10
            for x in range(0, 1000, 10):
                if V1val>x and V1val<y:
                    V1val=y
                if R1val>x and R1val<y:
                    R1val=y
                if G1val>x and G1val<y:
                    G1val=y
                if B1val>x and B1val<y:
                    B1val=y
                y+= 10
            #
            print "V"
            print V1val
            #
            print "R"
            print R1val
            #
            print "G"
            print G1val
            #
            print "B"
            print B1val

            s.setAmp(G1val)
            a.freq = B1val + mod
    except KeyboardInterrupt:
        pass
    arduino.close()
    s.stop()