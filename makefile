
run1.one:
	g++ -std=c++17 ./1.one.cpp -o ./build/1.one -g && ./build/1.one
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





run2.two:
	g++ -std=c++17 ./2.two.cpp ./2.two_linkfile.cpp -o ./build/2.two -g && ./build/2.two

run3.three:
	g++ -std=c++17 ./3.abstrackClass.cpp -o ./build/3.abstrackClass -g && ./build/3.abstrackClass

run4.set:
	g++ -std=c++17 ./4.set.cpp -o ./build/4.set -g && ./build/4.set

run5.obj_pointers:
	g++ -std=c++17 ./5.obj_pointers.cpp -o ./build/5.obj_pointers -g && ./build/5.obj_pointers

run6.wchar:
	g++ -std=c++17 ./6.wchar.cpp -o ./build/6.wchar -g && ./build/6.wchar

run7.str:
	g++ -std=c++17 ./7.str.cpp -o ./build/7.str -g && ./build/7.str

run8.cin:
	g++ -std=c++17 ./8.cin.cpp -o ./build/8.cin -g && ./build/8.cin

run_9.class_stack:
	g++ -std=c++17 ./9.class_stack.cpp -o ./build/9.class_stack -g && ./build/9.class_stack
run_9.1.class_stack:
	g++ -std=c++17 ./9.1.class_stack.cpp ./9.1.stack_funcs.cpp -o ./build/9.1.class_stack -g && ./build/9.1.class_stack



run_10.move:
	g++ -std=c++17 ./10.move.cpp -o ./build/10.move -g && ./build/10.move
run_11.class_prototype:
	g++ -std=c++17 ./11.class_prototype.cpp -o ./build/11.class_prototype -g && ./build/11.class_prototype

run_12.virtual:
	g++ -std=c++17 ./12.virtual.cpp -o ./build/12.virtual -g && ./build/12.virtual







