#include <iostream>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;

int main()
{
	std::unordered_map<int, std::string> umap;

	umap.insert(std::make_pair<int, std::string>(1, "one"));
	umap.insert(std::make_pair<int, std::string>(2, "two"));
	umap.insert(std::make_pair<int, std::string>(3, "three"));
	umap.insert(std::make_pair(4, "four"));

	cout << "unordered_map iterator" << endl;
	for (auto it = umap.begin(); it != umap.end(); it++)
	{
		cout << it->first << ",  " << it->second << endl;
	}

	cout << "unordered_map find(..) test" << endl;
	auto it = umap.find(3);
	cout << "3: " << it->first << ", " << it->second << endl;

	cout << "unordered_map erase test" << endl;
	umap.erase(3);
	for (auto& it : umap)
		cout << it.first << ", " << it.second << endl;

	cout << "unordered_map operator[] test" << endl;
	cout << "umap[1]: " << umap[1] << endl;
	cout << "umap[2]: " << umap[2] << endl;
	cout << "umap[3]: " << umap[3] << endl;		// key가 3인 element는 지워져서 없음. 없는 key에 access하는 경우 해당 key를 갖는 새로운 element를 생성.
	cout << "umap[4]: " << umap[4] << endl;

	cout << "unordered_map informations" << endl;
	cout << "size: " << umap.size() << endl;
	cout << "max_size: " << umap.max_size() << endl;

	cout << "unordered_map erase(..) test" << endl;
	umap.clear();
	for (auto& it : umap)
		cout << it.first << ", " << it.second << endl;

	return 0;
}

// Posting
//	operator[]
//	make_pair(..)
//	insert(..)
//	erase(..)
//	iterator
//	find(..)
//	count(..)
//	size()
//	empty()
//	max_size()
