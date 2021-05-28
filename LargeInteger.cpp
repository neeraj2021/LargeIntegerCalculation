#include <cstdlib>
#include <iostream>
#include <string>
#include "List.cpp"
//moved OVER_FLOW and DIGIT from main to here
int OVER_FLOW(int &);
int DIGIT(int);

using namespace std;
class List;

class LongInteger
{
public:
    List X;
    bool negative;

    void INITIALIZE(string &S)
    {
        SETSIGN(S[0]);
        int count;
        if (GETSIGN())
            S = S.substr(1);
        count = S.length();

        int FirstNodeLength = count % 4;

        string VALUE;
        int VAL;
        int position;

        if (FirstNodeLength == 0)
        {
            VALUE = S.substr(0, 4);
            position = 4;
        }
        else
        {
            VALUE = S.substr(0, FirstNodeLength);
            position = FirstNodeLength;
        }

        VAL = atoi(VALUE.c_str());

        X.INSERT_FIRST(VAL);

        while (position != S.length())
        {
            VALUE = S.substr(position, 4);
            VAL = atoi(VALUE.c_str());
            X.INSERT_RIGHT(VAL);
            position = position + 4;
        };
    }

    bool GETSIGN()
    {
        return negative;
    }

    void SETSIGN(char S)
    {
        if (S == '-')
            negative = 1;
        else
            negative = 0;
    }

    int GETDIGITCOUNT()
    {
        int count = 0;

        if (X.IS_EMPTY())
            return count;

        int nodeCount;
        int num;
        Node *temp = X.GET_FIRST();
        num = X.NODE_VALUE(temp);
        /* Find out number of digits in the first Node */
        if (num < 10)
            count = 1;
        else if (num < 100)
            count = 2;
        else if (num < 1000)
            count = 3;
        else
            count = 4;

        count = count + ((X.NODE_COUNT() - 1) * 4);

        return count;
    }

    void PRINT()
    {
        Node *temp = X.GET_FIRST();
        int num;
        if (GETSIGN())
            cout << "-";

        while (!(X.IS_LAST(temp)))
        {
            num = X.NODE_VALUE(temp);

            if (!(X.IS_FIRST(temp)))
            {
                if (num < 10)
                    cout << "000";
                else if (num < 100)
                    cout << "00";
                else if (num < 1000)
                    cout << "0";
            }

            cout << num;
            temp = X.NEXT_RIGHT(temp);
        }

        num = X.NODE_VALUE(temp);
        if (!(X.IS_FIRST(temp)))
        {
            if (num < 10)
                cout << "000";
            else if (num < 100)
                cout << "00";
            else if (num < 1000)
                cout << "0";
        }
        cout << num;
    }

    bool GREATERTHAN(LongInteger Q)
    {
        if (GETSIGN() == 0 && Q.GETSIGN() == 1)
            return 1;
        if (GETSIGN() == 1 && Q.GETSIGN() == 0)
            return 0;

        int num;
        int numQ;
        Node *temp = X.GET_FIRST();
        Node *tempQ = Q.X.GET_FIRST();

        /* Both positive numbers */
        if (GETSIGN() == 0 && Q.GETSIGN() == 0)
        {
            if (GETDIGITCOUNT() > Q.GETDIGITCOUNT())
                return 1;
            if (GETDIGITCOUNT() < Q.GETDIGITCOUNT())
                return 0;

            while (!X.IS_LAST(temp))
            {
                if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                    return 1;
                if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                    return 0;
                temp = X.NEXT_RIGHT(temp);
                tempQ = Q.X.NEXT_RIGHT(tempQ);
            }

            if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                return 1;
            if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                return 0;
            return 0;
        }

        /* Both negative numbers */
        if (GETSIGN() == 1 && Q.GETSIGN() == 1)
        {
            if (GETDIGITCOUNT() < Q.GETDIGITCOUNT())
                return 1;
            if (GETDIGITCOUNT() > Q.GETDIGITCOUNT())
                return 0;

            while (!X.IS_LAST(temp))
            {
                if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                    return 0;
                if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                    return 1;
                temp = X.NEXT_RIGHT(temp);
                tempQ = Q.X.NEXT_RIGHT(tempQ);
            }

            if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                return 0;
            if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                return 1;
            return 0;
        }
    }

