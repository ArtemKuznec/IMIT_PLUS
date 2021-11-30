#pragma once
#include <iostream>

using namespace std;
namespace ContBox {

	struct BoxStruct {
		int length = 0;           // длина
		int width = 0;            // ширина
		int height = 0;           // высота
		double weight = 0.0;      // вес
		double value = 0;         // цена (в коп.)

		BoxStruct() {
			BoxStruct(0, 0, 0, 0, 0);
		}

		BoxStruct(BoxStruct const& box) {
			BoxStruct(box.length, box.width, box.height, box.weight, box.value);
		}

		BoxStruct(int l, int wi, int h, double we, double v) {
			length = l;
			width = wi;
			height = h;
			weight = we;
			value = v;
		}
	};

	class Box {
	private:
		int length = 0;           // длина
		int width = 0;            // ширина
		int height = 0;           // высота
		double weight = 0.0;      // вес
		double value = 0;         // цена (в коп.)

		const char* ERROR_LESS_THAN_ZERO = "Значение не может быть меньше нуля";
		const char* ERROR_INC_PAR = "Неправильно заданы значения параметров";

	public:
		Box();
		Box(Box const& b);
		Box(int l, int wi, int h, double we, double v);
		int getLength() const;
		void setLength(int length);
		int getWidth() const;
		void setWidth(int width);
		int getHeight() const;
		void setHeight(int height);
		double getWeight() const;
		void setWeight(double weight);
		long getValue() const;
		void setValue(long value);
		friend long sumValue(Box* arr, int len);  // сумма стоимости коробок
		friend bool isLessMaxDim(Box* arr, int len, int maxV);  // проверка, что сумма длины, ширины и высоты всех коробок не превосходит maxV
		friend double maxWeightDimLess(Box* arr, int len, int maxV);  // поиск максимального веса коробок, объём которых не превышает maxV
		friend bool boxDimComparator(const Box& b1, const Box& b2, bool (*f)(int, int)); // Компаратор для putEachOther
		friend istream& operator>>(istream& in, Box& box); // Перегрузка оператора ввода
		friend ostream& operator<<(ostream& out, const Box& box); // Перегрузка оператора вывода
		friend bool operator==(const Box& b1, const Box& b2); // Перегрузка оператора сравнения
	};

	Box* putEachOther(Box* arr, int len);  // Проверка на возможность вложения коробок друг в друга
}