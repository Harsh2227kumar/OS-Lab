read n

i=1
sum=0

while [ $i -le $n ]
do

	sum=$((sum + i))
	((i++))

done

echo $sum
