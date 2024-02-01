
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

run_13.cout:
	g++ -std=c++17 ./13.cout.cpp -o ./build/13.cout -g && ./build/13.cout

run_14.events:
	g++ -std=c++17 ./14.events.cpp -o ./build/14.events -g && ./build/14.events

run_15.cast:
	g++ -std=c++17 ./15.cast.cpp -o ./build/15.cast -g && ./build/15.cast

run_16.throw:
	g++ -std=c++17 ./16.throw.cpp -o ./build/16.throw -g && ./build/16.throw

run_17.namespaces:
	g++ -std=c++17 ./17.namespaces.cpp ./17.ns.cpp -o ./build/17.namespaces -g && ./build/17.namespaces


run_18.class_one:
	g++ -std=c++17 ./18.class_one.cpp -o ./build/18.class_one -g && ./build/18.class_one

run_19.destructor:
	g++ -std=c++17 ./19.destructor.cpp -o ./build/19.destructor -g && ./build/19.destructor

# 2a - standart 2020 year
run_20.operator:
	g++ -std=c++2a ./20.operator.cpp -o ./build/20.operator -g && ./build/20.operator  

run_21.templates_v1:
	g++ -std=c++17 ./21.templates_v1.cpp -o ./build/21.templates_v1 -g && ./build/21.templates_v1







