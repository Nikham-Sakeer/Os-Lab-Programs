echo -n "Enter the number: "
read n
function ams
{
t=$n
s=0
b=0
while [ $n -gt $b ]
do
r=$((n % 10))
i=$((r * r * r))
s=$((s + i))
n=$((n / 10))
done
if [ $s == $t ]
then
echo "Amstrong number"
else
echo "Not an Armstrong number"
fi
}
result=`ams $n`
echo "$result"
