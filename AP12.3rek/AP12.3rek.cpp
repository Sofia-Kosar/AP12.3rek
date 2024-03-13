#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void LAddRecursive(Elem*& first, Elem*& last, Info value)
{
    if (first == NULL) {
        Elem* tmp = new Elem;
        tmp->info = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        first = tmp;
        last = tmp;
    }
    else {
        LAddRecursive(first->next, last, value);
    }
}

bool LisSubset(Elem* first1, Elem* first2)
{
    if (first2 == NULL)
        return true;

    bool found = false;
    Elem* tmp = first1;
    while (tmp != NULL && !found)
    {
        if (tmp->info == first2->info)
            found = true;
        tmp = tmp->next;
    }

    if (!found)
        return false;

    return LisSubset(first1, first2->next);
}

void LPrint(Elem* first)
{
    if (first == NULL)
        return;

    cout << first->info << "  ";
    LPrint(first->next);
}

void DeleteList(Elem*& first)
{
    if (first == NULL)
        return;

    Elem* tmp = first->next;
    delete first;
    first = tmp;

    DeleteList(first);
}

int main()
{
    Elem* L1 = NULL, * last1 = NULL, * L2 = NULL, * last2 = NULL;

    int n1;
    cout << "Enter the number of elements for list L1: ";
    cin >> n1;
    cout << "Enter the elements for list L1: ";
    for (int i = 0; i < n1; ++i) {
        Info value;
        cin >> value;
        LAddRecursive(L1, last1, value);
    }

    int n2;
    cout << "Enter the number of elements for list L2: ";
    cin >> n2;
    cout << "Enter the elements for list L2: ";
    for (int i = 0; i < n2; ++i) {
        Info value;
        cin >> value;
        LAddRecursive(L2, last2, value);
    }

    cout << "List L1: ";
    LPrint(L1);
    cout << endl << "List L2: ";
    LPrint(L2);
    cout << endl;

    if (LisSubset(L2, L1))
        cout << " yes " << endl;
    else
        cout << " no " << endl;

    DeleteList(L1);
    DeleteList(L2);

    return 0;
}
