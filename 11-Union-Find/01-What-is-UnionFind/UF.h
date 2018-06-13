//
// Created by hpf on 18-6-10.
//

#ifndef UNION_FIND_UF_H
#define UNION_FIND_UF_H

template<class T>
class UF {
    int getSize();

    bool isConnected();

    void unionElements(int p, int q);
};

#endif //UNION_FIND_UF_H
