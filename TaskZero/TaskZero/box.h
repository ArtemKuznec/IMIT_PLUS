#pragma once
#include <iostream>

using namespace std;
namespace ContBox {

	struct BoxStruct {
		int length = 0;           // �����
		int width = 0;            // ������
		int height = 0;           // ������
		double weight = 0.0;      // ���
		double value = 0;         // ���� (� ���.)

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
		int length = 0;           // �����
		int width = 0;            // ������
		int height = 0;           // ������
		double weight = 0.0;      // ���
		double value = 0;         // ���� (� ���.)

		const char* ERROR_LESS_THAN_ZERO = "�������� �� ����� ���� ������ ����";
		const char* ERROR_INC_PAR = "����������� ������ �������� ����������";

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
		friend long sumValue(Box* arr, int len);  // ����� ��������� �������
		friend bool isLessMaxDim(Box* arr, int len, int maxV);  // ��������, ��� ����� �����, ������ � ������ ���� ������� �� ����������� maxV
		friend double maxWeightDimLess(Box* arr, int len, int maxV);  // ����� ������������� ���� �������, ����� ������� �� ��������� maxV
		friend bool boxDimComparator(const Box& b1, const Box& b2, bool (*f)(int, int)); // ���������� ��� putEachOther
		friend istream& operator>>(istream& in, Box& box); // ���������� ��������� �����
		friend ostream& operator<<(ostream& out, const Box& box); // ���������� ��������� ������
		friend bool operator==(const Box& b1, const Box& b2); // ���������� ��������� ���������
	};

	Box* putEachOther(Box* arr, int len);  // �������� �� ����������� �������� ������� ���� � �����
}