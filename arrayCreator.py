from random import sample
n = int(input())
i = 0
array = sample(range(1,n*2), n)
string = ""
for i in array:
    string += str(i) + " "
f = open("input.txt","w")
f.write(str(n)+"\n")
f.write(string)
f.close()