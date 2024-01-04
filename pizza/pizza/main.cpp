#include <iostream>
#include <string>

// Product class
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}
	void setMemory(const std::string& memory) {
		memory_ = memory;
	}
	void setStorage(const std::string& storage) {
		storage_ = storage;
	}
	void display() {
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: " << memory_ << std::endl;
		std::cout << "Storage: " << storage_ << std::endl;
	}
private:
	std::string cpu_;
	std::string memory_;
	std::string storage_;
};
// Builder interface
class ComputerBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	virtual Computer getResult() = 0;
};
// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
	DesktopComputerBuilder() {
		computer_ = Computer();
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
	Computer getResult() override {
		return computer_;
	}
private:
	Computer computer_;
};
// Director
class ComputerAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		return builder.getResult();
	}
};

class MagicAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i3");
		builder.buildMemory("8GB");
		builder.buildStorage("256GB SSD");
		return builder.getResult();
	}
};

// Product class
class Pizza {
public:
	void setDough(const std::string& dough)
	{
		this->dough = dough;
	}
	void setSauce(const std::string& sauce)
	{
		this->sauce = sauce;
	}
	void setTopping(const std::string& topping)
	{
		this->topping = topping;
	}
	void displayPizza() const
	{
		std::cout << "Pizza with Dough: " << dough
			<< ", Sauce: " << sauce
			<< ", Topping: " << topping << std::endl;
	}
private:
	std::string dough;
	std::string sauce;
	std::string topping;
};
// Abstract builder class
class PizzaBuilder {
public:
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	virtual Pizza getPizza() const = 0;
};
// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Pan Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Hawaiian Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Ham and Pineapple");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};
// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Thin Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Spicy Tomato Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Pepperoni and Jalapenos");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};

class Smalec : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Ciasto babuni");
	}
	void buildSauce() override
	{
		pizza.setSauce("majonez kielecki");
	}
	void buildTopping() override
	{
		pizza.setTopping("Ser gouda, smalec, boczek i szpinak");
	}
	Pizza getPizza() const override { return pizza; }
private:
	Pizza pizza;
};

// Director class that orchestrates the construction
class Cook {
public:
	void makePizza(PizzaBuilder& builder)
	{
		builder.buildDough();
		builder.buildSauce();
		builder.buildTopping();
	}
};
int main()
{
	DesktopComputerBuilder desktopBuilder;
	ComputerAssembler assembler;
	Computer desktop = assembler.assembleComputer(desktopBuilder);
	std::cout << "Desktop Computer Configuration:" << std::endl;
	desktop.display();
	MagicAssembler magic;
	Computer magci = magic.assembleComputer(desktopBuilder);
	std::cout << "Desktop Computer Configuration:" << std::endl;
	magci.display();


	Cook cook;
	HawaiianPizzaBuilder hawaiianBuilder;
	cook.makePizza(hawaiianBuilder);
	Pizza hawaiianPizza = hawaiianBuilder.getPizza();
	hawaiianPizza.displayPizza();
	SpicyPizzaBuilder spicyBuilder;
	cook.makePizza(spicyBuilder);
	Pizza spicyPizza = spicyBuilder.getPizza();
	spicyPizza.displayPizza();
	Smalec LorencBuilder;
	cook.makePizza(LorencBuilder);
	Pizza LorencPizza = LorencBuilder.getPizza();
	LorencPizza.displayPizza();
	return 0;
}