    bool LESSTHAN(LongInteger Q)
    {
        if (GETSIGN() == 0 && Q.GETSIGN() == 1)
            return 0;
        if (GETSIGN() == 1 && Q.GETSIGN() == 0)
            return 1;

        int num;
        int numQ;
        Node *temp = X.GET_FIRST();
        Node *tempQ = Q.X.GET_FIRST();

        /* Both positive numbers */
        if (GETSIGN() == 0 && Q.GETSIGN() == 0)
        {
            if (GETDIGITCOUNT() > Q.GETDIGITCOUNT())
                return 0;
            if (GETDIGITCOUNT() < Q.GETDIGITCOUNT())
                return 1;

            while (!X.IS_LAST(temp))
            {
                if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                    return 0;
                if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                    return 1;
                temp = X.NEXT_RIGHT(temp);
                tempQ = Q.X.NEXT_RIGHT(tempQ);
            }

            if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                return 0;
            if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                return 1;
            return 0;
        }

        /* Both negative numbers */
        if (GETSIGN() == 1 && Q.GETSIGN() == 1)
        {
            if (GETDIGITCOUNT() < Q.GETDIGITCOUNT())
                return 0;
            if (GETDIGITCOUNT() > Q.GETDIGITCOUNT())
                return 1;

            while (!X.IS_LAST(temp))
            {
                if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                    return 1;
                if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                    return 0;
                temp = X.NEXT_RIGHT(temp);
                tempQ = Q.X.NEXT_RIGHT(tempQ);
            }

            if (X.NODE_VALUE(temp) > Q.X.NODE_VALUE(tempQ))
                return 1;
            if (X.NODE_VALUE(temp) < Q.X.NODE_VALUE(tempQ))
                return 0;
            return 0;
        }
    }

    bool EQUALTO(LongInteger Q)
    {
        if (GETSIGN() != Q.GETSIGN())
            return 0;
        if (GETDIGITCOUNT() != Q.GETDIGITCOUNT())
            return 0;
        Node *temp = X.GET_FIRST();
        Node *tempQ = Q.X.GET_FIRST();

        while (!X.IS_LAST(temp))
        {
            if (X.NODE_VALUE(temp) != Q.X.NODE_VALUE(tempQ))
                return 0;
            temp = X.NEXT_RIGHT(temp);
            tempQ = Q.X.NEXT_RIGHT(tempQ);
        }

        if (X.NODE_VALUE(temp) != Q.X.NODE_VALUE(tempQ))
            return 0;
        return 1;
    }

