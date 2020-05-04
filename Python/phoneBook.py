import sys

PhoneBookDict = {}

choice = sys.argv[0];

#Name = input('Name: ')
#Number = input('Phone number: ')
if sys.argv[1] == 'add':
  Name = sys.argv[2]
  Number = sys.argv[3]
  PhoneBookDict[Name] = Number
  with open('phoneBook.txt', 'a') as file:
    file.write(str( Name +" " + PhoneBookDict[Name] + '\n' ))
elif sys.argv[1] == 'search': 
  SearchName = sys.argv[2]
  with open('phoneBook.txt', 'r') as file:
    lines = file.readlines()
    #print(lines)
    for line in lines:
      if line != '\n':
        temp = line.split()
        #print(temp)
        if(SearchName == temp[0]):
          print("the Phone Number is:  " + temp[1])