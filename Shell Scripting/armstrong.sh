num=0
echo "Enter the value to check for Armstrong number"
read n
t=$n
while [ $n -gt 0 ]
do
r=$( expr $n % 10 )
p=$( expr $r \* $r \* $r )
num=$( expr $num + $p )
n=$( expr $n / 10 )
done
if [ $num -eq $t ]
then
echo $t is Armstrong
else
echo $t is not Armstrong
fi