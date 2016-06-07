#include <iostream>

class Test
{
public:
	//Test();
	//Test(int i) : val(i) {};		// 이렇게 하면 안됨. 초기화는 되나 이상한 값 출력.
	Test(int & i) : val(i) {};		// reference member를 초기화 시엔 이렇게.
	
public:
	int & val;
private:
};

int main()
{
	int value = 10;

	//Test();	// Test() 정의 안할 시: "error C2512 'Test': 사용할 수 있는 적절한 기본 생성자가 없습니다."
				// Test() 선언만 할 시: "error LNK2019: (..) 외부 기호에서 확인하지 못했습니다."
				
				// Test() 가 없어도 default ctor를 부르지만 않으면 괜찮다!
	
	int a = 10;
	Test t = Test(a);
	std::cout << t.val << std::endl;

	std::cout << "Program ends." << std::endl;

	return 0;
}