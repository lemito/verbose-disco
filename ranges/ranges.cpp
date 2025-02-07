#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

void sort_test(const std::vector<int> &meow) {
	// Стандартная сортировка из algo (итераторы); стандартный компоратор
	auto cpy0 = meow;
	// ReSharper disable once CppUseRangeAlgorithm
	std::sort(cpy0.begin(), cpy0.end());
	// сортировка с помощью ranges
	auto cpy1 = meow;
	std::ranges::sort(cpy1);
	// todo: clion почему-то пишет, что лучше не юзать std::sort и предлагает std::ranges::sort
	auto cpy2 = meow;
	std::ranges::sort(cpy2, [](const int a, const int b) { return a > b; });
}

void easy_labda(const std::vector<int> &meow) {
	auto lambda = [&meow](const int n) -> int {
		int cnt = 0;
		for (const auto &elem : meow) {
			if (n == elem) cnt++;
		}
		return cnt;
	};
	const int cnt_of_two = lambda(2);
	std::cout << cnt_of_two << std::endl;
}

void range_filter_and_tranform(const std::vector<int> &meow) {
	// только фильтрует контейнер по критерию, при этом элементы не изменяются
	auto n = meow | std::views::filter([](const int elem) { return elem % 2 == 0; });
	for (const auto &elem : n) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;


	// изменяет все(?) элементы по какому-то правилу
	auto ne = n | std::views::transform([](const int elem) { return elem + elem + 5 * elem; });
	for (const auto &elem : ne) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}


int main() {
	const std::vector meow = {27, 02, 2005, 52, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	sort_test(meow);

	easy_labda(meow);

	const auto& cpy = meow;

	range_filter_and_tranform(cpy);

	return 0;
}