    LongInteger ADD(LongInteger Q)
    {
        LongInteger result;

        if (GETSIGN() == Q.GETSIGN()) //used to add numbers with the same sign
        {
            if (GETSIGN() == 0)
                result.SETSIGN('+');
            else
                result.SETSIGN('-');

            int thisNode;
            int QNode;
            int maxNode;
            int minNode;
            thisNode = X.NODE_COUNT();
            QNode = Q.X.NODE_COUNT();

            if (thisNode >= QNode)
            {
                maxNode = thisNode;
                minNode = QNode;
            }
            else
            {
                maxNode = QNode;
                minNode = thisNode;
            }

            Node *temp1 = X.GET_LAST();
            Node *temp2 = Q.X.GET_LAST();
            int overflow = 0;
            int addValue = 0;
            addValue = X.NODE_VALUE(temp1) + Q.X.NODE_VALUE(temp2);
            overflow = OVER_FLOW(addValue);
            result.X.INSERT_FIRST(addValue);

            if (!(X.IS_FIRST(temp1)))
                temp1 = X.NEXT_LEFT(temp1);
            if (!(Q.X.IS_FIRST(temp2)))
                temp2 = Q.X.NEXT_LEFT(temp2);

            for (int i = 1; i < minNode; i++)
            {
                addValue = X.NODE_VALUE(temp1) + Q.X.NODE_VALUE(temp2) + overflow;
                overflow = OVER_FLOW(addValue);
                result.X.INSERT_LEFT(addValue);

                if (!(X.IS_FIRST(temp1)))
                    temp1 = X.NEXT_LEFT(temp1);
                if (!(Q.X.IS_FIRST(temp2)))
                    temp2 = Q.X.NEXT_LEFT(temp2);
            }

            if (minNode == maxNode) //if both numbers have same node count
            {
                if (overflow > 0)
                    result.X.INSERT_LEFT(overflow);
            }
            else if (thisNode == maxNode) //if the first number has greatest number of nodes
            {
                for (int i = minNode; i < maxNode; i++)
                {
                    addValue = X.NODE_VALUE(temp1) + overflow;
                    overflow = OVER_FLOW(addValue);
                    result.X.INSERT_LEFT(addValue);
                    if (!(X.IS_FIRST(temp1)))
                        temp1 = X.NEXT_LEFT(temp1);
                }

                if (overflow > 0)
                    result.X.INSERT_LEFT(overflow);
            }
            else if (QNode == maxNode) //if the second number has greatest number of nodes
            {
                for (int i = minNode; i < maxNode; i++)
                {
                    addValue = Q.X.NODE_VALUE(temp2) + overflow;
                    overflow = OVER_FLOW(addValue);
                    result.X.INSERT_LEFT(addValue);
                    if (!(Q.X.IS_FIRST(temp2)))
                        temp2 = Q.X.NEXT_LEFT(temp2);
                }

                if (overflow > 0)
                    result.X.INSERT_LEFT(overflow);
            }

        } //end sign ==sign

        else //opposite signs
        {
            int thisNode;
            int QNode;
            thisNode = X.NODE_COUNT();
            QNode = Q.X.NODE_COUNT();
            if (GREATERTHAN(Q)) //Q is negative
            {
                //create an ABS value of Q and pass it to SUBTRACT
                LongInteger ABSQ;
                ABSQ.SETSIGN('+');
                Node *tempc2 = Q.X.GET_FIRST();
                ABSQ.X.INSERT_FIRST(Q.X.NODE_VALUE(tempc2));
                for (int i = 1; i < QNode; i++)
                {
                    tempc2 = Q.X.NEXT_RIGHT(tempc2);
                    ABSQ.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
                }
                result = SUBTRACT(ABSQ);
            }
            else //Qis positive
            {
                //create an ABS value of this LongInteger and pass it to Q.SUBTRACT
                LongInteger ABSthis;
                ABSthis.SETSIGN('+');
                Node *tempc2 = X.GET_FIRST();
                ABSthis.X.INSERT_FIRST(X.NODE_VALUE(tempc2));
                for (int i = 1; i < thisNode; i++)
                {
                    tempc2 = X.NEXT_RIGHT(tempc2);
                    ABSthis.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
                }
                result = Q.SUBTRACT(ABSthis);
            }
        }

        return result;
    }

