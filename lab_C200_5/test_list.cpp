//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------
#include "List.h"
#define	  stop __asm nop
const char* sep = "------------------------------------\n";

int main()
{
	//
	// 1. Создаем список
	//
	List ls1;
	
	ls1.AddLast(Circle(1, 1, 1));		//добавляем элементы в список
	ls1.AddLast(Circle(5, 5, 5));
	ls1.AddLast(Circle(2, 2, 2));
	ls1.AddLast(Circle(4, 4, 4));
	ls1.AddLast(Circle(2, 2, 2));
	ls1.AddLast(Circle(3, 3, 3));
	std::cout << ls1<<sep;					//выводим список	

	ls1.RemoveFirst(Circle(5,5,5));			// удаляем первый элемент, равный заданному
	std::cout << ls1<<sep; 

	int count=ls1.RemoveAll(Circle(2, 2, 2));     // удаляем все элементы, равные заданному
	stop;
	std::cout << ls1<< sep;	
	////
	//// 2. Приведенный ниже код должен выполняться корректно	
	////
	List ls2 = ls1;
	std::cout << ls2<<sep; 
	List ls3 = ls2;
	std::cout << ls3<<sep; 

	ls2.AddFirst(Circle(2, 2, 2));
	ls2.AddLast(Circle(5, 5, 5));	
	//
	std::cout << ls2<<sep;	
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1<<sep;	
	//
	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;	
	////
	//// 3. Вспоминаем про семантику перемещения	
	////
	List ls4 = std::move(ls2);
	std::cout << ls4<<sep; 
	std::cout << ls2<<sep; 	

	ls3 = std::move(ls4);
	std::cout << ls3<<sep; 
	std::cout << ls4 << sep;
	////
	////4.  Сортировка по возрастанию площади кружка
	////
	std::cout << ls3<<sep;
	ls3.ListSort();
	std::cout << ls3 << sep;
	////
	//// 5. Файловый ввод/вывод
	////
	std::ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();
	//	
    std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	//
	std::cout << ls5<<sep;
	//// 
	//// 6. Дополнительные проверки
	////
	//// ...

	return 0;
}