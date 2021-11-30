#include "box.h"
#include "stdafx.h"
#include <iostream>

namespace ContBox {

	Box::Box() {
		this->length = 0;
		this->width = 0;
		this->height = 0;
		this->weight = 0;
		this->value = 0;
	}


	Box::Box(Box const& b) {
		this->length = b.length;
		this->width = b.width;
		this->height = b.height;
		this->weight = b.weight;
		this->value = b.value;
	}


	Box::Box(int l, int wi, int h, double we, double v) {
		if (l < 0 || wi < 0 || h < 0 || we < 0 || v < 0)
			//throw invalid_argument(ERROR_INC_PAR);
			cout << "error";
		this->length = l;
		this->width = wi;
		this->height = h;
		this->weight = we;
		this->value = v;
	}


	int Box::getLength() const {
		return length;
	}


	void Box::setLength(int newLength) {
		if (newLength < 0)
			throw invalid_argument(ERROR_LESS_THAN_ZERO);
		Box::length = newLength;
	}


	int Box::getWidth() const {
		return width;
	}


	void Box::setWidth(int newWidth) {
		if (newWidth < 0)
			throw invalid_argument(ERROR_LESS_THAN_ZERO);
		Box::width = newWidth;
	}


	int Box::getHeight() const {
		return height;
	}


	void Box::setHeight(int newHeight) {
		if (newHeight < 0)
			throw invalid_argument(ERROR_LESS_THAN_ZERO);
		Box::height = newHeight;
	}


	double Box::getWeight() const {
		return weight;
	}


	void Box::setWeight(double newWeight) {
		if (newWeight < 0)
			throw invalid_argument(ERROR_LESS_THAN_ZERO);
		Box::weight = newWeight;
	}


	long Box::getValue() const {
		return value;
	}


	void Box::setValue(long newValue) {
		if (newValue < 0)
			throw invalid_argument(ERROR_LESS_THAN_ZERO);
		Box::value = newValue;
	}

	// Сумма стоимости коробок
	long sumValue(Box * arr, int len) {
		long outValue = 0;
		for (int i = 0; i < len; i++) {
			outValue += arr[i].value;
		}
		return outValue;
	}

	// проверка, что сумма длины, ширины и высоты всех коробок	не превосходит maxV
	bool isLessMaxDim(Box * arr, int len, int maxV) {
		for (int i = 0; i < len; i++) {
			if (arr[i].length +
				arr[i].width +
				arr[i].height > maxV)
				return false;
		}
		return true;
	}

	// поиск максимального веса коробок, объём которых не превышает maxV
	double maxWeightDimLess(Box * arr, int len, int maxV) {
		double maxWeight = 0;
		for (int i = 0; i < len; i++) {
			if (arr[i].length +
				arr[i].width +
				arr[i].height <= maxV)
				if (arr[i].weight > maxWeight)
					maxWeight = arr[i].weight;
		}
		return maxWeight;
	}

	// Компаратор для putEachOther
	bool boxDimComparator(const Box & b1, const Box & b2, bool (*f)(int, int)) {
		return (f(b1.length, b2.length) && f(b1.width, b2.width) && f(b1.height, b2.height)) ||
			(f(b1.length, b2.width) && f(b1.width, b2.height) && f(b1.height, b2.length)) ||
			(f(b1.length, b2.height) && f(b1.width, b2.length) && f(b1.height, b2.width)) ||
			(f(b1.length, b2.length) && f(b1.width, b2.height) && f(b1.height, b2.width)) ||
			(f(b1.length, b2.height) && f(b1.width, b2.width) && f(b1.height, b2.length)) ||
			(f(b1.length, b2.width) && f(b1.width, b2.length) && f(b1.height, b2.height));
	}

	void flip(Box * arr, int i, int j) {
		Box buf(arr[i]);
		arr[i] = arr[j];
		arr[j] = buf;
	}

	bool isLess(int x, int y) {
		return x < y;
	}

	bool isBigger(int x, int y) {
		return x > y;
	}

	bool isEquals(int x, int y) {
		return x == y;
	}

	// Проверка на возможность вложения коробок друг в друга
	Box* putEachOther(Box * arr, int len) {
		Box* finalArr = new Box[len];
		finalArr[0] = Box(arr[0]);
		bool isPut = false;
		for (int i = 1; i < len; i++) {
			for (int j = 0; j <= i; j++) {
				if ((j == 0 || boxDimComparator(arr[i], finalArr[j - 1], isBigger)) &&
					(j == i || boxDimComparator(arr[i], finalArr[j], isLess))) {
					for (int g = i; g > j; g--)
						flip(finalArr, g - 1, g);
					finalArr[j] = Box(arr[i]);
					isPut = true;
					break;
				}
			}
			if (!isPut)
				return nullptr;
			isPut = false;
		}

		return finalArr;
	}


	// Перегрузка оператора ввода
	istream& operator>>(istream & in, Box & box) {
		in >> box.length;
		in >> box.weight;
		in >> box.height;
		in >> box.width;
		in >> box.value;
		return in;
	}


	// Перегрузка оператора вывода
	ostream& operator<<(ostream & out, const Box & box) {
		out << "Box{ dim:(" << box.length << ", " << box.width << ", " << box.height <<
			") weight:" << box.weight << " value:" << box.value << "}";
		return out;
	}


	// Перегрузка оператора сравнения
	bool operator==(const Box & box1, const Box & box2) {
		return box1.length == box2.length &&
			box1.width == box2.width &&
			box1.height == box2.height &&
			box1.value == box2.value &&
			std::abs(box1.weight - box2.weight) < 1E-9;
	}
};