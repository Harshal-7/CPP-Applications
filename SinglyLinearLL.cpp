#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class SinglyLinear
{
    private:
        struct node<T> *Head;
        int Count;

    public:
        SinglyLinear();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

template <class T>
SinglyLinear<T>::SinglyLinear()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void SinglyLinear<T>::InsertFirst(T No)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    Count++;
}

template <class T>
void SinglyLinear<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
    
        temp->next = newn;
    
    }

    Count++;
}

template <class T>
void SinglyLinear<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > Count+1))
    {
        cout << "Invalid Position...!" << endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *temp = Head;
        struct node<T> *newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }

}

template <class T>
void SinglyLinear<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;
        Head = Head->next;
        delete temp;
    }

    Count--;
}

template <class T>
void SinglyLinear<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    Count--;
}

template <class T>
void SinglyLinear<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Count+1))
    {
        cout << "Invalid Position...!" << endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        struct node<T> *tempX = temp->next;

        temp->next = tempX->next;
        delete tempX;

        Count--;
    }
}

template <class T>
void SinglyLinear<T>::Display()
{
    struct node<T> *temp = Head;

    if(Count == 0)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    cout << "\nElements from Linked List are: \n" << endl;

    while(temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

template <class T>
int SinglyLinear<T>::CountNode()
{
    return Count;
}

int main()
{
    SinglyLinear <int> obj1;
    SinglyLinear <float> obj2;
    SinglyLinear <char> obj3;

    int iValue = 0;
    float fValue = 0.0;
    char cValue = '\0';
    int iPosition = 0;
    int iOpr = 0;
    int CountRet = 0;

    cout << "\nChoose the operation:" << endl;
    cout << "1 : Integer" << endl;
    cout << "2 : Float" << endl;
    cout << "3 : Character" << endl;

    cout << "\n > ";
    cin >> iOpr;

    if(iOpr == 1)
    {
        int iChoice = 0;
        
        while(iChoice != 10)
        {
            cout << "\nEnter Your Choice" << endl;
            cout << "\n1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate the Application" << endl;

            cin >> iChoice;

            switch(iChoice)
            {
                case 1:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> iValue;
                    obj1.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value" << endl;
                    cout << " > ";
                    cin >> iValue;
                    obj1.InsertLast(iValue);
                    break;

                case 3:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> iValue;
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj1.InsertAtPos(iValue,iPosition);
                    break;

                case 4:
                    obj1.DeleteFirst();
                    break;

                case 5:
                    obj1.DeleteLast();
                    break;

                case 6:
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj1.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj1.Display();
                    break;

                case 8:
                    CountRet = obj1.CountNode();
                    cout << "\nNumber of Nodes in Linked List are : " << CountRet << endl;
                    break;

                case 9:
                    cout << "\nThank You For Using The Application" << endl;
                    iChoice = 10;
                    break;
                
                default:
                    cout << "\nPlease Enter Valid Choise..!!" << endl;

            }
        }

    }
    else if(iOpr == 2)
    {
        int fChoice = 0;
        
        while(fChoice != 10)
        {
            cout << "\nEnter Your Choice" << endl;
            cout << "\n1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate the Application" << endl;

            cout << "\n > ";
            cin >> fChoice;

            switch(fChoice)
            {
                case 1:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> fValue;
                    obj2.InsertFirst(fValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value" << endl;
                    cout << " > ";
                    cin >> fValue;
                    obj2.InsertLast(fValue);
                    break;

                case 3:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> fValue;
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj2.InsertAtPos(fValue,iPosition);
                    break;

                case 4:
                    obj2.DeleteFirst();
                    break;

                case 5:
                    obj2.DeleteLast();
                    break;

                case 6:
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj2.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj2.Display();
                    break;

                case 8:
                    CountRet = obj2.CountNode();
                    cout << "\nNumber of Nodes in Linked List are : " << CountRet << endl;
                    break;

                case 9:
                    cout << "\nThank You For Using The Application" << endl;
                    fChoice = 10;
                    break;
                
                default:
                    cout << "\nPlease Enter Valid Choise..!!" << endl;

            }
        }

    }
    else if(iOpr == 3)
    {
        int cChoice = 0;
        
        while(cChoice != 10)
        {
            cout << "\nEnter Your Choice" << endl;
            cout << "\n1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate the Application" << endl;

            cout << "\n > ";
            cin >> cChoice;

            switch(cChoice)
            {
                case 1:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> cValue;
                    obj3.InsertFirst(cValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value" << endl;
                    cout << " > ";
                    cin >> cValue;
                    obj3.InsertLast(cValue);
                    break;

                case 3:
                    cout << "\nEnter First Value" << endl;
                    cout << "\n > ";
                    cin >> cValue;
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj3.InsertAtPos(cValue,iPosition);
                    break;

                case 4:
                    obj3.DeleteFirst();
                    break;

                case 5:
                    obj3.DeleteLast();
                    break;

                case 6:
                    cout << "\nEnter the Position" << endl;
                    cout << "\n > ";
                    cin >> iPosition;
                    obj3.DeleteAtPos(iPosition);
                    break;

                case 7:
                    obj3.Display();
                    break;

                case 8:
                    CountRet = obj3.CountNode();
                    cout << "\nNumber of Nodes in Linked List are : " << CountRet << endl;
                    break;

                case 9:
                    cout << "\nThank You For Using The Application" << endl;
                    cChoice = 10;
                    break;
                
                default:
                    cout << "\nPlease Enter Valid Choise..!!" << endl;

            }
        }
    }
    else
    {
        cout << "\nInvalid Operation...!" << endl;
    }

    return 0;
    
}