//
// Created by hpf on 18-6-10.
//

#ifndef UNION_FIND_UF_H
#define UNION_FIND_UF_H

class UF {
    int getSize();

    bool isConnected(int p, int q);

    void unionElements(int p, int q);
};

#endif //UNION_FIND_UF_H
