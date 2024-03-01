#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <chrono>  // chrono

template <typename T>
void zapolnit(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Генерация случайных чисел от 0 до 999
    }
}

template <typename T>
void vivod(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubbleSort(T* arr, int size) {
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Время выполнения сортировки пузырьком: " << duration.count() << " микросекунд" << std::endl;
}

template <typename T>
int delenie(T* arr, int low, int high) {
    int index = low + rand() % (high - low + 1);
    std::swap(arr[index], arr[high]);

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T* arr, int low, int high) {

    if (low < high) {
        int index = delenie(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

}

template <typename T>
void selectionSort(T* arr, int size) {
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++) {
        int minInd = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        if (minInd != i) {
            std::swap(arr[i], arr[minInd]);
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Время выполнения selectionSort: " << duration.count() << " микросекунд" << std::endl;
    
}

int main() {
    srand(time(0)); // Генерация случайных чисел

    // Сортировка пузырьком
    std::cout << "Сортировка пузырьком" << std::endl;
    int sizeBubble;
    std::cout << "Введите размер массива для сортировки пузырьком: ";
    std::cin >> sizeBubble;

    int* massivBubble = new int[sizeBubble];
    zapolnit(massivBubble, sizeBubble);
    std::cout << "Исходный массив: ";
    // vivod(massivBubble, sizeBubble);

    bubbleSort(massivBubble, sizeBubble);
    std::cout << "Отсортированный массив: ";
    // vivod(massivBubble, sizeBubble);
    std::cout << std::endl;

    delete[] massivBubble;

    // Quick Sort
    std::cout << "QuickSort" << std::endl;
    int sizeQuick;
    std::cout << "Введите размер массива для QuickSort: ";
    std::cin >> sizeQuick;

    int* massivQuick = new int[sizeQuick];
    zapolnit(massivQuick, sizeQuick);
    std::cout << "Исходный массив: ";
    // vivod(massivQuick, sizeQuick);
    
    auto start_time = std::chrono::high_resolution_clock::now();
    quickSort(massivQuick, 0, sizeQuick - 1);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Время выполнения сортировки выбором: " << duration.count() << " микросекунд" << std::endl;
    std::cout << "Отсортированный массив: ";
    // vivod(massivQuick, sizeQuick);
    std::cout << std::endl;

    delete[] massivQuick;

    // Selection Sort
    std::cout << "SelectionSort" << std::endl;
    int sizeSelection;
    std::cout << "Введите размер массива для сортировки выбором: ";
    std::cin >> sizeSelection;

    int* massivSelection = new int[sizeSelection];
    zapolnit(massivSelection, sizeSelection);
    std::cout << "Исходный массив: ";
    // vivod(massivSelection, sizeSelection);

    selectionSort(massivSelection, sizeSelection);
    std::cout << "Отсортированный массив: ";
    // vivod(massivSelection, sizeSelection);

    delete[] massivSelection;

    return 0;
}
