import sys
import re


def main():
  # +++your code here+++
  arg_sys = sys.argv[1:]

  for arg in arg_sys:
    TextSectionSize=0
    BssSectionSize=0
    RoDataSectionSize=0
    DataSectionSize=0
  
    extractedTextSection = []
    extractedBssSection      = []
    extractedRoDataSection   = []
    extractedDataSection     = []
    file = open('Project_Memory_Map_File.map','r')
    file.seek(0)
    extractedTextSection  = re.findall(r'\w+\W(\w+)\s+(\.text)\s+'+arg+'\w+\.o',file.read())
    file.seek(0)
    extractedBssSection     = re.findall(r'\w+\W(\w+)\s+(\.bss)\s+'+arg+'\w+\.o',file.read())
    file.seek(0)
    extractedRoDataSection = re.findall(r'\w+\W(\w+)\s+(\.rodata)\s+'+arg+'\w+\.o',file.read())
    file.seek(0)
    extractedDataSection    = re.findall(r'\w+\W(\w+)\s+(\.data)\s+'+arg+'\w+\.o',file.read())

    print(extractedTextSection)
    for tuple in extractedTextSection:
      TextSectionSize+=int(tuple[0],16)
    print(TextSectionSize)
    
    print(extractedBssSection)
    for tuple in extractedBssSection:
      BssSectionSize+=int(tuple[0],16)
    print(BssSectionSize)
    
    print(extractedRoDataSection)
    for tuple in extractedRoDataSection:
      RoDataSectionSize+=int(tuple[0],16)
    print(RoDataSectionSize)
    
    print(extractedDataSection)
    for tuple in extractedDataSection:
      DataSectionSize+=int(tuple[0],16)
    print(DataSectionSize)
    
  
    RomSize = TextSectionSize + RoDataSectionSize
    RamSize = BssSectionSize + DataSectionSize
    if RomSize + RamSize != 0:
      with open(arg+'_info.txt', 'a') as file:
        file.write(str(str( '\n'+"                  ***** "+arg +" component Info *****"+'\n\n' )))
        file.write(str(str( "Size of .text   section in " +arg+ " component is = "+  str(TextSectionSize  ) +" Bytes"+'\n' )))
        file.write(str(str( "Size of .rodata   section in " +arg+ " component is = "+str(RoDataSectionSize) +" Bytes"+'\n\n' )))
        file.write(str(str( "Size of .data   section in " +arg+ " component is = "+  str(DataSectionSize  ) +" Bytes"+'\n' )))
        file.write(str(str( "Size of .bss   section in " +arg+ " component is = "+   str(BssSectionSize   )+" Bytes"+'\n\n' )))
        file.write(str(str( "-> Size of ROM in " +arg+ " component is = "+          str(RomSize          )+" Bytes"+'\n' )))
        file.write(str(str( "-> Size of RAM in " +arg+ " component is = "+          str(RamSize          ) +" Bytes"+'\n' )))
    
  file.close()

    
'''
There is something missing Here :)
'''
if __name__ == '__main__':
  main()
