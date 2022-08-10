echo Enter a number
read a
i=1
f=1
while [ $i -le $a ]
do
f=$( expr $f \* $i )
i=$( expr $i + 1 )
done
echo The factorial of $a is equal to $f