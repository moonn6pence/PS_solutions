allow=['(',')','[',']']
while(True):
  stack=[True]
  line=input()
  string=[char for char in line if (char in allow)]
  for char in string:
    if(char=='['):stack.append('[')
    elif(char==']' and stack[-1]=='['):stack.pop(-1)
    elif(char=='('):stack.append('(')
    elif(char==')' and stack[-1]=='('):stack.pop(-1)
    else:
      stack.append(False)
      break
  if line=='.':break
  print('yes' if stack==[True] else 'no')