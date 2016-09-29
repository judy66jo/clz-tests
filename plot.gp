reset
set ylabel 'Time(sec)'
set xlabel 'x'
set style data points
set title 'clz time analysis'
set datafile separator ","
set terminal png enhanced font 'Verdana,10' size 1000,800
set output 'clz_time.png'

plot [0:][0:]'result.csv' using 1:2 title 'recursive', \
'' using 1:3 title 'iteration', \
'' using 1:4 title 'binary search', \
'' using 1:5 title 'byte-shift'