    //The SUBTRACT function implements subtract by 6 conditions, 4 where the signs are the same
    //and the outcome differs on which number is greater, and two that are opposite signs turned
    //to addition.
    LongInteger SUBTRACT(LongInteger Q)
    {
        LongInteger result;
        LongInteger burrowTemp;
        int constructBurrow;

        int subValue = 0;

        int thisNode;
        int QNode;
        int maxNode;
        int minNode;
        thisNode = X.NODE_COUNT();
        QNode = Q.X.NODE_COUNT();

        if (GETSIGN() == Q.GETSIGN())
        {
            if (EQUALTO(Q))
            {
                result.SETSIGN('+');
                result.X.INSERT_FIRST(0);
                return result;
            }
            if (GETSIGN() == 0) //if both positive
            {
                if (GREATERTHAN(Q))
                {
                    result.SETSIGN('+');
                    Node *tempBurrow = X.GET_FIRST();
                    constructBurrow = X.NODE_VALUE(tempBurrow);
                    burrowTemp.X.INSERT_FIRST(constructBurrow);
                    maxNode = thisNode;
                    minNode = QNode;
                    // I felt I needed a copy for the whole number to burrow from freely
                    //since I could encounter a Node to the left that was 0000 and this
                    //could happen for a number of consecutive nodes, then i would need
                    //to burrow from the first non-zero and alter all of the Nodes
                    //between the Node I burrowed from and the Node that burrowed
                    //this was a simple way to keep track and the LongInteger is
                    //deconstructed at the end of its use.

                    for (int i = 1; i < maxNode; i++)
                    {
                        tempBurrow = X.NEXT_RIGHT(tempBurrow);
                        constructBurrow = X.NODE_VALUE(tempBurrow);
                        burrowTemp.X.INSERT_RIGHT(constructBurrow);
                    }

                    Node *temp1 = burrowTemp.X.GET_LAST();
                    Node *temp2 = Q.X.GET_LAST();
                    Node *burrowSeek = burrowTemp.X.GET_LAST();

                    subValue = burrowTemp.X.NODE_VALUE(temp1) - Q.X.NODE_VALUE(temp2);
                    if (subValue < 0)
                    {
                        //burrowSeek goes out and finds the first Node I can burrow from
                        burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                        if (burrowTemp.X.NODE_VALUE(burrowSeek) > 0)
                        {
                            burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                            burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                            burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                        }
                        //if burrowSeek does not find the first Node able to lend it enters a loop
                        //until one is found. Then another loop that takes care of the numbers from
                        //the Node that was burrowed from to the Node that needed to burrow
                        else
                        {
                            while (burrowTemp.X.NODE_VALUE(burrowSeek) == 0)
                            {
                                burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                            }
                            while (burrowSeek != temp1)
                            {
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                            }
                        }
                        subValue = burrowTemp.X.NODE_VALUE(temp1) - Q.X.NODE_VALUE(temp2);
                    }
                    result.X.INSERT_FIRST(subValue); //end of inserting the first Node into result

                    //the following is an image of the above that takes care of inserting the remaining Nodes into
                    //result.
                    for (int i = 1; i < minNode; i++)
                    {
                        temp1 = burrowTemp.X.NEXT_LEFT(temp1);
                        temp2 = Q.X.NEXT_LEFT(temp2);
                        burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);

                        subValue = burrowTemp.X.NODE_VALUE(temp1) - Q.X.NODE_VALUE(temp2);
                        if (subValue < 0)
                        {
                            burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                            if (burrowTemp.X.NODE_VALUE(burrowSeek) > 0)
                            {
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                            }
                            else
                            {
                                while (burrowTemp.X.NODE_VALUE(burrowSeek) == 0)
                                {
                                    burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                                }
                                while (burrowSeek != temp1)
                                {
                                    burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                    burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                    burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                                }
                            }
                            subValue = burrowTemp.X.NODE_VALUE(temp1) - Q.X.NODE_VALUE(temp2);
                        }
                        result.X.INSERT_LEFT(subValue);
                    }

                    //inserts the remaining Nodes that are not subtracted from.
                    for (int i = minNode; i < maxNode; i++)
                    {
                        temp1 = burrowTemp.X.NEXT_LEFT(temp1);
                        //incase a number has been burrowed from from the first Node and made it a 0 Node
                        if (burrowTemp.X.IS_FIRST(temp1) && burrowTemp.X.NODE_VALUE(temp1) == 0)
                            break;
                        result.X.INSERT_LEFT(burrowTemp.X.NODE_VALUE(temp1));
                    }
                }
                ////////////////////

                else //the number subtracted is larger both positive
                {
                    result.SETSIGN('-');
                    Node *tempBurrow = Q.X.GET_FIRST();
                    constructBurrow = Q.X.NODE_VALUE(tempBurrow);
                    burrowTemp.X.INSERT_FIRST(constructBurrow);
                    maxNode = QNode;
                    minNode = thisNode;
                    for (int i = 1; i < maxNode; i++)
                    {
                        tempBurrow = Q.X.NEXT_RIGHT(tempBurrow);
                        constructBurrow = Q.X.NODE_VALUE(tempBurrow);
                        burrowTemp.X.INSERT_RIGHT(constructBurrow);
                    }

                    Node *temp1 = burrowTemp.X.GET_LAST();
                    Node *temp2 = X.GET_LAST();
                    Node *burrowSeek = burrowTemp.X.GET_LAST();

                    subValue = burrowTemp.X.NODE_VALUE(temp1) - X.NODE_VALUE(temp2);
                    if (subValue < 0)
                    {
                        burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                        if (burrowTemp.X.NODE_VALUE(burrowSeek) > 0)
                        {
                            burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                            burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                            burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                        }
                        else
                        {
                            while (burrowTemp.X.NODE_VALUE(burrowSeek) == 0)
                            {
                                burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                            }
                            while (burrowSeek != temp1)
                            {
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                            }
                        }
                        subValue = burrowTemp.X.NODE_VALUE(temp1) - X.NODE_VALUE(temp2);
                    }
                    result.X.INSERT_FIRST(subValue);

                    for (int i = 1; i < minNode; i++)
                    {
                        temp1 = burrowTemp.X.NEXT_LEFT(temp1);
                        temp2 = X.NEXT_LEFT(temp2);
                        burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);

                        subValue = burrowTemp.X.NODE_VALUE(temp1) - X.NODE_VALUE(temp2);
                        if (subValue < 0)
                        {
                            burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                            if (burrowTemp.X.NODE_VALUE(burrowSeek) > 0)
                            {
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                            }
                            else
                            {
                                while (burrowTemp.X.NODE_VALUE(burrowSeek) == 0)
                                {
                                    burrowSeek = burrowTemp.X.NEXT_LEFT(burrowSeek);
                                }
                                while (burrowSeek != temp1)
                                {
                                    burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) - 1);
                                    burrowSeek = burrowTemp.X.NEXT_RIGHT(burrowSeek);
                                    burrowTemp.X.CHANGE_NODE_VALUE(burrowSeek, burrowTemp.X.NODE_VALUE(burrowSeek) + 10000);
                                }
                            }
                            subValue = burrowTemp.X.NODE_VALUE(temp1) - X.NODE_VALUE(temp2);
                        }
                        result.X.INSERT_LEFT(subValue);
                    }

