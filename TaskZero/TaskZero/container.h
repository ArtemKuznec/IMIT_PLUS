#pragma once

#include "box.h"
#include <vector>
using namespace std;

namespace ContBox {
	class Container {
	private:
		vector<Box> set; // массив коробок
		int length;
		int width;
		int height;
		double maxWeight; // Максимально допустимый вес
		double curWeight; // Текущий вес
		const char* ERROR_ADD = "Ошибка при добавлении коробки";
		const char* ERROR_INDEX = "Отсутствует коробка с данным индексом";

	public:
		Container(int length, int width, int height, double maxWeight);
		unsigned int getCount();
		double getWeight() const;
		double sum();
		Box at(int index);
		void add(Box newBox);
		void del(int index);
		friend istream& operator>>(istream& in, Container& cnt);
		friend ostream& operator<<(ostream& out, const Container& cnt);
		Box& operator[](int index); // Перегрузка индексации
		Container();
	};
}