/*


������� ��������

������� � �������� ����� A ������ � B ������. ����������, ������� ������ � ������ ����� ��������� �� N ��������.


������ ������� ������

��������� �������� �� ���� ��� �����: A, B, N - �����, �������������, �� ��������� 10000.

������ �������� ������

��������� ������ ������� ��� ����� ����� ������: ��������� ������� � ������ � ��������.

Sample Input 1:

10
15
2

Sample Output 1:

20 30

Sample Input 2:

2
50
4

Sample Output 2:

10 0

*/

#include <iostream>

using namespace std;

int main() {
	int a, b, c, z, x;
	cin >> a >> b >> c;
	z = (b * c) % 100;
	x = ((a * c) + ((b * c) / 100));
	cout << x << " " << z;
	return 0;
}