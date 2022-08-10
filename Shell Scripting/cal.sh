p=1
q=1
while [ $p -eq 1 ]
do
if [ $q -eq 1 ]
then
echo Enter the value of a
read a
echo Enter the value of b
read b
fi
echo Operation Menu
echo 1.Addition
echo 2.Subtraction
echo 3.Multiplication
echo 4.Division
echo 5.Modulus
echo Enter the operation you want to perform
read o
s=$( expr $a + $b )
d=$( expr $a - $b )
m=$( expr $a \* $b )
q=$( expr $a / $b )
mo=$( expr $a % $b )
case $o in
1) echo "Sum= $s" ;;
2) echo "Difference= $d" ;;
3) echo "Product= $m" ;;
4) echo "Quotient= $q" ;;
5) echo "Modulus= $mo" ;;
*) echo "Invalid Option" ;;
esac
echo "Do you want to continue? 1.Yes 2.No"
read p
if [ $p -eq 1 ]
then
echo Do you want to change the inputs?
echo 1.Yes 2.No
read q
else
exit
fi
done