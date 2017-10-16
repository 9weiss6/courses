/*
����������� ����

����������� ���� ���������� ����� � ������� h:mm:ss (�� 0:00:00 �� 23:59:59), �� ���� ������� ������������ ���������� �����, ����� ����������� ���������� ���������� �����, ����� ����������� ���������� ���������� ������. ���������� ����� � ������ ��� ������������� ����������� �� ����������� ����� ������.

� ������ ����� ������ N ������. ��������, ��� ������� ����.

������ ������� ������

�� ���� ������ ���������� ����� N, �� ������������� 107

(10000000).

������ �������� ������

�������� ����� �� ������.

Sample Input 1:

3602

Sample Output 1:

1:00:02

Sample Input 2:

129700

Sample Output 2:

12:01:40
*/

#include <iostream>

using namespace std;

int main() {
	int t, H, M, m, S, s;
	cin >> t;
	H = t / 3600 % 24;
	M = (t % 3600) / 60 / 10;
	m = (t % 3600) / 60 % 10;
	S = ((t % 3600) % 60) / 10;
	s = ((t % 3600) % 60) % 10;
	cout << H << ":" << M << m << ":" << S << s;
	return 0;
}