#include <iostream>
#include <Windows.h>
#include "task.h"

void task1();
void task2();

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int choice;

  do {
    std::cout << "================================" << std::endl;
    std::cout << "   ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ТЕСТА   " << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "1 - Задание 1 (Базовый класс)" << std::endl;
    std::cout << "2 - Задание 2 (Перегруженные операции)" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        task1();
        break;
      case 2:
        task2();
        break;
      case 0:
        std::cout << "Выход из программы." << std::endl;
        break;
      default:
        std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
    }

  } while (choice != 0);

  return 0;
}

void task1() {
  std::cout << "\n=== ЗАДАНИЕ 1: БАЗОВЫЙ КЛАСС ===" << std::endl;

  // Тестирование конструктора по умолчанию
  std::cout << "1. Тестирование конструктора по умолчанию:" << std::endl;
  RightTriangle triangle1;
  std::cout << triangle1 << std::endl;
  std::cout << "Площадь: " << triangle1.calculateArea() << std::endl;
  std::cout << std::endl;

  // Тестирование конструктора с параметрами
  std::cout << "2. Тестирование конструктора с параметрами:" << std::endl;
  double a, b;

  std::cout << "Введите длину первого катета: ";
  std::cin >> a;
  std::cout << "Введите длину второго катета: ";
  std::cin >> b;

  RightTriangle triangle2(a, b);
  std::cout << triangle2 << std::endl;
  std::cout << "Площадь: " << triangle2.calculateArea() << std::endl;
  std::cout << std::endl;

  // Тестирование конструктора копирования
  std::cout << "3. Тестирование конструктора копирования:" << std::endl;
  RightTriangle triangle3 = triangle2;
  std::cout << triangle3 << std::endl;
  std::cout << "Площадь: " << triangle3.calculateArea() << std::endl;
  std::cout << std::endl;

  // Тестирование сеттеров и геттеров
  std::cout << "4. Тестирование сеттеров и геттеров:" << std::endl;
  RightTriangle triangle4;

  std::cout << "Исходный треугольник: " << triangle4 << std::endl;

  std::cout << "Введите новое значение для катета a: ";
  std::cin >> a;
  triangle4.setA(a);

  std::cout << "Введите новое значение для катета b: ";
  std::cin >> b;
  triangle4.setB(b);

  std::cout << "Измененный треугольник: " << triangle4 << std::endl;
  std::cout << "Проверка через геттеры:" << std::endl;
  std::cout << "Катет a = " << triangle4.getA() << std::endl;
  std::cout << "Катет b = " << triangle4.getB() << std::endl;
  std::cout << "Площадь = " << triangle4.calculateArea() << std::endl;
}

void task2() {
  std::cout << "\n=== ЗАДАНИЕ 2: ПЕРЕГРУЖЕННЫЕ ОПЕРАЦИИ ===" << std::endl;

  // Создание треугольников с вводом от пользователя
  std::cout << "Создаем два треугольника для тестирования операций:"
            << std::endl;

  double a1, b1, a2, b2;

  std::cout << "\nПервый треугольник:" << std::endl;
  std::cout << "Введите длину первого катета: ";
  std::cin >> a1;
  std::cout << "Введите длину второго катета: ";
  std::cin >> b1;

  std::cout << "\nВторой треугольник:" << std::endl;
  std::cout << "Введите длину первого катета: ";
  std::cin >> a2;
  std::cout << "Введите длину второго катета: ";
  std::cin >> b2;

  RightTriangle tri1(a1, b1);
  RightTriangle tri2(a2, b2);

  std::cout << "\nСозданные треугольники:" << std::endl;
  std::cout << "tri1: " << tri1 << " (площадь: " << tri1.calculateArea() << ")"
            << std::endl;
  std::cout << "tri2: " << tri2 << " (площадь: " << tri2.calculateArea() << ")"
            << std::endl;

  // Тестирование унарных операций
  std::cout << "\n1. Тестирование унарных операций ++/--:" << std::endl;

  int operation;
  std::cout << "Выберите операцию для tri1 (1 - ++, 2 - --): ";
  std::cin >> operation;

  if (operation == 1) {
    ++tri1;
    std::cout << "После ++tri1: " << tri1 << std::endl;
  } else if (operation == 2) {
    --tri1;
    std::cout << "После --tri1: " << tri1 << std::endl;
  }

  // Тестирование приведения типов
  std::cout << "\n2. Тестирование приведения типов:" << std::endl;

  std::cout << "tri1: " << tri1 << std::endl;
  std::cout << "Явное приведение к double: " << static_cast<double>(tri1)
            << std::endl;
  std::cout << "Неявное приведение к bool: " << (tri1 ? "true" : "false")
            << std::endl;

  std::cout << "tri2: " << tri2 << std::endl;
  std::cout << "Явное приведение к double: " << static_cast<double>(tri2)
            << std::endl;
  std::cout << "Неявное приведение к bool: " << (tri2 ? "true" : "false")
            << std::endl;

  // Тестирование бинарных операций
  std::cout << "\n3. Тестирование бинарных операций <= и >=:" << std::endl;

  std::cout << "Сравнение площадей:" << std::endl;
  std::cout << "tri1 <= tri2: " << (tri1 <= tri2 ? "true" : "false")
            << std::endl;
  std::cout << "tri1 >= tri2: " << (tri1 >= tri2 ? "true" : "false")
            << std::endl;
}