tail +10 file.txt | head -1
awk 'NR==10' file.txt 
sed -n '10p' file.txt