#include "container.h"
#include "stdafx.h"

namespace ContBox {
	Container::Container(int length, int width, int height, double maxWeight) :
		length(length), width(width), height(height), maxWeight(maxWeight) {
		curWeight = 0;
	}

	unsigned int Container::getCount() {
		return set.size();
	}

	double Container::getWeight() const {
		return curWeight;
	}

	Box Container::at(int index) {
		return Box(set.at(index));
	}

	void Container::add(Box newBox) {
		if (newBox.getWeight() + curWeight > maxWeight)
			throw std::invalid_argument(ERROR_ADD);
		set.emplace_back(newBox);
		curWeight += newBox.getWeight();
	}

	void Container::del(int index) {
		curWeight -= this->operator[](index).getWeight();
		set.erase(set.begin() + index);
	}

	double Container::sum() {
		int count = 0;
		for (int i = 0; i < set.size() ; i++) {
			count = count + set[i].getValue();
		}
		return count;
	}


	std::istream& operator>>(std::istream & in, Container & cnt) {
		in >> cnt.length;
		in >> cnt.height;
		in >> cnt.width;
		in >> cnt.maxWeight;
		return in;
	}

	std::ostream& operator<<(std::ostream & out, const Container & cnt) {
		out << "Container{" << endl << " dim:(" << cnt.length << ", "  << cnt.width << ", "  << cnt.height <<
			") weight:" << cnt.curWeight << endl << " maxWeight:" << cnt.maxWeight << endl << " inside:( " << endl;
		for (int i = 0; i < cnt.set.size() - 1; i++)
			out << cnt.set[i] << ", " << endl;
		out << cnt.set[cnt.set.size() - 1];
		out << ")}";
		return out;
	}

	Box& Container::operator[](int index) {
		if (index < 0 || index >= set.size())
			throw std::invalid_argument(ERROR_INDEX);
		return set[index];
	}

	Container::Container() {
		length = 0;
		height = 0;
		width = 0;
		maxWeight = 0;
		curWeight = 0;
	}
}