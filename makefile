run: ./picmaker
	./picmaker

picmaker: picmaker.c
	gcc -o picmaker picmaker.c

clean:
	rm ./picmaker
	rm image.ppm
