#include "stdafx.h"
#include "iostream"
#include "Queue.h"
#include "Iterator.h"
#include "locale.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int status = 0, action, elem;
	Queue q1(4), q2(6), q3(5);
	while (status != 9) {
		if (status == 0) {
			std::cout << "1.Перезаполнить очередь\n2.Извлечь элемент из очереди" << std::endl;
			std::cout << "3.Посмотреть головной элемент\n4.Проверка на пустоту" << std::endl;
			std::cout << "5.Сделать пустой\n6.Узнать размер очереди" << std::endl;
			std::cout << "7.Запустить итератор\n8.Добавить элемент в конец очереди" << std::endl;
			std::cout << "9.Выход" << std::endl;
			std::cin >> status;
			system("cls");
		}
		if (status == 1) {
			std::cout << "Какую очередь хотите перезаполнить(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				q1.makeEmpty();
				for (int i = 0; i < q1.getSize(); i++) {
					std::cin >> elem;
					q1.pushElem(elem);
				}
			}
			if (status == 2) {
				q2.makeEmpty();
				for (int i = 0; i < q2.getSize(); i++) {
					std::cin >> elem;
					q2.pushElem(elem);
				}
			}
			if (status == 3) {
				q3.makeEmpty();
				for (int i = 0; i < q3.getSize(); i++) {
					std::cin >> elem;
					q3.pushElem(elem);
				}
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 2) {
			std::cout << "Из какой очереди хотите извлечь элементы(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				std::cout << "Сколько элементов хотите вытащить(Если число превосходит если колличество элементов в очереди, то просто извлекаются все элементы)?" << std::endl;
				std::cin >> action;
				while (action > 0 && !q1.isEmpty()) {
					elem = q1.popElem();
					std::cout << elem << std::endl;
					action--;
				}
			}
			if (status == 2) {
				std::cout << "Сколько элементов хотите вытащить(Если число превосходит если колличество элементов в очереди, то просто извлекаются все элементы)?" << std::endl;
				std::cin >> action;
				while (action > 0 && !q2.isEmpty()) {
					elem = q2.popElem();
					std::cout << elem << std::endl;
					action--;
				}
			}
			if (status == 3) {
				std::cout << "Сколько элементов хотите вытащить(Если число превосходит если колличество элементов в очереди, то просто извлекаются все элементы)?" << std::endl;
				std::cin >> action;
				while (action > 0 && !q3.isEmpty()) {
					elem = q3.popElem();
					std::cout << elem << std::endl;
					action--;
				}
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 3) {
			std::cout << "В какой очереди хотите посмотреть головной элемент?(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				try {//добавлено 02.12
					elem = q1.seeHead();
				}
				catch (QueueIsEmptyException) {
					std::cerr << "Очередь пустая!" << std::endl;
				}
				std::cout << elem << std::endl;
			}
			if (status == 2) {
				try {
					elem = q2.seeHead();
				}
				catch (QueueIsEmptyException) {
					std::cerr << "Очередь пустая!" << std::endl;
				}
				std::cout << elem << std::endl;
			}
			if (status == 3) {
				try {
					elem = q3.seeHead();
				}
				catch (QueueIsEmptyException) {
					std::cerr << "Очередь пустая!" << std::endl;
				}
				std::cout << elem << std::endl;
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 4) {
			std::cout << q1.isEmpty()<< " " << q2.isEmpty()<< " " << q3.isEmpty()<<std::endl;
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 5) {
			std::cout << "Какую очередь хотите сделать пустой(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				q1.makeEmpty();
			}
			if (status == 2) {
				q2.makeEmpty();
			}
			if (status == 3) {
				q3.makeEmpty();
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 6) {
			std::cout << "Размер какой очереди хотите узнать(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				std::cout<<q1.getSize()<<std::endl;
			}
			if (status == 2) {
				std::cout << q2.getSize() << std::endl;
			}
			if (status == 3) {
				std::cout << q3.getSize() << std::endl;
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 7) {
			std::cout << "Для какой очереди запустить итератор(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				Iterator iQ(q1);
				action = 0;
				while (action != 5) {
					if (action == 0) {
						std::cout << "Итератор создан! Что дальше?\n1.Перезапустить\n2.Получить значение\n3.Перейти на следующий\n4.Проверить кончилась ли очередь\n5.Выход" << std::endl;
						std::cin >> action;
						system("cls");
					}
					if (action == 1) {
						iQ.start();
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 2) {
						std::cout << iQ.getValue() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 3) {
						try {//добавлено 02.12
							iQ.next();
						}
						catch (EndOfIteratorException) {
							std::cerr << "Конец очерди" << std::endl;
						}
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 4) {
						std::cout << iQ.finish() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
				}
			}
			if (status == 2) {
				Iterator iQ(q2);
				action = 0;
				while (action != 5) {
					if (action == 0) {
						std::cout << "Итератор создан! Что дальше?\n1.Перезапустить\n2.Получить значение\n3.Перейти на следующий\n4.Проверить кончилась ли очередь\n5.Выход" << std::endl;
						std::cin >> action;
						system("cls");
					}
					if (action == 1) {
						iQ.start();
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 2) {
						std::cout << iQ.getValue() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 3) {
						try {
							iQ.next();
						}
						catch (EndOfIteratorException) {
							std::cerr << "Конец очерди" << std::endl;
						}
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 4) {
						std::cout << iQ.finish() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
				}
			}
			if (status == 3) {
				Iterator iQ(q3);
				action = 0;
				while (action != 5) {
					if (action == 0) {
						std::cout << "Итератор создан! Что дальше?\n1.Перезапустить\n2.Получить значение\n3.Перейти на следующий\n4.Проверить кончилась ли очередь\n5.Выход" << std::endl;
						std::cin >> action;
						system("cls");
					}
					if (action == 1) {
						iQ.start();
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 2) {
						std::cout << iQ.getValue() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 3) {
						try {
							iQ.next();
						}
						catch (EndOfIteratorException) {
							std::cerr << "Конец очерди" << std::endl;
						}
						action = 0;
						system("pause");
						system("cls");
					}
					if (action == 4) {
						std::cout << iQ.finish() << std::endl;
						action = 0;
						system("pause");
						system("cls");
					}
				}
			}
			status = 0;
			system("pause");
			system("cls");
		}
		if (status == 8) {
			std::cout << "В какую очередь добавить элемент(1-3)?" << std::endl;
			std::cin >> status;
			if (status == 1) {
				try {
					std::cout << "Введите элемент" << std::endl;
					std::cin >> action;
					q1.pushElem(action);
				}
				catch (EndOfQueueException) {
					std::cerr << "В очереди нет места!" << std::endl;
				}
			}
			if (status == 2) {
				try {
					std::cout << "Введите элемент" << std::endl;
					std::cin >> action;
					q1.pushElem(action);
				}
				catch (EndOfQueueException) {
					std::cerr << "В очереди нет места!" << std::endl;
				}
				}
			if (status == 3) {
				try {
					std::cout << "Введите элемент" << std::endl;
					std::cin >> action;
					q1.pushElem(action);
				}
				catch (EndOfQueueException) {
					std::cerr << "В очереди нет места!" << std::endl;
				}
			}
				status = 0;
				system("pause");
				system("cls");
		}
	}
	system("pause");
	return 0;
}

