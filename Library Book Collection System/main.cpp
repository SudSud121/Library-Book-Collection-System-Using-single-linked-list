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
