//
// Created by hpf on 18-5-9.
//

template<class T>
class Sum {
public:
    static T sum(T arr[], int n) {
        return sum(arr, 0, n);
    }

    static T sum(T arr[], int l, int n) {
        if (l == n) {
            return 0;
        }
        return arr[l] + sum(arr, l + 1, n);
    }
};
