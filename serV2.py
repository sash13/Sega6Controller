import os
import serial
import virtkey
import subprocess

ser = serial.Serial('/dev/ttyUSB0')

old={'z':0, 'x':0, 'c':0, 'v':0, 'b':0, 'n':0,'1':0, 'KP_Enter':0, 'Up':0, 'Down':0, 'Left':0, 'Right':0}

def click(old_bit, new_bit, key):
	if old_bit is 1 and new_bit is 0:
		press_os(key, 0)
	elif old_bit is 0 and new_bit is 1:
		press_os(key, 1)

def click_l(old_bit, new_bit, key):
        if old_bit is 0 and new_bit is 1:
		subprocess.Popen(["xdotool", 'key', key])

def check(pos,bit):
        if pos is 4:
                try:
                        click(old['z'], bit, 'z')

                except:
                        pass
        elif pos is 5:
                try:
                        click(old['x'], bit, 'x')
                except:
                        pass
        elif pos is 6:
                try:
                	click(old['c'], bit, 'c')
                except:
                        pass
        elif pos is 7:
                try:
                        click(old['KP_Enter'], bit, 'KP_Enter')
                except:
                        pass
        elif pos is 0:
                try:
                        click(old['Up'], bit, 'Up')
                except:
                        pass
        elif pos is 1:
                try:
                        click(old['Down'], bit, 'Down')
                except:
                        pass
        elif pos is 2:
                try:
                        click(old['Left'], bit, 'Left')
                except:
                        pass
        elif pos is 3:
                try:
                        click(old['Right'], bit, 'Right')
                except:
                        pass
        elif pos is 8:
                try:
                        click(old['v'], bit, 'v')

                except:
                        pass
        elif pos is 9:
                try:
                        click(old['b'], bit, 'b')
                except:
                        pass
        elif pos is 10:
                try:
                	click(old['n'], bit, 'n')
                except:
                        pass
        elif pos is 11:
                try:
                        click(old['1'], bit, '1')
                except:
                        pass
        else:
                pass

def func(num, pos):
        return (num & (1 << pos)) >> pos


def press_os(key, byte):
 if byte:
  subprocess.Popen(["xdotool", 'keydown', key])
  old[key] = 1
  '''print 'press '+key'''
 else:
  subprocess.Popen(["xdotool", 'keyup', key])
  old[key] =0
  '''print 'up ' + key'''

keyEmu = virtkey.virtkey()

temp=[0]*12

while 1:
 s="".join(ser.readline().splitlines())
 try:
  n=int(s)
  for pos in xrange(len(temp)):
   check(pos,func(n, pos))
 except:
  pass 
