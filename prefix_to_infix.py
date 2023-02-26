prefix= '-*+ABC*-DE+FG'
operator= ['+','-','*','/']

#to perform required operations
stack= list()

#traversing from right to left
for char in prefix[::-1]:
    #if operand
    if char not in operator:
        stack.insert(0,char)
        print(stack)
    #if operator
    else:
        #pop two values
        pop1= stack.pop(0)
        pop2= stack.pop(0)
        
        #combine the two expressions
        new_= '('+pop1+char+pop2+')'
        
        stack.insert(0,new_)
        print(stack)
        
print(stack)

#O/P:
# ['(((A+B)*C)-((D-E)*(F+G)))']