                    for (int i = minNode; i < maxNode; i++)
                    {
                        temp1 = burrowTemp.X.NEXT_LEFT(temp1);
                        if (burrowTemp.X.IS_FIRST(temp1) && burrowTemp.X.NODE_VALUE(temp1) == 0)
                            break;
                        result.X.INSERT_LEFT(burrowTemp.X.NODE_VALUE(temp1));
                    }
                }
                Node *temp1;
                temp1 = result.X.GET_FIRST();
                if (result.X.NODE_VALUE(temp1) == 0)
                {
                    while (result.X.NODE_VALUE(temp1) == 0)
                    {
                        temp1 = result.X.NEXT_RIGHT(temp1);
                    }
                    result.X.MOVE_HEAD(temp1);
                }

                return result;
            }

            else
            { //both signs are negative
                LongInteger ABSthis, ABSQ;
                ABSthis.SETSIGN('+');
                ABSQ.SETSIGN('+');
                Node *tempc1 = X.GET_FIRST();
                Node *tempc2 = Q.X.GET_FIRST();

                ABSthis.X.INSERT_FIRST(X.NODE_VALUE(tempc1));
                ABSQ.X.INSERT_FIRST(Q.X.NODE_VALUE(tempc2));
                for (int i = 1; i < thisNode; i++)
                {
                    tempc1 = X.NEXT_RIGHT(tempc1);
                    ABSthis.X.INSERT_RIGHT(X.NODE_VALUE(tempc1));
                }
                for (int i = 1; i < QNode; i++)
                {
                    tempc2 = Q.X.NEXT_RIGHT(tempc2);
                    ABSQ.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
                }

                if (ABSthis.LESSTHAN(ABSQ) || ABSthis.EQUALTO(ABSQ))
                {

                    result = ABSQ.SUBTRACT(ABSthis);
                    result.SETSIGN('+');
                }
                else
                {

                    result = ABSthis.SUBTRACT(ABSQ);
                    result.SETSIGN('-');
                }
            }
        }

        else //signs are different
        {
            if (GREATERTHAN(Q)) //Q is negative
            {
                LongInteger ABSQ;
                ABSQ.SETSIGN('+');
                Node *tempc2 = Q.X.GET_FIRST();
                ABSQ.X.INSERT_FIRST(Q.X.NODE_VALUE(tempc2));
                for (int i = 1; i < QNode; i++)
                {
                    tempc2 = X.NEXT_RIGHT(tempc2);
                    ABSQ.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
                }
                result = ADD(ABSQ);
                return result;
            }
            else //Q is positive
            {
                LongInteger NEGQ;
                NEGQ.SETSIGN('-');
                Node *tempc2 = Q.X.GET_FIRST();
                NEGQ.X.INSERT_FIRST(Q.X.NODE_VALUE(tempc2));
                for (int i = 1; i < QNode; i++)
                {
                    tempc2 = X.NEXT_RIGHT(tempc2);
                    NEGQ.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
                }
                result = ADD(NEGQ);
            }
        }
    }

    LongInteger MULTIPLY(LongInteger Q)
    {
        LongInteger result, tempAdd;
        int overflow = 0;
        int multValue = 0;
        int thisNode;
        int QNode;
        thisNode = X.NODE_COUNT();
        QNode = Q.X.NODE_COUNT();

        result.SETSIGN('+');

        Node *temp1 = X.GET_LAST();
        Node *temp2 = Q.X.GET_LAST();

        multValue = X.NODE_VALUE(temp1) * Q.X.NODE_VALUE(temp2);
        overflow = OVER_FLOW(multValue);
        result.X.INSERT_FIRST(multValue);
        temp1 = X.NEXT_LEFT(temp1);
        for (int i = 1; i < thisNode; i++)
        {
            multValue = (X.NODE_VALUE(temp1) * Q.X.NODE_VALUE(temp2)) + overflow;
            overflow = OVER_FLOW(multValue);
            result.X.INSERT_LEFT(multValue);
            temp1 = X.NEXT_LEFT(temp1);
        }
        if (overflow > 0)
            result.X.INSERT_LEFT(overflow);

        for (int i = 1; i < QNode; i++)
        {
            overflow = 0;
            temp2 = Q.X.NEXT_LEFT(temp2);
            temp1 = X.GET_LAST();
            tempAdd.X.~List();
            LongInteger tempAdd;
            tempAdd.SETSIGN('+');
            //Inserts zero Nodes at the end of tempAdd to account for the shift
            //before the add.
            tempAdd.X.INSERT_FIRST(0);
            for (int x = 1; x < i; x++)
                tempAdd.X.INSERT_LEFT(0);

            for (int j = 0; j < thisNode; j++)
            {
                multValue = (X.NODE_VALUE(temp1) * Q.X.NODE_VALUE(temp2)) + overflow;
                overflow = OVER_FLOW(multValue);
                tempAdd.X.INSERT_LEFT(multValue);
                temp1 = X.NEXT_LEFT(temp1);
            }
            if (overflow > 0)
                tempAdd.X.INSERT_LEFT(overflow);

            result = tempAdd.ADD(result);
        }

        if (GETSIGN() != Q.GETSIGN())
            result.SETSIGN('-');
        else
            result.SETSIGN('+');
        return result;
    }

    LongInteger POWER(int p)
    {
        LongInteger result;

        if (p == 0)
        {
            result.SETSIGN('+');
            result.X.INSERT_FIRST(1);
            return result;
        }

        LongInteger tempP;
        int ptemp = p;
        if (GETSIGN())
            tempP.SETSIGN('-');
        else
            tempP.SETSIGN('+');
        Node *temp = X.GET_FIRST();
        tempP.X.INSERT_FIRST(X.NODE_VALUE(temp));
        int nodeCount = X.NODE_COUNT();
        for (int i = 1; i < nodeCount; i++)
        {
            temp = X.NEXT_RIGHT(temp);
            tempP.X.INSERT_RIGHT(X.NODE_VALUE(temp));
        }

        result.X.INSERT_FIRST(1);
        result.SETSIGN('+');

        while (ptemp != 0)
        {
            if (ptemp % 2)
                result = result.MULTIPLY(tempP);

            tempP = tempP.MULTIPLY(tempP);
            ptemp = ptemp / 2;
        }
        return result;
    }

    LongInteger DIVIDE(LongInteger Q)
    {
        LongInteger result, remainder1, remainder2, paddedsub, ABSthis, ABSQ;
        string init;

        int thisNode;
        int QNode;
        thisNode = X.NODE_COUNT();
        QNode = Q.X.NODE_COUNT();

        ABSthis.SETSIGN('+');
        ABSQ.SETSIGN('+');
        Node *tempc1 = X.GET_FIRST();
        Node *tempc2 = Q.X.GET_FIRST();

        ABSthis.X.INSERT_FIRST(X.NODE_VALUE(tempc1));
        ABSQ.X.INSERT_FIRST(Q.X.NODE_VALUE(tempc2));
        for (int i = 1; i < thisNode; i++)
        {
            tempc1 = X.NEXT_RIGHT(tempc1);
            ABSthis.X.INSERT_RIGHT(X.NODE_VALUE(tempc1));
        }
        for (int i = 1; i < QNode; i++)
        {
            tempc2 = Q.X.NEXT_RIGHT(tempc2);
            ABSQ.X.INSERT_RIGHT(Q.X.NODE_VALUE(tempc2));
        }

        if (ABSthis.LESSTHAN(ABSQ))
        {
            init = "0";
            result.INITIALIZE(init);
            return result;
        }
        if (ABSthis.EQUALTO(ABSQ))
        {
            if (GETSIGN() == Q.GETSIGN())
            {
                init = "1";
                result.INITIALIZE(init);
                return result;
            }
            else
            {
                init = "-1";
                result.INITIALIZE(init);
                return result;
            }
        }

        int numerator, denominator, numDivide;

        remainder1.SETSIGN('+');
        remainder2.SETSIGN('+');
        paddedsub.SETSIGN('+');

        Node *temp1 = ABSthis.X.GET_FIRST();
        Node *temp2 = ABSQ.X.GET_FIRST();

        numerator = ABSthis.X.NODE_VALUE(temp1);
        denominator = ABSQ.X.NODE_VALUE(temp2);

        if (ABSthis.X.GET_FIRST() != ABSthis.X.GET_LAST())
        {
            numerator = numerator * 10000;
            temp1 = ABSthis.X.NEXT_RIGHT(temp1);
            numerator = numerator + ABSthis.X.NODE_VALUE(temp1);
        }

        if (ABSQ.X.GET_FIRST() != ABSQ.X.GET_LAST())
        {
            denominator = denominator * 10000;
            temp2 = ABSQ.X.NEXT_RIGHT(temp2);
            denominator = denominator + ABSQ.X.NODE_VALUE(temp2);
        }
        ////////////////

        while (numerator / denominator == 0)
        {
            denominator = denominator / 10;
        }
        while (DIGIT(numerator / denominator) > 1)
        {

            numerator = numerator / 10;
        }
        result.SETSIGN('+');
        LongInteger scale10;
        init = "10";
        scale10.INITIALIZE(init);

        numDivide = numerator / denominator;
        result.X.INSERT_FIRST(numDivide);

        ABSQ.PRINT();

        remainder2 = ABSQ.MULTIPLY(result);
        cout << "remainder 2 :";
        remainder2.PRINT();
        cout << endl;

        paddedsub = remainder2;

        while (ABSthis.GREATERTHAN(remainder2))
        {

            remainder2 = remainder2.MULTIPLY(scale10);
            if (ABSthis.GREATERTHAN(remainder2) || ABSthis.EQUALTO(remainder2))
            {
                paddedsub = remainder2;
            }
        }

        remainder1 = ABSthis.SUBTRACT(paddedsub);

        int zerocheck, zerochecklast;
        zerocheck = 0;

        while (ABSQ.LESSTHAN(remainder1) || ABSQ.EQUALTO(remainder1))
        {

            LongInteger multiplier;
            multiplier.SETSIGN('+');
            remainder1.SETSIGN('+');
            remainder2.SETSIGN('+');
            paddedsub.SETSIGN('+');

            temp1 = remainder1.X.GET_FIRST();
            temp2 = ABSQ.X.GET_FIRST();

            numerator = remainder1.X.NODE_VALUE(temp1);
            denominator = ABSQ.X.NODE_VALUE(temp2);
            if (ABSQ.X.GET_FIRST() != ABSQ.X.GET_LAST())
            {
                denominator = denominator * 10000;
                temp2 = ABSQ.X.NEXT_RIGHT(temp2);
                denominator = denominator + ABSQ.X.NODE_VALUE(temp2);
            }

            if (remainder1.X.GET_FIRST() != remainder1.X.GET_LAST())
            {
                numerator = numerator * 10000;
                temp1 = remainder1.X.NEXT_RIGHT(temp1);
                numerator = numerator + remainder1.X.NODE_VALUE(temp1);
            }

            while (numerator / denominator == 0)
            {

                denominator = denominator / 10;
            }
            while (DIGIT(numerator / denominator) > 1)
            {

                numerator = numerator / 10;
            }

            numDivide = numerator / denominator;

            multiplier.X.INSERT_FIRST(numDivide);

            remainder2 = ABSQ.MULTIPLY(multiplier);

            paddedsub = remainder2;

            zerochecklast = zerocheck;
            zerocheck = 0;
            while (remainder2.LESSTHAN(remainder1))
            {
                remainder2 = remainder2.MULTIPLY(scale10);
                if (remainder2.LESSTHAN(remainder1) || remainder2.EQUALTO(remainder1))
                {
                    zerocheck++;
                    paddedsub = remainder2;
                }
            }

            while (--zerochecklast > zerocheck)
            {
                result = result.MULTIPLY(scale10);
            }

            result = result.MULTIPLY(scale10);
            result = result.ADD(multiplier);
            remainder1 = remainder1.SUBTRACT(paddedsub);
            multiplier.X.~List();
        }

        if (GETSIGN() != Q.GETSIGN())
            result.SETSIGN('-');
        else
            result.SETSIGN('+');

        return result;
    }
};

int DIGIT(int T)
{
    if (T < 10)
        return 1;
    else if (T < 100)
        return 2;
    else if (T < 1000)
        return 3;
    else if (T < 10000)
        return 4;
    else if (T < 100000)
        return 5;
    else if (T < 1000000)
        return 6;
    else if (T < 10000000)
        return 7;
    else
        return 8;
}
int OVER_FLOW(int &T)
{
    if (DIGIT(T) < 5)
        return 0;
    int overflow = T / 10000;
    T = T % 10000;
    return overflow;
}