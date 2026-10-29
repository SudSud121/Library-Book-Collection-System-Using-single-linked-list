using namespace std;

struct BookNode
{
    int bookID;
    string title;
    BookNode* next;
};

class LinkedList
{
    BookNode* head;
    int count;

public:
    LinkedList()
    {
        head = NULL;
        count = 0;
    }

    bool IsEmpty()
    {
        return head == NULL;
    }

    bool IsNotEmpty()
    {
        return head != NULL;
    }

    void Insert(BookNode* book)
    {
        book->next = head;
        head = book;
        count++;
    }

    BookNode* Remove()
    {
        if (IsEmpty()) return NULL;

        BookNode* temp = head;
        head = head->next;
        temp->next = NULL;
        count--;
        return temp;
    }

    void InsertAt(BookNode* book, int index)
    {
        if (index < 0) index = 0;
        if (index > count) index = count;

        if (index == 0)
        {
            Insert(book);
            return;
        }

        BookNode* p = head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        book->next = p->next;
        p->next = book;
        count++;
    }

    BookNode* RemoveAt(int index)
    {
        if (IsEmpty() || index < 0 || index >= count)
            return NULL;

        if (index == 0) return Remove();

        BookNode* p = head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        BookNode* temp = p->next;
        p->next = temp->next;
        temp->next = NULL;
        count--;
        return temp;
    }

    BookNode* GetNodeAt(int index)
    {
        BookNode* p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p;
    }

    void Swap(int a, int b)
    {
        if (a < 0 || b < 0 || a >= count || b >= count)
            return;

        BookNode* x = GetNodeAt(a);
        BookNode* y = GetNodeAt(b);

        swap(x->bookID, y->bookID);
        swap(x->title, y->title);
    }

    void Sort()
    {
        for (BookNode* i = head; i != NULL; i = i->next)
            for (BookNode* j = i->next; j != NULL; j = j->next)
                if (i->bookID > j->bookID)
                {
                    swap(i->bookID, j->bookID);
                    swap(i->title, j->title);
                }
    }

    void Reverse()
    {
        BookNode* prev = NULL;
        BookNode* curr = head;

        while (curr != NULL)
        {
            BookNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void Print()
    {
        BookNode* p = head;
        int i = 0;

        while (p != NULL)
        {
            cout << i++ << "  " << p->bookID
                 << "  " << p->title << endl;
            p = p->next;
        }
        cout << "Total books: " << count << endl;
    }

    ~LinkedList()
    {
        while (IsNotEmpty())
            delete Remove();
    }
};

BookNode* CreateBook(int id, string title)
{
    BookNode* b = new BookNode;
    b->bookID = id;
    b->title = title;
    b->next = NULL;
    return b;
}
