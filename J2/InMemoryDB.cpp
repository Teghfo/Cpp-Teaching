#include <iostream>
using namespace std;

enum string_code
{
    add,
    get,
    sizeDic,
    ext,
    nothing
};

string_code hashit(string const &inString)
{
    if (inString == "add")
        return add;
    if (inString == "get")
        return get;
    if (inString == "size")
        return sizeDic;
    if (inString == "exit")
        return ext;
    return nothing;
}

class BSTnode
{
public:
    string key;
    string value;
    BSTnode *next;
    BSTnode *before;
    friend class BST;
};

class BST
{
private:
    BSTnode *first;
    BSTnode *last;
    int cnt;

public:
    BST()
    {
        first = NULL;
        last = NULL;
        cnt = 0;
    }
    void insert(string, string);
    string search(string) const;
    int size() const;
};

void BST::insert(string keyInput, string valueInput)
{

    BSTnode *ptrSearchInsert = first;
    while (ptrSearchInsert)
    {
        if (ptrSearchInsert->key == keyInput)
        {
            ptrSearchInsert->value = valueInput;
            return;
        }
        ptrSearchInsert = ptrSearchInsert->next;
    }

    cnt++;
    BSTnode *newNode = new BSTnode;
    newNode->key = keyInput;
    newNode->value = valueInput;
    newNode->next = NULL;
    if (first == NULL)
    {

        first = last = newNode;
        last->next = NULL;
    }
    else
    {
        last->next = newNode;
        newNode->before = last;
        last = newNode;
    }
};

int BST::size() const
{
    // int cnt = 0;
    // BSTnode *ptrSize = first;
    // while (ptrSize)
    // {
    //     ptrSize = ptrSize->next;
    //     cnt++;
    // }
    return cnt;
}

string BST::search(string keyInput) const
{
    string val = "";
    BSTnode *ptrSearch = first;
    while (ptrSearch)
    {
        if (ptrSearch->key == keyInput)
        {
            val = ptrSearch->value;
            break;
        }
        ptrSearch = ptrSearch->next;
    }
    return val;
}

class InMemoryDB
{
private:
    BST bstDictObj;
    InMemoryDB(){};
    InMemoryDB(const InMemoryDB &obj){};
    static InMemoryDB *instance;

public:
    static InMemoryDB *getInstance()
    {
        if (instance == NULL)
            instance = new InMemoryDB;
        return instance;
    }
    string getValue(string key) const
    {
        return bstDictObj.search(key);
    }
    int getSize() const
    {
        return bstDictObj.size();
    }
    void setValue(string key, string val)
    {
        bstDictObj.insert(key, val);
    }
};

InMemoryDB *InMemoryDB ::instance = NULL;

int main()
{

    InMemoryDB *obj = obj->getInstance();
    string input;
    for (;;)
    {
        getline(cin, input);
        string token = input.substr(0, input.find(' '));

        input.erase(0, token.length() + 1);
        // token = input.substr(0, input.find(' '));
        // cout << "dar in marhale" << token << endl;

        switch (hashit(token))
        {
        case ext:
            return 0;
        case get:
        {
            token = input.substr(0, input.find(' '));
            cout << obj->getValue(token) << endl;
            break;
        }
        case add:
        {
            string key = input.substr(0, input.find(' '));
            input.erase(0, key.length() + 1);
            string val = input.substr(0, input.find(' '));
            obj->setValue(key, val);
            break;
        }
        case sizeDic:
            cout << obj->getSize() << endl;
            break;
        case nothing:
            cout << "wrong command!(hint: add - get - size - exit)." << endl;
            break;
        }
    }

    return 0;
}
