grafica.png grafica2.png: data.txt data2.txt
	python grafica.py
	python grafica2.py
data.txt: a.out
	./a.out > data.txt
data2.txt : nolineal
	./nolineal > data2.txt
a.out: 
	c++ lineal.cpp
nolineal:
	c++ nolineal.cpp -o nolineal
clean:
	rm grafica.png data.txt a.out nolineal data2.txt grafica2.png
