import math 
import random
from random import randint
from random import randrange

print('Start Learning, to end please enter -1...')

List = []

while True: 
	temp, pm = input('Please enter pair of temperature and PM 2.5: ').split()
	List.append(temp, pm)


with open("output.txt", "a") as file: 
	file.write()