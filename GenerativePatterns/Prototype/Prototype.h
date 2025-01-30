//
// Created by lemito on 1/30/25.
//

#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <iostream>
#include <memory>

class Animal {
	std::string _name;

	public:
		Animal() = default;
		explicit Animal(const std::string &name): _name((name)) {
		}
		virtual ~Animal() = default;
		virtual void sound() = 0;
		virtual std::unique_ptr<Animal> make_clone() = 0;
		std::string get_name() const { return _name; };
		void set_name(const std::string &name) {
			_name = name;
		};
};

class Dog : public Animal {
	public:
		Dog() = default;
		explicit Dog(const std::string &name): Animal(name) {
		};
		Dog(const Dog &other) = default;
		~Dog() override = default;
		void sound() override {
			std::cout << "Dog::sound " << this->get_name() << std::endl;
		}
		std::unique_ptr<Animal> make_clone() override {
			return std::make_unique<Dog>(*this);
		}
};

class Cat : public Animal {
	public:
		Cat() = default;
		explicit Cat(const std::string &name): Animal(name) {
		}
		Cat(const Cat &other) = default;
		~Cat() override = default;
		void sound() override {
			std::cout << "Cat::sound " << this->get_name() << std::endl;
		}
		std::unique_ptr<Animal> make_clone() override {
			return std::make_unique<Cat>(*this);
		}
};

#endif //PROTOTYPE_H
