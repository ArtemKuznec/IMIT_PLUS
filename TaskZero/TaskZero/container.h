#pragma once

#include "box.h"
#include <vector>
using namespace std;

namespace ContBox {
	class Container {
	private:
		vector<Box> set; 
		int length;
		int width;
		int height;
		double maxWeight;    
		double curWeight;
		const char* ERROR_INC_PAR = "Неправильно заданы значения параметров при создании контейнера";
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