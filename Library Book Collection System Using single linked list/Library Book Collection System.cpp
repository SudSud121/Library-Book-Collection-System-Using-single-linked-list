
#include <iostream>
#include <string>
#include <utility>
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

int main()
{
    LinkedList library;

    library.InsertAt(CreateBook(103, "Operating Systems"), 0);
    library.InsertAt(CreateBook(101, "Data Structures"), 1);
    library.InsertAt(CreateBook(105, "Computer Networks"), 2);
    library.InsertAt(CreateBook(102, "Database Systems"), 3);
    library.InsertAt(CreateBook(104, "Software Engineering"), 4);

    int choice, id, index, a, b;
    string title;
    BookNode* removed;

    do
    {
        cout << "\n1. Display All Books";
        cout << "\n2. Insert Book at Head";
        cout << "\n3. Remove Book from Head";
        cout << "\n4. Insert Book at Index";
        cout << "\n5. Remove Book at Index";
        cout << "\n6. Swap Books";
        cout << "\n7. Sort Books by ID";
        cout << "\n8. Reverse Book Collection";
        cout << "\n9. Check Collection Status";
        cout << "\n10. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.Print();
            break;

        case 2:
            cout << "Enter ID and title: ";
            cin >> id;
            getline(cin >> ws, title);
            library.Insert(CreateBook(id, title));
            break;

        case 3:
            removed = library.Remove();
            if (removed != NULL)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else cout << "List is empty\n";
            break;

        case 4:
            cout << "Enter ID, title and index: ";
            cin >> id;
            getline(cin >> ws, title);
            cin >> index;
            library.InsertAt(CreateBook(id, title), index);
            break;

        case 5:
            cout << "Enter index: ";
            cin >> index;
            removed = library.RemoveAt(index);
            if (removed != NULL)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else cout << "Invalid index\n";
            break;

        case 6:
            cout << "Enter two indexes: ";
            cin >> a >> b;
            library.Swap(a, b);
            break;

        case 7:
            library.Sort();
            cout << "Books sorted\n";
            break;

        case 8:
            library.Reverse();
            cout << "Books reversed\n";
            break;

        case 9:
            if (library.IsEmpty())
                cout << "Collection is empty\n";
            else
                cout << "Collection has books\n";
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 10);

    return 0;
}

