echo Enter the number to check whether it is prime or not
read a
i=2
flag=0
b=$( expr $a / 2 )
if [ $a = 1 ]
then 
flag=1
elif [ $a = 2 ]
then 
flag=0
else
while [ $i -le $b ]
do
if [ $( expr $a % $i ) = 0 ]
then
flag=1
break;
fi
i=$( expr $i + 1 )
done
fi
if [ $flag = 0 ]
then 
echo Prime number
else
echo Not a prime number
fi