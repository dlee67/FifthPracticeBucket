#ifndef SWAPPER_H
#define SWAPPER_H

template <class T>
class Swapper {
    public:
        Swapper(T first, T second);
        void swap();
        T getFirst();
        T getSecond();

    private:
        T first;
        T second;
};

template<class T>
Swapper<T>::Swapper(T first, T second) {
    this->first = first;
    this->second = second;
}

template<class T>
void Swapper<T>::swap() {
    T temp = first;
    first = second;
    second = temp;
}

template<class T>
T Swapper<T>::getFirst() {
    return first;
}

template<class T>
T Swapper<T>::getSecond() {
    return second;
}

#endif