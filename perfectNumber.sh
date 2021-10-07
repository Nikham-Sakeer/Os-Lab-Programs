# !/bin/bash

echo "Enter a number"

# reading input from user 
read no  

# initializing the value of i
i=1

ans=0


# check if the value of left operand is less 
# than or equal to the value of right operand
# if yes, then the condition becomes true
while [ $i -le $((no / 2)) ]   

do
        # Checks if the value of two operands are
        # equal or not; if yes, then the condition
        # becomes true
        if [[ $((no%i)) -eq 0  ]] 
        then

                ans=$((ans + i))

fi

i = $((i + 1))

done

# Checks if the value of two operands are equal 
# or not; if yes, then the condition becomes true
if [ $no -eq $ans ]  
then
        # printing output
        echo "$no is perfect" 
        else
        
        # printing output
        echo "$no is NOT perfect" 
fi
