#include <iostream>

class Test
{
public:
	//Test();
	//Test(int i) : val(i) {};		// �̷��� �ϸ� �ȵ�. �ʱ�ȭ�� �ǳ� �̻��� �� ���.
	Test(int & i) : val(i) {};		// reference member�� �ʱ�ȭ �ÿ� �̷���.
	
public:
	int & val;
private:
};

int main()
{
	int value = 10;

	//Test();	// Test() ���� ���� ��: "error C2512 'Test': ����� �� �ִ� ������ �⺻ �����ڰ� �����ϴ�."
				// Test() ���� �� ��: "error LNK2019: (..) �ܺ� ��ȣ���� Ȯ������ ���߽��ϴ�."
				
				// Test() �� ��� default ctor�� �θ����� ������ ������!
	
	int a = 10;
	Test t = Test(a);
	std::cout << t.val << std::endl;

	std::cout << "Program ends." << std::endl;

	return 0;
}