//
// Created by hpf on 18-5-14.
//

template<typename Key, typename Value>
class Map {
    void add(Key key, Value value);

    Value remove(Key key);

    bool contains(Key key);

    Value get(Key key);

    void set(Key key, Value value);

    int getSize();

    bool isEmpty();
};
