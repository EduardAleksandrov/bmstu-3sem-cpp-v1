
run1.one:
	g++ -std=c++17 ./1.one.cpp ./1.one_linkfile.cpp -o ./build/1.one -g && ./build/1.one
# -g подключаем gdb
# препроцессор
run1.one.one:
	g++ -E ./1.one.cpp -o build/1.one.i
# компилятор - в ассемблер
run1.one.two:
	g++ -std=c++17 -S ./build/1.one.i -o ./build/1.one.s
# файл.сpp в объектный код
run1.one.three:
	g++ -c -std=c++17 ./1.one.cpp -o ./build/1.one.o
# объектный код в исполняемый
run1.one.four:
	g++ ./build/1.one.o -o ./build/1.one && ./build/1.one
