i=1
t1=0
t2=0
t3=0
while [ $i -le 3 ]
do
echo Student $i
echo " Enter marks for subject 1 "
read s1
echo " Enter marks for subject 2 "
read s2
echo " Enter marks for subject 3 "
read s3
if [ $i -eq 1 ]
then
t1=$( expr $t1 + $s1 + $s2 + $s3 )
elif [ $i -eq 2 ]
then
t2=$( expr $t2 + $s1 + $s2 + $s3 )
else
t3=$( expr $t3 + $s1 + $s2 + $s3 )
fi
i=$( expr $i + 1 )
done
t1=$( expr $t1 / 3 )
t2=$( expr $t2 / 3 )
t3=$( expr $t3 / 3 )
echo " Average Marks for Student 1 = $t1"
echo " Average Marks for Student 2 = $t2"
echo " Average Marks for Student 3 = $t3"