import os
import shutil

os.chdir('G:\ITI\COTS')
print("Welcome to Drivers Creater\n")
layer= input("pleaase enter Layer Name:  ")
dirList = os.listdir()
for element in dirList:
  if element.split('-')[len(element.split('-'))-1] == layer:
    layerNum = element.split('-')[0]
os.chdir('G:\ITI\COTS\\' +layerNum+ '-' +layer)
if layer == "MCAL"
  mc = input("pleaase enter MciroController Name:  ")
  dirList = os.listdir()
  for element in dirList:
    if element.split('-')[len(element.split('-'))-1] == mc:
      mcNum = element.split('-')[0]
  os.chdir('./'+mcNum+ '-' +mc)

num = int( os.listdir()[-1].split('-')[0] ) +1

name = input("pleaase enter Driver Name:  ")

os.mkdir(str('0'+str(num)+'-'+name + '_Driver'))
os.chdir(str('0'+str(num)+'-'+name + '_Driver'))
open(str(name + '_Interface.h'),'w')
open(str(name + '_Config.h'),'w')
open(str(name + '_Program.c'),'w')
open(str(name + '_Private.h'),'w')
open(str(name + '_Register.h'),'w')
#os.chdir('../')

file = open(str(name + '_Program.c'),'a')
dirList = os.listdir(str('../'+'0'+str(num)+'-'+name+'_Driver'))
print(dirList)
for i in dirList:
  if i[-1:] == 'h':
    file.write(str('#include '+ '"'+i +'"'+'\n'))
file.write(str('void '+ name+'_Init(){}\n'))
file.close()

file = open(str(name + '_Interface.h'),'a')
file.write(str('void '+ name+'_Init()\n'))
file.close()

os.chdir('../')